/*
 * drv_flash_operations.c
 *
 *  Created on: May 19, 2026
 *      Author: Paul Rojas
 */

#include "drv_ll_flash.h"


void drv_erase_flash()
{
	/* Before each op r/w/e we need to UNLOCK the flash memory
	 * Enable the erase operation
	 * Number of sectors indicated in REG: SNB[3:0]: Sector number
	 * Trigger the erase op
	 * Wait until BUSY bit is cleared by HW
	 * Clear bits of enable erase op and number of sectors */
	__disable_irq();
	while((FLASH->SR & (1 << 16)));
	FLASH->CR |= (1 << 1);
	FLASH->CR |= (2 << 3);
	FLASH->CR |= (1 << 16);
	while((FLASH->SR & (1 << 16)));
	FLASH->CR &=~(1 << 1);
	FLASH->CR &= ~(1 << 3);
	__enable_irq();
}

void drv_write_flash(uint32_t fls_sector_address, uint32_t *fls_ota_data)
{
	/* Before each op r/w/e we need to UNLOCK the flash memory
		 * Wait until BUSY bit is cleared by HW
		 * Trigger the write operation
		 * Select data format to write
		 * Clear bits of enable erase op and number of sectors */

	uint32_t *ptr_to_flash = (uint32_t *)fls_sector_address;

	while(FLASH->SR & (1 << 16));
	FLASH->CR |= (1 << 0);
	FLASH->CR &=~(0x3 << 8);
	FLASH->CR |= (0x2 << 8);

	/* Move through sectors */
	for(int j = 0; j < APPL_NB_OF_PAGE; j++)
	{
		for(int i = 0; i < 4; i++)
		{
			ptr_to_flash[i]= fls_ota_data[i];
		}

		ptr_to_flash = ptr_to_flash + APPL_SHIFT_PAGE;
	}

	 while(FLASH->SR & FLASH_SR_BSY);

	FLASH->CR &=~(1 << 0);
}

void drv_read_flash(uint32_t fls_sector_address, uint32_t *fls_data)
{
	uint32_t *get_header = (uint32_t *)fls_sector_address;

	for(int i = 0; i < sizeof(fls_data); i++)
		fls_data[i] = *(get_header + i);
}

void drv_unlock_flash()
{
    if (FLASH->CR & FLASH_CR_LOCK)
    {
        FLASH->KEYR = FLASH_KEY1;
        FLASH->KEYR = FLASH_KEY2;
    }
}

void drv_lock_flash()
{
    FLASH->CR |= FLASH_CR_LOCK;
}
