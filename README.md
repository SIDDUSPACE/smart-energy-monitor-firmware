# Smart Energy Monitor Firmware (Simulation-Based)

## Overview

This project implements a **simulation-first embedded firmware architecture** for a smart energy monitoring and protection system.  
It measures RMS voltage and current, computes real power and energy (Wh), detects overload conditions, and safely trips a relay using a **latched fault mechanism**.

The firmware is designed to be **hardware-independent** and validated entirely through simulation. The same architecture can later be deployed on a real microcontroller with minimal changes.

---

## Objectives

- Accurate RMS-based voltage and current measurement  
- Real power and energy calculation  
- Deterministic overload detection  
- Safe relay trip with fault latching  
- Continuous telemetry after fault (fail-safe behavior)  
- Simulation-based validation without physical hardware  

---

## Key Features

- RMS voltage and current computation using windowed sampling  
- Real power and energy (Wh) calculation  
- Overload detection synchronized to RMS updates  
- Latched relay trip using a fault manager  
- Clear separation between application logic and hardware abstraction  
- Simulation models for ADC, timer, GPIO, and communication  
- Production-style embedded firmware structure  

---

## Firmware Architecture

The firmware is organized into independent modules with clear responsibilities:

- **main.c**  
  System orchestration and control loop

- **Energy Manager**  
  - RMS voltage calculation  
  - RMS current calculation  
  - Real power computation  
  - Energy accumulation  

- **Load Controller**  
  - Overload detection using RMS current  
  - Multi-cycle validation  
  - Relay state decision  

- **Fault Manager**  
  - Latched fault handling  
  - Safety authority over relay state  

- **HAL (Hardware Abstraction Layer)**  
  - ADC interface  
  - GPIO interface  
  - Timer interface  
  - Communication interface  

- **Simulation Layer**  
  - Sine-wave voltage/current models  
  - Deterministic timing behavior  

---

## Project Structure
smart-energy-monitor-firmware/
├── firmware/
│ ├── app/ # Core application logic
│ ├── hal/ # Hardware abstraction layer
│ ├── sim/ # Simulation models
│ ├── include/ # Public headers
│ └── main.c
├── docs/
│ ├── architecture.md
│ └── simulation_model.md
├── assets/
│ └── screenshots/
├── README.md




---

## Simulation Flow

1. Simulated ADC generates sinusoidal voltage and current samples  
2. Samples are accumulated in a fixed RMS window  
3. RMS voltage and current are computed  
4. Load controller evaluates overload conditions  
5. Fault manager latches a fault if overload persists  
6. Relay is forced OFF  
7. System continues publishing telemetry  

This flow mirrors real industrial protection firmware behavior.

---

## Simulation Output (Example)

### Normal Operation
[SIM] Vrms=229.80 V, Irms=7.05 A, Energy=1.71 Wh

### Overload Condition
[SIM] Vrms=229.80 V, Irms=8.49 A, Energy=2.19 Wh

### Protection Triggered
[SIM] RELAY OFF


After the relay trips, the system continues running and reporting metrics.  
This is intentional and reflects fail-safe embedded design principles.

---

## Build and Run (Windows + MSYS2)

Compile the simulation binary:

```bash
gcc -DSIMULATION \
firmware/main.c \
firmware/app/*.c \
firmware/hal/*.c \
firmware/sim/*.c \
-o sim_energy_monitor -lm

```
Run:
./sim_energy_monitor

License

This project is intended for educational and demonstration purposes.

