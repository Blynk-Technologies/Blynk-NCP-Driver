# Button and LED

## `rpc_hw_initUserButton(UInt16 gpio, Bool active_low)`

- `gpio`: GPIO number/pin used for the user button input.
- `active_low`: `true` if the button is considered **pressed** when the pin reads low (pulled to GND). `false` if pressed when the pin reads high.

Initialize the user button GPIO as a digital input.

## `rpc_hw_initLED(UInt16 gpio, Bool active_low)`

- `gpio`: GPIO number/pin used for a single-color LED output.
- `active_low`: `true` if the LED turns on when the pin is driven low. `false` if the LED turns on when driven high.

Initialize a single (monochrome) LED GPIO as a digital output.

## `rpc_hw_initRGB(UInt16 gpio_r, UInt16 gpio_g, UInt16 gpio_b, Bool common_anode)`

- `gpio_r`: GPIO for the Red channel.
- `gpio_g`: GPIO for the Green channel.
- `gpio_b`: GPIO for the Blue channel.
- `common_anode`: `true` for common-anode RGB (channels are active-low). `false` for common-cathode RGB (channels are active-high).

Initialize a discrete (3-pin) RGB LED using three GPIO outputs.

## `rpc_hw_initARGB(UInt16 gpio, UInt8 mode, UInt8 count)`

- `gpio`: GPIO number/pin used for the addressable RGB LED data line.
- `mode`: Reserved for future use. Currently it's fixed to `WS2812 / GRB / KHZ800`.
- `count`: Number of addressable LEDs (pixels) in the chain.

Initialize an addressable RGB LED strip/device (e.g., WS2812-like) on the given GPIO.

## `rpc_hw_setLedBrightness(UInt8 value)`

- `value`: Global brightness level `0..255`.

Set the global LED brightness scaling used by LED outputs.
