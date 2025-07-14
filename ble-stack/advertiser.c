#include "contiki.h"
#include "dev/leds.h"
#include "ble-radio.h"
#include <stdio.h>

PROCESS(ble_advertiser_process, "BLE Advertiser");
AUTOSTART_PROCESSES(&ble_advertiser_process);

PROCESS_THREAD(ble_advertiser_process, ev, data)
{
  static struct etimer adv_timer;
  PROCESS_BEGIN();

  // ⚠️ This is the important part
  ble_radio_init();

  while(1) {
    ble_radio_send_adv_packet();
    etimer_set(&adv_timer, CLOCK_SECOND / 2); // 500ms
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&adv_timer));
  }

  PROCESS_END();
}

