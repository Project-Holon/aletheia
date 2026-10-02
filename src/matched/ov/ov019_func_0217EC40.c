/*
 * function: func_0217EC40
 * address: 0x0217EC40
 * packet: pkt_ov019_0217EC40
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021805E4 0x021805E4 data a2
 */
typedef unsigned short u16;
extern const u16 d_021805E4[][2];
u16 func_0217EC40(int i, int j)
{
    return d_021805E4[i - 2][j];
}
