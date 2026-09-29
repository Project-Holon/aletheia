/*
 * function: DWCi_GT2ClosedProcess
 * address:  0x0216C230
 * packet:   pkt_ov009_0216C230
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF   (parked; not EXACT/MATCH)
 *
 * sdk:      DWCi_GT2ClosedProcess (libdwcmatch dwc_main.o, static)
 *
 * Reconstructed from the DWARF of the defining object (param/local names and
 * registers) plus the object disassembly.  Object stamp is 4.0.0.1025;
 * dsi/1.1p1 is the calibrated front end used for this object.
 *
 * BLOCKER (codegen only, extent exact at 1368 bytes, 25 aligned blocks): all 45
 * relocations resolve.  Recovered from the object: isServer = profileID = 0 and
 * errorCode = dwcError = profileID (the object reads the profileID stack slot),
 * errorCode -7600 for reasons 2/3 and -7601 for 4, SetError(dwcError, errorCode - 80000)
 * (pool word), aidValid left uninitialised, the f365 test written as
 * !(f365 != 3 && f365 != 2).  Left: the object reloads the byte f365 in the second
 * arm of `== 3 || == 2` (ldrbne) which every spelling here folds, and it holds the
 * constant 0 in r6 at +0x150 (module pointer reloaded later into r5) where this build
 * hoists the module pointer instead, giving a r5/r6/r8 rotation from +0x150 on.
 *
 * symbols:
 *   DWCi_IsShutdownMatch                      0x0216F370  arm   ov009
 *   gt2GetConnectionData                      0x02195E78  arm   ov009
 *   DWCi_NodeInfoList_GetNodeInfoForAID       0x02176410  arm   ov009
 *   DWCi_ClearTransConnection                 0x021776A0  arm   ov009
 *   DWCi_NodeInfoList_GetServerNodeInfo       0x02176358  arm   ov009
 *   DWCi_DeleteAID                            0x0216BCA4  arm   ov009
 *   DWCi_IsBackupMine                         0x021754FC  arm   ov009
 *   DWCi_GetGT2Connection                     0x0216BAF4  arm   ov009
 *   DWC_IsServerMyself                        0x0216BA08  arm   ov009
 *   DWC_GetNumConnectionHost                  0x0216B804  arm   ov009
 *   DWCi_NodeInfoList_GetCount                0x0217603C  arm   ov009
 *   DWCi_NodeInfoList_GetNodeInfoForIndex     0x0217637C  arm   ov009
 *   DWCi_GetFriendListIndex                   0x02169038  arm   ov009
 *   DWCi_IsFullMesh                           0x0217695C  arm   ov009
 *   DWCi_GPSetServerStatus                    0x0216F20C  arm   ov009
 *   DWCi_ProcessMatchSCClosing                0x0216F1E8  arm   ov009
 *   DWCi_ProcessMatchClosing                  0x0216F0A0  arm   ov009
 *   DWCi_SetError                             0x02059F54  arm
 *   qr2_send_statechanged                     0x0219B490  arm   ov009
 *   DWCi_StopMeshMaking                       0x02176674  arm   ov009
 *   DWCi_SetMatchStatus                       0x02175F4C  arm   ov009
 *   DWCi_NNFreeNegotiateList                  0x02176B34  arm   ov009
 *   DWCi_SetState                             0x0216BC84  arm   ov009
 *   DWCi_ClearQR2Key                          0x0216EC18  arm   ov009
 *   DWCi_IsServerChangeEnabled                0x02175FC8  arm   ov009
 *   g_021AA878                                0x021AA878  data
 *   g_021AA8A0                                0x021AA8A0  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct GTI2Connection;

struct DWCstConnectionInfo {
    u8 index;                /* 0x00 */
    u8 aid;                  /* 0x01 */
    u16 pad;                 /* 0x02 */
    int profileID;           /* 0x04 */
};

struct DWCstNodeInfo {
    int profileID;                    /* 0x00 */
    u32 publicInetAddress;            /* 0x04 */
    u32 privateInetAddress;           /* 0x08 */
    u16 publicQueryPort;              /* 0x0c */
    u16 privateQueryPort;             /* 0x0e */
    u32 gt2IP;                        /* 0x10 */
    u16 gt2Port;                      /* 0x14 */
    u8 aid;                           /* 0x16 */
    u8 hasPrivateAddress;             /* 0x17 */
    int nnTryCount;                   /* 0x18 */
    unsigned long long nextMeshMakeTryTick;  /* 0x1c */
    u8 connUserData[4];               /* 0x24 */
};

typedef void (*DwcClosedProc)(int, int, int, int, int, void *);

