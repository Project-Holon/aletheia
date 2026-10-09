/*
 * file:     unit_02174D04.c
 * unit:     yes
 * function: func_02174D04, func_02174D28, func_02174E10, func_02174ED0
 * address:  0x02174D04
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
 *   DWCi_GetMatchCnt  0x02175F3C arm
 *   func_0216BA08  0x0216BA08  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_0217695C  0x0217695C  arm  ov009
 *   func_02175F4C  0x02175F4C  arm  ov009
 *   func_0216FC34  0x0216FC34  arm  ov009
 *   func_02173EF8  0x02173EF8  arm  ov009
 *   DWC_GetState                    0x0216B994 arm
 *   MI_CpuCopy8                     0x02082D44 arm
 *   DWCi_ProcessRecvMatchCommand    0x021702A0 arm
 *   func_0216B994                0x0216B994 arm   ov009
 *   func_02082D44                0x02082D44 arm
 *   func_020949F4                0x020949F4 arm
 *   func_021702A0                0x021702A0 arm   ov009
 *   g_021A2188                   0x021A2188 data
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32;

typedef unsigned long long u64;

struct DWCstMatchControl
{
    void *          pGpObj;                                /* +0x000 */
    void *          pGt2Socket;                            /* +0x004 */
    void *          gt2Callbacks;                          /* +0x008 */
    u8              gt2ConnectCount;                       /* +0x00c */
    u8              connectedOnceBefore;                   /* +0x00d */
    u8              pad0[2];
    void *          qr2Obj;                                /* +0x010 */
    u8              qr2MatchType;                          /* +0x014 */
    u8              qr2MatchTypeExt;                       /* +0x015 */
    u8              hostState;                             /* +0x016 */
    u8              qr2NumEntry;                           /* +0x017 */
    u8              qr2IsReserved;                         /* +0x018 */
    u8              pad1[3];
    u32             suspendMatchBitmap;                    /* +0x01c */
    u64             suspendRequestTick;                    /* +0x020 */
    int             suspendMatch;                          /* +0x028 */
    int             suspend;                               /* +0x02c */
    u8              suspendServerResponse;                 /* +0x030 */
    u8              pad2[3];
    void *          suspendCallback;                       /* +0x034 */
    void *          suspendResultParam;                    /* +0x038 */
    u64             suspendTimeoutTick;                    /* +0x03c */
    int             suspendRetry;                          /* +0x044 */
    int             isSuspending;                          /* +0x048 */
    u8              qr2ShutdownFlag;                       /* +0x04c */
    u8              pad3[3];
    u8              nodoInfoList[0x504];                   /* +0x050 */
    u8              tempNewNodeInfo[0x28];                 /* +0x554 */
    u8              tempNewClientInfo[0x28];               /* +0x57c */
    int             inMeshMaking;                          /* +0x5a4 */
    int             lastStateBeforeStopMeshMaking;         /* +0x5a8 */
    u8              tempNodeInfoBeforeStopMeshMaking[0x28];/* +0x5ac */
    u16             qr2Port;                               /* +0x5d4 */
    u8              pad4[2];
    u32             qr2IP;                                 /* +0x5d8 */
    int             qr2Reservation;                        /* +0x5dc */
    void *          sbObj;                                 /* +0x5e0 */
    int             sbUpdateFlag;                          /* +0x5e4 */
    u64             sbUpdateTick;                          /* +0x5e8 */
    u64             sbUpdateRequestTick;                   /* +0x5f0 */
    u8              nnRecvCount;                           /* +0x5f8 */
    u8              nnFailureCount;                        /* +0x5f9 */
    u16             nnCookieRand;                          /* +0x5fa */
    int             nnLastCookie;                          /* +0x5fc */
    u64             nnFailedTime;                          /* +0x600 */
    u64             nnFinishTime;                          /* +0x608 */
    u8              nnInfo[12];                            /* +0x610 */
    int             state;                                 /* +0x61c */
    u8              clLinkProgress;                        /* +0x620 */
    u8              friendCount;                           /* +0x621 */
    u8              pad5[2];
    int             distantFriend;                         /* +0x624 */
    u8              resvWaitCount;                         /* +0x628 */
    u8              closeState;                            /* +0x629 */
    u8              cancelState;                           /* +0x62a */
    u8              scResvRetryCount;                      /* +0x62b */
    u8              synResendCount;                        /* +0x62c */
    u8              cancelSynResendCount;                  /* +0x62d */
    u8              clWaitTimeoutCount;                    /* +0x62e */
    u8              needServerPoll;                        /* +0x62f */
    u16             baseLatency;                           /* +0x630 */
    u16             cancelBaseLatency;                     /* +0x632 */
    u32             nnResvCheckValue;                      /* +0x634 */
    int             cmdResendFlag;                         /* +0x638 */
    u64             cmdResendTick;                         /* +0x63c */
    u32             cmdTimeoutTime;                        /* +0x644 */
    u64             cmdTimeoutStartTick;                   /* +0x648 */
    u32             synAckBit;                             /* +0x650 */
    u32             cancelSynAckBit;                       /* +0x654 */
    u64             lastSynSent;                           /* +0x658 */
    u64             lastCancelSynSent;                     /* +0x660 */
    u64             closedTime;                            /* +0x668 */
    u64             clWaitTime;                            /* +0x670 */
    int             profileID;                             /* +0x678 */
    int             reqProfileID;                          /* +0x67c */
    int             cbEventPid;                            /* +0x680 */
    char *          gameName;                              /* +0x684 */
    char *          secretKey;                             /* +0x688 */
    void *          friendList;                            /* +0x68c */
    int             friendListLen;                         /* +0x690 */
    u8              friendIdxList[64];                     /* +0x694 */
    int             friendIdxListLen;                      /* +0x6d4 */
    u8              cmdCnt[0x98];                          /* +0x6d8 */
    void *          matchedCallback;                       /* +0x770 */
    void *          matchedParam;                          /* +0x774 */
    void *          newClientCallback;                     /* +0x778 */
    void *          newClientParam;                        /* +0x77c */
    void *          evalCallback;                          /* +0x780 */
    void *          evalParam;                             /* +0x784 */
    u32             serverDownBuff;                        /* +0x788 */
    u32             serverDownBase;                        /* +0x78c */
    u32             groupID;                               /* +0x790 */
    u8              searchGroupIDRetryHostCount;           /* +0x794 */
    u8              pad6[3];
    int             connectGroupID;                        /* +0x798 */
    u8              serverDownQueryCount;                  /* +0x79c */
    u8              serverDownNakCount;                    /* +0x79d */
    u8              pad7[2];
    u64             serverPollingTime;                     /* +0x7a0 */
    u8              serverFind;                            /* +0x7a8 */
    u8              pad8[3];
    u32             serverBrowserUpdateCount;              /* +0x7ac */
    int             topologyType;                          /* +0x7b0 */
    u8              denyReason;                            /* +0x7b4 */
    u8              cancelFromConnection;                  /* +0x7b5 */
    u8              retryCountMax;                         /* +0x7b6 */
    u8              pad9;
    void *          connectAttemptCallback;                /* +0x7b8 */
    u8              connUserDataOwn[4];                    /* +0x7bc */
    void *          connectAttemptParam;                   /* +0x7c0 */
    int             firstServer;                           /* +0x7c4 */
    u32             serverPollingUID;                      /* +0x7c8 */
    u64             suspendWaitTime;                       /* +0x7cc */
    int             serverLocked;                          /* +0x7d4 */
};

