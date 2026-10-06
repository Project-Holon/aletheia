/*
 * function: func_021A3208
 * address:  0x021A3208
 * packet:   pkt_ov021_021A3208
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3098  0x021A3098  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
u32 func_021A3098(u8 *p);

int func_021A3208(u8 *a)
{
    switch (func_021A3098(a)) {
    case 2:
    case 3:
        return 0;
    }
    return 1;
}
