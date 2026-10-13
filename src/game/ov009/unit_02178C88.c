/*
 * file:     unit_02178C88.c
 * unit:     yes
 * function: func_02178C88, func_02178CE0, func_02178D14
 * address:  0x02178C88
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02177EC8  0x02177EC8  arm
 *   g_021A2424     0x021A2424  data
 *   g_021A244C     0x021A244C  data
 *   g_021A2470     0x021A2470  data
 *   g_021AB1A4     0x021AB1A4  data
 *   g_021AB208     0x021AB208  data
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02082D44  0x02082D44  arm
 *   func_020870D0  0x020870D0  arm
 *   func_02177EE8  0x02177EE8  arm  ov009
 *   g_021AB1C0     0x021AB1C0  data
 *   g_021AB1F4     0x021AB1F4  data
 */
#include "../../matched/include/G_DWCAuthState.h"
#include "../../matched/include/G_DWCAuthParam.h"

extern void func_02177EC8(int v);
extern void MI_CpuFill8(void *dst, int data, unsigned long size);
extern void func_02082D44(void *src, void *dst, unsigned long size);
extern unsigned long long func_020870D0(void);
extern int func_02177EE8(struct DWCAuthParam *param, void *http);
int func_02178C88(int auth_server);
void func_02178CE0(void);
int func_02178D14(unsigned short *ingamesn, char *gsbrcd, unsigned long long userid, void *(*allocator)(unsigned long, long), void (*deallocator)(unsigned long, void *, long));
extern char g_021A2424[];
extern char g_021A244C[];
extern char g_021A2470[];
extern struct DWCAuthState g_021AB1A4;
extern unsigned char g_021AB208[];
extern struct DWCAuthParam g_021AB1C0;
extern unsigned char g_021AB1F4[];


/*
 * sdk:      DWCi_Auth_InitInterface (libdwcauth.TWL.HYB.a(dwc_auth_interfa))
 */
int func_02178C88(int auth_server)
{
	switch (auth_server) {
	case 0:
		func_02177EC8((int)g_021A2424);
		break;
	case 2:
		func_02177EC8((int)g_021A244C);
		break;
	case 1:
		func_02177EC8((int)g_021A2470);
		break;
	default:
		return 0;
	}
	return 1;
}


/*
 * sdk:      DWCi_Auth_InitAdapterParam (libdwcauth.TWL.HYB.a(dwc_auth_interfa))
 */
void func_02178CE0(void)
{
	g_021AB1A4.s_finished = 0;
	g_021AB1A4.state = 0;
	g_021AB1A4.returnCode = 0;
	MI_CpuFill8(g_021AB208, 0, 0x1c50);
}


/*
 * sdk:      DWCi_Auth_StartAuthentication (libdwcauth.TWL.HYB.a(dwc_auth_interfa))
 */
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
