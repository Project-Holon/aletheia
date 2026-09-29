/*
 * function: func_02176254
 * address:  0x02176254
 * packet:   pkt_ov009_02176254
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_NodeInfoList_RemoveProfileID (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 */

typedef struct NodeInfo {
    int profileID;
    unsigned char pad0[0x28 - 4];
} NodeInfo;

typedef struct MatchCnt {
    unsigned char pad0[0x50];
    int nodeCount;
    NodeInfo nodes[1];
} MatchCnt;

extern MatchCnt *func_02175F3C(void);

int func_02176254(int profileID)
{
    int removeIndex;

    if (func_02175F3C()->nodeCount == 0)
        return 0;
    for (removeIndex = 0; removeIndex < func_02175F3C()->nodeCount; removeIndex++) {
        if (profileID == func_02175F3C()->nodes[removeIndex].profileID)
            break;
    }
    if (removeIndex == func_02175F3C()->nodeCount)
        return 0;
    for (; removeIndex < func_02175F3C()->nodeCount - 1; removeIndex++)
        func_02175F3C()->nodes[removeIndex] = func_02175F3C()->nodes[removeIndex + 1];
    func_02175F3C()->nodeCount--;
    return 1;
}
