/*
 * function: func_020597C8
 * address:  0x020597C8
 * packet:   pkt_020597C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_CheckHasProfile (libdwcaccount.TWL.HYB.a(dwc_account.o))
 *
 * symbols:
 *   DWCi_Acc_IsValidLoginId          0x020596b0 arm
 */

struct DWCstAccUserData;
extern int DWCi_Acc_IsValidLoginId(void *loginid);

int func_020597C8(struct DWCstAccUserData *userdata)
{
    return DWCi_Acc_IsValidLoginId((char *)userdata + 0x10) && ((int *)userdata)[7] > 0;
}
