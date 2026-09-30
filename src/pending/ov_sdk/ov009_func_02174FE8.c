/*
 * function: DWCi_NNCompletedCallback
 * address:  0x02174FE8
 * packet:   pkt_ov009_02174FE8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      DWCi_NNCompletedCallback (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * blocker:  register rename only, size exact at 1008 bytes (65 concrete bytes differ,
 *           49 sites).  The size gap that used to sit here was a body-shape bug, not
 *           allocation: `status = (f_61c == 0xe) ? 0xf : 6; DWCi_SetMatchStatus(status);`
 *           if-converts to moveq/movne and comes out 8 bytes short.  Writing the call
 *           into both arms (`if (..) DWCi_SetMatchStatus(0xf); else DWCi_SetMatchStatus(6);`)
 *           gives the image's single tail-merged bl with the bne/mov/b/mov join --
 *           see docs/idioms/a-constant-argument-selected-into-a-local-if-converts-where-a-call-in-each-arm-does-not.md.
 *           DWARF of dwc_match.o (4.0.0.1025) gives the real signature -- three named
 *           params (enum result r6, SOCSockAddrIn *remoteaddr r5, void *userdata r4) with
 *           an unnamed second argument, locals pNodeInfo/nnInfo (r0), gt2Result (r4),
 *           nnResult (r5), nnError (r0), pidStr[24] at [fb+16].
 *           Left: the image keeps `result` in r6 and the shared constant zero in r7;
 *           this build has those two swapped (zero r6, result r7), which cascades into
 *           49 sites (the pidStr address also lands in r5 instead of r6 at +00CC, and
 *           -1 for the gt2Connect length is `r4 - 0x19` instead of `r5 - 0x19`).
 *           Measured and inert: every declaration order, pidStr first/last, a named zero
 *           local (int / unsigned / enum-typed, first or last), `result = result;`,
 *           `res = result;` forwarding, a nameless second parameter.  This is the
 *           4.0.0.1025 "one register higher / one local takes the free slot" allocator
 *           signature of docs/notes/lane_U4_ov009_sdk_rows45_59.md -- park as that class.
 *
 * symbols:
 *   DWCi_GetMatchCnt                 0x02175f3c arm
 *   DWCi_SetMatchStatus              0x02175f4c arm
 *   DWCi_MakeGT2ConnectString        0x0216e808 arm
 *   gt2AddressToString               0x02198620 arm
 *   gt2Connect                       0x02195b44 arm
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID 0x021763ac arm
 *   DWCi_StopMeshMaking              0x02176674 arm
 *   DWCi_HandleGT2Error              0x02173fb4 arm
 *   DWCi_CancelPreConnectedServerProcess 0x021720d8 arm
 *   OS_GetTick                       0x020870d0 arm
 *   DWCi_HandleNNResult              0x02173f54 arm
 *   NNCancel                         0x02199fb4 arm
 *   DWCi_ProcessNNFailure            0x021753d8 arm
 *   DWCi_CancelPreConnectedClientProcess 0x02172124 arm
 *   DWCi_DoNatNegotiationAsync       0x0216fe34 arm
 *   DWCi_HandleNNError               0x02173ef8 arm

 * lane U62 (2026-09-30): 1008/1008, 65 concrete (49 sites), unchanged. The residue is exactly
 *           one exchange: `result`(r0) saved to r6, shared zero to r7 in the image; r7/r6 here.
 *           Everything else - frame (sp+0x10 pidStr, sp+0 stack args), every immediate, the
 *           gt2Connect argument block - agrees. Measured inert this lane (+8 variants):
 *           64-bit clear via `*(unsigned long long *)&MC->f_600 = 0;` (65), f_600 split into two
 *           32-bit stores (744), chained `MC->f_5fc = MC->f_600 = (MC->f_5f8 = 0);` (770/1028),
 *           enum-typed parameter and gt2Result (65), named zero local (65). Parked as the
 *           4.0.0.1025 allocator signature.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct SOCSockAddrIn {
    u8 len;
    u8 family;
    u16 port;
    u32 addr;
};

struct DWCstNodeInfo {
    int profileID;
    u32 publicInetAddress;
    u32 privateInetAddress;
    u16 publicQueryPort;
    u16 privateQueryPort;
    u32 gt2IP;
    u16 gt2Port;
    u8 aid;
    u8 hasPrivateAddress;
    int nnTryCount;
    unsigned long long nextMeshMakeTryTick;
    u8 connUserData[4];
};

struct DWCstNNInfo {
    u8 isQR2;
    u8 retryCount;
    u16 port;
    u32 ip;
    int cookie;
};

struct DWCstMatchControl {
    int pad0;
    void **f_4;
    void *f_8;
    u8 f_c;
    u8 pad1[0x15 - 0xd];
    u8 f_15;
    u8 pad2[0x554 - 0x16];
    int f_554;
    u8 pad3[0x564 - 0x558];
    u32 f_564;
    u16 f_568;
    u8 pad4[0x5a4 - 0x56a];
    int f_5a4;
    u8 pad5[0x5f8 - 0x5a8];
    u8 f_5f8;
    u8 pad6[0x5fc - 0x5f9];
    int f_5fc;
    unsigned long long f_600;
    unsigned long long f_608;
    u8 pad7[0x618 - 0x610];
    int f_618;
    int f_61c;
};

extern struct DWCstMatchControl *DWCi_GetMatchCnt(void);
extern void DWCi_SetMatchStatus(int state);
extern void DWCi_MakeGT2ConnectString(char *buf, int bufLen);
extern char *gt2AddressToString(u32 ip, u16 port, char *string);
extern int gt2Connect(void *socket, void *connection, char *remoteAddress,
                      unsigned char *message, int len, int timeout, void *callbacks,
                      int blocking);
extern struct DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForProfileID(int profileID);
extern int DWCi_StopMeshMaking(void);
extern int DWCi_HandleGT2Error(int result);
extern int DWCi_CancelPreConnectedServerProcess(int profileID);
extern unsigned long long OS_GetTick(void);
extern int DWCi_HandleNNResult(int result);
extern void NNCancel(int cookie);
extern int DWCi_ProcessNNFailure(int ignoreError);
extern int DWCi_CancelPreConnectedClientProcess(int profileID);
extern int DWCi_DoNatNegotiationAsync(struct DWCstNNInfo *nnInfo);
extern int DWCi_HandleNNError(int error);

#define MC DWCi_GetMatchCnt()

void DWCi_NNCompletedCallback(int result, int unused, struct SOCSockAddrIn *remoteaddr,
                              struct DWCstNNInfo *nnInfo)
{
    char pidStr[24];
    int status;
    unsigned long long tick;
    int gt2Result;
    struct DWCstMatchControl *mc;

    if (MC->f_61c != 5 && MC->f_61c != 0xe)
        return;
    if (nnInfo == 0)
        return;

    if (result == 0) {
        if (nnInfo->isQR2 != 0) {
        MC->f_564 = remoteaddr->addr;
        {
            int p = remoteaddr->port;
            MC->f_568 = ((p >> 8) & 0xff) | ((p << 8) & 0xff00);
        }
        MC->f_5f8 = 0;
        MC->f_5fc = 0;
        MC->f_600 = 0;
        if (MC->f_61c == 0xe)
            DWCi_SetMatchStatus(0xf);
        else
            DWCi_SetMatchStatus(6);
        MC->f_c = 0;
        DWCi_MakeGT2ConnectString(pidStr, 0x18);
        {
            char *s = gt2AddressToString(MC->f_564, MC->f_568, 0);
            mc = MC;
            gt2Result = gt2Connect(*mc->f_4, 0, s, (unsigned char *)pidStr, -1, 5000,
                                   DWCi_GetMatchCnt()->f_8, 0);
        }
        if (MC->f_5a4 != 0 && gt2Result != 0) {
            DWCi_NodeInfoList_GetNodeInfoForProfileID(MC->f_554)->nnTryCount++;
            DWCi_StopMeshMaking();
            DWCi_SetMatchStatus(1);
            return;
        }
        if (gt2Result == 1) {
            DWCi_HandleGT2Error(1);
            return;
        }
        if (gt2Result == 0)
            return;
        DWCi_CancelPreConnectedServerProcess(MC->f_554);
        return;
        }

        if (remoteaddr != 0) {
            MC->f_564 = remoteaddr->addr;
            {
                int p = remoteaddr->port;
                MC->f_568 = ((p >> 8) & 0xff) | ((p << 8) & 0xff00);
            }
        }
        tick = OS_GetTick();
        MC->f_608 = tick;
        DWCi_SetMatchStatus(6);
        return;
    }

    if (nnInfo->cookie == 0)
        return;
    if (MC->f_5a4 != 0) {
        DWCi_NodeInfoList_GetNodeInfoForProfileID(MC->f_554)->nnTryCount++;
        DWCi_StopMeshMaking();
        DWCi_SetMatchStatus(1);
        return;
    }
    status = DWCi_HandleNNResult(result);
    if (status != 2 && status != 1 && status != 3)
        return;
    if (nnInfo->isQR2 == 0) {
        if (status == 1 || status == 3 || (status == 2 && nnInfo->retryCount >= 1)) {
            NNCancel(MC->f_618);
            nnInfo->cookie = 0;
            if (DWCi_ProcessNNFailure(0) == 0)
                return;
            DWCi_CancelPreConnectedClientProcess(MC->f_554);
            return;
        }
        nnInfo->retryCount++;
        DWCi_HandleNNError(DWCi_DoNatNegotiationAsync(nnInfo));
        return;
    }
    tick = OS_GetTick();
    MC->f_600 = tick;
    if (status != 1 && status != 3) {
        if (status != 2)
            return;
        if (MC->f_5f8 < 1)
            return;
    }
    NNCancel(MC->f_618);
    nnInfo->cookie = 0;
    if (MC->f_15 == 3 || MC->f_15 == 2) {
        if (DWCi_ProcessNNFailure(1) == 0)
            return;
    } else {
        if (DWCi_ProcessNNFailure(0) == 0)
            return;
    }
    MC->f_5f8 = 0;
    MC->f_5fc = 0;
    MC->f_600 = 0;
    DWCi_CancelPreConnectedServerProcess(MC->f_554);
}
