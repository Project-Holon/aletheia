/*
 * function: DWCi_PostProcessConnectionSYNFinishHybrid
 * address:  0x0217253C
 * packet:   pkt_ov009_0217253C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_PostProcessConnectionSYNFinishHybrid (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt                     0x02175F3C arm
 *   DWCi_TempNewNodeInfo_IsValid         0x02176554 arm
 *   DWCi_NodeInfoList_Append             0x021760FC arm
 *   DWCi_TempNewNodeInfo_Clear           0x0217653C arm
 *   DWCi_NodeInfoList_GetCount           0x0217603C arm
 *   DWCi_NodeInfoList_InsertToTop        0x0217604C arm
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID 0x021763AC arm
 *   DWCi_CloseConnectionHard             0x0216BEA4 arm
 *   DWCi_NodeInfoList_GetNodeInfoForAID  0x02176410 arm
 */

typedef unsigned char u8;

struct DWCstNodeInfo
{
    int profileID;           /* +0x00 */
    u8 pad0[0x16 - 4];
    u8 aid;                  /* +0x16 */
    u8 pad1[0x28 - 0x17];
};

struct DWCstMatchControl
{
    u8 pad0[0x14];
    u8 qr2MatchType;         /* +0x14 */
    u8 pad1[0x554 - 0x15];
    struct DWCstNodeInfo tempNewNodeInfo;    /* +0x554 */
    struct DWCstNodeInfo tempNewClientInfo;  /* +0x57c */
};

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern int DWCi_TempNewNodeInfo_IsValid(void);
extern int DWCi_NodeInfoList_Append(struct DWCstNodeInfo *newNode);
extern void DWCi_TempNewNodeInfo_Clear(void);
extern int DWCi_NodeInfoList_GetCount(void);
extern int DWCi_NodeInfoList_InsertToTop(struct DWCstNodeInfo *newNode);
extern struct DWCstNodeInfo * DWCi_NodeInfoList_GetNodeInfoForProfileID(int profileID);
extern int DWCi_CloseConnectionHard(unsigned char aid);
extern struct DWCstNodeInfo * DWCi_NodeInfoList_GetNodeInfoForAID(unsigned char aid);

void DWCi_PostProcessConnectionSYNFinishHybrid(void)
{
    struct DWCstMatchControl *p;

    if (DWCi_GetMatchCnt()->qr2MatchType == 2) {
        if (DWCi_TempNewNodeInfo_IsValid() == 0)
            return;
        DWCi_NodeInfoList_Append(&DWCi_GetMatchCnt()->tempNewNodeInfo);
        DWCi_TempNewNodeInfo_Clear();
        return;
    }
    if (DWCi_NodeInfoList_GetCount() == 1) {
        DWCi_NodeInfoList_InsertToTop(&DWCi_GetMatchCnt()->tempNewNodeInfo);
        DWCi_TempNewNodeInfo_Clear();
        return;
    }
    p = DWCi_GetMatchCnt();
    {
        struct DWCstNodeInfo *newNode = &p->tempNewClientInfo;
        struct DWCstNodeInfo *n;

        if (newNode->profileID == 0)
            return;
        n = DWCi_NodeInfoList_GetNodeInfoForProfileID(newNode->profileID);
        if (n != 0)
            DWCi_CloseConnectionHard(n->aid);
        n = DWCi_NodeInfoList_GetNodeInfoForAID(newNode->aid);
        if (n != 0)
            DWCi_CloseConnectionHard(n->aid);
        DWCi_NodeInfoList_Append(newNode);
        newNode->profileID = 0;
    }
}
