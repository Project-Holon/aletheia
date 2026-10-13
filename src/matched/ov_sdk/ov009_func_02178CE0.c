/*
 * function: func_02178CE0
 * address:  0x02178CE0
 * packet:   pkt_ov009_02178CE0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Auth_InitAdapterParam (libdwcauth.TWL.HYB.a(dwc_auth_interfa))
 *
 * symbols:
 *   g_021AB1A4     0x021AB1A4  data
 *   g_021AB208     0x021AB208  data
 *   MI_CpuFill8  0x02082BCC  arm
 */

#include "../include/G_DWCAuthState.h"

extern struct DWCAuthState g_021AB1A4;
extern unsigned char g_021AB208[];
extern void MI_CpuFill8(void *dst, int data, unsigned long size);

void func_02178CE0(void)
{
	g_021AB1A4.s_finished = 0;
	g_021AB1A4.state = 0;
	g_021AB1A4.returnCode = 0;
	MI_CpuFill8(g_021AB208, 0, 0x1c50);
}
