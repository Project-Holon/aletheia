/*
 * function: DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID
 * address:  0x02176500
 * packet:   pkt_ov009_02176500
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID 0x021763AC arm
 *   DWCi_NodeInfoList_GetMyNodeInfo           0x02176344 arm
 *   DWCi_GetGT2Connection                     0x0216BAF4 arm
 */

typedef unsigned char u8;

struct DWCstNodeInfo
{
    u8 pad0[0x16];
    u8 aid;
};

extern struct DWCstNodeInfo * DWCi_NodeInfoList_GetNodeInfoForProfileID(int profileID);
extern struct DWCstNodeInfo * DWCi_NodeInfoList_GetMyNodeInfo(void);
extern void * DWCi_GetGT2Connection(unsigned char aid);

int DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID(int profileID)
{
    struct DWCstNodeInfo *pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForProfileID(profileID);

    if (pNodeInfo == 0)
        return 0;
    if (pNodeInfo == DWCi_NodeInfoList_GetMyNodeInfo())
        return 0;
    return DWCi_GetGT2Connection(pNodeInfo->aid) == 0;
}
