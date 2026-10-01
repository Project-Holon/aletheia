/*
 * function: func_021D2D24
 * address:  0x021D2D24
 * packet:   pkt_ov021_021D2D24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DD738     0x021DD738  data  ov021  a4
 *   func_020056EC  0x020056EC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020056EC(u32 v);
extern u32 d_021DD738[];

u32 func_021D2D24(void *a, u32 v, int c)
{
    int i;

    if (c == 0) {
        for (i = 0; i < 0xf; i++) {
            if (v == d_021DD738[i]) {
                return func_020056EC(0x14) + 0x6e;
            }
        }
    }
    return v;
}
