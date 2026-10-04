/*
 * function: func_021BD340
 * address:  0x021BD340
 * packet:   pkt_021BD340
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_021BD2D8  0x021BD2D8  thumb  ov021
 *   func_021BD36C  0x021BD36C  thumb  ov021
 *   func_021BD394  0x021BD394  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021BD2D8(u32, u32, u32, u32);
extern int func_021BD36C(void *p);
extern int func_021BD394(void *p);

int func_021BD340(u32 a, u32 b, u32 c, u32 d)
{
if (func_021BD2D8(a, b, c, d) == 0) {
    return 1;
}
if (func_021BD36C((void *)a) != 0) {
    if (func_021BD394((void *)a) != 0) {
        return 1;
    }
}
return 0;
}

