/*
 * function: DSP_ExecuteProcess
 * address:  0x02705C24
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DAT_027344AC   0x027344AC  data twl
 *   DSPi_ProcList  0x027344AC  data twl
 *   DSPi_MasterInterrupts  0x0270532C  arm
 *   DSPi_PreSleepCallback  0x02705320  arm
 *   DSPi_ShutdownCallback  0x027052FC  arm
 *   DSP_PowerOnCore  0x02704E90  arm
 *   DSP_PowerOffCore  0x02704EE8  arm
 *   DSP_ResetOnCore  0x02704F1C  arm
 *   DSP_ResetOffExCore  0x02704F4C  arm
 *   DSP_RecvDataCore  0x0270505C  arm
 *   DSP_MaskSemaphoreCore  0x027052A4  arm
 *   DSP_StopDSPComponent  0x027052B4  arm
 *   DSP_SetProcessHook  0x02705B70  arm
 *   DSP_HookPostStartProcess  0x02705C20  arm
 *   DSP_InitPipe  0x02706CD4  arm
 *   MI_FreeWram  0x02730B04  arm
 *   PMi_InsertPostExitCallbackEx  0x0273156C  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm  arm9
 *   FS_Init  0x0207AD04  arm  arm9
 *   OS_EnableIrqMask  0x02084968  arm  arm9
 *   OS_DisableIrqMask  0x02084998  arm  arm9
 *   OS_DisableInterrupts  0x02087988  arm  arm9
 *   OS_RestoreInterrupts  0x0208799C  arm  arm9
 *   STD_CompareString  0x0208CD94  arm  arm9
 *   FS_IsAvailable  0x0207AD30  arm  arm9
 *   PMi_InsertPreSleepCallbackEx  0x0208C848  arm  arm9
 *   PM_DeletePreSleepCallback  0x0208C86C  arm  arm9
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef volatile u16 vu16;
typedef struct DSPProc {
    struct DSPProc *next;
    char name[16];
    u32 f14;
    u32 pad18;
    u32 flags;
    u32 pad20[18];
    s32 mask;
} DSPProc;
typedef struct DspGlobals {
    DSPProc *head;
    u32 preInit;
    u32 thrInit;
    void (*thrFn)(void);
    u32 thrArg;
    u32 pad14[2];
    void (*preFn)(void);
    u32 preArg;
} DspGlobals;
extern DspGlobals DAT_027344AC;
extern DSPProc *DSPi_ProcList;
extern int FS_IsAvailable(void);
extern void FS_Init(u32 v);
extern void DSP_InitPipe(void);
extern void func_02084774(u32 mask, void (*fn)(void));
extern u32 OS_EnableIrqMask(u32 mask);
extern u32 OS_DisableIrqMask(u32 mask);
extern void DSPi_MasterInterrupts(void);
extern void DSPi_PreSleepCallback(void);
extern void DSPi_ShutdownCallback(void);
extern void DSP_StopDSPComponent(void);
extern void DSP_SetProcessHook(DSPProc *p, u32 a, u32 b, u32 c);
extern u32 DSP_MapAndLoadProcessImage(DSPProc *p, u32 a, u32 b, u32 c);
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 v);
extern int OS_IsRunOnTwl(void);
extern void PMi_InsertPostExitCallbackEx(void *p, u32 v);
extern void PMi_InsertPreSleepCallbackEx(void *p, u32 v);
extern void PM_DeletePreSleepCallback(void *p);
extern void DSP_PowerOnCore(void);
extern void DSP_ResetOffExCore(u32 v);
extern void DSP_MaskSemaphoreCore(u32 v);
extern void DSP_ResetOnCore(void);
extern void DSP_PowerOffCore(void);
extern u16 DSP_RecvDataCore(u32 ch);
extern void DSP_HookPostStartProcess(void);
extern void MI_FreeWram(u32 a, u32 b);
extern int STD_CompareString(const char *a, const char *b);

u32 DSP_ExecuteProcess(DSPProc *p, u32 a, u32 b, u32 c)
{
    u32 ret = 0;
    u32 irq;
    DSPProc **pp;
    u16 i;
    u16 en;
    u16 dis;
    vu16 v;
    if (FS_IsAvailable() == 0) {
        FS_Init(-1);
    }
    DSP_InitPipe();
    func_02084774(0x1000000, DSPi_MasterInterrupts);
    DSP_SetProcessHook(p, 0x48000, 0x027070DC, 0);
    OS_EnableIrqMask(0x1000000);
    if (DSP_MapAndLoadProcessImage(p, a, b, c) != 0) {
        irq = OS_DisableInterrupts();
        pp = &DSPi_ProcList;
        while (*pp != 0 && *pp != p) {
            pp = (DSPProc **)*pp;
        }
        *pp = p;
        p->f14 = 0;
        if (DAT_027344AC.thrInit == 0) {
            DAT_027344AC.thrFn = DSPi_ShutdownCallback;
            DAT_027344AC.thrArg = 0;
            PMi_InsertPostExitCallbackEx(&DAT_027344AC.thrFn, 0x3F2);
            DAT_027344AC.thrInit = 1;
        }
        if (DAT_027344AC.preInit == 0) {
            DAT_027344AC.preFn = DSPi_PreSleepCallback;
            DAT_027344AC.preArg = 0;
            PMi_InsertPreSleepCallbackEx(&DAT_027344AC.preFn, 0x3F2);
            DAT_027344AC.preInit = 1;
        }
        if (OS_IsRunOnTwl() == 1) {
            DSP_PowerOnCore();
        }
        en = (u16)(p->mask >> 16);
        if (OS_IsRunOnTwl() == 1) {
            DSP_ResetOffExCore(en);
        }
        dis = (u16)~p->mask;
        if (OS_IsRunOnTwl() == 1) {
            DSP_MaskSemaphoreCore(dis);
        }
        DSP_HookPostStartProcess();
        if (p->flags & 1) {
            for (i = 0; i < 3; i++) {
                do {
                    v = DSP_RecvDataCore(i);
                } while (v != 1);
            }
        }
        DSPi_MasterInterrupts();
        ret = 1;
        OS_RestoreInterrupts(irq);
    }
    return ret;
}
