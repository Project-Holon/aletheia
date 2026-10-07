/*
 * function: func_0216C230
 * address:  0x0216C230
 * packet:   pkt_ov009_0216C230
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GT2ClosedProcess (libdwcmatch dwc_main.o, static)
 *
 * Reconstructed from the DWARF of the defining object (param/local names and
 * registers) plus the object disassembly.  Object stamp is 4.0.0.1025.
 *
 * Closed 2026-10-01 (wave 3 lane 11) by re-deriving semantics from branch
 * targets: the fb14 if/else chain sits after the `dwcError == 0` block (the
 * image's `bne` at +0080 lands on it), its last arm is an if/else with two
 * stores, the final NodeInfoList_GetCount()==1 test is `f2d != 0`, faf0 and
 * fab8 are 64-bit fields (two stores off one base), locals declared in DWARF
 * order with pNodeInfo scoped to the IsBackupMine block, and f365 is a
 * volatile byte field (the image re-reads it, `ldrbne`).
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

#include "../include/G_DwcGlobal.h"

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
    volatile u8 f365;                 /* 0x365 */
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
    unsigned long long fab8;          /* 0xab8 */
    char padac0[0xadc - 0xac0];
    int fadc;                         /* 0xadc */
    char pade0[0xaf0 - 0xae0];
    unsigned long long faf0;          /* 0xaf0 */
    char padaf8[0xb14 - 0xaf8];
    int fb14;                         /* 0xb14 */
};

extern struct DwcGlobal g_021AA878;
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

void func_0216C230(struct GTI2Connection *connection, int reason,
                           int isPseudClose, unsigned char closeAid)
{
    unsigned char aid;
    int profileID;
    int errorCode;
    int i;
    int isServer;
    int aidValid;
    struct DWCstConnectionInfo *conninfo;
    int dwcError;

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
        ((struct DWCControl *)g_021AA878.st)->f36c &= ~(1 << aid);

        if (((struct DWCControl *)g_021AA878.st)->f398 != 0 && isServer) {
            if (!DWCi_IsBackupMine())
                ((struct DWCControl *)g_021AA878.st)->f394 = 1;
        }

        i = 0;

        if (profileID == 0)
            profileID = gt2GetConnectionData(DWCi_GetGT2Connection(aid))->profileID;

        if (!isPseudClose)
            g_021AA8A0[conninfo->index] = 0;
    }

    if (((struct DWCControl *)g_021AA878.st)->fb14 == 1 && DWC_IsServerMyself())
        ((struct DWCControl *)g_021AA878.st)->fb14 = 1;
    else if ((((struct DWCControl *)g_021AA878.st)->f365 == 3 || ((struct DWCControl *)g_021AA878.st)->f365 == 2))
        ((struct DWCControl *)g_021AA878.st)->fb14 = 0;
    else if (DWC_GetNumConnectionHost() == 1)
        ((struct DWCControl *)g_021AA878.st)->fb14 = 1;
    else
        ((struct DWCControl *)g_021AA878.st)->fb14 = 0;

    if (DWCi_IsBackupMine()) {
        struct DWCstNodeInfo *pNodeInfo;

        ((struct DWCControl *)g_021AA878.st)->fadc = 0;

        for (i = 0; i < DWCi_NodeInfoList_GetCount(); ) {
            pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);

            if (pNodeInfo->profileID != ((struct DWCControl *)g_021AA878.st)->f9c8 &&
                DWCi_GetGT2Connection(pNodeInfo->aid) == 0) {
                if (((struct DWCControl *)g_021AA878.st)->cb88 != 0) {
                    ((struct DWCControl *)g_021AA878.st)->cb88(dwcError, reason == 0, isServer,
                                          pNodeInfo->aid,
                                          DWCi_GetFriendListIndex(pNodeInfo->profileID),
                                          ((struct DWCControl *)g_021AA878.st)->f8c);
                }
                DWCi_DeleteAID(pNodeInfo->aid);
            } else {
                pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
                ((struct DWCControl *)g_021AA878.st)->fadc |= 1 << pNodeInfo->aid;
                i++;
            }
        }
    }

    if (reason != 0 && DWC_IsServerMyself() == 1) {
        ((struct DWCControl *)g_021AA878.st)->faf0 = 0;

        if (DWCi_IsFullMesh()) {
            if (((struct DWCControl *)g_021AA878.st)->f96c == 0x10 && ((struct DWCControl *)g_021AA878.st)->fa28 == 8) {
                ((struct DWCControl *)g_021AA878.st)->fab8 = 0;
            }
        }
    }

    if (((struct DWCControl *)g_021AA878.st)->f2d == 0 && ((struct DWCControl *)g_021AA878.st)->f24 == 5 && aidValid == 0) {
        if (!(((struct DWCControl *)g_021AA878.st)->f364 == 2 && dwcError == 0))
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

    if (((struct DWCControl *)g_021AA878.st)->f364 == 2) {
        if (((struct DWCControl *)g_021AA878.st)->f2d == 0)
            DWCi_GPSetServerStatus(-1);
        else if (DWCi_NodeInfoList_GetCount() == 1)
            DWCi_GPSetServerStatus(1);
    } else if (DWCi_NodeInfoList_GetCount() == 1) {
        DWCi_GPSetServerStatus(1);
    }

    if (((struct DWCControl *)g_021AA878.st)->f366 == 2)
        qr2_send_statechanged(((struct DWCControl *)g_021AA878.st)->f360);

    if (((struct DWCControl *)g_021AA878.st)->cb88 != 0 && aidValid != 0) {
        ((struct DWCControl *)g_021AA878.st)->cb88(dwcError, reason == 0, isServer, aid,
                              DWCi_GetFriendListIndex(profileID),
                              ((struct DWCControl *)g_021AA878.st)->f8c);
    }

    if (((struct DWCControl *)g_021AA878.st)->f2d == 0 && ((struct DWCControl *)g_021AA878.st)->f364 == 2)
        return;

    if (DWCi_StopMeshMaking() == 1)
        DWCi_SetMatchStatus(1);

    if (DWCi_NodeInfoList_GetCount() == 1) {
        if (((struct DWCControl *)g_021AA878.st)->f2d != 0) {
            DWCi_NNFreeNegotiateList();
            DWCi_SetState(3);
            DWCi_ClearQR2Key();
            ((struct DWCControl *)g_021AA878.st)->f366 = 0;
        } else {
            DWCi_SetMatchStatus(0xb);
        }
        return;
    }

    if (((struct DWCControl *)g_021AA878.st)->f364 == 3 && isServer && DWCi_NodeInfoList_GetCount() >= 1) {
        if (DWCi_NodeInfoList_GetCount() == 1 && DWCi_IsServerChangeEnabled())
            DWCi_SetMatchStatus(0xb);
        else
            DWCi_SetMatchStatus(9);
    }
}
