/*
 * file:     unit_02177ED8_p01.c
 * unit:     yes
 * function: func_021780A8, func_02178144, func_02178194, func_021781DC
 * address:  0x021780A8
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
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   func_021797D4  0x021797D4  arm  ov009
 *   func_0208574C  0x0208574C  arm
 *   func_02085710  0x02085710  arm
 *   g_021AB184     0x021AB184  data
 *   func_02179CF4  0x02179CF4  arm
 */
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

extern void func_02086028(void *mutex);
extern void func_02086078(void *mutex);
extern void func_021797D4(void *http);
extern int func_0208574C(void *thread);
extern void func_02085710(void *thread);
extern void func_02179CF4(char *http);
void func_021780A8(void);
void func_02178144(void);
void func_02178194(void);
int func_021781DC(void);
extern struct DWCAuthGlobal g_021AB184;


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
