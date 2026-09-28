/*
 * function: DWC_BACKUPlCheckAddress
 * address:  0x020588D0
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwcbm dwc_backup.o.
 */
int DWC_BACKUPlCheckAddress(unsigned char *address)
{
    unsigned char v = *address;
    if (v == 127)
        return 0;
    if (v < 1)
        return 0;
    return v <= 223;
}
