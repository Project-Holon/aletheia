/*
 * function: func_021C12F4
 * address:  0x021C12F4
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Symbols:
 *   (none)
 *
 * Sums 16 bytes at +0x404 and returns the total plus 0x11.
 *
 * Addresses are Black-image addresses.
 */

int func_021C12F4(unsigned char *p)
{
    unsigned int i;
    int sum = 0;

    for (i = 0; i < 0x10; i++)
        sum += p[i + 0x404];

    return sum + 0x11;
}
