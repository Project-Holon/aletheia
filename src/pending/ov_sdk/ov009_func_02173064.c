/*
 * function: DWCi_SendMatchSynPacket
 * address:  0x02173064
 * packet:   pkt_ov009_02173064
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker: register allocation, compiled 624 vs 660.  The control flow,
 *          switch arms, packing and allocation/free calls all reproduce the
 *          original, but mwccarm 1.1p1 keeps `sendSize` in r6 and `pSendBuf`
 *          in r5 with only 8 saved registers, while the vendor object keeps
 *          `sendSize` in fp (r11), `pSendBuf` in r6 and `i` in r5.  The extra
 *          live callee-saved value (and the r3 alignment push) never appears
 *          under 1.1p1 regardless of declaration order tried.
 *
 * sdk:      DWCi_SendMatchSynPacket (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_TempNewNodeInfo_IsValid     0x02176554 arm
 *   DWCi_GetMatchCnt                 0x02175F3C arm
 *   DWC_Alloc                        0x0205A16C arm
 *   DWCi_IsFullMesh                  0x0217695C arm
 *   DWCi_NodeInfoList_GetCount       0x0217603C arm
 *   DWCi_NodeInfoList_GetNodeInfoForIndex 0x0217637C arm
 *   DWCi_SendReliable                0x02176EB0 arm
 *   DWC_Free                         0x0205A1B0 arm
 *   OS_GetTick                       0x020870D0 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct DWCstNodeInfo
{
    u32 f0;
    u32 f4;
    u32 f8;
    u16 f_c;
    u16 f_e;
    u8 pad0[0x16 - 0x10];
    u8 f16;
    u8 f17;
    u8 pad1[0x24 - 0x18];
    u32 f_24;
};

struct DWCstMatchControl
{
    u8 pad0[0x554];
    struct DWCstNodeInfo myNode;
    u8 pad1[0x630 - 0x57c];
    u16 f_630;
    u8 pad2[0x658 - 0x632];
    unsigned long long f_658;
    u8 pad3[0x7c8 - 0x660];
    u32 f_7c8;
};

extern int DWCi_TempNewNodeInfo_IsValid(void);
extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern void * DWC_Alloc(int name, unsigned long size);
extern int DWCi_IsFullMesh(void);
extern int DWCi_NodeInfoList_GetCount(void);
extern struct DWCstNodeInfo * DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern int DWCi_SendReliable(u16 type, u8 aid, void * buffer, int size);
extern void DWC_Free(int name, void * ptr, int flag);
extern unsigned long long OS_GetTick(void);

void DWCi_SendMatchSynPacket(u8 aid, u16 type)
{
    struct DWCstNodeInfo * pNodeInfo;
    int sendCount;
    int clientCount;
    u32 * pSendBuf;
    int sendSize;
    unsigned long long tick;
    u8 buf[8];
    u8 i;

    sendSize = 4;
    pSendBuf = (u32 *)buf;

    switch (type) {
    case 2:
        if (DWCi_TempNewNodeInfo_IsValid() != 0 &&
            aid == DWCi_GetMatchCnt()->myNode.f16) {
            buf[0] = 1;
            break;
        }
        sendSize = 0x1c;
        pSendBuf = DWC_Alloc(4, sendSize);
        if (pSendBuf == 0)
            return;
        pSendBuf[0] = 0;
        pSendBuf[1] = (DWCi_GetMatchCnt()->myNode.f17 << 16) |
                      DWCi_GetMatchCnt()->myNode.f16;
        pSendBuf[2] = DWCi_GetMatchCnt()->myNode.f0;
        pSendBuf[3] = DWCi_GetMatchCnt()->myNode.f4;
        pSendBuf[4] = DWCi_GetMatchCnt()->myNode.f8;
        pSendBuf[5] = (DWCi_GetMatchCnt()->myNode.f_c << 16) |
                      DWCi_GetMatchCnt()->myNode.f_e;
        pSendBuf[6] = DWCi_GetMatchCnt()->myNode.f_24;
        break;
    case 3:
        buf[0] = DWCi_GetMatchCnt()->f_630;
        buf[1] = DWCi_GetMatchCnt()->f_630 >> 8;
        break;
    case 4:
        if (DWCi_TempNewNodeInfo_IsValid() == 0 ||
            aid != DWCi_GetMatchCnt()->myNode.f16)
            goto fourElse;
        if (DWCi_IsFullMesh() != 0)
            clientCount = 0;
        else
            clientCount = DWCi_NodeInfoList_GetCount() - 1;
        if (clientCount == 0) {
            buf[0] = 0;
            buf[1] = 0;
            buf[2] = 0;
            buf[3] = 0;
            sendSize = 8;
            pSendBuf[1] = DWCi_GetMatchCnt()->f_7c8;
            break;
        }
        sendSize = clientCount * 0x18 + 8;
        pSendBuf = DWC_Alloc(4, sendSize);
        if (pSendBuf == 0)
            return;
        pSendBuf[0] = clientCount;
        sendCount = 1;
        for (i = 0; i < clientCount; i++) {
            pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i + 1);
            pSendBuf[sendCount] = (pNodeInfo->f17 << 16) | pNodeInfo->f16;
            pSendBuf[sendCount + 1] = pNodeInfo->f0;
            pSendBuf[sendCount + 2] = pNodeInfo->f4;
            pSendBuf[sendCount + 3] = pNodeInfo->f8;
            pSendBuf[sendCount + 4] = (pNodeInfo->f_c << 16) | pNodeInfo->f_e;
            pSendBuf[sendCount + 5] = pNodeInfo->f_24;
            sendCount += 6;
        }
        pSendBuf[sendCount] = DWCi_GetMatchCnt()->f_7c8;
        break;
    fourElse:
        buf[0] = 0;
        buf[1] = 0;
        buf[2] = 0;
        buf[3] = 0;
        sendSize = 8;
        pSendBuf[1] = DWCi_GetMatchCnt()->f_7c8;
        break;
    }
    DWCi_SendReliable(type, aid, pSendBuf, sendSize);
    if (pSendBuf != (u32 *)buf)
        DWC_Free(4, pSendBuf, 0);
    tick = OS_GetTick();
    DWCi_GetMatchCnt()->f_658 = tick;
}
