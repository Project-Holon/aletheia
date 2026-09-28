/*
 * function: func_021B6ECC
 * address:  0x021B6ECC
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Bump the u16 counter at *c and wrap it to 0 at the limit in o+2.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021B6ECC(void *o, u16 *c)
{
    *c += 1;
    if (*c >= *(u16 *)((char *)o + 2)) {
        *c = 0;
    }
}
