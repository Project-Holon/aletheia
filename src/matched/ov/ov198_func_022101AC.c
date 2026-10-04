/*
 * function: func_022101AC
 * address:  0x022101AC
 * packet:   pkt_022101AC
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

u32 func_022101AC(u32 a)
{
    if (func_02210C88((u8 *)a, 0) == 0) {
        return 0xb;
    }
    return 0x3;
}

