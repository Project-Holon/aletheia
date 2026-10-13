/*
 * function: DWC_CreateFriendKey
 * address:  0x0205994C
 * packet:   pkt_0205994C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_CreateFriendKey (libdwcaccount.TWL.HYB.a(dwc_account.o))
 *
 * symbols:
 *   DWC_Acc_CreateFriendKey          0x020592d0 arm
 */

struct DWCstAccUserData {
    unsigned char pad[0x1c];
    int gs_profile_id;
    unsigned long reserved;
    unsigned long gamecode;
};

extern unsigned long long DWC_Acc_CreateFriendKey(int gs_profile_id, unsigned long gamecode, int method);

unsigned long long DWC_CreateFriendKey(struct DWCstAccUserData *userdata)
{
    unsigned long long ret = 0;

    if (userdata->gs_profile_id != 0) {
        ret = DWC_Acc_CreateFriendKey(userdata->gs_profile_id, userdata->gamecode, 1);
    }
    return ret;
}
