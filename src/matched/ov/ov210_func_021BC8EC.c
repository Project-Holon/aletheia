/*
 * function: func_021BC8EC
 * address: 0x021BC8EC
 * packet: pkt_ov210_021BC8EC
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021BC8F0/021BC900 read WINOUT; 021BC912 reads DISPCNT hardware registers.
 */
typedef unsigned short u16;
typedef unsigned int u32;
static inline void inside(int wnd,int effect)
{
    u32 tmp=(*(volatile u16 *)0x0400104a & ~0x3f00) | ((u32)wnd<<8);
    if (effect) tmp|=0x20<<8;
    *(volatile u16 *)0x0400104a=(u16)tmp;
}
static inline void outside(int wnd,int effect)
{
    u32 tmp=(*(volatile u16 *)0x0400104a & ~0x3f) | (u32)wnd;
    if (effect) tmp|=0x20;
    *(volatile u16 *)0x0400104a=(u16)tmp;
}
static inline void visible(int window)
{
    *(volatile u32 *)0x04001000=(*(volatile u32 *)0x04001000 & ~0xe000) | (window<<13);
}
void func_021BC8EC(void)
{
    inside(29,1);
    outside(31,1);
    visible(4);
}
