/*
 * function: func_021BB3FC
 * address:  0x021BB3FC
 * packet:   pkt_ov091_021BB3FC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   d_021BEC74  0x021BEC74  data  ov091  a1
 *   d_021BEC75  0x021BEC75  data  ov091  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 d_021BEC74[];
extern u8 d_021BEC75[];

void func_021BB3FC(int unused, u8 *s, u8 *out)
{
    out[2] = d_021BEC74[s[4] * 2] << 3;
    out[0] = d_021BEC75[s[4] * 2] << 3;
    out[3] = (d_021BEC74[s[4] * 2] + 16) << 3;
    out[1] = (d_021BEC75[s[4] * 2] + 6) << 3;
}
