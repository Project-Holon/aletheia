/*
 * function: DWCi_ShutdownMatch
 * address:  0x0216F334
 * packet:   pkt_ov009_0216F334
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ShutdownMatch (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_SetMatchCnt         0x02175F1C arm
 *   DWC_Free                 0x0205A1B0 arm
 *   DWCi_ClearGameMatchKeys  0x02173B18 arm
 *   s_bInNNThink             0x021AAA20 data
 */

typedef unsigned char u8;

struct NNThinkGlobal
{
    int  f0;
    int  f4;
    int  f8;
    void *pC;
};

extern void DWCi_SetMatchCnt(void *pCnt);
extern void DWC_Free(int name, void *ptr, int flag);
extern void DWCi_ClearGameMatchKeys(void);
extern struct NNThinkGlobal s_bInNNThink;

void DWCi_ShutdownMatch(void)
{
    DWCi_SetMatchCnt(0);
    if (s_bInNNThink.pC != 0) {
        DWC_Free(4, s_bInNNThink.pC, 0);
        s_bInNNThink.pC = 0;
    }
    DWCi_ClearGameMatchKeys();
}
