/*
 * function: DSP_RecvFifoExCore
 * address:  0x02705150
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef volatile u16 vu16;

extern u32 func_02087988(void);
extern void func_0208799C(u32);

#define REG_DATA (*(vu16 *)0x04004300)
#define REG_CTRL (*(vu16 *)0x04004304)
#define REG_MODE (*(vu16 *)0x04004308)
#define REG_STAT (*(vu16 *)0x0400430C)

void DSP_RecvFifoExCore(u32 a, u16 *dst, u16 v, s32 n, u16 flags)
{
    u32 irq = func_02087988();
    u32 x = (u16)((flags & 1) ? 0 : 2);
    u32 sel;
    switch (flags & 0x300) {
    case 0x100: sel = 0; n = 1; break;
    case 0x200: sel = 4; n = 8; break;
    case 0x300: sel = 8; n = 16; break;
    default: sel = 12; break;
    }
    REG_CTRL = v;
    REG_MODE = (REG_MODE & ~0xF00E) | a | sel | x | 0x10;
    if (flags & 2) {
        while (n-- > 0) {
            while (!(REG_STAT & 0x40)) {
            }
            *dst = REG_DATA;
        }
    } else {
        while (n-- > 0) {
            while (!(REG_STAT & 0x40)) {
            }
            *dst++ = REG_DATA;
        }
    }
    REG_MODE &= 0xFFEF;
    func_0208799C(irq);
}
