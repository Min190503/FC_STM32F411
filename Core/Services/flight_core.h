#ifndef FLIGHT_CORE_H_
#define FLIGHT_CORE_H_

#include "main.h"


//khoi tao truoc khi RTOS chia thoi gian
void FlightCore_Init(void);


//vongf lap vo tan cua rieng task FlightCore
void FlightCore_Task(void *argument);

#endif
