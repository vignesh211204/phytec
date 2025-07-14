#include "ble-utils.h"
#include <string.h>

/**
 * Build BLE ADV_IND packet
 * Structure: [Header][Length][AdvA][AD Structures...]
 */
int ble_utils_create_adv_pdu(uint8_t *buf) {
  int index = 0;

  // 1. BLE Header: ADV_IND (0x00) + TxAdd=0 (public address)
  buf[index++] = 0x40; // PDU Type: ADV_IND (0x00) + TxAdd=0 → 0x40

  // 2. Payload length = AdvA (6) + Flags (3) + Name (10) = 19 (0x13)
  buf[index++] = 0x13;

  // 3. AdvA (MAC Address) - little endian
  uint8_t mac[6] = { 0xDE, 0xAD, 0xBE, 0xEF, 0x00, 0x01 };
  memcpy(&buf[index], mac, 6);
  index += 6;

  // 4. AD Structure 1: Flags
  buf[index++] = 0x02; // Length (type + value)
  buf[index++] = 0x01; // Type: Flags
  buf[index++] = 0x06; // LE General Discoverable Mode, BR/EDR not supported

  // 5. AD Structure 2: Complete Local Name
  buf[index++] = 0x09; // Length (type + "BLE-Test" 8 chars)
  buf[index++] = 0x09; // Type: Complete Local Name
  memcpy(&buf[index], "BLE-Test", 8); // Copy name
  index += 8;

  // Total PDU length
  return index;
}

