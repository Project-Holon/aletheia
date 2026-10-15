/*
 * function: BOX2_MAIN_RefreshCursorBox
 * address:  0x021DD14C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_DeleteSlotObjects  0x021EE038  thumb  ov170
 *   BOX2_UI_PutFadeFrame  0x021EF660  thumb  ov170
 *
 * Forward the three status bytes at p+0x1f..0x21 with p, then
 *   refresh.  Bytes 0x20 and 0x21 go through a computed address because 32 is
 *   past the ldrb immediate range -- and the fields are unsigned char (ldrb).
 */
#include "../include/Obj00000.h"


struct WinMgr;
extern void BOX2_UI_DeleteSlotObjects(char *, int, int, int);
extern void BOX2_UI_PutFadeFrame(struct WinMgr *mgr);
void BOX2_MAIN_RefreshCursorBox(char *p)
{
    BOX2_UI_DeleteSlotObjects(p, ((struct Obj00000 *)p)->f1F, ((struct Obj00000 *)p)->f20,
                  ((struct Obj00000 *)p)->f21);
    BOX2_UI_PutFadeFrame(*(struct WinMgr **)(*(int *)&((struct Obj00000 *)p)->f2C + 0x74));
}
