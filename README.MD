# Smart Bracelet Project with Raspberry Pi Pico

This repository contains the source code for a smart bracelet project based on the Raspberry Pi Pico microcontroller. It utilizes the DHT11 temperature and humidity sensor, along with LEDs and buttons to display measured values.

## Requirements

- **Arduino IDE**: The project is developed using Arduino IDE. Make sure you have the latest version of Arduino IDE installed on your computer.
- **DHT sensor library for Arduino**: Before compiling the code, install the DHT sensor library in the Arduino IDE. Go to `Sketch` > `Include Library` > `Manage Libraries...` and search for `DHT sensor library`. Install the library for seamless integration with the DHT11 sensor.

## Hardware Setup

- **DHT11 Sensor**: Connect the DHT11 sensor to pin `16` of your Raspberry Pi Pico.
- **LEDs**:
  - **Temperature LED (Green)**: Connect the green LED to pin `21` for temperature indication.
  - **Humidity LED (Red)**: Connect the red LED to pin `22` for humidity indication.
- **Buttons**:
  - **Temperature Button**: Connect a button to pin `19`. Pressing this button will display the temperature reading.
  - **Humidity Button**: Connect another button to pin `12`. Pressing this button will display the humidity reading.

## How It Works

- The DHT11 sensor periodically measures the temperature and humidity.
- Press the **Temperature Button** to blink the green LED. The number of blinks represents the temperature value. For example, 23 blinks for 23°C.
- Press the **Humidity Button** to blink the red LED. The number of blinks represents the humidity percentage. For example, 60 blinks for 60% RH.

## Contributing

Contributions to this project are welcome. Please consider forking the repository and submitting a pull request with your improvements.
