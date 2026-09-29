/*
 * function: DWCi_SendResvCommandToFriend
 * address:  0x02171C08
 * packet:   pkt_ov009_02171C08
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SendResvCommandToFriend (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt                 0x02175F3C arm
 *   _s32_div_f                       0x0209C0A4 arm
 *   DWCi_GetUserData                 0x0216A39C arm
 *   DWC_GetGsProfileId               0x020598EC arm
 *   DWCi_Acc_IsValidFriendData       0x020596F0 arm
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID 0x021763AC arm
 *   gpGetBuddyIndex                  0x02186108 arm
 *   gpGetBuddyStatus                 0x02185FD4 arm
 *   DWCi_IsLockedBuddyStatus         0x02176984 arm
 *   DWCi_TempNewNodeInfo_Clear       0x0217653C arm
 *   DWCi_SendResvCommand             0x021719D0 arm
 *   OS_GetTick                       0x020870D0 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct DWCstMatchControl
{
    void *f0;
    u8 pad0[0x14 - 4];
    u8 f_14;
    u8 pad1[0x554 - 0x15];
    u32 f_554;
    u8 pad2[0x56a - 0x558];
    u8 f_56a;
    u8 pad3[0x621 - 0x56b];
    u8 f_621;
    u8 pad4[0x638 - 0x622];
    u32 f_638;
    u8 pad5[0x644 - 0x63c];
    u32 f_644;
    unsigned long long f_648;
    u8 pad6[0x68c - 0x650];
    u8 *f_68c;
    u8 pad7[0x694 - 0x690];
    u8 f_694[0x6d4 - 0x694];
    int f_6d4;
};

struct GPBuddyStatus
{
    int f0;
    int f4;
    u8 pad[0x214 - 8];
};

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern void * DWCi_GetUserData(void);
extern int DWC_GetGsProfileId(void * userdata, void * frienddata);
extern int DWCi_Acc_IsValidFriendData(void * frienddata);
extern void * DWCi_NodeInfoList_GetNodeInfoForProfileID(int profileID);
extern int gpGetBuddyIndex(void * connection, int profile, int * index);
extern int gpGetBuddyStatus(void * connection, int index, struct GPBuddyStatus * status);
extern int DWCi_IsLockedBuddyStatus(struct GPBuddyStatus * status);
extern void DWCi_TempNewNodeInfo_Clear(void);
extern int DWCi_SendResvCommand(int profileID, int delay);
extern unsigned long long OS_GetTick(void);

extern void _s32_div_f(void);

int DWCi_SendResvCommandToFriend(int delay, int init, int resendPid)
{
    int found = 0;
    int profileID;
    int i;
    int gpResult;
    struct GPBuddyStatus status;
    int buddyIdx;
    unsigned long long tick;

    if (init == 0) {
        DWCi_GetMatchCnt()->f_621++;
        DWCi_GetMatchCnt()->f_621 =
            DWCi_GetMatchCnt()->f_621 % DWCi_GetMatchCnt()->f_6d4;
    }
    DWCi_GetMatchCnt()->f_14 = 3;
    i = 0;
    if (DWCi_GetMatchCnt()->f_6d4 > 0) {
        do {
            profileID = DWC_GetGsProfileId(
                DWCi_GetUserData(),
                DWCi_GetMatchCnt()->f_68c +
                    DWCi_GetMatchCnt()->f_694[DWCi_GetMatchCnt()->f_621] * 12);
            if (profileID == 0 || profileID == -1)
                goto next;
            if (DWCi_Acc_IsValidFriendData(
                    DWCi_GetMatchCnt()->f_68c +
                    DWCi_GetMatchCnt()->f_694[DWCi_GetMatchCnt()->f_621] * 12) == 0)
                goto next;
            if (DWCi_NodeInfoList_GetNodeInfoForProfileID(profileID) != 0)
                goto next;
            gpResult = gpGetBuddyIndex(DWCi_GetMatchCnt()->f0, profileID, &buddyIdx);
            gpResult |= gpGetBuddyStatus(DWCi_GetMatchCnt()->f0, buddyIdx, &status);
            if (!(DWCi_IsLockedBuddyStatus(&status) == 0 &&
                  gpResult == 0 && status.f4 == 4))
                goto next;
            found = 1;
            break;
        next:
            i++;
            DWCi_GetMatchCnt()->f_621 =
                (i + DWCi_GetMatchCnt()->f_621) % DWCi_GetMatchCnt()->f_6d4;
        } while (i < DWCi_GetMatchCnt()->f_6d4);
    }
    if (found) {
        if (profileID == resendPid)
            delay = 1;
        DWCi_TempNewNodeInfo_Clear();
        DWCi_GetMatchCnt()->f_56a = 0xff;
        DWCi_GetMatchCnt()->f_554 = profileID;
        return DWCi_SendResvCommand(profileID, delay);
    }
    DWCi_GetMatchCnt()->f_644 = 0xbb8;
    tick = OS_GetTick();
    DWCi_GetMatchCnt()->f_648 = tick;
    DWCi_GetMatchCnt()->f_638 = 0;
    return 0;
}

