/*
 * function: DWCi_Acc_SetMaskBits
 * address:  0x02059058
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwcaccount dwc_account.o.
 */
int DWCi_Acc_SetMaskBits(unsigned long *ptr, unsigned long data, unsigned long shift, unsigned long mask)
{
    if (data & ~mask)
        return 0;
    *ptr = (*ptr & ~(mask << shift)) | (data << shift);
    return 1;
}
