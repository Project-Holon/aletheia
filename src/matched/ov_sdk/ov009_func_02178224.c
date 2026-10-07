/*
 * function: func_02178224
 * address:  0x02178224
 * packet:   pkt_ov009_02178224
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Auth_GetResult (libdwcauth.TWL.HYB.a(dwc_auth.o))
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02082D44  0x02082D44  arm
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

extern void func_02082BCC(void *dst, int data, unsigned long size);
extern void func_02082D44(void *src, void *dst, unsigned long size);

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
