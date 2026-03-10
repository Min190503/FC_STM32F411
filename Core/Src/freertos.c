/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "flight_core.h"

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
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for Task_FlightCore */
osThreadId_t Task_FlightCoreHandle;
const osThreadAttr_t Task_FlightCore_attributes = {
  .name = "Task_FlightCore",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for Task_Radio */
osThreadId_t Task_RadioHandle;
const osThreadAttr_t Task_Radio_attributes = {
  .name = "Task_Radio",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for Task_Nav_IO */
osThreadId_t Task_Nav_IOHandle;
const osThreadAttr_t Task_Nav_IO_attributes = {
  .name = "Task_Nav_IO",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void Start_FlightCore(void *argument);
void Start_Radio(void *argument);
void Start_Nav_IO(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of Task_FlightCore */
  Task_FlightCoreHandle = osThreadNew(Start_FlightCore, NULL, &Task_FlightCore_attributes);

  /* creation of Task_Radio */
  Task_RadioHandle = osThreadNew(Start_Radio, NULL, &Task_Radio_attributes);

  /* creation of Task_Nav_IO */
  Task_Nav_IOHandle = osThreadNew(Start_Nav_IO, NULL, &Task_Nav_IO_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_Start_FlightCore */
/**
  * @brief  Function implementing the Task_FlightCore thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Start_FlightCore */
void Start_FlightCore(void *argument)
{
  /* USER CODE BEGIN Start_FlightCore */
  /* Infinite loop */

	// 1. tao cam bien va cac thanh phan chinh
	FlightCore_Init();

	// 2. toan quyen dieu khien cho vongf lap bay trong Service
	FlightCore_Task(NULL);

	// Thuc te se khong chay dong nay vi FLightCore_Task chua vong lap vo tan
	osThreadExit();
  /* USER CODE END Start_FlightCore */
}

/* USER CODE BEGIN Header_Start_Radio */
/**
* @brief Function implementing the Task_Radio thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_Radio */
void Start_Radio(void *argument)
{
  /* USER CODE BEGIN Start_Radio */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Start_Radio */
}

/* USER CODE BEGIN Header_Start_Nav_IO */
/**
* @brief Function implementing the Task_Nav_IO thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_Nav_IO */
void Start_Nav_IO(void *argument)
{
  /* USER CODE BEGIN Start_Nav_IO */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Start_Nav_IO */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