struct DWCControl {
    char pad00[0x24];
    int f24;                          /* 0x24 */
    char pad28[0x2d - 0x28];
    u8 f2d;                           /* 0x2d */
    char pad2e[0x88 - 0x2e];
    DwcClosedProc cb88;               /* 0x88 */
    void *f8c;                        /* 0x8c */
    char pad90[0x360 - 0x90];
    void *f360;                       /* 0x360 */
    u8 f364;                          /* 0x364 */
    u8 f365;                          /* 0x365 */
    u8 f366;                          /* 0x366 */
    char pad367[0x36c - 0x367];
    int f36c;                         /* 0x36c */
    char pad370[0x394 - 0x370];
    int f394;                         /* 0x394 */
    int f398;                         /* 0x398 */
    char pad39c[0x96c - 0x39c];
    int f96c;                         /* 0x96c */
    char pad970[0x9c8 - 0x970];
    int f9c8;                         /* 0x9c8 */
    char pad9cc[0xa28 - 0x9cc];
    u8 fa28;                          /* 0xa28 */
    char pada29[0xab8 - 0xa29];
    int fab8;                         /* 0xab8 */
    int fabc;                         /* 0xabc */
    char padac0[0xadc - 0xac0];
    int fadc;                         /* 0xadc */
    char pade0[0xaf0 - 0xae0];
    int faf0;                         /* 0xaf0 */
    int faf4;                         /* 0xaf4 */
    char padaf8[0xb14 - 0xaf8];
    int fb14;                         /* 0xb14 */
};

struct DWCModule {
    int f00;                          /* 0x00 */
    struct DWCControl *ctrl;          /* 0x04 */
};

extern struct DWCModule g_021AA878;
extern int g_021AA8A0[];

extern int DWCi_IsShutdownMatch(void);
extern struct DWCstConnectionInfo *gt2GetConnectionData(struct GTI2Connection *connection);
extern struct DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForAID(unsigned char aid);
extern void DWCi_ClearTransConnection(unsigned char aid);
extern struct DWCstNodeInfo *DWCi_NodeInfoList_GetServerNodeInfo(void);
extern int DWCi_DeleteAID(unsigned char aid);
extern int DWCi_IsBackupMine(void);
extern struct GTI2Connection *DWCi_GetGT2Connection(unsigned char aid);
extern int DWC_IsServerMyself(void);
extern int DWC_GetNumConnectionHost(void);
extern int DWCi_NodeInfoList_GetCount(void);
extern struct DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern int DWCi_GetFriendListIndex(int profileID);
extern int DWCi_IsFullMesh(void);
extern int DWCi_GPSetServerStatus(int matchType);
extern void DWCi_ProcessMatchSCClosing(int clientPid);
extern int DWCi_ProcessMatchClosing(int error, int errorCode, int profileID);
extern void DWCi_SetError(int error, int errorCode);
extern void qr2_send_statechanged(void *qrec);
extern int DWCi_StopMeshMaking(void);
extern void DWCi_SetMatchStatus(int state);
extern void DWCi_NNFreeNegotiateList(void);
extern void DWCi_SetState(int state);
extern void DWCi_ClearQR2Key(void);
extern int DWCi_IsServerChangeEnabled(void);

