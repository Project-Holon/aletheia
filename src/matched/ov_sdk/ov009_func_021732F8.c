/*
 * function: DWCi_ProcessMatchSynTimeout
 * address:  0x021732F8
 * packet:   pkt_ov009_021732F8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 2026-10-01 lane07: EXACT.  The aid read is `node = &DWCi_GetMatchCnt()->tempNewNodeInfo;
 *          node->aid` (DWARF local `node`, tempNewNodeInfo at 0x554).  0x554 is not an ARM
 *          immediate, so the compiler splits it as add #0x154 plus 0x400 folded into the
 *          ldrb offset (0x416).  The old blocker modelled a flat byte at 0x56a.
 * sdk:      DWCi_ProcessMatchSynTimeout (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt                 0x02175F3C arm
 *   OS_GetTick                       0x020870D0 arm
 *   _ll_udiv                         0x0209C00C arm
 *   DWCi_NodeInfoList_GetCount       0x0217603C arm
 *   DWCi_NodeInfoList_GetServerNodeInfo 0x02176358 arm
 *   DWCi_CancelPreConnectedClientProcess 0x02172124 arm
 *   DWCi_ServerSynTimeoutExec        0x0217352C arm
 *   DWCi_NodeInfoList_GetNodeInfoForIndex 0x0217637C arm
 *   DWCi_SendMatchSynPacket          0x02173064 arm
 *   DWCi_SendTypeMatchAck            0x021735A4 arm
 *   DWCi_PostProcessConnection       0x02172254 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct DWCstMatchControl;

struct DWCstNodeInfo
{
    int f0;
    u8 pad[0x16 - 4];
    u8 f16;
    u8 pad17[0x28 - 0x17];
};

struct DWCstMatchControl
{
    u8 pad0[0x554];
    struct DWCstNodeInfo tempNewNodeInfo;
    u32 f_57c;
    u8 pad2[0x61c - 0x580];
    int f_61c;
    u8 pad3[0x62c - 0x620];
    u8 f_62c;
    u8 pad4[0x630 - 0x62d];
    u16 f_630;
    u8 pad5[0x650 - 0x632];
    u32 f_650;
    u8 pad6[0x658 - 0x654];
    unsigned long long f_658;
    u8 pad7[0x670 - 0x660];
    unsigned long long f_670;
};


extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern unsigned long long OS_GetTick(void);
extern int DWCi_NodeInfoList_GetCount(void);
extern struct DWCstNodeInfo * DWCi_NodeInfoList_GetServerNodeInfo(void);
extern int DWCi_CancelPreConnectedClientProcess(int profileID);
extern void DWCi_ServerSynTimeoutExec(void);
extern struct DWCstNodeInfo * DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern void DWCi_SendMatchSynPacket(u8 aid, u16 type);

extern void DWCi_SendTypeMatchAck(void);
extern void DWCi_PostProcessConnection(int type);

int DWCi_ProcessMatchSynTimeout(void)
{
    struct DWCstNodeInfo * node;
    unsigned long long passTime;
    int i;

    if (DWCi_GetMatchCnt()->f_61c == 8 ||
        DWCi_GetMatchCnt()->f_61c == 0x13 ||
        DWCi_GetMatchCnt()->f_61c == 0x17 ||
        DWCi_GetMatchCnt()->f_61c == 0x14) {
        passTime = OS_GetTick() - DWCi_GetMatchCnt()->f_658;
        passTime = passTime * 64 / 0x82ea;
    } else {
        return 1;
    }

    switch (DWCi_GetMatchCnt()->f_61c) {
    case 8:
        if (passTime <= DWCi_GetMatchCnt()->f_670)
            break;
        DWCi_NodeInfoList_GetCount();
        DWCi_GetMatchCnt()->f_57c = 0;
        node = DWCi_NodeInfoList_GetServerNodeInfo();
        if (DWCi_CancelPreConnectedClientProcess(node->f0) == 0)
            return 0;
        break;
    case 0x13:
        if (passTime <= 0x1770)
            break;
        DWCi_GetMatchCnt()->f_62c++;
        if (DWCi_GetMatchCnt()->f_62c > 5) {
            DWCi_GetMatchCnt()->f_62c = 0;
            passTime = OS_GetTick();
            DWCi_GetMatchCnt()->f_658 = passTime;
            DWCi_ServerSynTimeoutExec();
        } else {
            for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++) {
                node = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
                if (DWCi_GetMatchCnt()->f_650 & (1 << node->f16))
                    continue;
                DWCi_SendMatchSynPacket(node->f16, 2);
            }
            node = &DWCi_GetMatchCnt()->tempNewNodeInfo;
            if (!(DWCi_GetMatchCnt()->f_650 & (1 << node->f16)))
                DWCi_SendMatchSynPacket(node->f16, 2);
        }
        break;
    case 0x17:
        if (passTime <= 0xbb8)
            break;
        DWCi_SendTypeMatchAck();
        break;
    case 0x14:
        if (passTime <= DWCi_GetMatchCnt()->f_630)
            break;
        DWCi_PostProcessConnection(3);
        break;
    }
    return 1;
}

