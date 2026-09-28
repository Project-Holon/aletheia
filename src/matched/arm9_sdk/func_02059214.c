/*
 * function: func_02059214
 * address:  0x02059214
 * packet:   pkt_02059214
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK symbol: DWCi_SetBuddyFriendData (libdwcaccount.TWL.HYB.a(dwc_account.o))
 * DWARF dwc_account.c:437-446, formal frienddata (r0), local flags (r0).
 */

extern int DWCi_Acc_GetFlag_DataType(void *frienddata);
extern unsigned long DWCi_Acc_GetFlags(void *frienddata);
extern void DWCi_Acc_SetFlags(void *frienddata, unsigned long flags);

void func_02059214(void *frienddata)
{
    unsigned long flags;

    if (DWCi_Acc_GetFlag_DataType(frienddata) == 3) {
        flags = DWCi_Acc_GetFlags(frienddata) | 4;
        DWCi_Acc_SetFlags(frienddata, flags);
    }
}
