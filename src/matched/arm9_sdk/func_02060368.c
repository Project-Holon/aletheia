/*
 * function: func_02060368
 * address:  0x02060368
 * packet:   pkt_0205F7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Symbol at this offset is DWCi_BACKUPlConvMaskAddr (libdwcbm dwc_backup.o,
 * dwc_backup.c:483).  DWARF: formals (int mask, unsigned char *buf), locals
 * (int i, unsigned long snm).  Writes the 4 bytes of the network-order mask.
 *
 * symbols:
 *   DWCi_BACKUPlConvMaskAddr 0x02060368 arm
 */

void func_02060368(int mask, unsigned char *buf)
{
    int i;
    unsigned int snm = ~0u ^ (~0u >> mask);

    for (i = 0; i < 4; i++)
        buf[i] = snm >> (24 - i * 8);
}
