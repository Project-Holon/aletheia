/*
 * function: func_021B94D8
 * address:  0x021B94D8
 * packet:   pkt_021B94D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   (unverified)
 *
 * symbols:
 *   func_021B94C0  0x021B94C0  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_021B94C0(u16 *p, u16 v);

int func_021B94D8(u16 *r, u8 *tbl, u8 *sr)
{
    u8 *s = sr;
    u8 *t = tbl;
    u16 *rp = r;
    int i = 0, found = 0;
    if (*(u16 *)(s + 2) > 0) {
        do {
            if (t == *(u8 **)(s + 0x14) + i * 0x48)
                found = i;
            i++;
        } while (i < *(u16 *)(s + 2));
    }
    *rp = found;
    return func_021B94C0(rp, (u16)found);
}