typedef struct MatchCnt {
    unsigned char pad0[0x554];
    unsigned char f554[0x57C - 0x554];
    int f57C;
    unsigned char pad1[0x5F8 - 0x580];
    unsigned char f5F8;
    unsigned char pad2[0x5FC - 0x5F9];
    int f5FC;
    long long f600;
    unsigned char pad3[0x61C - 0x608];
    int f61C;
    unsigned char pad4[0x6D8 - 0x620];
    unsigned char f6D8;
} MatchCnt;

struct DWCstBinaryMessage_02174E10 {
    unsigned long unk00;
    unsigned long type;
    unsigned char command;
    unsigned char length;
    unsigned short port;
    unsigned long ip;
    unsigned long pid;
};

struct DWCstBinaryMessage_02174ED0 {
    char keyword[4];
    int identifier;
    u8 command;
    u8 size;
    u16 port;
    u32 ip;
    int pid;
};

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern int func_0216BA08(void);
extern int func_02175F3C(void);
extern int func_0217695C(void);
extern void func_02175F4C(int status);
extern int func_0216FC34(int type, int cookie, void *param);
extern int func_02173EF8(int nnError);
extern int DWC_GetState(void);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern int DWCi_ProcessRecvMatchCommand(unsigned char command, int srcPid,
    unsigned long srcIP, unsigned short srcPort, unsigned long *data, int len);
