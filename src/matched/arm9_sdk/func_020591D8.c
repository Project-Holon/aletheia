/*
 * function: DWCi_Acc_SetFlags
 * address:  0x020591D8
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
extern int DWCi_Acc_SetMaskBits(unsigned long *ptr, unsigned long data, unsigned long shift, unsigned long mask);

void DWCi_Acc_SetFlags(void *userdata, unsigned long flags)
{
    DWCi_Acc_SetMaskBits(userdata, flags, 11, 0x1fffff);
}
