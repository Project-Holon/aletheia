/*
 * function: func_02211A10
 * address:  0x02211A10
 * packet:   pkt_02211A10
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_0220AFDC  0x0220AFDC  thumb  ov198
 * blocker: codegen near miss (DIFF)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0220AFDC(u32);

u32 func_02211A10(u8 *p, u32 v)
{
    u32 i = 0x218c;

    *(u32 *)(p + i) = v;
    return func_0220AFDC(*(u32 *)(p + i - 4));
}