void DWCi_GT2ClosedProcess(struct GTI2Connection *connection, int reason,
                           int isPseudClose, unsigned char closeAid)
{
    struct DWCstConnectionInfo *conninfo;
    struct DWCstNodeInfo *pNodeInfo;
    int dwcError;
    int isServer;
    int i;
    unsigned char aid;
    int profileID;
    int errorCode;
    int aidValid;

    isServer = profileID = 0;

    if (DWCi_IsShutdownMatch())
        return;

    switch (reason) {
    case 0:
    case 1:
        errorCode = dwcError = profileID;
        break;
    case 2:
    case 3:
        dwcError = 6;
        errorCode = -7600;
        break;
    case 4:
        dwcError = 9;
        errorCode = -7601;
        break;
    }

    if (dwcError == 0) {
        if (!isPseudClose) {
            conninfo = gt2GetConnectionData(connection);
            if (conninfo == 0)
                return;
            aid = conninfo->aid;
        } else {
            aid = closeAid;
        }

        aidValid = DWCi_NodeInfoList_GetNodeInfoForAID(aid) != 0;

        if (!isPseudClose)
            DWCi_ClearTransConnection(aid);

        if (DWCi_NodeInfoList_GetServerNodeInfo() != 0) {
            if (aid == DWCi_NodeInfoList_GetServerNodeInfo()->aid)
                isServer = 1;
        }

        profileID = DWCi_DeleteAID(aid);
        g_021AA878.ctrl->f36c &= ~(1 << aid);

        if (g_021AA878.ctrl->f398 != 0 && isServer) {
            if (!DWCi_IsBackupMine())
                g_021AA878.ctrl->f394 = 1;
        }

        i = 0;

        if (profileID == 0)
            profileID = gt2GetConnectionData(DWCi_GetGT2Connection(aid))->profileID;

        if (!isPseudClose)
            g_021AA8A0[conninfo->index] = 0;

        if (g_021AA878.ctrl->fb14 == 1 && DWC_IsServerMyself())
            g_021AA878.ctrl->fb14 = 1;
        else if ((!(g_021AA878.ctrl->f365 != 3 && g_021AA878.ctrl->f365 != 2)))
            g_021AA878.ctrl->fb14 = 0;
        else
            g_021AA878.ctrl->fb14 = (DWC_GetNumConnectionHost() == 1);
    }

    if (DWCi_IsBackupMine()) {
        g_021AA878.ctrl->fadc = 0;

        for (i = 0; i < DWCi_NodeInfoList_GetCount(); ) {
            pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);

            if (pNodeInfo->profileID != g_021AA878.ctrl->f9c8 &&
                DWCi_GetGT2Connection(pNodeInfo->aid) == 0) {
                if (g_021AA878.ctrl->cb88 != 0) {
                    g_021AA878.ctrl->cb88(dwcError, reason == 0, isServer,
                                          pNodeInfo->aid,
                                          DWCi_GetFriendListIndex(pNodeInfo->profileID),
                                          g_021AA878.ctrl->f8c);
                }
                DWCi_DeleteAID(pNodeInfo->aid);
            } else {
                pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
                g_021AA878.ctrl->fadc |= 1 << pNodeInfo->aid;
                i++;
            }
        }
    }

    if (reason != 0 && DWC_IsServerMyself() == 1) {
        g_021AA878.ctrl->faf0 = 0;
        g_021AA878.ctrl->faf4 = 0;

        if (DWCi_IsFullMesh()) {
            if (g_021AA878.ctrl->f96c == 0x10 && g_021AA878.ctrl->fa28 == 8) {
                g_021AA878.ctrl->fab8 = 0;
                g_021AA878.ctrl->fabc = 0;
            }
        }
    }

    if (g_021AA878.ctrl->f2d == 0 && g_021AA878.ctrl->f24 == 5 && aidValid == 0) {
        if (!(g_021AA878.ctrl->f364 == 2 && dwcError == 0))
            return;

        DWCi_GPSetServerStatus(-1);
        DWCi_ProcessMatchSCClosing(profileID);
        return;
    }

    if (DWCi_ProcessMatchClosing(dwcError, errorCode, profileID) != 0)
        return;

    i = 0;

    if (dwcError != 0) {
        DWCi_SetError(dwcError, errorCode - 80000);
        return;
    }

    if (g_021AA878.ctrl->f364 == 2) {
        if (g_021AA878.ctrl->f2d == 0)
            DWCi_GPSetServerStatus(-1);
        else if (DWCi_NodeInfoList_GetCount() == 1)
            DWCi_GPSetServerStatus(1);
    } else if (DWCi_NodeInfoList_GetCount() == 1) {
        DWCi_GPSetServerStatus(1);
    }

    if (g_021AA878.ctrl->f366 == 2)
        qr2_send_statechanged(g_021AA878.ctrl->f360);

    if (g_021AA878.ctrl->cb88 != 0 && aidValid != 0) {
        g_021AA878.ctrl->cb88(dwcError, reason == 0, isServer, aid,
                              DWCi_GetFriendListIndex(profileID),
                              g_021AA878.ctrl->f8c);
    }

    if (g_021AA878.ctrl->f2d == 0 && g_021AA878.ctrl->f364 == 2)
        return;

    if (DWCi_StopMeshMaking() == 1)
        DWCi_SetMatchStatus(1);

    if (DWCi_NodeInfoList_GetCount() == 1) {
        if (g_021AA878.ctrl->f2d == 0) {
            DWCi_NNFreeNegotiateList();
            DWCi_SetState(3);
            DWCi_ClearQR2Key();
            g_021AA878.ctrl->f366 = 0;
        } else {
            DWCi_SetMatchStatus(0xb);
        }
        return;
    }

    if (g_021AA878.ctrl->f364 == 3 && isServer && DWCi_NodeInfoList_GetCount() >= 1) {
        if (DWCi_NodeInfoList_GetCount() == 1 && DWCi_IsServerChangeEnabled())
            DWCi_SetMatchStatus(0xb);
        else
            DWCi_SetMatchStatus(9);
    }
}
