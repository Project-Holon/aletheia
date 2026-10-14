/*
 * function: POKETRADE_SAVE_SetupWindowRegsSummary
 * address:  0x021E26AC
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D658  0x0207D658  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0207D658(u32 addr, int plane, int brightness);

void POKETRADE_SAVE_SetupWindowRegsSummary(void *a0)
{
    u32 v;

    func_0207D658(0x04001050, 0x1A, -8);

    v = (*(volatile u16 *)0x04001048 & ~0x3F) | 0x1F;
    *(volatile u16 *)0x04001048 = v | 0x20;
    *(volatile u16 *)0x04001040 = 0x00FF;
    *(volatile u16 *)0x04001044 = 0x00C0;
    v = (*(volatile u16 *)0x04001048 & ~0x3F00) | 0x1F00;
    *(volatile u16 *)0x04001048 = v | 0x2000;
    *(volatile u16 *)0x04001042 = 0xFF00;
    *(volatile u16 *)0x04001046 = 0x00C0;
    v = (*(volatile u16 *)0x0400104A & ~0x3F) | 0x1F;
    *(volatile u16 *)0x0400104A = v;
    *(volatile u32 *)0x04001000 =
        (*(volatile u32 *)0x04001000 & 0xFFFF1FFF) | 0x6000;
}
