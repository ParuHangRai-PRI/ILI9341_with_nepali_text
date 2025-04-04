# 320x240 LCD with ILI9341 driver and preeti font for STM32

The drivers are taken in reference to:

1. [https://github.com/eziya/STM32_HAL_ILI9341](https://github.com/eziya/STM32_HAL_ILI9341)
2. [https://github.com/martnak/STM32-ILI9341](https://github.com/martnak/STM32-ILI9341)

Font generated through [Mikroe GLCD Font Creator](https://www.mikroe.com/glcd-font-creator), same as in [Eziya](https://github.com/eziya/STM32_HAL_ILI9341) repository.

[Modification]
1. Added PreetiText and Nep_Char to plot nepali letters.
2. Rearranged SPI functions to suit the LCD

[Adding other Nepali fonts]
The available font is 63x85. It is generated from preeti font at 72 size. The font can be scaled down using PreetiTest function. If memory and computaion is limited you may prefer to have seperate font, following is the procedure:

1. Run GLCD Font Creator
2. Create new font with your desired font and size
3. You need to mannualy create some fonts, especially for मात्रा( ि, ी, ु, े, etc). "द्य" has been replaced with "ङ", so change it.
4. Move bitmap images of font to middle, leave ( ि, ी, ा) as it is.
5. Some letters(झ, ष, क्ष, फ, ण) are formed by combining half letters(ह्रस्व अक्षर) with other as such the half letteres should be moved to fit.
6. Export it in mikroC format
7. Modify data type to uint8_t
8. Add 4 byte
   1.  Offset: the number of bytes representing a letter
   2.  Width: maximum width of the character
   3.  Height: maximum height of the character
   4.  BPL: ceil(Height/8)
9. Add it to fonts.h
