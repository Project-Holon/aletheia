/*
 * file:     unit_0217576C_p07.c
 * unit:     yes
 * function: func_02176254, func_02176344
 * address:  0x02176254
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
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_021763AC  0x021763AC  arm  ov009
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

extern int func_02175F3C(void);
extern char *func_021763AC(int pid);
int func_02176254(int profileID);
char *func_02176344(void);


/*
 * sdk:      DWCi_NodeInfoList_RemoveProfileID (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02176254(int profileID)
{
    int removeIndex;

    if (((MatchCnt *)func_02175F3C())->nodeCount == 0)
        return 0;
    for (removeIndex = 0; removeIndex < ((MatchCnt *)func_02175F3C())->nodeCount; removeIndex++) {
        if (profileID == ((MatchCnt *)func_02175F3C())->nodes[removeIndex].profileID)
            break;
    }
    if (removeIndex == ((MatchCnt *)func_02175F3C())->nodeCount)
        return 0;
    for (; removeIndex < ((MatchCnt *)func_02175F3C())->nodeCount - 1; removeIndex++)
        ((MatchCnt *)func_02175F3C())->nodes[removeIndex] = ((MatchCnt *)func_02175F3C())->nodes[removeIndex + 1];
    ((MatchCnt *)func_02175F3C())->nodeCount--;
    return 1;
}


/*
 * Passes the word at +0x678 of the module block on.
 */
char *func_02176344(void)
{
    return func_021763AC(*(int *)(func_02175F3C() + 0x678));
}
