/*
 * function: func_021C28BC
 * address:  0x021C28BC
 * packet:   pkt_021C28BC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

extern int _s32_div_f(int, int);

u8 func_021C28BC(char *p)
{
    return (u8)(*(u8 *)(p + 2) / 100);
}
