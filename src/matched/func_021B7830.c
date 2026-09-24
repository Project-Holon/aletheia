/*
 * function: func_021B7830
 * address:  0x021B7830
 * packet:   pkt_021B6A00
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Scaled offset: func_021B785C's value times a2 when the state probe passes and a2 is non-zero.
 *
 * symbols:
 *   func_021B785C  0x021B785C  thumb  ov172
 *   func_021BE05C  0x021BE05C  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 func_021B785C(void *p);
extern int func_021BE05C(void *p);

int func_021B7830(void *a0, char *a1, int a2)
{
    int n = (int)func_021B785C(a0);

    if (func_021BE05C(a0) == 1 && a2 != 0)
        return *(int *)(a1 + 4) + n;
    return *(int *)(a1 + 4) + n * a2;
}
