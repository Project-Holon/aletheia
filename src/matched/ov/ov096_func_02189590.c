/*
 * function: func_02189590
 * address: 0x02189590
 * packet: pkt_ov096_02189590
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_020113B0 0x020113B0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201134C(u8 *);
extern void func_020113B0(u8 *, u32);
int func_02189590(u8 *a, u8 *b)
{
    u32 t; t = func_0201134C(a); func_020113B0(a, *(u32 *)(a + 0x14) + t); return *(int *)(b + 0xc4);
}
