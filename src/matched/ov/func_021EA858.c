/*
 * function: BOX2_SEQ_ResetEntryB
 * address:  0x021EA858
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_CloseInfoBar  0x021EF75C  thumb  ov170
 *   BOX2_SEQ_SetSeqThird  0x021E8FC0  thumb  ov170
 *
 * Same forward as BOX2_SEQ_ResetEntry but after restarting the queue.
 */
#include "../include/Obj00000.h"


struct WinMgr;
extern void BOX2_UI_CloseInfoBar(struct WinMgr *mgr);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
int BOX2_SEQ_ResetEntryB(char *p, int a)
{
    BOX2_UI_CloseInfoBar(*(struct WinMgr **)(*(int *)&((struct Obj00000 *)p)->f2C + 0x74));
    return BOX2_SEQ_SetSeqThird(p, 0x021E01E1, a);
}
