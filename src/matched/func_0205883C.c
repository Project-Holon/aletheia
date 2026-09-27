/*
 * function: DWCi_BACKUPlConvMaskAddr
 * address:  0x0205883C
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwcbm dwc_backup.o.
 * Declaring i before snm gets the source's register assignment.
 */
void DWCi_BACKUPlConvMaskAddr(int mask, unsigned char *buf)
{
    int i;
    unsigned long snm = 0xffffffff ^ (0xffffffff >> mask);
    for (i = 0; i < 4; i++)
        buf[i] = (unsigned char)(snm >> (24 - i * 8));
}
