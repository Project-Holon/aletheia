/*
 * function: func_0216BBC4
 * address: 0x0216BBC4
 * packet: pkt_ov010_0216BBC4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * arithmetic: address and stride are unsigned 32-bit additions, preserving
 * the original MUL/ADD wrapping for every input bit pattern.
 * symbols:
 *   d_021723C2 0x021723C2 data a1
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern const u8 d_021723C2[];
int func_0216BBC4(int index)
{
    return *(const u8 *)((u32)d_021723C2 + (u32)index * 7u);
}
