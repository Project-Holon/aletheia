/*
 * function: STDi_FillBitset
 * address:  0x0208CF84
 * packet:   pkt_0208CF84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libstd std_string.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 */

void STDi_FillBitset(unsigned long *bitset, unsigned long a, unsigned long b)
{
    while (a < b) {
        unsigned long pos = a >> 5;
        unsigned long mask = ~0UL << (a & 31);
        a = (pos + 1) << 5;
        if (b < a)
            mask &= (1UL << (b & 31)) - 1;
        bitset[pos] |= mask;
    }
}
