/*
 * function: func_0205F504
 * address:  0x0205F504
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * SDK symbol: ConvAddress (test.o, libdwcac.TWL.HYB.a)
 */

unsigned long func_0205F504(unsigned char *add)
{
    unsigned long address = ((unsigned long)add[0] << 24) | ((unsigned long)add[1] << 16)
                          | ((unsigned long)add[2] << 8) | (unsigned long)add[3];

    return ((address >> 24) & 0xff) | ((address >> 8) & 0xff00)
         | ((address << 8) & 0xff0000) | ((address << 24) & 0xff000000);
}
