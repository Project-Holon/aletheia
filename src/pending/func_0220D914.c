/*
 * function: func_0220D914
 * address:  0x0220D914
 * packet:   pkt_0220D914
 * region:   ov197
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 * blocker: +000C ABS32 func_02025D14          -> unresolved: 02025D14 (arm, from name) has no witness outside 0220D914..0220D924
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02025D14(u32);

u32 func_0220D914(u8 *p)
{
    return func_02025D14(*(u32 *)(p + 0x144));
}

