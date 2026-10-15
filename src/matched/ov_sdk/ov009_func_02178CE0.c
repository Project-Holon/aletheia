/*
 * function: DWCi_Auth_InitAdapterParam
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
 *   gDwcAuthState     0x021AB1A4  data
 *   gDwcAuthResultBuf     0x021AB208  data
 *   MI_CpuFill8  0x02082BCC  arm
 */

#include "../include/G_DWCAuthState.h"

extern struct DWCAuthState gDwcAuthState;
extern unsigned char gDwcAuthResultBuf[];
extern void MI_CpuFill8(void *dst, int data, unsigned long size);

void DWCi_Auth_InitAdapterParam(void)
{
	gDwcAuthState.s_finished = 0;
	gDwcAuthState.state = 0;
	gDwcAuthState.returnCode = 0;
	MI_CpuFill8(gDwcAuthResultBuf, 0, 0x1c50);
}
