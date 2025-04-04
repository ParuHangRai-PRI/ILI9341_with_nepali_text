/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ILI9341_GFX.h"
#include "ILI9341_STM32_Driver.h"
#include "stdio.h"
#include "snow_tiger.h"
#include "pri_logo.h"
#include "tst_img.h"
#include "string.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
/* USER CODE BEGIN PFP */
void test_nepali(void);
void phut_nep(void);
void draw_logo(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
  ILI9341_Init();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//  phut_nep();
//  HAL_Delay(2000);
  test_nepali();
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA3 PA5 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PA4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : LD3_Pin */
  GPIO_InitStruct.Pin = LD3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD3_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void test_nepali(void)
{
	char nepali[42] = "svu3Br5hem`67890ftybwgkkmaedo/njzif;xIfq1";
	char vow[25] = "ccfOO{ppmPP]cf]cf}c+cM";
	char spc[18] = "flL'\"]}+MF[\\{|f]f}";
	char misc[5] = ",-_.=";
	char num[10] = "!@#$%^&*()";

	uint8_t fWidth = PREETI[1]+4;
	uint8_t fHeight = PREETI[2]+4;
	float scale = 0.5;

	uint16_t x = 0;
	uint16_t y = 0;
	uint8_t i = 0;
	uint8_t tst[3] = {0,8,37};
	char word[5];

	uint8_t len_spc = strlen(spc);
	uint8_t len_nep = strlen(nepali);

	ILI9341_SetRotation(SCREEN_VERTICAL_2);
	ILI9341_FillScreen(BLACK);

	while(i<len_nep)
	{
		if(i == 8 || i == 15 || i == 23 || i == 33 || i == 37)
		{
			word[0] = nepali[i];
			word[1] = nepali[i+1];
			word[2] = '\0';
			i += 2;
		}
		else
		{
			word[0] = nepali[i];
			word[1] = '\0';
			i++;
		}
		ILI9341_PreetiText(word, PREETI, scale, x,y, WHITE, BLACK);
		x += fWidth;
		if(x > (320/scale - fWidth)){x = 0; y += fHeight;}
	}
	HAL_Delay(2000);

	/*Print numbers 1,2,3,4,5,6,7,8,9,0*/
	ILI9341_FillScreen(BLACK);
	x = 0; y = 0;
	ILI9341_PreetiText(num, PREETI,scale, x,y, WHITE, BLACK);

	/*Print Vowels*/
	x = 0; y += fHeight;
	ILI9341_PreetiText(vow, PREETI, scale, x,y, WHITE, BLACK);

	/*Print special characters available in the font*/
	x = 0; y += fHeight;
	ILI9341_PreetiText("sf]", PREETI, scale ,x,y, WHITE, BLACK);
	HAL_Delay(5000);

	/*Test varnamala*/
	i = 0;
	while(i < 3)
	{
	  uint16_t x = 0;
	  uint8_t y = 0;
	  uint8_t j = 0;

	  ILI9341_FillScreen(BLACK);
	  while(j<len_spc)
	  {
		  if (i == 0 && j <14)
		  {
			  word[0] = nepali[tst[i]];
			  word[1] = spc[j];
			  word[2] = '\0';
		  }
		  else if (i == 0 && j >13)
		  {
			  word[0] = nepali[tst[i]];
			  word[1] = spc[j];
			  word[2] = spc[j+1];
			  word[3] = '\0';
			  j++;
		  }
		  else if (i > 0 && j >13)
		  {
			  word[0] = nepali[tst[i]];
			  word[1] = nepali[tst[i]+1];
			  word[2] = spc[j];
			  word[3] = spc[j+1];
			  word[4] = '\0';
			  j++;
		  }
		  else
		  {
			  word[0] = nepali[tst[i]];
			  word[1] = nepali[tst[i]+1];
			  word[2] = spc[j];
			  word[3] = '\0';
		  }

		  ILI9341_PreetiText(word, PREETI, scale ,x,y, WHITE, BLACK);
		  x += fWidth +10;
		  if(x > (320/scale - (fWidth+10))){x = 0; y += fHeight;}
		  j++;
	  }

	  HAL_Delay(10000);
	  i++;
	}
//	/*Print Hello World*/
//	ILI9341_FillScreen(BLACK);
//	x = 0; y = 0;
//	ILI9341_PreetiText("x]Nnf] jf]N8{", PREETI,1,x,y, WHITE, BLACK);

}

void draw_logo(void)
{
	ILI9341_FillScreen(WHITE);
	ILI9341_DrawImage(fig, SCREEN_VERTICAL_2);
}

void phut_nep(void)
{
	ILI9341_SetRotation(SCREEN_VERTICAL_2);
	ILI9341_FillScreen(BLACK);
	uint16_t x = 60;
	uint16_t y = 30;
	ILI9341_PreetiText("km'6'B\\u",PREETI, 1, x,y, 0x065F, BLACK);
	y += 90;
	ILI9341_DrawFilledRectangleCoord(x, y,x+30*6+15 ,y+6, 0x0257);
	y += 10;
	y *= 2.5;
	x *= 2.5;
	ILI9341_PreetiText("/l;{r", PREETI, 0.4, x,y, 0x0257, BLACK);
	x += 55*3;
	ILI9341_PreetiText("OG;6l6\\o'6", PREETI, 0.4, x,y, 0x8DA0, BLACK);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