extern int func_0216B994(void);
extern void func_02082D44(void *srcp, void *dstp, u32 size);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern int func_021702A0(u8 command, int srcPid, u32 srcIP, u16 srcPort, u32 *data, int len);
void DWCi_QR2PublicAddrCallback(unsigned int ip, unsigned short port);
void func_02174D28(int cookie);
void DWCi_HandleGT2UnreliableMatchCommandMessage(void *data, int len);
void func_02174ED0(char *data, int len);
extern char g_021A2188[];



void DWCi_QR2PublicAddrCallback(unsigned int ip, unsigned short port)
{
    DWCi_GetMatchCnt()->qr2IP = ip;
    DWCi_GetMatchCnt()->qr2Port = port;
}



/*
 * sdk:      DWCi_QR2NatnegCallback (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
void func_02174D28(int cookie)
{
    int nnError;

    if (func_0216BA08() == 0 && ((MatchCnt *)func_02175F3C())->f57C != 0)
        return;
    if (((MatchCnt *)func_02175F3C())->f61C == 1) {
        if (func_0217695C() == 0)
            return;
        func_02175F4C(5);
    } else if (((MatchCnt *)func_02175F3C())->f61C != 5 && ((MatchCnt *)func_02175F3C())->f61C != 14) {
        return;
    }
    if (cookie == ((MatchCnt *)func_02175F3C())->f5FC) {
        ((MatchCnt *)func_02175F3C())->f5F8++;
    } else {
        ((MatchCnt *)func_02175F3C())->f5F8 = 0;
        ((MatchCnt *)func_02175F3C())->f5FC = cookie;
    }
    ((MatchCnt *)func_02175F3C())->f600 = 0;
    nnError = func_0216FC34(1, cookie, ((MatchCnt *)func_02175F3C())->f554);
    if (func_02173EF8(nnError) != 0)
        return;
    ((MatchCnt *)func_02175F3C())->f6D8 = 0xFF;
}



void DWCi_HandleGT2UnreliableMatchCommandMessage(void *data, int len)
{
    unsigned long payload[32];
    struct DWCstBinaryMessage_02174E10 binaryCommand;

    if (DWC_GetState() == 4 ||
        (DWC_GetState() == 5 && (DWCi_GetMatchCnt()->qr2MatchType == 2 ||
                                 DWCi_GetMatchCnt()->qr2MatchType == 3))) {
        MI_CpuCopy8(data, &binaryCommand, 0x14);
        binaryCommand.pid = (unsigned long)(binaryCommand.pid);
        if (binaryCommand.type != 0x5a || len != binaryCommand.length + 0x14)
            return;
        MI_CpuCopy8((char *)data + 0x14, payload, binaryCommand.length);
        DWCi_ProcessRecvMatchCommand(binaryCommand.command, binaryCommand.pid,
            binaryCommand.ip, binaryCommand.port, payload, binaryCommand.length >> 2);
    }
}



/*
 * sdk:      DWCi_QR2ClientMsgCallback (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
void func_02174ED0(char *data, int len)
{
    struct DWCstBinaryMessage_02174ED0 sbMsg;
    u32 payload[32];
    int boolResult;
    int offset = 0;

    if (func_0216B994() != 4) {
        if (func_0216B994() != 5)
            return;
        if (DWCi_GetMatchCnt()->qr2MatchType != 2 && DWCi_GetMatchCnt()->qr2MatchType != 3)
            return;
    }
    while (offset + 0x14 <= len) {
        func_02082D44(data, &sbMsg, 0x14);
        *(volatile int *)&sbMsg.pid = sbMsg.pid;
        if (func_020949F4((const u8 *)sbMsg.keyword, (const u8 *)g_021A2188, 4) != 0 || sbMsg.identifier != 0x5a)
            return;
        func_02082D44(data + 0x14, payload, sbMsg.size);
        boolResult = func_021702A0(sbMsg.command, sbMsg.pid, sbMsg.ip, sbMsg.port, payload, sbMsg.size >> 2);
        if (boolResult == 0)
            return;
        offset += sbMsg.size + 0x14;
    }
}
