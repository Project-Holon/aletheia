/*
 * file:     unit_02177ED8_p02.c
 * unit:     yes
 * function: func_02177FFC, func_021780A8, func_02178144, func_02178194, func_021781DC, func_02178224
 * address:  0x02177FFC
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
 *   func_02086004  0x02086004  arm
 *   func_0208574C  0x0208574C  arm
 *   func_020853C0  0x020853C0  arm
 *   func_02085868  0x02085868  arm
 *   func_021783BC  0x021783BC  arm  ov009
 *   g_021AB184     0x021AB184  data
 *   g_021AB188     0x021AB188  data
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   func_021797D4  0x021797D4  arm  ov009
 *   func_02085710  0x02085710  arm
 *   func_02179CF4  0x02179CF4  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02082D44  0x02082D44  arm
 */
#include "../../matched/include/G_DWCAuthGlobal.h"
#include "../../matched/include/G_DWCAuthGlobal.h"

struct DWCAuthCtx {
	unsigned char pad0[0x1004];
	int error;
	unsigned char result[0x1c4];
	unsigned char pad1[0x44];
	void (*free_fn)(unsigned long, void *, long);
	unsigned char pad2[0x100];
	void *http;
	unsigned char thread[0x6c];
	int started;
	unsigned char pad3[0x50];
	unsigned char mutex[0x18];
	int abort_flag;
};

extern void func_02086004(void *mutex);
extern int func_0208574C(void *thread);
extern void func_020853C0(void *thread, void (*func)(void *), void *arg, void *stack, unsigned long stack_size, unsigned long prio);
extern void func_02085868(void *thread);
extern void func_021783BC(void);
extern void func_02086028(void *mutex);
extern void func_02086078(void *mutex);
extern void func_021797D4(void *http);
extern void func_02085710(void *thread);
extern void func_02179CF4(char *http);
extern void func_02082BCC(void *dst, int data, unsigned long size);
extern void func_02082D44(void *src, void *dst, unsigned long size);
void func_02177FFC(void);
/* * sdk: DWC_Auth_Abort (libdwcauth.TWL.HYB.a(dwc_auth.o)) */ void func_021780A8(void);
/* * sdk: DWC_Auth_Destroy (libdwcauth.TWL.HYB.a(dwc_auth.o)) */ void func_02178144(void);
/* * sdk: DWC_Auth_Join (libdwcauth.TWL.HYB.a(dwc_auth.o)) */ void func_02178194(void);
/* * sdk: DWC_Auth_GetError (libdwcauth.TWL.HYB.a(dwc_auth.o)) */ int func_021781DC(void);
void func_02178224(int *result);
extern struct DWCAuthGlobal g_021AB184;
extern struct DWCAuthCtx *g_021AB188;



/*
 * sdk:      DWCi_Auth_StartThread (libdwcauth.TWL.HYB.a(dwc_auth.o))
 */
void func_02177FFC(void)
{
	func_02086004(&g_021AB184.ctx->mutex);
	g_021AB184.ctx->abort_flag = 0;
	if (g_021AB184.ctx->started != 0) {
		if (func_0208574C(g_021AB184.ctx->thread) == 0)
			return;
	}
	func_020853C0(g_021AB184.ctx->thread, (void (*)(void *))func_021783BC, &g_021AB188, (unsigned char *)g_021AB184.ctx + 0x1000, 0x1000, 0x10);
	func_02085868(g_021AB184.ctx->thread);
}




/*
 * sdk:      DWC_Auth_Abort (libdwcauth.TWL.HYB.a(dwc_auth.o))
 */
void func_021780A8(void)
{
	if (g_021AB184.ctx == 0)
		return;
	func_02086028(&g_021AB184.ctx->mutex);
	g_021AB184.ctx->abort_flag = 1;
	func_02086078(&g_021AB184.ctx->mutex);
	if (g_021AB184.ctx->http != 0)
		func_021797D4(g_021AB184.ctx->http);
	if (g_021AB184.ctx->started == 0)
		return;
	if (func_0208574C(g_021AB184.ctx->thread) != 0)
		return;
	func_02085710(g_021AB184.ctx->thread);
}




/*
 * sdk:      DWC_Auth_Destroy (libdwcauth.TWL.HYB.a(dwc_auth.o))
 */
void func_02178144(void)
{
	void (*free)(unsigned long, void *, long);

	if (g_021AB184.ctx == 0)
		return;
	free = g_021AB184.ctx->free_fn;
	if (g_021AB184.ctx->http != 0)
		func_02179CF4(g_021AB184.ctx->http);
	free(0, g_021AB184.ctx, 0);
	g_021AB184.ctx = 0;
}




/*
 * sdk:      DWC_Auth_Join (libdwcauth.TWL.HYB.a(dwc_auth.o))
 */
void func_02178194(void)
{
	if (g_021AB184.ctx->started == 0)
		return;
	if (func_0208574C(g_021AB184.ctx->thread) != 0)
		return;
	func_02085710(g_021AB184.ctx->thread);
}




/*
 * sdk:      DWC_Auth_GetError (libdwcauth.TWL.HYB.a(dwc_auth.o))
 */
int func_021781DC(void)
{
	int error;

	if (g_021AB184.ctx == 0)
		return 0x16;
	func_02086028(&g_021AB184.ctx->mutex);
	error = g_021AB184.ctx->error;
	func_02086078(&g_021AB184.ctx->mutex);
	return error;
}


/*
 * sdk:      DWC_Auth_GetResult (libdwcauth.TWL.HYB.a(dwc_auth.o))
 */
void func_02178224(int *result)
{
	if (g_021AB184.ctx == 0)
		func_02082BCC(result, 0, 0x1c4);
	func_02082D44(g_021AB184.ctx->result, result, 0x1c4);
	if (result[0] < 20000 || result[0] >= 30000)
		result[0] = 20998;
	if (result[0] >= 20100)
		result[0] = -result[0];
}
