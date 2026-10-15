/*
 * function: DWC_Auth_Join
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

extern int OS_IsThreadTerminated(void *thread);
extern void OS_JoinThread(void *thread);

void DWC_Auth_Join(void)
{
	if (gDwcAuthGlobal.ctx->started == 0)
		return;
	if (OS_IsThreadTerminated(gDwcAuthGlobal.ctx->thread) != 0)
		return;
	OS_JoinThread(gDwcAuthGlobal.ctx->thread);
}
