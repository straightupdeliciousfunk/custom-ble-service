//LE Custom User Service

#include "sdk_common.h"
#include "ble_srv_common.h"
#include "ble_cus.h"
#include <string.h>
#include "nrf_gpio.h"
#include "boards.h"
#include "nrf_log.h"


uint32_t ble_cus_init(ble_cus_t * p_cus, const ble_cus_init_t * p_cus_init)
{
    if (p_cus == NULL || p_cus_init == NULL)
    {
        return NRF_ERROR_NULL;
    };

    uint32_t err_code; // can i make this uint32_t?
    ble_uuid_t ble_uuid; // uint32_t

    // initialize custom service structure
    p_cus->conn_handle = BLE_CONN_HANDLE_INVALID;

    // add out curstom (a.k.a vendor specific) base uuid to ble stack table
    ble_uuid128_t base_uuid = {CUSTOM_SERVICE_UUID_BASE};
    err_code = sd_ble_uuid_vs_add(&base_uuid, &p_cus->uuid_type);
    
    VERIFY_SUCCESS(err_code); // this is a macro! 
    /* in sdk_macros.h
    #define VERIFY_SUCCESS(statement)                       \
    do                                                      \
    {                                                       \
        uint32_t _err_code = (uint32_t) (statement);        \
        if (_err_code != NRF_SUCCESS)                       \
        {                                                   \
            return _err_code;                               \
        }                                                   \
    } while(0)
    */
    
    ble_uuid.type = p_cus->uuid_type;
    ble_uuid.uuid = CUSTOM_SERVICE_UUID;

    // add custom service declaration to BLE stack's GATT table
    // sd_ble_gatts_service_add(uint8_t type, ble_uuid_t const *p_uuid, uint16_t *p_handle);
    // BLE_GATT_SRVC_TYPE_PRIMARY = 0x01
    err_code = sd_ble_gatts_service_add(BLE_GATTS_SRVC_TYPE_PRIMARY, &ble_uuid, &p_cus->conn_handle);
    if (err_code != NRF_SUCCESS)
    {
        return err_code;
    }


}