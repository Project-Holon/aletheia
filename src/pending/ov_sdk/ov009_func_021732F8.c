/*
 * function: DWCi_ProcessMatchSynTimeout
 * address:  0x021732F8
 * packet:   pkt_ov009_021732F8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker: codegen, 4 bytes short (560 vs 564).  Everything matches except the
 *          aid read.  The original at 0x021734B8 is
 *            bl DWCi_GetMatchCnt ; add r0, r0, #0x154 ; ldrb r5, [r0, #0x416]
 *          (0x154 + 0x416 = 0x56a: an inner object's base offset kept apart from
 *          its field offset).  dsi/1.1p1 folds the pair into a single
 *          `ldrb r5, [r0, #0x56a]` for every spelling tried: flat `->f_56a`,
 *          a nested struct member, `*(u8*)((char*)cnt + 0x56a)`, a
 *          `volatile` cast, and a `static inline` helper taking the inner
 *          object (the helper's call site does produce the `add #0x154`, but
 *          the inliner then folds the field into it).  A non-`inline` static
 *          helper is not inlined here, so its call site is +4 bytes (568).
 *          The vendor object is stamped 4.0.0.1025; the fold looks like a
 *          1024-vs-1025 difference in the inliner's displacement folding.
 *
 * measured (U23): the 1025 stamp makes ../2.0/* the permitted check, and it does split the
 *   address -- ../2.0/base emits `add r0,r0,#0x154 ; ldrb r4,[r0,#0x416]` -- but at 568
 *   bytes (image 564) with 416 concrete diffs, i.e. the whole allocation differs there, and
 *   all eleven 2.0 trees are byte-identical to each other. dsi/1.1p1 keeps the 560-byte fold.
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

struct DWCstMatchControl
{
    u8 pad0[0x56a];
    u8 f_56a;
    u8 pad1[0x57c - 0x56b];
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

struct DWCstNodeInfo
{
    int f0;
    u8 pad[0x16 - 4];
    u8 f16;
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
    u8 aid;

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
            aid = DWCi_GetMatchCnt()->f_56a;
            if (!(DWCi_GetMatchCnt()->f_650 & (1 << aid)))
                DWCi_SendMatchSynPacket(aid, 2);
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

