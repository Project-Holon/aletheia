/*
 * function: func_0215E3E4
 * address: 0x0215E3E4
 * packet: pkt_ov010_0215E3E4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200D478 0x0200D478 thumb
 *   d_021711C6 0x021711C6 data a2
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_0200D478(void *, u32);
extern const u16 d_021711C6[];
u32 func_0215E3E4(void *p, u32 slot)
{
    u32 i = func_0200D478(p, slot);
    if (i > 16) return 319;
    return d_021711C6[i];
}
