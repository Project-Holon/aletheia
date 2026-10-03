/*
 * function: func_0219390C
 * address:  0x0219390C
 * packet:   pkt_0219390C
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
 *   func_02193F34  0x02193F34  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct E50;
struct V;
extern struct E50 *func_02193F34(struct V *v, u32 key);

void *func_0219390C(void *a, u32 b)
{
if (b < 30) {
    return func_02193F34(a, b);
}
return 0;
}

