/*
 * function: NWM_End
 * address:  0x02702A98
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NWMi_CheckState  0x027028E4  arm twl
 *   OS_DisableInterrupts  0x02087988  arm twl
 *   NWMi_ClearFifoRecvFlag  0x027026EC  arm twl
 *   func_020885A0  0x020885A0  arm twl
 *   OS_RestoreInterrupts  0x0208799C  arm twl
 *   DAT_027341a4   0x027341a4  data twl
 *   DAT_027341a0   0x027341a0  data twl
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 NWMi_CheckState(u32, ...);
extern u32 OS_DisableInterrupts(void);
extern void NWMi_ClearFifoRecvFlag(void);
extern void func_020885A0(u32, u32);
extern void OS_RestoreInterrupts(u32);
extern u32 DAT_027341a4[];
extern u8 DAT_027341a0[];

u32 NWM_End(void) {
    u32 st = NWMi_CheckState(1, 1);
    u32 irq;
    if (st != 0 && st != 2) {
        return st;
    }
    irq = OS_DisableInterrupts();
    *(u16 *)(*(u32 *)(DAT_027341a4[0] + 0x2278) + 0x24) = 0;
    NWMi_ClearFifoRecvFlag();
    func_020885A0(0x16, 0);
    DAT_027341a4[0] = 0;
    DAT_027341a0[0] = 0;
    OS_RestoreInterrupts(irq);
    return 0;
}
