/*
 * function: func_021A23D4
 * address:  0x021A23D4
 * packet:   pkt_ov021_021A23D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A0354  0x021A0354  thumb  ov021
 */

typedef unsigned char  u8;
u8 func_021A0354(u8 *p);

int func_021A23D4(int *p)
{
    if (func_021A0354((u8 *)p[4]) == 1) {
        return 1;
    }
    return 0;
}
