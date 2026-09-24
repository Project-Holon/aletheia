/*
 * function: func_021C2D0C
 * address:  0x021C2D0C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 1 when the ARM9 predicate is zero.
 *
 * symbols:
 *   func_020889C0  0x020889C0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_020889C0(void);

int func_021C2D0C(void)
{
    if (func_020889C0() == 0) {
        return 1;
    }
    return 0;
}
