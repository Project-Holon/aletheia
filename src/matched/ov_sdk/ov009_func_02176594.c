/*
 * function: func_02176594
 * address:  0x02176594
 * packet:   pkt_ov009_02176594
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GetNextMeshMakeTryTick (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   func_02176344  0x02176344  arm  ov009
 *   OS_GetTick     0x020870D0  arm
 *   func_0217603C  0x0217603C  arm  ov009
 *   func_0217637C  0x0217637C  arm  ov009
 *   DWCi_GetGT2Connection  0x0216BAF4  arm  ov009
 */

typedef struct NodeInfo {
    unsigned char pad0[0x16];
    unsigned char aid;
} NodeInfo;

extern char *func_02176344(void);
extern unsigned long long OS_GetTick(void);
extern int func_0217603C(void);
extern char *func_0217637C(int index);
extern int DWCi_GetGT2Connection(int aid);

unsigned long long func_02176594(void)
{
    int existGT2Count;
    int i;
    int myNodeIndex;
    NodeInfo *pMyNodeInfo;
    unsigned long long tick;
    NodeInfo *pNodeInfo;

    pMyNodeInfo = (NodeInfo *)func_02176344();
    tick = OS_GetTick();
    tick += 0x17F898;
    existGT2Count = 0;
    myNodeIndex = 0;
    if (func_0217603C() > 2) {
        for (i = 1; i < func_0217603C(); i++) {
            pNodeInfo = (NodeInfo *)func_0217637C(i);
            if (pMyNodeInfo == pNodeInfo) {
                myNodeIndex = i;
            } else {
                DWCi_GetGT2Connection(pNodeInfo->aid);
                if (DWCi_GetGT2Connection(pNodeInfo->aid) != 0)
                    existGT2Count++;
            }
        }
    }
    tick += (long long)existGT2Count * 0x17F898;
    tick += ((unsigned long long)((func_0217603C() - 1 - myNodeIndex) * 6000) * 33514) >> 6;
    return tick;
}
