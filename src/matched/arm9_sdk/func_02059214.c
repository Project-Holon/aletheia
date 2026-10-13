/*
 * function: DWCi_SetBuddyFriendData
 * address:  0x02059214
 * packet:   pkt_02059214
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SetBuddyFriendData (dwc_account.o)
 *
 * symbols:
 *   DWCi_Acc_GetFlag_DataType        0x0205911c arm
 *   DWCi_Acc_GetFlags                0x02059108 arm
 *   DWCi_Acc_SetFlags                0x020591d8 arm
 */

typedef struct DWCstAccFlag DWCstAccFlag;
typedef union DWCstAccFriendData DWCstAccFriendData;

extern unsigned long func_0205911C(DWCstAccFlag *userdata);
extern unsigned long func_02059108(DWCstAccFlag *userdata);
extern void func_020591D8(DWCstAccFlag *userdata, unsigned long flags);

void DWCi_SetBuddyFriendData(DWCstAccFriendData *frienddata)
{
    unsigned long flags;

    if (func_0205911C((DWCstAccFlag *)frienddata) == 3) {
        flags = func_02059108((DWCstAccFlag *)frienddata) | 4;
        func_020591D8((DWCstAccFlag *)frienddata, flags);
    }
}
