/*
 * function: func_06898DE0
 * address: 0x06898DE0
 * packet: pkt_ov095_06898DE0
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_06898E0C 0x06898E0C thumb ov095
 *   d_0689E7EC 0x0689E7EC data a4
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern int func_06898E0C(int);
extern const u32 d_0689E7EC[];
int func_06898DE0(int a, u32 b)
{
    int index;
    index = func_06898E0C(a);
    if (index < 14 && b < 2)
        return (u8)*(const u32 *)((u32)d_0689E7EC + b * 224 + index * 16);
    return 0;
}
