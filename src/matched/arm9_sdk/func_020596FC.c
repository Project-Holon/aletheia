/*
 * function: DWC_CreateUserData
 * address:  0x020596FC
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwcaccount dwc_account.o.
 * 0x0205A10C is labelled DWCi_GetGamecode.
 *
 * symbols:
 *   DWCi_GetGamecode  0x0205A10C  arm
 */
extern void *DWCi_GetGamecode(void);
extern void DWCi_Acc_CreateUserData(void *userdata, unsigned long gamecode);

void DWC_CreateUserData(void *userdata)
{
    DWCi_Acc_CreateUserData(userdata, (long unsigned int)DWCi_GetGamecode());
}
