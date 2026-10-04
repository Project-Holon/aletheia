/*
 * function: func_022101E8
 * address:  0x022101E8
 * packet:   pkt_022101E8
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02210C88  0x02210C88  thumb  ov198
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_02210C88(u8 *p, unsigned mode);

u32 func_022101E8(u32 a)
{
    if (func_02210C88((u8 *)a, 3) == 0) {
        return 0xe;
    }
    return 0x6;
}

