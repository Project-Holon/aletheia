/*
 * function: func_0216BB70
 * address: 0x0216BB70
 * packet: pkt_ov010_0216BB70
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * arithmetic: address and stride are unsigned 32-bit additions, preserving
 * the original MUL/ADD wrapping for every input bit pattern.
 * symbols:
 *   d_021723BC 0x021723BC data a1
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern const u8 d_021723BC[];
int func_0216BB70(int index)
{
    return *(const u8 *)((u32)d_021723BC + (u32)index * 7u);
}
