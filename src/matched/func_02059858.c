/*
 * function: DWCi_Acc_IsDirty
 * address:  0x02059858
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
int DWCi_Acc_IsDirty(void *userdata)
{
    return (*(unsigned long *)((char *)userdata + 32) & 1) == 1;
}
