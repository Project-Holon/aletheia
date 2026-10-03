/*
 * function: func_021BF810
 * address:  0x021BF810
 * packet:   pkt_ov217_021BF810
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BF834 0x021BF834 thumb ov217
 *   func_021BF844 0x021BF844 thumb ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 func_021BF834(void *p);
extern u32 func_021BF844(void *p);
u32 func_021BF810(void *p)
{
    u32 r = 0;
    switch (*(u32 *)((char *)p + 0x2cc)) {
    case 0:
        r = func_021BF834(p);
        break;
    case 1:
        r = func_021BF844(p);
        break;
    }
    return r;
}
