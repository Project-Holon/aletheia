/*
 * function: DSP_QuitProcess
 * address:  0x02705E04
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
 *   DSP_MapAndLoadProcessImage  0x02705ACC  arm
 *   DSP_SetProcessHook  0x02705B70  arm
 *   DSP_HookPostStartProcess  0x02705C20  arm
 *   DSP_InitPipe  0x02706CD4  arm
 *   MI_FreeWram  0x02730B04  arm
 *   PMi_InsertPostExitCallbackEx  0x0273156C  arm
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
extern int func_0207AD30(void);
extern void func_0207AD04(u32 v);
extern void DSP_InitPipe(void);
extern void func_02084774(u32 mask, void (*fn)(void));
extern u32 func_02084968(u32 mask);
extern u32 func_02084998(u32 mask);
extern void DSPi_MasterInterrupts(void);
extern void DSPi_PreSleepCallback(void);
extern void DSPi_ShutdownCallback(void);
extern void DSP_StopDSPComponent(void);
extern void DSP_SetProcessHook(DSPProc *p, u32 a, u32 b, u32 c);
extern u32 DSP_MapAndLoadProcessImage(DSPProc *p, u32 a, u32 b, u32 c);
extern u32 func_02087988(void);
extern void func_0208799C(u32 v);
extern int func_02085D3C(void);
extern void PMi_InsertPostExitCallbackEx(void *p, u32 v);
extern void func_0208C848(void *p, u32 v);
extern void func_0208C86C(void *p);
extern void DSP_PowerOnCore(void);
extern void DSP_ResetOffExCore(u32 v);
extern void DSP_MaskSemaphoreCore(u32 v);
extern void DSP_ResetOnCore(void);
extern void DSP_PowerOffCore(void);
extern u16 DSP_RecvDataCore(u32 ch);
extern void DSP_HookPostStartProcess(void);
extern void MI_FreeWram(u32 a, u32 b);
extern int func_0208CD94(const char *a, const char *b);

void DSP_QuitProcess(DSPProc *p)
{
    u32 irq;
    DSPProc *q;
    DSPProc **pp;
    DSP_StopDSPComponent();
    irq = func_02087988();
    if (func_02085D3C() == 1) {
        DSP_ResetOnCore();
    }
    if (func_02085D3C() == 1) {
        DSP_PowerOffCore();
    }
    func_02084998(0x1000000);
    func_02084774(0x1000000, 0);
    MI_FreeWram(1, 2);
    MI_FreeWram(2, 2);
    q = DAT_027344AC.head;
    pp = &DSPi_ProcList;
    while (q != 0) {
        if (q == p) {
            *pp = q->next;
            break;
        }
        pp = (DSPProc **)q;
        q = q->next;
    }
    p->next = 0;
    func_0208799C(irq);
    func_0208C86C(&DAT_027344AC.preFn);
    DAT_027344AC.preInit = 0;
}
