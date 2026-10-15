/*
 * function: NCFGi_ConvMaskAddr
 * address:  0x02060368
 * packet:   pkt_0205F7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NCFGi_ConvMaskAddr (check.o)
 *
 * symbols:
 *   (none)
 */

void NCFGi_ConvMaskAddr(int mask, unsigned char *buf)
{
    int i;
    unsigned long snm;

    snm = 0xFFFFFFFF ^ (0xFFFFFFFF >> mask);
    for (i = 0; i < 4; i++) {
        buf[i] = (unsigned char)(snm >> (24 - i * 8));
    }
}
