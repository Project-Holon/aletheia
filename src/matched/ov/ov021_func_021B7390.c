/*
 * function: func_021B7390
 * address:  0x021B7390
 * packet:   pkt_ov021_021B7390
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D99D4     0x021D99D4  data  a2
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 d_021D99D4[];

int func_021B7390(u32 a, int b)
{
    u32 i;
    u16 k;

    k = (a << 8) | b;
    for (i = 0; i < 5; i++) {
        if (k == d_021D99D4[i]) {
            return 1;
        }
    }
    return 0;
}
