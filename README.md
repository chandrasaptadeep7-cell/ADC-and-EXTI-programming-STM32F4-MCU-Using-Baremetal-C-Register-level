# ADC-and-EXTI-programming-STM32F4-MCU-Using-Baremetal-C-Register-level

## Objective:
To configure ADC(Analog Digital Converter) and EXTI(External Interrupt), where PB1 handles the external interrupts and the PA0 read the analog values from sensor or potentiometer, PC15, and PC13 are the output two LEDs will be connected to these pins.

## Note:
This Embedded C program is strictly for STM32F401CCU6 if you using some other MCUs it will  or may not work. 

## Hardware used:
* STM32F401CCU6 Microcontroller
* ST link V2
* 2 Resistors - 33 Ohm, 10k
* 1 Potentiometer - 10k
* Wires - To make connection between the microcontroller and ST link v2, connect with button
* 1 Bread Board
* 1 Button
* 1 LED
* 1 Capacitor (0.1 or 0.01 uF)

## Software Required:
* STM32cubeIDE
* STM32CubeProgrammer

## Documents required:
* STM32F401CCU6 Reference manual (RM).
* STM32F401CCU6 Datasheet (DS).
* Arm Cortex M4 Program Manual.

## Connection between STlink v2 and the MCU:
| **ST-Link V2 Pin** | **STM32F401CCU6 Pin** | **Purpose** |
|---|---|---|
| **3.3V** | **3.3V** | Power supply |
| **GND** | **GND** | Ground |
| **SWDIO** | **DIO (SWDIO)** | Serial Wire Debug data input/output |
| **SWCLK** | **CLK (SWCLK)** | Serial Wire Debug clock |

## How to download the documents:
* STM32F401CCU6 Reference manual - https://www.st.com/resource/en/reference_manual/rm0368-stm32f401xbc-and-stm32f401xde-advanced-armbased-32bit-mcus-stmicroelectronics.pdf
* STM32F401CCU6 Datasheet - https://www.st.com/resource/en/datasheet/stm32f401cc.pdf
* Arm Cortex M4 Program manual -  https://www.st.com/resource/en/programming_manual/pm0214-stm32-cortexm4-mcus-and-mpus-programming-manual-stmicroelectronics.pdf

## Challenges faced:
* Logical Error while manipulating bits of each register.
* STlink v2 stopped working that we shall discusse in "fix.pdf" document.
* Understanding ADC congiguretion.
