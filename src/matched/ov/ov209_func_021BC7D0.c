/*
 * function: func_021BC7D0
 * address: 0x021BC7D0
 * packet: pkt_ov209_021BC7D0
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: WINOUT reads/writes at 021BC7D4..021BC7F2; DISPCNT read/write at 021BC7F8..021BC802
 */
typedef unsigned short u16;
typedef unsigned int u32;
static inline void obj(int wnd, int effect)
{
    u32 tmp = (*(volatile u16 *)0x0400104A & ~0x3F00) | ((u32)wnd << 8);
    if (effect) tmp |= 0x2000;
    *(volatile u16 *)0x0400104A = (u16)tmp;
}
static inline void outside(int wnd, int effect)
{
    u32 tmp = (*(volatile u16 *)0x0400104A & ~0x3F) | (u32)wnd;
    if (effect) tmp |= 0x20;
    *(volatile u16 *)0x0400104A = (u16)tmp;
}
void func_021BC7D0(void)
{
    obj(27, 1);
    outside(31, 1);
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~0xE000) | 0x8000;
}
