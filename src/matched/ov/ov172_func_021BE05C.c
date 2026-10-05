/*
 * function: func_021BE05C
 * address:  0x021BE05C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * 1 for states 1 and 2, else 2.
 *
 * symbols:
 *   func_021BE054  0x021BE054  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u8 func_021BE054(void *p);

int func_021BE05C(void *p)
{
    u8 v = func_021BE054(p);
    if (v == 1) {
        return 1;
    }
    if (v == 2) {
        return 1;
    }
    return 2;
}
