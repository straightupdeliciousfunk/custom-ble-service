// BLE Custom User Service header

#include <stdint.h>
#include <stdbool.h>
#include "ble.h"
#include "ble_srv_common.h"



// randomly generated 128-bit UUID: 50726474-43f3-4ec2-a496-219dda6deedb
// given as 8-4-4-4-16 big endian from https://www.uuidgenerator.net/version4 

// little endian and capitalized: BDEED6ADD912-694A-3F34-47462705
//
#define CUSTOM_SERVICE_UUID_BASE    { 0xBD, 0XEE, 0XD6, 0xAD, 0xD9, 0x12, 0x69, 0x4A, \
                                      0x3F, 0x34, 0x47, 0x46, 0x27, 0x05 }
    


// These will be inserted into the base_uuid
//  
#define CUSTOM_SERVICE_UUID               0x1400        // 16-bit custom service uuid
#define CUSTOM_VALUE_CHAR_UUID            0x1401        // 16-bit custom value characteristic uuid


/**@brief   Macro for defining a ble_cus instance.
 *
 * @param   _name   Name of the instance.
 * @hideinitializer
 */
#define BLE_CUS_DEF(_name) static ble_cus_t _name;


/**@brief Custom Service init structure. This contains all options and data needed for
 *        initialization of the service.*/
typedef struct
{
    uint8_t                       initial_custom_value;           /**< Initial custom value */
    ble_srv_cccd_security_mode_t  custom_value_char_attr_md;     /**< Initial security level for Custom characteristics attribute */
} ble_cus_init_t;


/**@brief Custom Service structure. This contains various status information for the service. */
struct ble_cus_s
{
    uint16_t                      service_handle;                 /**< Handle of Custom Service (as provided by the BLE stack). */
    ble_gatts_char_handles_t      custom_value_handles;           /**< Handles related to the Custom Value characteristic. */
    uint16_t                      conn_handle;                    /**< Handle of the current connection (as provided by the BLE stack, is BLE_CONN_HANDLE_INVALID if not in a connection). */
    uint8_t                       uuid_type; 
};


// forward declaration of ble_cus_t type
typedef struct ble_cus_s ble_cus_t;

/**@brief Function for initializing the Custom Service.
 *
 * @param[out]  p_cus       Custom Service structure. This structure will have to be supplied by
 *                          the application. It will be initialized by this function, and will later
 *                          be used to identify this particular service instance.
 * @param[in]   p_cus_init  Information needed to initialize the service.
 *
 * @return      NRF_SUCCESS on successful initialization of service, otherwise an error code.
 */
// uint32_t?
__uint32_t ble_cus_init(ble_cus_t * p_cus, const ble_cus_init_t * p_cus_init);





