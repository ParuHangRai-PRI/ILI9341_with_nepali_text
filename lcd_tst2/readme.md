# STM32 implementation of ILI9341 320x240 LCD

The example is based on STM32L432KC. Following pins are used:

|Operation Mode|STM32 Pin  |LCD pin|
|--------------|-----------|-------|
|SPI           |PA1        |SCK    |
|SPI           |PA7        |MOSI   |
|GPIO          |PA3        |CS     |
|GPIO          |PA4        |RST    |
|GPIO          |PA5        |DC     |
------------------------------------

Copy driver source codes to Inc and Src folder for headers and source codes respectively.
Edit ILI9341_STM32_Driver.h to configure to your respective STM device and pins if other pins are used.
Include the header files in main.c and you are good to go.
