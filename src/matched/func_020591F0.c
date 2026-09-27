/*
 * function: DWCi_Acc_SetFlag_DataType
 * address:  0x020591F0
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
extern unsigned long DWCi_Acc_GetFlags(void *userdata);
extern void DWCi_Acc_SetFlags(void *userdata, unsigned long flags);

void DWCi_Acc_SetFlag_DataType(void *userdata, int type)
{
    unsigned long flags = DWCi_Acc_GetFlags(userdata);
    DWCi_Acc_SetFlags(userdata, (flags & ~3) | type);
}
