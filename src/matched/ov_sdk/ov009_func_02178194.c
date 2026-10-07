/*
 * function: func_02178194
 * address:  0x02178194
 * packet:   pkt_ov009_02178194
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Auth_Join (libdwcauth.TWL.HYB.a(dwc_auth.o))
 *
 * symbols:
 *   func_0208574C  0x0208574C  arm
 *   func_02085710  0x02085710  arm
 *   g_021AB184     0x021AB184  data
 */

#include "../include/G_DWCAuthGlobal.h"

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

extern struct DWCAuthGlobal g_021AB184;

extern int func_0208574C(void *thread);
extern void func_02085710(void *thread);

void func_02178194(void)
{
	if (g_021AB184.ctx->started == 0)
		return;
	if (func_0208574C(g_021AB184.ctx->thread) != 0)
		return;
	func_02085710(g_021AB184.ctx->thread);
}
