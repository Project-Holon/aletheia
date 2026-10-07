/*
 * file:     unit_0217A880_p02.c
 * unit:     yes
 * function: func_0217AADC, func_0217AAF4
 * address:  0x0217AADC
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
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_CreateThread        0x020853C0  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   func_0217AB78          0x0217AB78  arm  ov009
 *   g_021ACE5C             0x021ACE5C  data
 */
#include "../../matched/include/G_G.h"

typedef struct {
    void *http;
    char *nc;
} G;

extern int OS_IsThreadTerminated(void *thread);
extern void OS_CreateThread(void *thread, void (*func)(void *), void *arg, void *stack, unsigned long size, unsigned long prio);
extern void OS_WakeupThreadDirect(void *thread);
extern void func_0217AB78(void *arg);
asm void DWC_Netcheck_GetReturnCode(void);
void func_0217AAF4(void);
extern struct G g_021ACE5C;

asm void DWC_Netcheck_GetReturnCode(void)
{
	ldr r0, =0x021ACE5C
	ldr r0, [r0, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #4]
	bx lr
}


/*
 * sdk:      DWCi_Netcheck_StartThread (dwc_netcheck.o)
 */
void func_0217AAF4(void)
{
    if (*(int *)(g_021ACE5C.nc + 0x1188) != 0 &&
        !OS_IsThreadTerminated(g_021ACE5C.nc + 0x111c)) {
        return;
    }
    OS_CreateThread(g_021ACE5C.nc + 0x111c, func_0217AB78, g_021ACE5C.nc,
                    g_021ACE5C.nc + 0x1000, 0x1000, 16);
    OS_WakeupThreadDirect(g_021ACE5C.nc + 0x111c);
}
