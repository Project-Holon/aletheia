/*
 * file:     dwc_account_8.c
 * function: DWC_CheckDirtyFlag
 * address:  0x0205984C
 * packet:   pkt_0205984C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_Acc_IsDirty  0x02059858  arm
 *
 * Tail call to DWCi_Acc_IsDirty (ldr ip, =target; bx ip; pool word).
 */

extern int DWCi_Acc_IsDirty(void *userdata);

int DWC_CheckDirtyFlag(void *userdata)
{
    return DWCi_Acc_IsDirty(userdata);
}
