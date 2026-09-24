/*
 * function: func_0218198C
 * address:  0x0218198C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Number of halfwords before the terminating zero, less one.
 */

int func_0218198C(const unsigned short *p)
{
    const unsigned short *q = p;
    unsigned short v;

    do {
        v = *q++;
    } while (v != 0);
    return (int)((const char *)q - (const char *)p) / 2 - 1;
}
