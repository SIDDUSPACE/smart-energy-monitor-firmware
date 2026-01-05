# Firmware Architecture

## Design Philosophy
This firmware follows a simulation-first, layered architecture. 
All application logic is decoupled from hardware-specific implementations through a Hardware Abstraction Layer (HAL).

## Layered Structure

Application Layer (app/)
- Energy computation logic (RMS, power, kWh)
- System state machine
- Load control policy
- Fault handling

Hardware Abstraction Layer (hal/)
- ADC interface
- GPIO interface
- Timer interface
- Communication interface

Simulation Layer (sim/)
- Simulated voltage and current waveforms
- Fault injection
- Load behavior modeling

## Data Flow
Simulated or real sensor data flows upward through HAL interfaces into the application layer.
Control decisions flow downward through HAL interfaces to actuators or simulated outputs.

## Key Rule
Application layer must never directly access hardware or simulation code.

## Firmware Modules

### Application Layer (app/)
- energy_manager
- system_state
- load_controller
- fault_manager

### HAL Layer (hal/)
- adc_if
- gpio_if
- timer_if
- comm_if

### Simulation Layer (sim/)
- adc_sim
- fault_sim
- load_sim

## Public Interfaces

### ADC Interface
float adc_get_voltage(void);
float adc_get_current(void);

### GPIO Interface
void gpio_set_relay(bool state);

### Timer Interface
uint32_t timer_get_ms(void);

### Communication Interface
void comm_publish_metrics(void);

## Task Ownership

- SensorTask: ADC sampling
- EnergyTask: RMS, power, energy calculation
- ControlTask: Load decision & relay control
- CommTask: Data publishing
- FaultTask: System monitoring & recovery
