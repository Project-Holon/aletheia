/*
 * function: func_0217F060
 * address: 0x0217F060
 * packet: pkt_ov019_0217F060
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021806AC 0x021806AC data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 d_021806AC[][4];
int func_0217F060(int i)
{
    if (i >= 27) return 0;
    return d_021806AC[i][0];
}
