/*
 * function: func_02210F04
 * address:  0x02210F04
 * packet:   pkt_02210F04
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02210EFC  0x02210EFC  thumb  ov198
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_02210EFC(char **p);

u32 func_02210F04(u32 a, u32 b)
{
    if (func_02210EFC((char **)a) == 1 && b >= 3) {
        return 1;
    }
    return 0;
}

