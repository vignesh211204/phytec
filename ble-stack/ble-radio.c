#include "ble-radio.h"
#include "ble-utils.h"
#include "nrf.h"
#include <stdio.h>
#include <string.h>

static uint8_t adv_buf[40];

void ble_radio_init(void) {
  // Start High Frequency Clock
  NRF_CLOCK->TASKS_HFCLKSTART = 1;
  while (NRF_CLOCK->EVENTS_HFCLKSTARTED == 0);
  NRF_CLOCK->EVENTS_HFCLKSTARTED = 0;

  // Set Radio TX Power and Mode
  NRF_RADIO->TXPOWER = RADIO_TXPOWER_TXPOWER_0dBm;
  NRF_RADIO->MODE = RADIO_MODE_MODE_Ble_1Mbit;

  // Access Address for ADV channels
  NRF_RADIO->BASE0 = 0x89BED600;
  NRF_RADIO->PREFIX0 = 0x8E;
  NRF_RADIO->TXADDRESS = 0;
  NRF_RADIO->RXADDRESSES = 1;

  // CRC config
  NRF_RADIO->CRCCNF = RADIO_CRCCNF_LEN_Three;
  NRF_RADIO->CRCINIT = 0x555555;
  NRF_RADIO->CRCPOLY = 0x00065B;

  // Packet configuration
  NRF_RADIO->PCNF0 = (1 << RADIO_PCNF0_LFLEN_Pos) |  // 8-bit length
                     (0 << RADIO_PCNF0_S0LEN_Pos) |
                     (0 << RADIO_PCNF0_S1LEN_Pos);

  NRF_RADIO->PCNF1 = (37 << RADIO_PCNF1_MAXLEN_Pos) |
                     (3 << RADIO_PCNF1_STATLEN_Pos) |
                     (RADIO_PCNF1_WHITEEN_Enabled << RADIO_PCNF1_WHITEEN_Pos) |
                     (RADIO_PCNF1_ENDIAN_Little << RADIO_PCNF1_ENDIAN_Pos);

  printf("BLE radio initialized\n");
}

void ble_radio_send_adv_packet(void) {
  int len = ble_utils_create_adv_pdu(adv_buf);
  printf("Sending ADV packet: len=%d\n", len);

  // Debug: print raw PDU bytes
  printf("Raw PDU: ");
  for(int i = 0; i < len; i++) {
    printf("%02X ", adv_buf[i]);
  }
  printf("\n");

  NRF_RADIO->PACKETPTR = (uint32_t)adv_buf;

  // BLE advertising on channel 37 (2402 MHz)
  NRF_RADIO->FREQUENCY = 2;
  NRF_RADIO->DATAWHITEIV = 37;

  NRF_RADIO->EVENTS_READY = 0;
  NRF_RADIO->EVENTS_END = 0;

  NRF_RADIO->TASKS_TXEN = 1;
  while(NRF_RADIO->EVENTS_READY == 0);
  NRF_RADIO->TASKS_START = 1;
  while(NRF_RADIO->EVENTS_END == 0);
  NRF_RADIO->TASKS_DISABLE = 1;

  printf("ADV packet sent\n");
}

