/*
 * function: ConvAddress
 * address:  0x0205F504
 * packet:   pkt_0205F504
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ConvAddress (libdwcac.TWL.HYB.a(test.o))
 *
 * symbols:
 *   (none)
 */

unsigned long ConvAddress(unsigned char *add)
{
    unsigned long address;

    address = 0;
    address |= (unsigned long)add[0] << 24;
    address |= (unsigned long)add[1] << 16;
    address |= (unsigned long)add[2] << 8;
    address |= add[3];
    return ((address >> 24) & 0xff) | ((address >> 8) & 0xff00) | ((address << 8) & 0xff0000) | ((address << 24) & 0xff000000);
}
