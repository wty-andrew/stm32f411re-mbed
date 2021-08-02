# Pinout

| Function                            | Pololu VHN5019 Pin    | Sparkfun VNH2SP30 Pin |
|-------------------------------------|-----------------------|-----------------------|
| Motor 1 Enable Input / Fault Output | M1EN  (Digital - D6)  | Analog  - A0          |
| Motor 2 Enable Input / Fault Output | M2EN  (Digital - D12) | Analog  - A1          |
| Motor 1 Current Sense Output        | M1CS  (Analog  - A0)  | Analog  - A2          |
| Motor 2 Current Sense Output        | M2CS  (Analog  - A1)  | Analog  - A3          |
| Motor 2 Counterclockwise Input      | M2INB (Digital - D8)  | Digital - D9          |
| Motor 1 Counterclockwise Input      | M1INB (Digital - D4)  | Digital - D8          |
| Motor 1 Clockwise Input             | M1INA (Digital - D2)  | Digital - D7          |
| Motor 2 Speed Input                 | M2PWM (Digital - D10) | Digital - D6          |
| Motor 1 Speed Input                 | M1PWM (Digital - D9)  | Digital - D5          |
| Motor 2 Clockwise Input             | M2INA (Digital - D7)  | Digital - D4          |

# Operating Conditions

| Mode             | INA  | INB  |
|------------------|------|------|
| Clockwise        | HIGH | LOW  |
| Counterclockwise | LOW  | HIGH |
| Brake to VCC     | HIGH | HIGH |
| Brake to GND     | LOW  | LOW  |

# References
- Sparkfun Monster Moto Shield
  - https://www.sparkfun.com/products/retired/10182
  - https://github.com/sparkfun/Monster_Moto_Shield
- Pololu Dual VNH5019 Motor Driver Shield
  - https://www.pololu.com/product/2507
  - https://github.com/pololu/dual-vnh5019-motor-shield
- https://os.mbed.com/users/ianmcc/code/VNH5019/
- https://github.com/bmellink/VNH3SP30
