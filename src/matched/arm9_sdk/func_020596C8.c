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
 * The tail target 0x020596B0 is labelled DWCi_Acc_IsValidLoginId in the listing; see DWCi_Acc_IsValidLoginId.c.
 *
 * symbols:
 *   DWCi_Acc_IsValidLoginId  0x020596B0  arm
 */
extern int DWCi_Acc_IsValidLoginId(void *loginid);

int DWCi_Acc_IsAuthentic(void *userdata)
{
    return DWCi_Acc_IsValidLoginId((char *)userdata + 16);
}
