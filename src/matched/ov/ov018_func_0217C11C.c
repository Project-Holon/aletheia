/*
 * function: func_0217C11C
 * address: 0x0217C11C
 * packet: pkt_ov018_0217C11C
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: index declared before count preserves r3/r4 allocation.
 * symbols:
 *   d_021700A4 0x021700A4 data a4
 *   d_02170128 0x02170128 data a2
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern const u32 d_021700A4;
extern const u16 d_02170128[];
int func_0217C11C(u32 value)
{
    u32 i;
    u32 count;
    count = d_021700A4;
    for (i = 0; i < count; ++i) {
        if (value == d_02170128[i])
            return 1;
    }
    return 0;
}
