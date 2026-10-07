/*
 * function: func_02178D14
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
 *   func_02178CE0  0x02178CE0  arm  ov009
 *   func_02082D44  0x02082D44  arm
 *   func_020870D0  0x020870D0  arm
 *   func_02177EE8  0x02177EE8  arm  ov009
 *   g_021AB1C0     0x021AB1C0  data
 *   g_021AB1F4     0x021AB1F4  data
 *   g_021AB1A4     0x021AB1A4  data
 *   g_021AB208     0x021AB208  data
 */

#include "../include/G_DWCAuthState.h"
#include "../include/G_DWCAuthParam.h"

extern struct DWCAuthParam g_021AB1C0;
extern unsigned char g_021AB1F4[];
extern struct DWCAuthState g_021AB1A4;
extern unsigned char g_021AB208[];

extern void func_02178CE0(void);
extern void func_02082D44(void *src, void *dst, unsigned long size);
extern unsigned long long func_020870D0(void);
extern int func_02177EE8(struct DWCAuthParam *param, void *http);

int func_02178D14(unsigned short *ingamesn, char *gsbrcd, unsigned long long userid, void *(*allocator)(unsigned long, long), void (*deallocator)(unsigned long, void *, long))
{
	func_02178CE0();
	func_02082D44(ingamesn, &g_021AB1C0, 0x34);
	func_02082D44(gsbrcd, g_021AB1F4, 0xc);
	g_021AB1C0.allocator = allocator;
	g_021AB1C0.deallocator = deallocator;
	g_021AB1A4.tick = func_020870D0();
	g_021AB1A4.userid = userid;
	if (func_02177EE8(&g_021AB1C0, g_021AB208) == 0)
		return 1;
	return 0;
}
