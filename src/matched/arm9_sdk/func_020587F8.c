/*
 * function: DWCi_BACKUPlConvMaskCidr
 * address:  0x020587F8
 * packet:   pkt_020587F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_BACKUPlConvMaskCidr (libdwcbm.TWL.HYB.a dwc_backup.o)
 *
 */

typedef unsigned char u8;

u8 DWCi_BACKUPlConvMaskCidr(u8 *mask)
{
    int snm;
    int i;
    int j;

    i = 0;
    snm = 0;
    for (; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            if ((mask[i] >> j) & 1)
                snm++;
        }
    }
    return (u8)snm;
}
