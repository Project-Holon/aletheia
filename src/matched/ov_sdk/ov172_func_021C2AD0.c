/*
 * function: SSPi_JpegEncoderCheckWidthHeight
 * address:  0x021C2AD0
 * packet:   pkt_021C2AD0
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Range/alignment validator for a transfer pair: both addresses must be
 * non-zero and inside 0x10000, then the mode picks which of the two has to be
 * 8- or 16-byte aligned (1: both 8, 2: both 16, 3: first 16 and second 8).
 * Returns 1 when the pair is legal, 0 otherwise.  The three cases share the
 * out-of-line "return 1" tail and each keeps its own "return 0" as the
 * fall-through of its second test.
 *
 * symbols:  (none)
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

int SSPi_JpegEncoderCheckWidthHeight(u32 a0, u32 a1, u32 a2)
{
    if (a0 == 0 || a0 > 0xffff || a1 == 0 || a1 > 0xffff)
        return 0;
    switch (a2) {
    case 1:
        if ((a0 & 7) != 0 || (a1 & 7) != 0)
            return 0;
        break;
    case 2:
        if ((a0 & 0xf) != 0 || (a1 & 0xf) != 0)
            return 0;
        break;
    case 3:
        if ((a0 & 0xf) != 0 || (a1 & 7) != 0)
            return 0;
        break;
    default:
        return 0;
    }
    return 1;
}
