# Simulation Model

## Electrical Model
- AC Voltage: 230V RMS, 50 Hz sinusoidal waveform
- AC Current: Variable RMS based on simulated load
- Sampling Rate: 2 kHz per channel

## Mathematical Representation
Instantaneous voltage:
v(t) = V_peak × sin(2πft)

Instantaneous current:
i(t) = I_peak × sin(2πft + φ)

Where:
- V_peak = 325V
- f = 50 Hz
- φ = phase angle (0–30 degrees)

## RMS Calculation
RMS values are computed over one full AC cycle.

## Power Metrics
- Instantaneous Power: p(t) = v(t) × i(t)
- Real Power: P = V_rms × I_rms × cos(φ)
- Energy accumulation in watt-hours (Wh)

## Fault Scenarios
- Overcurrent condition
- Voltage spike
- Sensor disconnect
- Communication failure

## Overload Definition
System enters overload state when current exceeds configured RMS threshold for more than 2 consecutive cycles.
