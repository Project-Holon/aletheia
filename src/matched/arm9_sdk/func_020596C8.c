/*
 * function: DWCi_Acc_IsAuthentic
 * address:  0x020596C8
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwcaccount dwc_account.o.
 * The tail target 0x020596B0 is labelled func_020596B0 in the listing; see func_020596B0.c.
 */
extern int func_020596B0(void *loginid);

int DWCi_Acc_IsAuthentic(void *userdata)
{
    return func_020596B0((char *)userdata + 16);
}
