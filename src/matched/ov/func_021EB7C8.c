/*
 * function: BOX2_SEQ_AddNameFrame
 * address:  0x021EB7C8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_SEQ_DrawFrameDefault  0x021EB6F0  thumb  ov170
 *   BOX2_SEQ_AddBmpWinFrame  0x021EB708  thumb  ov170
 *
 * Stage 0x17/0x46 then hand the 0x14C word over with index 0xb.
 */
#include "../include/Obj01558.h"


struct WinMgr;
extern void BOX2_SEQ_DrawFrameDefault(int a, int b, int c);
extern void BOX2_SEQ_AddBmpWinFrame(void *m, unsigned i, void *d);
void BOX2_SEQ_AddNameFrame(char *p)
{
    BOX2_SEQ_DrawFrameDefault((int)p, 0x17, 0x46);
    BOX2_SEQ_AddBmpWinFrame(*(struct WinMgr **)(*(int *)&((struct Obj01558 *)p)->f2C + 0x74), 0xb,
                  (void *)(*(int *)(*(int *)&((struct Obj01558 *)p)->f2C + 0x14C)));
}
