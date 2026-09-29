/*
 * function: DWCi_CheckResvCommand_Sub
 * address:  0x02171524
 * packet:   pkt_ov009_02171524
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CheckResvCommand_Sub (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_IsServerLocked              0x021767f4 arm
 *   DWCi_GetMatchCnt                 0x02175f3c arm
 *   gpIsBuddy                        0x021861a8 arm
 *   DWCi_GetFriendListIndex          0x02169038 arm
 *   DWCi_IsFriendByIdxList           0x02173b74 arm
 *   DWCi_GetNumEntry                 0x02175760 arm
 *   DWC_GetSuspendMatch              0x0216cb90 arm
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID 0x021763ac arm
 *   DWCi_GetHostStatus               0x02175fb8 arm
 *   DWCi_SetupGameServer_InterChange 0x021755d4 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct DWCstMatchControl
{
    void **connection;
    u8 pad0[0x14 - 0x4];
    u8 f_14;
    u8 f_15;
    u8 pad1[0x17 - 0x16];
    u8 f_17;
    u8 pad2[0x48 - 0x18];
    int f_48;
    u8 pad3[0x5d4 - 0x4c];
    u16 f_5d4;
    u8 pad4[0x5d8 - 0x5d6];
    int f_5d8;
    int f_5dc;
    u8 pad5[0x61c - 0x5e0];
    int f_61c;
    u8 pad6[0x678 - 0x620];
    int f_678;
    int f_67c;
    u8 pad7[0x7b0 - 0x680];
    int f_7b0;
    u8 f_7b4;
    u8 pad8[0x7b8 - 0x7b5];
    int (*f_7b8)(unsigned char *, int);
    u8 pad9[0x7c0 - 0x7bc];
    int f_7c0;
};

extern int DWCi_IsServerLocked(void);
extern struct DWCstMatchControl *DWCi_GetMatchCnt(void);
extern int gpIsBuddy(void **connection, int profile);
extern int DWCi_GetFriendListIndex(int profileID);
extern int DWCi_IsFriendByIdxList(int profileID);
extern int DWCi_GetNumEntry(void);
extern int DWC_GetSuspendMatch(void);
extern void *DWCi_NodeInfoList_GetNodeInfoForProfileID(int profileID);
extern int DWCi_GetHostStatus(void);
extern void DWCi_SetupGameServer_InterChange(int init);

unsigned char DWCi_CheckResvCommand_Sub(int profileID, u32 qr2IP, u16 qr2Port,
                                        u32 matchType, int connectGroupID,
                                        u32 topologyType,
                                        unsigned char *newClientUserData,
                                        int meshReserve)
{
    unsigned char sendCommand;

    if (DWCi_IsServerLocked() != 0) {
        DWCi_GetMatchCnt()->f_7b4 = 0x13;
        return 3;
    }
    if (meshReserve != 0) {
        DWCi_GetMatchCnt()->f_7b4 = 0x18;
        return 3;
    }
    if (connectGroupID != 0)
        goto main;

    if ((matchType == 0 && DWCi_GetMatchCnt()->f_15 != 0) ||
        (matchType == 1 && DWCi_GetMatchCnt()->f_15 != 1) ||
        (matchType == 3 && DWCi_GetMatchCnt()->f_15 != 2)) {
        DWCi_GetMatchCnt()->f_7b4 = 0x12;
        return 3;
    }

    if (DWCi_GetMatchCnt()->f_15 == 1) {
        if (gpIsBuddy(DWCi_GetMatchCnt()->connection, profileID) != 0) {
            if (DWCi_GetFriendListIndex(profileID) != -1)
                goto isfriend;
        }
        return 0xff;
    isfriend:
        if (DWCi_IsFriendByIdxList(profileID) != 0)
            goto main;
        DWCi_GetMatchCnt()->f_7b4 = 0x15;
        return 3;
    }
    if (DWCi_GetMatchCnt()->f_15 == 2) {
        if (gpIsBuddy(DWCi_GetMatchCnt()->connection, profileID) != 0) {
            if (DWCi_GetFriendListIndex(profileID) != -1)
                goto main;
        }
        return 0xff;
    }

main:
    if (DWCi_GetMatchCnt()->f_17 + 1 == DWCi_GetNumEntry()) {
        sendCommand = 3;
        DWCi_GetMatchCnt()->f_7b4 = 0x10;
        goto done;
    }
    if (DWCi_GetMatchCnt()->f_61c == 0x16) {
        sendCommand = 4;
        goto done;
    }
    if (DWC_GetSuspendMatch() != 0 || DWCi_GetMatchCnt()->f_48 != 0) {
        sendCommand = 3;
        DWCi_GetMatchCnt()->f_7b4 = 0x11;
        goto done;
    }
    if (topologyType != DWCi_GetMatchCnt()->f_7b0) {
        sendCommand = 3;
        DWCi_GetMatchCnt()->f_7b4 = 0x12;
        goto done;
    }
    if (DWCi_NodeInfoList_GetNodeInfoForProfileID(profileID) != 0) {
        sendCommand = 0xff;
        goto done;
    }
    if (DWCi_GetMatchCnt()->f_61c == 0xd ||
        DWCi_GetMatchCnt()->f_61c == 2 ||
        DWCi_GetMatchCnt()->f_61c == 3) {
        if ((DWCi_GetMatchCnt()->f_5d8 != 0 || DWCi_GetMatchCnt()->f_5d4 != 0) &&
            (qr2IP != 0 || qr2Port != 0))
            goto lookup;
    }
    if (DWCi_GetMatchCnt()->f_61c == 0xe &&
        profileID == DWCi_GetMatchCnt()->f_5dc) {
        sendCommand = 0xff;
        goto done;
    }
    sendCommand = 4;
    goto done;

lookup:
    if (DWCi_GetMatchCnt()->f_14 != 2 &&
        DWCi_GetMatchCnt()->f_67c != 0) {
        if (profileID == DWCi_GetMatchCnt()->f_67c) {
            if (DWCi_GetMatchCnt()->f_678 < profileID)
                sendCommand = 2;
            else
                sendCommand = 0xff;
        } else {
            sendCommand = 3;
            DWCi_GetMatchCnt()->f_7b4 = 0x17;
        }
        goto done;
    }
    sendCommand = 2;
    goto done;

done:
    if (sendCommand == 2) {
        if (DWCi_GetMatchCnt()->f_7b8 != 0) {
            if (DWCi_GetMatchCnt()->f_7b8(newClientUserData, DWCi_GetMatchCnt()->f_7c0) == 0) {
                DWCi_GetMatchCnt()->f_7b4 = 0x16;
                return 3;
            }
        }
        if (DWCi_GetHostStatus() == 0)
            DWCi_SetupGameServer_InterChange(1);
    }
    return sendCommand;

err12:
    DWCi_GetMatchCnt()->f_7b4 = 0x12;
    return 3;
}
