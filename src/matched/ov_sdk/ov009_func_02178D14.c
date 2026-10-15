/*
 * function: DWCi_Auth_StartAuthentication
 * address:  0x02178D14
 * packet:   pkt_ov009_02178D14
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Auth_StartAuthentication (libdwcauth.TWL.HYB.a(dwc_auth_interfa))
 *
 * symbols:
 *   DWCi_Auth_InitAdapterParam  0x02178CE0  arm  ov009
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_020870D0  0x020870D0  arm
 *   DWC_Auth_Create  0x02177EE8  arm  ov009
 *   gDwcAuthParam     0x021AB1C0  data
 *   gDwcAuthGsbrcdBuffer     0x021AB1F4  data
 *   gDwcAuthState     0x021AB1A4  data
 *   gDwcAuthResultBuf     0x021AB208  data
 */

#include "../include/G_DWCAuthState.h"
#include "../include/G_DWCAuthParam.h"

extern struct DWCAuthParam gDwcAuthParam;
extern unsigned char gDwcAuthGsbrcdBuffer[];
extern struct DWCAuthState gDwcAuthState;
extern unsigned char gDwcAuthResultBuf[];

extern void DWCi_Auth_InitAdapterParam(void);
extern void MI_CpuCopy8(void *src, void *dst, unsigned long size);
extern unsigned long long func_020870D0(void);
extern int DWC_Auth_Create(struct DWCAuthParam *param, void *http);

int DWCi_Auth_StartAuthentication(unsigned short *ingamesn, char *gsbrcd, unsigned long long userid, void *(*allocator)(unsigned long, long), void (*deallocator)(unsigned long, void *, long))
{
	DWCi_Auth_InitAdapterParam();
	MI_CpuCopy8(ingamesn, &gDwcAuthParam, 0x34);
	MI_CpuCopy8(gsbrcd, gDwcAuthGsbrcdBuffer, 0xc);
	gDwcAuthParam.allocator = allocator;
	gDwcAuthParam.deallocator = deallocator;
	gDwcAuthState.tick = func_020870D0();
	gDwcAuthState.userid = userid;
	if (DWC_Auth_Create(&gDwcAuthParam, gDwcAuthResultBuf) == 0)
		return 1;
	return 0;
}
