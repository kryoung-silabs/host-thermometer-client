/***************************************************************************//**
 * @file
 * @brief Application header file
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#ifndef APP_H
#define APP_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************//**
 * \defgroup app Application Code
 * \brief Sample Application Implementation
 **************************************************************************************************/

 //#define _DEBUG                        1 //uncomment for debug printing
 // connection parameters
 #define CONN_INTERVAL_MIN             80   //100ms
 #define CONN_INTERVAL_MAX             80   //100ms
 #define CONN_SLAVE_LATENCY            0    //no latency
 #define CONN_TIMEOUT                  100  //1000ms

 #define SCAN_INTERVAL                 16   //10ms
 #define SCAN_WINDOW                   16   //10ms
 #define SCAN_PASSIVE                  0

 #define TEMP_INVALID                  (uint32_t)0xFFFFFFFFu
 #define RSSI_INVALID                  (int8_t)127
 #define CONNECTION_HANDLE_INVALID     (uint8_t)0xFFu
 #define SERVICE_HANDLE_INVALID        (uint32_t)0xFFFFFFFFu
 #define CHARACTERISTIC_HANDLE_INVALID (uint16_t)0xFFFFu
 #define TABLE_INDEX_INVALID           (uint8_t)0xFFu

 #define EXT_SIGNAL_PRINT_RESULTS      0x01

#ifndef MAX_CONNECTIONS
#define MAX_CONNECTIONS               4
#endif

#define USE_CODED_PHY 0     //1 to use coded phy, 0 to use 1mbps PHY

#if USE_CODED_PHY == 1
#define DEFAULT_PHY_TYPE le_gap_phy_coded
#else
#define DEFAULT_PHY_TYPE le_gap_phy_1m
#endif

/***********************************************************************************************//**
 * @addtogroup Application
 * @{
 **************************************************************************************************/

/***********************************************************************************************//**
 * @addtogroup app
 * @{
 **************************************************************************************************/

/***************************************************************************************************
 * Type Definitions
 **************************************************************************************************/
 typedef enum {
   scanning,
   opening,
   discoverServices,
   discoverCharacteristics,
   enableIndication,
   running
 } ConnState;

 typedef struct {
   uint8_t  connectionHandle;
   int8_t   rssi;
   uint16_t serverAddress;
   uint32_t thermometerServiceHandle;
   uint16_t thermometerCharacteristicHandle;
   uint32_t temperature;
 } ConnProperties;

/***************************************************************************************************
 * Function Declarations
 **************************************************************************************************/

/***********************************************************************************************//**
 *  \brief  Handle application events.
 *  \param[in]  evt  incoming event ID
 **************************************************************************************************/
void appHandleEvents(struct gecko_cmd_packet *evt);

/** @} (end addtogroup app) */
/** @} (end addtogroup Application) */

#ifdef __cplusplus
};
#endif

#endif /* APP_H */
