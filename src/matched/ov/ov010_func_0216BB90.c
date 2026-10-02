/*
 * function: func_0216BB90
 * address: 0x0216BB90
 * packet: pkt_ov010_0216BB90
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * arithmetic: unsigned 32-bit address/stride arithmetic preserves original
 * MUL/ADD wrapping; each byte load remains ordered before its output store.
 * symbols:
 *   d_021723BE 0x021723BE data a1
 *   d_021723BF 0x021723BF data a1
 *   d_021723C0 0x021723C0 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 d_021723BE[], d_021723BF[], d_021723C0[];
void func_0216BB90(int index, u8 *out)
{
    out[0] = *(const u8 *)((u32)d_021723BE + (u32)index * 7u);
    out[1] = *(const u8 *)((u32)d_021723BF + (u32)index * 7u);
    out[2] = *(const u8 *)((u32)d_021723C0 + (u32)index * 7u);
}
