/*
 * function: func_021B960C
 * address:  0x021B960C
 * packet:   pkt_021B960C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   (unverified)
 *
 * symbols:
 *   func_021B87FC  0x021B87FC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

u8 *func_021B87FC(u8 *p, u32 idx);

u32 func_021B960C(u32 *p, u8 *v, u8 *q)
{
    int i;
    for (i = 0; i < 4; i++) {
        u32 *e = &p[i];
        if (func_021B87FC(q, *e) == v)
            return *(u32 *)((u8 *)e + 0x10);
    }
    return 0;
}
