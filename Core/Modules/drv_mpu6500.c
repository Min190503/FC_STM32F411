#include "drv_mpu6500.h"

// Gọi biến hspi1 đã được tạo sẵn ở bên file main.c sang đây để dùng
extern SPI_HandleTypeDef hspi1;

// Hàm đọc 1 byte từ thanh ghi của MPU6500
uint8_t MPU6500_ReadReg(uint8_t reg) {
    uint8_t read_data = 0;

    // MPU6500 quy định: Để ĐỌC, bit cao nhất (bit 7) của địa chỉ phải là 1
    uint8_t tx_data = reg | 0x80;

    // 1. Kéo chân CS xuống LOW để chọn chip
    HAL_GPIO_WritePin(MPU_CS_GPIO_Port, MPU_CS_Pin, GPIO_PIN_RESET);

    // 2. Gửi địa chỉ thanh ghi cần đọc
    HAL_SPI_Transmit(&hspi1, &tx_data, 1, 100);

    // 3. Nhận dữ liệu trả về (phải gửi 1 byte rác 0x00 để đẩy xung clock)
    uint8_t dummy = 0x00;
    HAL_SPI_TransmitReceive(&hspi1, &dummy, &read_data, 1, 100);

    // 4. Kéo chân CS lên HIGH để kết thúc phiên giao tiếp
    HAL_GPIO_WritePin(MPU_CS_GPIO_Port, MPU_CS_Pin, GPIO_PIN_SET);

    return read_data;
}

// Hàm ghi 1 byte vào thanh ghi của MPU6500
void MPU6500_WriteReg(uint8_t reg, uint8_t data) {
    // MPU6500 quy định: Để GHI, bit cao nhất (bit 7) của địa chỉ phải là 0
    uint8_t tx_data = reg & 0x7F;

    // Kéo CS xuống LOW
    HAL_GPIO_WritePin(MPU_CS_GPIO_Port, MPU_CS_Pin, GPIO_PIN_RESET);

    // Gửi địa chỉ thanh ghi
    HAL_SPI_Transmit(&hspi1, &tx_data, 1, 100);

    // Gửi dữ liệu cần ghi
    HAL_SPI_Transmit(&hspi1, &data, 1, 100);

    // Kéo CS lên HIGH
    HAL_GPIO_WritePin(MPU_CS_GPIO_Port, MPU_CS_Pin, GPIO_PIN_SET);
}

// Hàm khởi tạo và test kết nối SPI
uint8_t MPU6500_Init(void) {
    // Đảm bảo CS ở mức HIGH khi hệ thống vừa cấp điện
    HAL_GPIO_WritePin(MPU_CS_GPIO_Port, MPU_CS_Pin, GPIO_PIN_SET);

    // Chờ 100ms cho cảm biến khởi động ổn định sau khi có điện
    HAL_Delay(100);

    // Đọc thử thanh ghi WHO_AM_I (0x75)
    uint8_t who_am_i = MPU6500_ReadReg(MPU6500_REG_WHO_AM_I);

    // Kiểm tra xem nó có trả về đúng mã định danh 0x70 không
    if (who_am_i == MPU6500_WHO_AM_I_VAL) {
        return 1; // Kết nối OK
    }

    return 0; // Lỗi (có thể do đứt dây, lỏng cáp, sai cấu hình SPI hoặc hỏng cảm biến)
}
