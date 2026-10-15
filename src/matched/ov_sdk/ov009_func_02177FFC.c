/*
 * function: DWCi_Auth_StartThread
 * address:  0x02177FFC
 * packet:   pkt_ov009_02177FFC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Auth_StartThread (libdwcauth.TWL.HYB.a(dwc_auth.o))
 *
 * symbols:
 *   OS_InitMutex  0x02086004  arm
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_CreateThread  0x020853C0  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   DWCi_Auth_Thread  0x021783BC  arm  ov009
 *   gDwcAuthGlobal     0x021AB184  data
 *   gDwcAuth     0x021AB188  data
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
extern struct DWCAuthCtx *gDwcAuth;

extern void OS_InitMutex(void *mutex);
extern int OS_IsThreadTerminated(void *thread);
extern void OS_CreateThread(void *thread, void (*func)(void *), void *arg, void *stack, unsigned long stack_size, unsigned long prio);
extern void OS_WakeupThreadDirect(void *thread);
extern void DWCi_Auth_Thread(void);

void DWCi_Auth_StartThread(void)
{
	OS_InitMutex(&gDwcAuthGlobal.ctx->mutex);
	gDwcAuthGlobal.ctx->abort_flag = 0;
	if (gDwcAuthGlobal.ctx->started != 0) {
		if (OS_IsThreadTerminated(gDwcAuthGlobal.ctx->thread) == 0)
			return;
	}
	OS_CreateThread(gDwcAuthGlobal.ctx->thread, (void (*)(void *))DWCi_Auth_Thread, &gDwcAuth, (unsigned char *)gDwcAuthGlobal.ctx + 0x1000, 0x1000, 0x10);
	OS_WakeupThreadDirect(gDwcAuthGlobal.ctx->thread);
}
