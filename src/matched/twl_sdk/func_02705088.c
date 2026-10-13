/*
 * function: DSP_SendFifoExCore
 * address:  0x02705088
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

void DSP_SendFifoExCore(u32 a, u16 v, u16 *src, s32 n, u16 flags)
{
    u32 irq = func_02087988();
    u32 x = (u16)((flags & 2) ? 0 : 2);
    REG_CTRL = v;
    REG_MODE = (REG_MODE & ~0xF002) | a | x;
    if (flags & 1) {
        while (n-- > 0) {
            while (REG_STAT & 0x80) {
            }
            REG_DATA = *src;
        }
    } else {
        while (n-- > 0) {
            while (REG_STAT & 0x80) {
            }
            REG_DATA = *src++;
        }
    }
    func_0208799C(irq);
}
