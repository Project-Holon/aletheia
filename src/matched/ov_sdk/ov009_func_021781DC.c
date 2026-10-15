/*
 * function: DWC_Auth_GetError
 * address:  0x021781DC
 * packet:   pkt_ov009_021781DC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Auth_GetError (libdwcauth.TWL.HYB.a(dwc_auth.o))
 *
 * symbols:
 *   OS_LockMutex  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   gDwcAuthGlobal     0x021AB184  data
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

extern struct DWCAuthGlobal gDwcAuthGlobal;

extern void OS_LockMutex(void *mutex);
extern void func_02086078(void *mutex);

int DWC_Auth_GetError(void)
{
	int error;

	if (gDwcAuthGlobal.ctx == 0)
		return 0x16;
	OS_LockMutex(&gDwcAuthGlobal.ctx->mutex);
	error = gDwcAuthGlobal.ctx->error;
	func_02086078(&gDwcAuthGlobal.ctx->mutex);
	return error;
}
