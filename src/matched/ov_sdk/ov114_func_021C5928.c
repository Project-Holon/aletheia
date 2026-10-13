/*
 * function: DWC_NdInitAsync
 * address:  0x021C5928
 * packet:   pkt_ov114_021C5928
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_NdInitAsync (libdwcnd.TWL.HYB.a(dwc_nd.o))
 *
 * symbols:
 *   func_02059F38  0x02059F38  arm
 *   func_02086004  0x02086004  arm
 *   func_02086028  0x02086028  arm
 *   DWCi_NdSetError  0x021C659C  arm  ov114
 *   OS_UnlockMutex 0x02086078  arm
 *   DWCi_NdAlloc  0x021C569C  arm  ov114
 *   MI_CpuFill8  0x02082BCC  arm
 *   strncpy        0x02094860  arm
 *   func_02167FA8  0x02167FA8  arm
 *   DWCi_NdFree  0x021C56B4  arm  ov114
 *   OS_CreateThread  0x020853C0  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   gDwcNdMutex     0x021D3B84  data
 *   gDwcNdState     0x021D3B68  data
 *   sDwcNdServiceLocatorPort     0x021CF370  data
 *   DWCi_SVLTokenWaitThread  0x021C5724  arm  ov114
 */

#include "../include/G_NdState.h"

typedef struct NdParam {
    char gamecd[0x20];
    char passwd[0x20];
    int f40;
    unsigned char svl[0x1b8 - 0x44];
    unsigned char stack[0x800];
    unsigned char thread[0xa78 - 0x9b8];
} NdParam;

typedef struct NdState NdState;

extern int func_02059F38(void);
extern void func_02086004(void *mutex);
extern void func_02086028(void *mutex);
extern void DWCi_NdSetError(int err, int servererror);
extern void OS_UnlockMutex(void *mutex);
extern void *DWCi_NdAlloc(int a, int b);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern char *strncpy(char *dst, const char *src, unsigned long n);
extern int func_02167FA8(char *svl, void *result);
extern void DWCi_NdFree(int a);
extern void OS_CreateThread(void *thread, void (*func)(void *), void *arg, void *stack,
                          unsigned long stackSize, unsigned long prio);
extern void OS_WakeupThreadDirect(void *thread);
extern void DWCi_SVLTokenWaitThread(void);

extern struct NdState gDwcNdState;
extern char gDwcNdMutex[];
extern char sDwcNdServiceLocatorPort[];

int DWC_NdInitAsync(void (*callback)(int, int, int), char *gamecd, char *passwd)
{
    if (func_02059F38())
        return 0;
    func_02086004(gDwcNdMutex);
    func_02086028(gDwcNdMutex);
    if (gDwcNdState.f14 != 0) {
        DWCi_NdSetError(2, 0);
        OS_UnlockMutex(gDwcNdMutex);
        return 0;
    }
    gDwcNdState.f14 = 2;
    OS_UnlockMutex(gDwcNdMutex);
    gDwcNdState.f10 = 0;
    gDwcNdState.fC = 0;
    gDwcNdState.f8 = 0;
    gDwcNdState.cb = callback;
    gDwcNdState.f4 = 0;
    gDwcNdState.svl = DWCi_NdAlloc(sizeof(NdParam), 0x20);
    if (gDwcNdState.svl == 0) {
        DWCi_NdSetError(1, 0);
        return 0;
    }
    MI_CpuFill8(gDwcNdState.svl, 0, sizeof(NdParam));
    ((NdParam *)gDwcNdState.svl)->f40 = 0;
    strncpy(((NdParam *)gDwcNdState.svl)->gamecd, gamecd, 31);
    strncpy(((NdParam *)gDwcNdState.svl)->passwd, passwd, 31);
    if (func_02167FA8(sDwcNdServiceLocatorPort, ((NdParam *)gDwcNdState.svl)->svl) == 0) {
        DWCi_NdFree((int)gDwcNdState.svl);
        gDwcNdState.svl = 0;
        return 0;
    }
    OS_CreateThread(((NdParam *)gDwcNdState.svl)->thread, (void (*)(void *))DWCi_SVLTokenWaitThread, 0,
                  ((NdParam *)gDwcNdState.svl)->stack + sizeof(((NdParam *)gDwcNdState.svl)->stack), 0x800, 0x10);
    OS_WakeupThreadDirect(((NdParam *)gDwcNdState.svl)->thread);
    return 1;
}
