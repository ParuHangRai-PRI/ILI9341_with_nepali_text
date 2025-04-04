# STM32 implementation of ILI9341 320x240 LCD

The example is based on STM32L432KC. Following pins are used:

|Operation Mode|STM32 Pin  |LCD pin|
|--------------|-----------|-------|
|SPI           |PA1        |SCK    |
|SPI           |PA7        |MOSI   |
|GPIO          |PA3        |CS     |
|GPIO          |PA4        |RST    |
|GPIO          |PA5        |DC     |
