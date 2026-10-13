/*
 * function: NitroMain
 * address:  0x02005124
 * packet:   pkt_02005124
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The game's main(): reached only through crt0's pool word 0x02005125 at
 * 0x020049F8, so the listing carried it as raw words until the seed in
 * layout/function_starts.txt.  Init, IRQ setup, then the frame loop.
 * The main-memory priority toggles are the SDK inline
 * MI_SetMainMemoryPriority (0 = ARM9, 1 = ARM7); open-coding the and/or
 * costs 123 B because the 0x8000 constant is then rebuilt from the mask
 * instead of from the IME address (0x04000208 >> 11).
 *
 * symbols:
 *   GFL_USE_InitSdk          0x02005328  thumb
 *   GFL_USE_InitSystem           0x0200545C  thumb
 *   OS_SetIrqFunction      0x02084774  arm
 *   OS_EnableIrqMask       0x02084968  arm
 *   GX_HBlankIntr          0x0207D3AC  arm
 *   GX_VBlankIntr          0x0207D3E4  arm
 *   OS_EnableInterrupts    0x02087974  arm
 *   GFL_USE_InitGameSystems          0x0200523C  thumb
 *   GFL_USE_PollPowerExit          0x020053EC  thumb
 *   GFL_USE_PollFrameInput          0x020055F8  thumb
 *   GFL_USE_UpdateFrameSubsystems          0x020052EC  thumb
 *   GFL_USE_NoOpFrameHook          0x0200560C  thumb
 *   G3D_SYSTEM_SwapBuffersMain          0x02047990  arm
 *   GFL_USE_IsNetQuiet          0x020051D8  thumb
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_SleepThreadDirect   0x02085760  arm
 *   OS_WaitIrq             0x0208459C  arm
 *   GFL_USE_PostIrqUpdate          0x02005230  thumb
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   GFL_USE_HBlankHandler          0x02005204  thumb
 *   GFL_USE_VBlankHandler          0x0200520C  thumb
 *   _WorkerThread             0x020AA354  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            BOOL;

#define reg_EXMEMCNT (*(volatile u16 *)0x04000204)
#define reg_IME      (*(volatile u16 *)0x04000208)

struct OSThread;

extern void GFL_USE_InitSdk(void);
extern void GFL_USE_InitSystem(void);
extern void OS_SetIrqFunction(u32 mask, void (*fn)(void));
extern u32  OS_EnableIrqMask(u32 mask);
extern void GX_HBlankIntr(BOOL enable);
extern void GX_VBlankIntr(BOOL enable);
extern u32  OS_EnableInterrupts(void);
extern void GFL_USE_InitGameSystems(void);
extern void GFL_USE_PollPowerExit(void);
extern void GFL_USE_PollFrameInput(void);
extern void GFL_USE_UpdateFrameSubsystems(void);
extern void GFL_USE_NoOpFrameHook(void);
extern void G3D_SYSTEM_SwapBuffersMain(void);
extern BOOL GFL_USE_IsNetQuiet(void);
extern BOOL OS_IsThreadTerminated(struct OSThread *thread);
extern void OS_SleepThreadDirect(struct OSThread *thread, void *queue);
extern void OS_WaitIrq(BOOL clear, u32 mask);
extern void GFL_USE_PostIrqUpdate(void);
extern void OS_WakeupThreadDirect(struct OSThread *thread);
extern void GFL_USE_HBlankHandler(void);
extern void GFL_USE_VBlankHandler(void);
extern struct OSThread _WorkerThread;

static inline u16 OS_EnableIrq(void)
{
    u16 prep = reg_IME;
    reg_IME = 1;
    return prep;
}

static inline void MI_SetMainMemoryPriority(u32 proc)
{
    reg_EXMEMCNT = (u16)((reg_EXMEMCNT & ~0x8000) | (proc << 15));
}

void NitroMain(void)
{
    BOOL busy;

    GFL_USE_InitSdk();
    GFL_USE_InitSystem();
    OS_SetIrqFunction(2, GFL_USE_HBlankHandler);
    OS_SetIrqFunction(1, GFL_USE_VBlankHandler);
    (void)OS_EnableIrqMask(3);
    (void)OS_EnableIrq();
    GX_HBlankIntr(1);
    GX_VBlankIntr(1);
    (void)OS_EnableInterrupts();
    GFL_USE_InitGameSystems();
    for (;;) {
        GFL_USE_PollPowerExit();
        GFL_USE_PollFrameInput();
        GFL_USE_UpdateFrameSubsystems();
        GFL_USE_NoOpFrameHook();
        G3D_SYSTEM_SwapBuffersMain();
        busy = GFL_USE_IsNetQuiet();
        if (busy)
            MI_SetMainMemoryPriority(0);
        if (!OS_IsThreadTerminated(&_WorkerThread))
            OS_SleepThreadDirect(&_WorkerThread, 0);
        OS_WaitIrq(1, 1);
        GFL_USE_PostIrqUpdate();
        if (!OS_IsThreadTerminated(&_WorkerThread))
            OS_WakeupThreadDirect(&_WorkerThread);
        if (busy)
            MI_SetMainMemoryPriority(1);
    }
}
