/*
 * function: func_021BE91C
 * address:  0x021BE91C
 * packet:   pkt_021BE91C
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

extern int _s32_div_f(int, int);

void func_021BE91C(char *p, int a)
{
    *(int *)(p + 0x34) = (*(int *)(p + 0x34) + a + 5) % 5;
}
