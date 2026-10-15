/*
 * function: BOX2_MAIN_RefreshBoxUi
 * address:  0x021DD1E8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_UI_RefreshBoxName  0x021ED904  thumb  ov170
 *   BOX2_UI_SetCloseButtonPos  0x021ED9B4  thumb  ov170
 *   BOX2_UI_DeleteSlotIcon  0x021EDF5C  thumb  ov170
 *   BOX2_SEQ_DrawOffsetName  0x021EB85C  thumb  ov170
 *   BOX2_UI_PutInfoBar  0x021EF738  thumb  ov170
 *
 * Five-step reset: fold the delta, rebuild the queue object,
 *   re-run the frame update, clear the flag and re-stage channel 9.
 */
#include "../include/Obj00000.h"


struct WinMgr;
extern void BOX2_UI_RefreshBoxName(unsigned char *p);
extern void BOX2_UI_SetCloseButtonPos(int);
extern void BOX2_UI_DeleteSlotIcon(unsigned char *p);
extern void BOX2_SEQ_DrawOffsetName(unsigned char *p, int i);
extern void BOX2_UI_PutInfoBar(struct WinMgr *mgr);
void BOX2_MAIN_RefreshBoxUi(char *p)
{
    BOX2_UI_RefreshBoxName((unsigned char *)p);
    BOX2_UI_SetCloseButtonPos(*(int *)&((struct Obj00000 *)p)->f2C);
    BOX2_UI_DeleteSlotIcon((unsigned char *)p);
    BOX2_SEQ_DrawOffsetName((unsigned char *)p, 0);
    BOX2_UI_PutInfoBar(*(struct WinMgr **)(*(int *)&((struct Obj00000 *)p)->f2C + 0x74));
}
