/*
 * function: func_020598EC
 * address:  0x020598EC
 * packet:   pkt_020598EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GetGsProfileId (libdwcaccount.TWL.HYB.a(dwc_account.o))
 *
 * symbols:
 *   DWCi_Acc_GetFlag_DataType        0x0205911c arm
 *   DWCi_Acc_GetFriendKey            0x020590ac arm
 *   DWC_Acc_FriendKeyToGsProfileId   0x020593b8 arm
 *   DWCi_Acc_GetGsProfileId          0x020590c0 arm
 */

struct DWCstAccUserData {
    unsigned char pad[0x24];
    unsigned long gamecode;
};

extern unsigned long DWCi_Acc_GetFlag_DataType(void *userdata);
extern unsigned long long DWCi_Acc_GetFriendKey(void *data);
extern int DWC_Acc_FriendKeyToGsProfileId(unsigned long long friendkey, unsigned long gamecode);
extern int DWCi_Acc_GetGsProfileId(void *data);

int func_020598EC(struct DWCstAccUserData *userdata, void *frienddata)
{
    unsigned long long friend_key;
    unsigned long type;

    type = DWCi_Acc_GetFlag_DataType(frienddata);
    switch (type) {
    case 2:
        friend_key = DWCi_Acc_GetFriendKey(frienddata);
        return DWC_Acc_FriendKeyToGsProfileId(friend_key, userdata->gamecode);
    case 3:
        return DWCi_Acc_GetGsProfileId(frienddata);
    case 1:
        return -1;
    }
    return 0;
}
