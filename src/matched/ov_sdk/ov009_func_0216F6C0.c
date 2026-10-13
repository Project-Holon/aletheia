/*
 * function: DWCi_CloseMatch
 * address:  0x0216F6C0
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Resets the match state: frees the server browser and negotiation data and clears the node lists.
 *
 * symbols:
 *   g_021AAA20  0x021AAA20  data
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_0219ED4C  0x0219ED4C  arm  ov009
 *   func_02176B34  0x02176B34  arm  ov009
 *   DWCi_SetMatchStatus  0x02175F4C  arm  ov009
 *   DWC_Free  0x0205A1B0  arm
 *   DWCi_ClearGameMatchKeys  0x02173B18  arm  ov009
 *   DWCi_NodeInfoList_Clear  0x0217601C  arm  ov009
 *   DWCi_TempNewNodeInfo_Clear  0x0217653C  arm  ov009
 *   DWCi_GPSetServerStatus  0x0216F20C  arm  ov009
 */

#include "../include/G_NNThinkGlobal.h"

extern struct NNThinkGlobal g_021AAA20;
struct ServerBrowser;
extern int func_02175F3C(void);
extern void func_0219ED4C(struct ServerBrowser *sb);
extern void func_02176B34(void);
extern void DWCi_SetMatchStatus(int state);
extern void DWC_Free(int kind, void *p, int size);
extern void DWCi_ClearGameMatchKeys(void);
extern void DWCi_NodeInfoList_Clear(void);
extern void DWCi_TempNewNodeInfo_Clear(void);
extern int DWCi_GPSetServerStatus(int status);

void DWCi_CloseMatch(void)
{
    if (func_02175F3C() == 0) {
        return;
    }
    if (*(void **)(func_02175F3C() + 0x5e0) != 0) {
        if (*(int *)(((char *)&g_021AAA20) + 0x14) != 0) {
            *(int *)(((char *)&g_021AAA20) + 0x10) = 1;
        } else {
            func_0219ED4C(*(void **)(func_02175F3C() + 0x5e0));
            *(void **)(func_02175F3C() + 0x5e0) = 0;
        }
    }
    func_02176B34();
    DWCi_SetMatchStatus(0);
    if (*(void **)(((char *)&g_021AAA20) + 0xc) != 0) {
        DWC_Free(4, *(void **)(((char *)&g_021AAA20) + 0xc), 0);
        *(void **)(((char *)&g_021AAA20) + 0xc) = 0;
    }
    DWCi_ClearGameMatchKeys();
    *(unsigned char *)(func_02175F3C() + 0x4c) = 1;
    DWCi_NodeInfoList_Clear();
    DWCi_TempNewNodeInfo_Clear();
    *(int *)(func_02175F3C() + 0x7c4) = 1;
    DWCi_GPSetServerStatus(1);
}
