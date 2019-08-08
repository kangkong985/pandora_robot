/**
  *      __            ____
  *     / /__ _  __   / __/                      __  
  *    / //_/(_)/ /_ / /  ___   ____ ___  __ __ / /_ 
  *   / ,<  / // __/_\ \ / _ \ / __// _ \/ // // __/ 
  *  /_/|_|/_/ \__//___// .__//_/   \___/\_,_/ \__/  
  *                    /_/   github.com/KitSprout    
  * 
  * @file    imu.h
  * @author  KitSprout
  * @date    27-Mar-2017
  * @brief   
  * 
  */

/* Define to prevent recursive inclusion ---------------------------------------------------*/
#ifndef __IMU_H
#define __IMU_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes --------------------------------------------------------------------------------*/
#include "mpu9250.h"

/* Exported types --------------------------------------------------------------------------*/

typedef struct {
  int8_t calibState;

  int16_t gyrRaw[3];      /* x = raw[0], y = raw[1], z = raw[2] */
  int16_t accRaw[3];
  int16_t magRaw[3];
  int16_t ictempRaw;

  int16_t gyrInt[3];
  int16_t accInt[3];
  int16_t magInt[3];
  int16_t ictempInt;
  int32_t baroInt[2];

  float32_t gyrData[3];
  float32_t accData[3];
  float32_t magData[3];
  float32_t ictempData;

  float32_t accMotion[3];

  // float32_t gyrScale[3];
  // float32_t accScale[3];
  // float32_t magScale[3];
  float32_t ictempScale;

  float32_t gyrFactor[3];
  float32_t accFactor[3];
  float32_t magFactor[3];

  // float32_t gyrCalib[3];
  // float32_t accCalib[9];
  // float32_t magCalib[9];    /* c11 = calib[0], c12 = calib[1], c13 = calib[2],
  //                              c21 = calib[3], c22 = calib[4], c23 = calib[5],
  //                              c31 = calib[6], c32 = calib[7], c33 = calib[8] */

  float32_t gyrOffset[3];
  float32_t accOffset[3];
  float32_t magOffset[3];
  float32_t ictempOffset;

  // float32_t accStrength;
  // float32_t magStrength;

} __attribute__((aligned)) imu_data_t;

typedef struct {
  imu_data_t data;
  mpu_config_t mpu;

} imu_t;

/* Exported constants ----------------------------------------------------------------------*/
/* Exported functions ----------------------------------------------------------------------*/  

int imu_init(imu_t *imux);
void imu_update(imu_t *imux);

#ifdef __cplusplus
}
#endif

#endif

/*************************************** END OF FILE ****************************************/
