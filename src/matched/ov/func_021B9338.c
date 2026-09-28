/*
 * function: func_021B9338
 * address:  0x021B9338
 * packet:   pkt_021B9338
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
  * status:   EXACT*
 *
 * symbols:
 *   func_021B9280  0x021B9280  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_021B9280(u8 *a, u32 arg2, u32 arg3, u8 *tbl);

int func_021B9338(u8 *p, u8 *base, u32 arg3, int arg4)
{
    int r = func_021B9280(base, *(u32 *)(p + 0xc), arg3, *(u8 **)(p + 0x24));
    int f = *(int *)(p + 0x14);

    *(int *)(p + 0x18) = r;
    if ((f < 0 ? -f : f) >= r) {
        if (f > 0)
            *(int *)(p + 0x14) = r;
        else
            *(int *)(p + 0x14) = -r;
    }
    return arg4;
}

