#ifndef INC_APPL_FLASH_OPS_H_
#define INC_APPL_FLASH_OPS_H_

#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

/* External macros */

#define APPL_NB_OF_PAGE 3U
#define APPL_SHIFT_PAGE 4U

#define FLASH_KEY1               0x45670123U
#define FLASH_KEY2               0xCDEF89ABU

/* External objects */


/* External methods */

void drv_erase_flash();
void drv_write_flash(uint32_t fls_sector_address, uint32_t *fls_ota_data);
void drv_read_flash(uint32_t fls_sector_address, uint32_t *fls_data);
void drv_unlock_flash();
void drv_lock_flash();


#endif /* INC_APPL_FLASH_OPS_H_ */
