/*
 * function: ConvNetMask
 * address:  0x0205F558
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ConvNetMask (test.o)
 *
 * symbols:
 *   (none)
 */

#define SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | (((x) << 24) & 0xFF000000))

static unsigned long ConvNetMask(unsigned char netmask)
{
    int i;
    int n;
    unsigned long netmask32;

    netmask32 = 0xFFFFFFFF;
    n = 32 - netmask;
    for (i = 0; i < n; i++) {
        netmask32 <<= 1;
    }
    return SWAP32(netmask32);
}
