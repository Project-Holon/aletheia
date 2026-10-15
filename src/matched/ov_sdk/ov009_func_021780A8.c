/*
 * function: DWC_Auth_Abort
 * address:  0x021780A8
 * packet:   pkt_ov009_021780A8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Auth_Abort (libdwcauth.TWL.HYB.a(dwc_auth.o))
 *
 * symbols:
 *   OS_LockMutex  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   func_021797D4  0x021797D4  arm  ov009
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_JoinThread  0x02085710  arm
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
extern void func_021797D4(void *http);
extern int OS_IsThreadTerminated(void *thread);
extern void OS_JoinThread(void *thread);

void DWC_Auth_Abort(void)
{
	if (gDwcAuthGlobal.ctx == 0)
		return;
	OS_LockMutex(&gDwcAuthGlobal.ctx->mutex);
	gDwcAuthGlobal.ctx->abort_flag = 1;
	func_02086078(&gDwcAuthGlobal.ctx->mutex);
	if (gDwcAuthGlobal.ctx->http != 0)
		func_021797D4(gDwcAuthGlobal.ctx->http);
	if (gDwcAuthGlobal.ctx->started == 0)
		return;
	if (OS_IsThreadTerminated(gDwcAuthGlobal.ctx->thread) != 0)
		return;
	OS_JoinThread(gDwcAuthGlobal.ctx->thread);
}
