/*! \file sys/uart.h
*/

#ifndef __SYS_UART_H__
#define __SYS_UART_H__

#include <ppu-lv2.h>

#ifdef __cplusplus
	extern "C" {
#endif

typedef struct vuart_params
{
	u64 rx_buf_size;
	u64 tx_buf_size;
} vuart_params_t;

/*! \brief Requires root permissions */
LV2_SYSCALL sysUartInitialize()
{
	lv2syscall0(367);
	return_to_user_prog(s32);
}

/*! \brief Requires root permissions */
LV2_SYSCALL sysUartReceive(void *buffer,u64 size,u32 mode)
{
	lv2syscall3(368,(u64)buffer,size,mode);
	return_to_user_prog(s32);
}

/*! \brief Requires root permissions */
LV2_SYSCALL sysUartSend(const void *buffer,u64 size,u32 mode)
{
	lv2syscall3(369,(u64)buffer,size,mode);
	return_to_user_prog(s32);
}

/*! \brief Requires root permissions */
LV2_SYSCALL sysUartGetParams(vuart_params_t *buffer)
{
	lv2syscall1(370, buffer);
	return_to_user_prog(s32);
}

#ifdef __cplusplus
	}
#endif

#endif
