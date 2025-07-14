# BLE Stack for nRF52840 on Contiki-NG

This is a lightweight custom BLE advertising stack implemented for the **nRF52840** platform using **Contiki-NG**. It focuses on BLE advertising (`ADV_IND`) using direct hardware register access via the Nordic `NRF_RADIO` peripheral.

---
## 🚀 Features

- BLE advertising (non-connectable)
- Raw PDU creation with custom device name and flags
- Direct radio hardware manipulation (no SoftDevice)
- 500ms periodic advertising
- Minimal and educational — great for understanding BLE at the bare-metal level

---

## 📂 Project Structure

| File            | Description                                                  |
|-----------------|--------------------------------------------------------------|
| `advertiser.c`  | Contiki process that initializes radio and sends ADV packets |
| `ble-radio.c/h` | Handles low-level BLE radio setup and packet transmission     |
| `ble-utils.c/h` | Builds raw BLE advertising PDUs with MAC, flags, and name    |
| `Makefile`      | Contiki-NG build script for nRF52840                         |

---

## 🛠️ Build & Flash Instructions

### ✅ Prerequisites

- [Contiki-NG](https://github.com/contiki-os/contiki-ng)
- Nordic SDK (for header definitions if needed)
- nRF52840 DK board
- `arm-none-eabi-gcc` toolchain
- JLink tools or nrfjprog for flashing

---
### 🧪 Build Example

```bash
cd contiki-ng/examples/ble-stack
make TARGET=nrf52840 BOARD=dk
sudo nrfjprog --eraseall
sudo nrfjprog --program build/nrf52840/dk/advertiser.hex --verify --reset
```
---

## 📡 Advertising Packet Structure

This stack sends a BLE advertising packet (`ADV_IND`) with the following content:

- **AdvA (MAC Address)**: `01:00:EF:BE:AD:DE`
- **Flags**: `LE General Discoverable Mode`, `BR/EDR not supported`
- **Device Name**: `"BLE-Test"`
---
