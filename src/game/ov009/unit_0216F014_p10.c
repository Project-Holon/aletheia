/*
 * file:     unit_0216F014_p10.c
 * unit:     yes
 * function: DWCi_PostProcessConnection
 * address:  0x02172254
 * packet:   pkt_ov009_02172254
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The pair of trailing stores is written as one 64-bit zero (`*(unsigned
 * long long *)&p->f5f0 = 0;`): the 32-bit form makes mwcc pick r1 for the
 * zero, the 64-bit form r2, which is what the object has.
 *
 * sdk:      DWCi_PostProcessConnection (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * symbols:
 *   DWCi_IsFullMesh                       0x0217695C  arm
 *   DWCi_PostProcessSVConnectionFullmesh  0x0217273C  arm
 *   DWCi_PostProcessSVConnectionHybrid    0x02172604  arm
 *   DWCi_SetMatchStatus                   0x02175F4C  arm
 *   DWCi_GetMatchCnt                      0x02175F3C  arm
 *   DWCi_StopMeshMaking                   0x02176674  arm
 *   DWCi_ClearMeshMakingTempInfo          0x02176870  arm
 *   DWCi_SetHostStatus                    0x02175F84  arm
 *   DWCi_InitClWaitTimeout                0x02173CFC  arm
 *   DWCi_NodeInfo_IsValid                 0x02176580  arm
 *   DWCi_NodeInfoList_InsertToTop         0x0217604C  arm
 *   DWCi_SendMatchCommand                 0x0216FF2C  arm
 *   DWCi_NodeInfo_Clear                   0x0217656C  arm
 *   DWCi_HandleMatchCommandError          0x021719A4  arm
 *   DWCi_PostProcessConnectionSYNFinish   0x02172510  arm
 *   qr2_send_statechanged                 0x0219B490  arm
 *   DWCi_GetFriendListIndex               0x02169038  arm
 *   DWCi_GPSetServerStatus                0x0216F20C  arm
 *   DWCi_HandleGPError                    0x02173D28  arm
 *   DWCi_ResetLastSomeDataRecvTimeByAidAll 0x02175FE4  arm
 *   ServerBrowserClear                    0x0219F00C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct DWCstNodeInfo
{
    int profileID;                  /* +0x00 */
    u32 ip;                         /* +0x04 */
    u8 pad0[0xc - 8];
    u16 port;                       /* +0x0c */
    u8 pad1[0x28 - 0xe];
};

struct DWCstMatchControl
{
    u8 pad0[0xd];
    u8 f0d;                         /* +0x0d */
    u8 pad1[0x10 - 0xe];
    void *f10;                      /* +0x10 */
    u8 f14;                         /* +0x14 */
    u8 f15;                         /* +0x15 */
    u8 pad2[0x18 - 0x16];
    u8 f18;                         /* +0x18 */
    u8 pad3[0x554 - 0x19];
    struct DWCstNodeInfo tempNewNodeInfo;   /* +0x554 */
    struct DWCstNodeInfo tempNewClientInfo; /* +0x57c */
    u8 pad4[0x5dc - 0x5a4];
    int f5dc;                       /* +0x5dc */
    void *f5e0;                     /* +0x5e0 */
    u8 pad5[0x5f0 - 0x5e4];
    int f5f0;                       /* +0x5f0 */
    int f5f4;                       /* +0x5f4 */
    u8 pad6[0x62a - 0x5f8];
    u8 f62a;                        /* +0x62a */
    u8 pad7[0x62f - 0x62b];
    u8 f62f;                        /* +0x62f */
    u8 pad8[0x678 - 0x630];
    int f678;                       /* +0x678 */
    u8 pad9a[4];
    int f680;                       /* +0x680 */
    u8 pad9[0x770 - 0x684];
    void (*f770)(int, int, int, int, int, int);  /* +0x770 */
    int f774;                       /* +0x774 */
    u8 pad10[0x798 - 0x778];
    int f798;                       /* +0x798 */
};

extern int DWCi_IsFullMesh(void);
extern void DWCi_PostProcessSVConnectionFullmesh(void);
extern void DWCi_PostProcessSVConnectionHybrid(void);
extern void DWCi_SetMatchStatus(int state);
extern struct DWCstMatchControl *DWCi_GetMatchCnt(void);
extern int DWCi_StopMeshMaking(void);
extern void DWCi_ClearMeshMakingTempInfo(void);
extern void DWCi_SetHostStatus(int host);
extern void DWCi_InitClWaitTimeout(void);
extern int DWCi_NodeInfo_IsValid(struct DWCstNodeInfo *node);
extern int DWCi_NodeInfoList_InsertToTop(struct DWCstNodeInfo *newNode);
extern int DWCi_SendMatchCommand(unsigned char command, int profileID,
        u32 ip, unsigned short port, u32 *data, int len);
