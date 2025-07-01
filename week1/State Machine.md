## 🧠State Machine

A **state machine** is a programming pattern used to model system behavior as a sequence of defined **states** and **transitions**. It’s especially useful in embedded systems, communication protocols, and real-time applications.
A **state machine** consists of:
- **States**: Conditions or modes the system can be in.
- **Events**: Triggers that cause transitions between states.
- **Transitions**: Rules that define what happens when an event occurs in a given state.
- **Actions**: Operations performed during transitions or while in a state.

---
## 📨 Use Case: Message Exchange Between Devices

### 📘 States:
- **IDLE**: Waiting for a message
- **SENDING**: Sending a message
- **WAIT_ACK**: Waiting for acknowledgment
- **RECEIVING**: Receiving a message

### 📩 Events:
- `send_request`
- `ack_received`
- `message_received`
- `timeout`

### 🔁 Transition Table

| Current State | Event           | Next State   | Action                    |
|---------------|------------------|--------------|----------------------------|
| IDLE          | send_request     | SENDING      | Prepare and send message  |
| SENDING       | message_sent     | WAIT_ACK     | Start timeout timer       |
| WAIT_ACK      | ack_received     | IDLE         | Confirm success           |
| WAIT_ACK      | timeout          | IDLE         | Retry or fail             |
| IDLE          | message_received | RECEIVING    | Process incoming message  |
| RECEIVING     | ack_sent         | IDLE         | Return to idle            |

---

```c
#include <stdio.h>

typedef enum { IDLE, SENDING, WAIT_ACK, RECEIVING } State;
typedef enum { SEND_REQUEST, MESSAGE_SENT, ACK_RECEIVED, TIMEOUT, MESSAGE_RECEIVED, ACK_SENT } Event;

State currentState = IDLE;

void sendMessage() {
    printf("Action: Sending message...\n");
}

void processMessage() {
    printf("Action: Processing received message...\n");
}

void startAckTimer() {
    printf("Action: Starting ACK timer...\n");
}

void handleEvent(Event e) {
    switch (currentState) {
        case IDLE:
            if (e == SEND_REQUEST) {
                sendMessage();
                currentState = SENDING;
            } else if (e == MESSAGE_RECEIVED) {
                processMessage();
                currentState = RECEIVING;
            }
            break;
        case SENDING:
            if (e == MESSAGE_SENT) {
                startAckTimer();
                currentState = WAIT_ACK;
            }
            break;
        case WAIT_ACK:
            if (e == ACK_RECEIVED || e == TIMEOUT) {
                currentState = IDLE;
            }
            break;
        case RECEIVING:
            if (e == ACK_SENT) {
                currentState = IDLE;
            }
            break;
    }
}

int main() {
    printf("Initial State: IDLE\n");

    handleEvent(SEND_REQUEST);     
    handleEvent(MESSAGE_SENT);      
    handleEvent(ACK_RECEIVED);     

    handleEvent(MESSAGE_RECEIVED);  
    handleEvent(ACK_SENT);         

    return 0;
}

```

---

## ✅ Advantages of Event-Driven State Machines

- Clear and maintainable code structure  
- Scales well as complexity increases  
- Suitable for real-time, interrupt-driven systems  
- Easy debugging and simulation  

---
## 📌 Summary Table

| Term              | Meaning                                                |
|-------------------|--------------------------------------------------------|
| **State**         | A mode the system is in (e.g., IDLE, SENDING)         |
| **Event**         | An input or trigger that causes a transition          |
| **Transition**    | Change from one state to another based on event       |
| **Action**        | Task executed during a state or transition            |
| **Event-Driven**  | System reacts only when an event occurs               |
| **Use Case**      | Message passing, protocol handling, device control    |
