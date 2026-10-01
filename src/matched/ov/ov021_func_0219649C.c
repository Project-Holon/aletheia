/*
 * function: func_0219649C
 * address:  0x0219649C
 * packet:   pkt_ov021_0219649C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Cb { u32 x0; int (*fn)(void *, struct Cb *); } Cb;

void func_0219649C(void *a, int b, Cb *c)
{
    if (b == 0 && c->fn != 0 && c->fn(a, c) != 0) {
        return;
    }
}
