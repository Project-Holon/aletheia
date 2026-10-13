/*
 * file:     nwm_end.c
 * unit:     yes
 * function: NWM_End
 * address:  0x02702A98
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_end.o
 *
 * symbols:
 *   NWMi_ClearFifoRecvFlag  0x027026EC  arm
 *   NWMi_CheckState  0x027028E4  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 NWMi_CheckState(u32, ...);
extern u32 func_02087988(void);
extern void NWMi_ClearFifoRecvFlag(void);
extern void func_020885A0(u32, u32);
extern void func_0208799C(u32);
extern u32 DAT_027341a4[];
extern u8 DAT_027341a0[];

u32 NWM_End(void) {
    u32 st = NWMi_CheckState(1, 1);
    u32 irq;
    if (st != 0 && st != 2) {
        return st;
    }
    irq = func_02087988();
    *(u16 *)(*(u32 *)(DAT_027341a4[0] + 0x2278) + 0x24) = 0;
    NWMi_ClearFifoRecvFlag();
    func_020885A0(0x16, 0);
    DAT_027341a4[0] = 0;
    DAT_027341a0[0] = 0;
    func_0208799C(irq);
    return 0;
}
