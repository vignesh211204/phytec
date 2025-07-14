# 🌱 Contiki-NG on Nordic nRF52840 DK

This guide explains how to build and run the Contiki-NG operating system on the **Nordic nRF52840 DK** for low-power IPv6-based IoT applications like CoAP, RPL, and 6LoWPAN.

---

## 🧠 About Contiki-NG

Contiki-NG (Next Generation) is an open-source operating system for the Internet of Things (IoT). It is designed for:

- 🧠 Event-driven applications  
- 🌐 IPv6 and 6LoWPAN networking  
- 📡 CoAP, RPL, UDP, TCP protocols  
- 🔋 Ultra-low power consumption  
- 🧪 Simulations using Cooja  

---

## 🛠️ Hardware: Nordic nRF52840 DK

| Feature        | Description                        |
|----------------|------------------------------------|
| MCU            | ARM Cortex-M4F @ 64 MHz            |
| Flash          | 1 MB                               |
| RAM            | 256 KB                             |
| Connectivity   | BLE 5.0, Thread (802.15.4), Zigbee |
| Interfaces     | USB, UART, SPI, I2C, GPIO, PWM     |

---

## 🔧 Toolchain Setup

### Install Required Packages

```bash
sudo apt update
sudo apt install gcc-arm-none-eabi make git python3-pip
pip3 install pyelftools
```

---

## 📥 Clone Contiki-NG

```bash
git clone https://github.com/contiki-ng/contiki-ng.git
cd contiki-ng
git submodule update --init --recursive
```

## 📡 Communication Interfaces

| Interface     | Interface                          |
|---------------|------------------------------------|
| UART          | Serial console / debug output      |
| 802.15.4      | 6LoWPAN communication              |
| USB           | Flashing / power / serial          |
| BLE           | Not fully supported in Contiki-NGe |


---
# 🌐 CoAP in Contiki-NG

Contiki-NG includes a lightweight CoAP (Constrained Application Protocol) implementation based on the **Erbium (Er)** REST engine, allowing efficient RESTful communication for low-power IoT devices.

---

## 📦 CoAP Examples in Contiki-NG

These examples demonstrate how to use CoAP in real-world applications on both hardware and native Linux targets.

### ✅ `coap-example-server`

- A simple CoAP server that exposes several REST endpoints.
- Includes the `/actuators/toggle` resource.
- Used to simulate sensor/actuator endpoints in IoT networks.

### ✅ `coap-example-client`

- A CoAP client that sends GET requests to `/actuators/toggle` every 10 seconds.
- On button press, cycles through four predefined target resources.
- The target server address is hard-coded in the example.

### ✅ `coap-plugtest-server`

- A comprehensive CoAP server used in **ETSI Plugtest** interoperability events (Paris & Sophia-Antipolis).
- Conforms to draft CoAP specifications.
- Supports a broad range of REST resources and response types.
- Intended for use with the **native platform** (Linux host).

---

## 🛠️ Build & Run CoAP Examples

You can run the CoAP examples either on real hardware (like the Nordic nRF52840 DK) or directly on your Linux PC using the native platform for testing.

---

### 🔧 On Real Hardware (nRF52840 DK)

Compile and flash the CoAP server example:

```bash
cd contiki-ng/examples/coap/coap-example-server
make TARGET=nrf52840 BOARD=nrf52840dk coap-example-server.bin
nrfjprog --program coap-example-server.hex --chiperase --verify --reset
```
### ▶️ On Native (Linux)

Build and run like this:

```bash
cd contiki-ng/examples/coap/coap-example-server
make TARGET=native
sudo ./coap-example-server.native
```
---