extern void DWCi_NodeInfo_Clear(struct DWCstNodeInfo *node);
extern int DWCi_HandleMatchCommandError(int error);
extern void DWCi_PostProcessConnectionSYNFinish(void);
extern void qr2_send_statechanged(void *qrec);
extern int DWCi_GetFriendListIndex(int profileID);
extern int DWCi_GPSetServerStatus(int matchType);
extern int DWCi_HandleGPError(int result);
extern void DWCi_ResetLastSomeDataRecvTimeByAidAll(void);
extern void ServerBrowserClear(void *sb);

void DWCi_PostProcessConnection(int type)
{
    u32 senddata[1];
    int result;
    struct DWCstMatchControl *p;

    switch (type)
    {
    case 0:
        if (DWCi_IsFullMesh())
            DWCi_PostProcessSVConnectionFullmesh();
        else
            DWCi_PostProcessSVConnectionHybrid();
        break;
    case 1:
        DWCi_SetMatchStatus(1);
        if (DWCi_GetMatchCnt()->f14 == 3)
            DWCi_GetMatchCnt()->f680 = DWCi_GetMatchCnt()->tempNewNodeInfo.profileID;
        break;
    case 2:
        DWCi_SetMatchStatus(1);
        if (DWCi_StopMeshMaking() == 1)
        {
            DWCi_ClearMeshMakingTempInfo();
            break;
        }
        DWCi_SetHostStatus(1);
        DWCi_GetMatchCnt()->f14 = 3;
        if (DWCi_GetMatchCnt()->f15 == 0 || DWCi_GetMatchCnt()->f15 == 1)
        {
            DWCi_GetMatchCnt()->f18 = 1;
            DWCi_GetMatchCnt()->f5dc = DWCi_GetMatchCnt()->f678;
        }
        DWCi_InitClWaitTimeout();
        if (DWCi_IsFullMesh())
        {
            if (DWCi_NodeInfo_IsValid(&DWCi_GetMatchCnt()->tempNewClientInfo))
            {
                struct DWCstNodeInfo *pNodeInfo;
                struct DWCstMatchControl *p;

                pNodeInfo = &DWCi_GetMatchCnt()->tempNewNodeInfo;
                senddata[0] = pNodeInfo->profileID;
                DWCi_NodeInfoList_InsertToTop(pNodeInfo);
                DWCi_GetMatchCnt()->tempNewNodeInfo =
                    DWCi_GetMatchCnt()->tempNewClientInfo;
                p = DWCi_GetMatchCnt();
                pNodeInfo = &p->tempNewNodeInfo;
                result = DWCi_SendMatchCommand(9,
                    p->tempNewNodeInfo.profileID,
                    pNodeInfo->ip,
                    pNodeInfo->port,
                    senddata, 1);
                DWCi_NodeInfo_Clear(&DWCi_GetMatchCnt()->tempNewClientInfo);
                if (DWCi_HandleMatchCommandError(result))
                    return;
            }
            DWCi_GetMatchCnt()->f62f = 1;
        }
        break;
    case 3:
        DWCi_GetMatchCnt()->f0d = 1;
        DWCi_PostProcessConnectionSYNFinish();
        DWCi_GetMatchCnt()->f798 = 0;
        qr2_send_statechanged(DWCi_GetMatchCnt()->f10);
        {
            int flag = (DWCi_GetMatchCnt()->f680 == 0);
            struct DWCstMatchControl *p = DWCi_GetMatchCnt();
            result = DWCi_GetFriendListIndex(DWCi_GetMatchCnt()->f680);
            p->f770(0, 0, flag, 0, result, DWCi_GetMatchCnt()->f774);
        }
        if (DWCi_GetMatchCnt()->f14 == 2)
        {
            if (DWCi_HandleGPError(DWCi_GPSetServerStatus(-1)))
                return;
            DWCi_SetMatchStatus(0xd);
        }
        else
        {
            DWCi_GPSetServerStatus(2);
            DWCi_SetMatchStatus(1);
        }
        DWCi_GetMatchCnt()->f680 = 0;
        DWCi_GetMatchCnt()->f62a = 0;
        DWCi_ResetLastSomeDataRecvTimeByAidAll();
        break;
    }

    if (DWCi_GetMatchCnt()->f5e0 != 0)
    {
        ServerBrowserClear(DWCi_GetMatchCnt()->f5e0);
        p = DWCi_GetMatchCnt();
        *(unsigned long long *)&p->f5f0 = 0;
    }
}
