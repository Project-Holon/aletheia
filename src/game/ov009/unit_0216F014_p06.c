/*
 * file:     unit_0216F014_p06.c
 * unit:     yes
 * function: func_021713CC, func_02171524, func_02171884, func_021719A4
 * address:  0x021713CC
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
 *   func_02175F3C                0x02175F3C arm   ov009
 *   func_02175FB8                0x02175FB8 arm   ov009
 *   DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID 0x02176500 arm   ov009
 *   DWCi_ClearMeshMakingTempInfo 0x02176870 arm   ov009
 *   func_02176344                0x02176344 arm   ov009
 *   func_020870D0                0x020870D0 arm
 *   func_02171524                0x02171524 arm   ov009
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
 *   qr2_send_statechanged        0x0219B490 arm   ov009
 *   func_02176474                0x02176474 arm   ov009
 *   func_0217603C                0x0217603C arm   ov009
 *   func_0217637C                0x0217637C arm   ov009
 *   func_0216FF2C                0x0216FF2C arm   ov009
 *   func_02173D9C  0x02173D9C  arm  ov009
 *   func_02173D28  0x02173D28  arm  ov009
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef unsigned long long u64;

struct DWCstMatchControl_021713CC {
    u8 pad0[0x554];
    int f554;
    u8 pad1[0x57c - 0x558];
    int f57c;
    u8 pad2[0x5a4 - 0x580];
    int f5a4;
    u8 pad3[0x61c - 0x5a8];
    int f61c;
    u8 pad4[0x768 - 0x620];
    u64 f768;
    u8 pad5[0x7b4 - 0x770];
    u8 f7b4;
};

struct DWCstNodeInfo_021713CC {
    int profileID;
};

struct DWCstMatchControl_02171524
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

struct DWCstMatchControl_02171884 {
    u8 pad0[0x10];
    void *qr2Obj;
    u8 pad1[0x18 - 0x14];
    u8 f18;
    u8 pad2[0x554 - 0x19];
    u32 f554;
    u8 pad3[0x56a - 0x558];
    u8 aid;
    u8 pad4[0x5a4 - 0x56b];
    int f5a4;
    u8 pad5[0x5dc - 0x5a8];
    int f5dc;
    u8 pad6[0x638 - 0x5e0];
    int f638;
    u8 pad7[0x644 - 0x63c];
    int f644;
    u8 pad8[0x67c - 0x648];
    int f67c;
};

struct DWCstNodeInfo_02171884 {
    int profileID;
    u32 ip;
    u8 pad0[0xc - 0x8];
    u16 port;
};

extern int func_02175F3C(void);
extern unsigned char func_02175FB8(void);
extern int DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID(int profileID);
extern void DWCi_ClearMeshMakingTempInfo(void);
extern char *func_02176344(void);
extern u64 func_020870D0(void);
extern u8 func_02171524(int profileID, u32 qr2IP, u16 qr2Port, u32 matchType, int connectGroupID, u32 topologyType, u8 *newClientUserData, int meshReserve);
extern int DWCi_IsServerLocked(void);
extern struct DWCstMatchControl_02171524 *DWCi_GetMatchCnt(void);
extern int gpIsBuddy(void **connection, int profile);
extern int DWCi_GetFriendListIndex(int profileID);
extern int DWCi_IsFriendByIdxList(int profileID);
extern int DWCi_GetNumEntry(void);
extern int DWC_GetSuspendMatch(void);
extern void *DWCi_NodeInfoList_GetNodeInfoForProfileID(int profileID);
extern int DWCi_GetHostStatus(void);
extern void DWCi_SetupGameServer_InterChange(int init);
extern void qr2_send_statechanged(void *qrec);
extern u8 func_02176474(void);
extern int func_0217603C(void);
extern char *func_0217637C(int index);
extern int func_0216FF2C(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
extern int func_02173D9C(int error);
extern int func_02173D28(int error);
u8 func_021713CC(int profileID, u32 qr2IP, u16 qr2Port, u32 matchType, int connectGroupID, u32 topologyType, u8 *newClientUserData, int meshReserve);
unsigned char DWCi_CheckResvCommand_Sub(int profileID, u32 qr2IP, u16 qr2Port, u32 matchType, int connectGroupID, u32 topologyType, unsigned char *newClientUserData, int meshReserve);
int func_02171884(int profileID);
int func_021719A4(int error);


/*
 * sdk:      DWCi_CheckResvCommand (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
u8 func_021713CC(int profileID, u32 qr2IP, u16 qr2Port, u32 matchType, int connectGroupID, u32 topologyType, u8 *newClientUserData, int meshReserve)
{
    struct DWCstNodeInfo_021713CC *pMyNodeInfo;
    u8 sendCommand;
    u64 tick;

    ((struct DWCstMatchControl_021713CC *)func_02175F3C())->f7b4 = 1;
    switch (func_02175FB8()) {
    case 1:
        if (DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID(profileID)) {
            if (((struct DWCstMatchControl_021713CC *)func_02175F3C())->f5a4 == 0) {
                if (((struct DWCstMatchControl_021713CC *)func_02175F3C())->f61c == 1) {
                    if (((struct DWCstMatchControl_021713CC *)func_02175F3C())->f57c != 0) {
                        sendCommand = 4;
                    } else {
                        ((struct DWCstMatchControl_021713CC *)func_02175F3C())->f5a4 = 1;
                        DWCi_ClearMeshMakingTempInfo();
                        goto send;
                    }
                } else {
                    sendCommand = 4;
                }
            } else {
                if (((struct DWCstMatchControl_021713CC *)func_02175F3C())->f61c == 3) {
                    pMyNodeInfo = (struct DWCstNodeInfo_021713CC *)func_02176344();
                    if (profileID == ((struct DWCstMatchControl_021713CC *)func_02175F3C())->f554) {
                        if (pMyNodeInfo->profileID >= profileID) {
                            sendCommand = 0xff;
                        } else {
                        send:
                            sendCommand = 2;
                            tick = func_020870D0();
                            ((struct DWCstMatchControl_021713CC *)func_02175F3C())->f768 = tick;
                        }
                    } else {
                        sendCommand = 4;
                    }
                } else {
                    sendCommand = 4;
                }
            }
        } else {
            sendCommand = 3;
            ((struct DWCstMatchControl_021713CC *)func_02175F3C())->f7b4 = 0x14;
        }
        break;
    case 0:
    case 2:
        sendCommand = func_02171524(profileID, qr2IP, qr2Port, matchType, connectGroupID, topologyType, newClientUserData, meshReserve);
        break;
    }
    return sendCommand;
}


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


/*
 * sdk:      DWCi_ProcessResvOK (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02171884(int profileID)
{
    u32 senddata[16];
    int result;
    int i;
    u8 aid;
    struct DWCstNodeInfo_02171884 *pMyNodeInfo;
    struct DWCstNodeInfo_02171884 *pNodeInfo;

    if (((struct DWCstMatchControl_02171884 *)func_02175F3C())->f18 != 0 && profileID == ((struct DWCstMatchControl_02171884 *)func_02175F3C())->f5dc)
        return 0;
    ((struct DWCstMatchControl_02171884 *)func_02175F3C())->f18 = 1;
    ((struct DWCstMatchControl_02171884 *)func_02175F3C())->f5dc = profileID;
    ((struct DWCstMatchControl_02171884 *)func_02175F3C())->f638 = 0;
    ((struct DWCstMatchControl_02171884 *)func_02175F3C())->f644 = 0;
    qr2_send_statechanged(((struct DWCstMatchControl_02171884 *)func_02175F3C())->qr2Obj);
    ((struct DWCstMatchControl_02171884 *)func_02175F3C())->f67c = 0;
    aid = func_02176474();
    ((struct DWCstMatchControl_02171884 *)func_02175F3C())->aid = aid;
    if (((struct DWCstMatchControl_02171884 *)func_02175F3C())->f5a4 == 0) {
        senddata[0] = ((struct DWCstMatchControl_02171884 *)func_02175F3C())->f554;
        senddata[1] = ((struct DWCstMatchControl_02171884 *)func_02175F3C())->aid;
        pMyNodeInfo = (struct DWCstNodeInfo_02171884 *)func_02176344();
        for (i = 0; i < func_0217603C(); i++) {
            pNodeInfo = (struct DWCstNodeInfo_02171884 *)func_0217637C(i);
            if (pMyNodeInfo->profileID != pNodeInfo->profileID) {
                result = func_0216FF2C(7, pNodeInfo->profileID, pNodeInfo->ip, pNodeInfo->port, (const unsigned int *)senddata, 2);
                if (result != 0)
                    return result;
            }
        }
    }
    return 0;
}


/*
 * DWCi_HandleMatchCommandError: dispatches to the server-browsing or command error handler.
 */
int func_021719A4(int error)
{
    if (*(unsigned char *)(func_02175F3C() + 0x15) == 0) {
        return func_02173D9C(error);
    }
    return func_02173D28(error);
}
