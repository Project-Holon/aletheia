/*
 * function: func_0205F558
 * address:  0x0205F558
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK symbol: ConvNetMask (test.o, libdwcac.TWL.HYB.a)
 */

unsigned long func_0205F558(unsigned char netmask)
{
    unsigned long netmask32 = 0xffffffff;
    int i;
    int n = 32 - netmask;

    for (i = 0; i < n; i++)
        netmask32 <<= 1;
    return ((netmask32 >> 24) & 0xff) | ((netmask32 >> 8) & 0xff00)
         | ((netmask32 << 8) & 0xff0000) | ((netmask32 << 24) & 0xff000000);
}
