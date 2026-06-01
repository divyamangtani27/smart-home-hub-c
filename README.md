# 🏠 Smart Home Hub

A terminal-based Smart Home control system built in C, designed to simulate centralized control of home devices — room by room — through a clean menu-driven interface.

---

## 👩‍💻 About Me

**Divya Mangtani**  
B.Tech — Artificial Intelligence and Machine Learning  
Symbiosis Institute of Technology, Pune · Batch 2025–29  
GitHub: [divyamangtani27](https://github.com/divyamangtani27)

---

## 📌 Overview

Smart home systems are everywhere today — Alexa, Google Home, IoT devices. What fascinated me while building this was realising that the core logic behind all of them starts with exactly this: a program that tracks device states, handles user input, and makes decisions in real time.

This project is a software simulation of that logic, built entirely in C. No hardware. No sensors. Just pure programming — and a clearer understanding of how software connects to the real-world devices around us.

---

## ⚙️ Devices & Controls

| Device | Controls Available |
|---|---|
| 💡 Light | ON / OFF · Room selection |
| 🌀 Fan | ON / OFF · Speed (Slow / Medium / Fast) · Room selection |
| ❄️ AC | ON / OFF · Temperature setting (16°C – 30°C) |
| 🪟 Window | Open / Close / Halfway · Manual or Auto (sunlight-based) mode · Room selection |

**Supported Rooms:** Bedroom 1 · Bedroom 2 · Kitchen · Living Room

---

## 🔧 Technical Details

- **Language:** C
- **Concepts Used:** Functions, Global Variables, Switch-Case, Do-While Loop, Input Validation, State Management
- **Architecture:** Modular — each device has its own dedicated control function
- **Input Handling:** All invalid entries are caught and handled gracefully without crashing
- **State Tracking:** Device status, room, speed, and temperature are tracked globally across the entire session

---

## 📂 Project Structure

```
SmartHomeHub/
│
├── SmartHomeHub.c       # Main source file
└── README.md            # Project documentation
```

---

## 📸 Sample Output

```
========================================
      WELCOME TO SMART HOME HUB
         by Divya Mangtani
========================================

=== MAIN MENU ===
1. Light
2. Fan
3. AC
4. Window
5. View Status
6. Exit
Enter choice:
```

---

## 🔭 Future Scope

- Web-based interface using Python and Streamlit for browser-based control
- Multi-device conflict handling (e.g. prevent AC and Fan running simultaneously)
- Persistent session storage to remember settings across runs

