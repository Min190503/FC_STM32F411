#include "flight_core.h"
#include "drv_mpu6500.h"
#include "cmsis_os.h" //thu vien cac ham cua FreeRTOS


uint8_t fc_mpu_status =0;


//Logic 1: khoi tao
void FlightCore_Init(void){

	//check ICU
	fc_mpu_status = MPU6500_Init();
}


//Logic 2: vong lap bay
void FlightCore_Task(void *argument){

	// Tần số vòng lặp: Giả sử ta muốn vòng lặp này chạy ở 1000Hz (1ms/lần)
	// Trong CMSIS v2, 1 tick thường mặc định = 1ms.
	uint32_t loop_delay = 1;

	//lay thoi diem hien tai cua he dieu hanh
	uint32_t tick_update = osKernelGetTickCount();

	//vong lap vo tan cua Task
	for(;;){
		//-------BAT DAU 1 CHU KY-----------------

		if(fc_mpu_status == 1){

		}

		//------ KET THUC CHU KY ------

		//bat buoc chu ky keo dai dung loop_delay, neu task xong som se nhuong CPU neu k co ham, task se dung het cpu
		osDelayUntil(tick_update + loop_delay);

		tick_update += loop_delay;
	}
}
