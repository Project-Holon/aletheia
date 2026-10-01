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
 *   func_02005328          0x02005328  thumb
 *   sub_0200545C           0x0200545C  thumb
 *   OS_SetIrqFunction      0x02084774  arm
 *   OS_EnableIrqMask       0x02084968  arm
 *   GX_HBlankIntr          0x0207D3AC  arm
 *   GX_VBlankIntr          0x0207D3E4  arm
 *   OS_EnableInterrupts    0x02087974  arm
 *   func_0200523C          0x0200523C  thumb
 *   func_020053EC          0x020053EC  thumb
 *   func_020055F8          0x020055F8  thumb
 *   func_020052EC          0x020052EC  thumb
 *   sub_0200560C          0x0200560C  thumb
 *   func_02047990          0x02047990  arm
 *   func_020051D8          0x020051D8  thumb
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_SleepThreadDirect   0x02085760  arm
 *   OS_WaitIrq             0x0208459C  arm
 *   func_02005230          0x02005230  thumb
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   func_02005204          0x02005204  thumb
 *   func_0200520C          0x0200520C  thumb
 *   g_020AA354             0x020AA354  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            BOOL;

#define reg_EXMEMCNT (*(volatile u16 *)0x04000204)
#define reg_IME      (*(volatile u16 *)0x04000208)

struct OSThread;

extern void func_02005328(void);
extern void sub_0200545C(void);
extern void OS_SetIrqFunction(u32 mask, void (*fn)(void));
extern u32  OS_EnableIrqMask(u32 mask);
extern void GX_HBlankIntr(BOOL enable);
extern void GX_VBlankIntr(BOOL enable);
extern u32  OS_EnableInterrupts(void);
extern void func_0200523C(void);
extern void func_020053EC(void);
extern void func_020055F8(void);
extern void func_020052EC(void);
extern void sub_0200560C(void);
extern void func_02047990(void);
extern BOOL func_020051D8(void);
extern BOOL OS_IsThreadTerminated(struct OSThread *thread);
extern void OS_SleepThreadDirect(struct OSThread *thread, void *queue);
extern void OS_WaitIrq(BOOL clear, u32 mask);
extern void func_02005230(void);
extern void OS_WakeupThreadDirect(struct OSThread *thread);
extern void func_02005204(void);
extern void func_0200520C(void);
extern struct OSThread g_020AA354;

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

    func_02005328();
    sub_0200545C();
    OS_SetIrqFunction(2, func_02005204);
    OS_SetIrqFunction(1, func_0200520C);
    (void)OS_EnableIrqMask(3);
    (void)OS_EnableIrq();
    GX_HBlankIntr(1);
    GX_VBlankIntr(1);
    (void)OS_EnableInterrupts();
    func_0200523C();
    for (;;) {
        func_020053EC();
        func_020055F8();
        func_020052EC();
        sub_0200560C();
        func_02047990();
        busy = func_020051D8();
        if (busy)
            MI_SetMainMemoryPriority(0);
        if (!OS_IsThreadTerminated(&g_020AA354))
            OS_SleepThreadDirect(&g_020AA354, 0);
        OS_WaitIrq(1, 1);
        func_02005230();
        if (!OS_IsThreadTerminated(&g_020AA354))
            OS_WakeupThreadDirect(&g_020AA354);
        if (busy)
            MI_SetMainMemoryPriority(1);
    }
}
