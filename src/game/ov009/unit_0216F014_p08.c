/*
 * file:     unit_0216F014_p08.c
 * unit:     yes
 * function: DWCi_SendResvCommandToFriend, func_02171E34, func_02171F68
 * address:  0x02171C08
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   func_02175F3C                0x02175F3C arm   ov009
 *   func_020870D0                0x020870D0 arm
 *   func_0217653C                0x0217653C arm   ov009
 *   func_02175F4C                0x02175F4C arm   ov009
 *   func_0216F770                0x0216F770 arm   ov009
 *   func_02173D9C                0x02173D9C arm   ov009
 *   func_02171C08                0x02171C08 arm   ov009
 *   func_021719A4                0x021719A4 arm   ov009
 *   func_0216EB68                0x0216EB68 arm   ov009
 *   func_02176554  0x02176554  arm  ov009
 *   func_0216FF2C  0x0216FF2C  arm  ov009
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

struct DWCstMatchControl_02171C08
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

typedef unsigned long long u64;

struct DWCstMatchControl_0216F014 {
    u8 pad0[0x15];
    u8 qr2MatchTypeExt;
    u8 pad1[0x5e4 - 0x16];
    int f5e4;
    u64 f5e8;
    u8 pad2[0x628 - 0x5f0];
    u8 f628;
    u8 pad3[0x648 - 0x629];
    u64 f648;
    u8 pad4[0x67c - 0x650];
    int f67c;
    u8 pad5[0x798 - 0x680];
    int f798;
};

extern struct DWCstMatchControl_02171C08 * DWCi_GetMatchCnt(void);
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
extern int func_02175F3C(void);
extern u64 func_020870D0(void);
extern void func_0217653C(void);
extern void func_02175F4C(int state);
extern int func_0216F770(int profileID);
extern int func_02173D9C(int error);
extern int func_02171C08(int delay, int init, int resendPid);
extern int func_021719A4(int error);
extern void func_0216EB68(int error, int errorCode);
extern int func_02176554(void);
extern int func_0216FF2C(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
int DWCi_SendResvCommandToFriend(int delay, int init, int resendPid);
/* * sdk: DWCi_RetryReserving (libdwcmatch.TWL.HYB.a dwc_match.o) */ int func_02171E34(int resendPid);
/* * Sends command 5 to the new node recorded in the temporary node info. */ int func_02171F68(int arg);


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



/*
 * sdk:      DWCi_RetryReserving (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02171E34(int resendPid)
{
    int result;
    int sbError;
    u64 tick;

    ((struct DWCstMatchControl_0216F014 *)func_02175F3C())->f67c = 0;
    ((struct DWCstMatchControl_0216F014 *)func_02175F3C())->f628 = 0;
    tick = func_020870D0();
    ((struct DWCstMatchControl_0216F014 *)func_02175F3C())->f648 = tick;
    func_0217653C();
    if (((struct DWCstMatchControl_0216F014 *)func_02175F3C())->f798 != 0) {
        func_02175F4C(0xc);
        sbError = func_02173D9C(func_0216F770(0));
        if (sbError != 0)
            return 0;
    } else if (((struct DWCstMatchControl_0216F014 *)func_02175F3C())->qr2MatchTypeExt == 0) {
        func_02175F4C(2);
        if (resendPid != 0) {
            ((struct DWCstMatchControl_0216F014 *)func_02175F3C())->f5e4 = 1;
            tick = func_020870D0();
            ((struct DWCstMatchControl_0216F014 *)func_02175F3C())->f5e8 = tick;
        } else {
            sbError = func_02173D9C(func_0216F770(0));
            if (sbError != 0)
                return 0;
        }
    } else if (((struct DWCstMatchControl_0216F014 *)func_02175F3C())->qr2MatchTypeExt == 1) {
        result = func_021719A4(func_02171C08(1, 0, resendPid));
        if (result != 0)
            return 0;
    } else if (((struct DWCstMatchControl_0216F014 *)func_02175F3C())->qr2MatchTypeExt == 3) {
        func_0216EB68(6, -80410);
        return 0;
    }
    return 1;
}



/*
 * Sends command 5 to the new node recorded in the temporary node info.
 */
int func_02171F68(int arg)
{
    int result;

    if (func_02176554() == 0) {
        return 0;
    }
    result = func_0216FF2C(5, *(int *)(func_02175F3C() + 0x554), *(unsigned int *)(func_02175F3C() + 0x558),
                           *(unsigned short *)(func_02175F3C() + 0x560), 0, 0);
    *(int *)(func_02175F3C() + 0x67c) = 0;
    return result;
}
