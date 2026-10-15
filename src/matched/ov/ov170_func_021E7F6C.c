/*
 * function: BOX2_SEQ_StateSummaryE
 * address: 0x021E7F6C
 * packet: pkt_ov170_021E7F6C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_UI_MoveCursor 0x021EE364 thumb ov170
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb ov170
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb ov170
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb ov170
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb ov170
 *   BOX2_UI_RepenTopBar 0x021EF6CC thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb ov170
 *   BOX2_MAIN_UpdateWindowMove 0x021E01A8 thumb ov170
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23927.h"
struct WinMgr;
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
extern void BOX2_UI_ToggleSlotPair(char *w, int a);
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern void BOX2_SEQ_ShowWindowObject(char *w, int v);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_UI_RepenTopBar(struct WinMgr *mgr);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_UpdateWindowMove(char *p);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
#define WORK(p) (*(char **)((p) + 0x2C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
int BOX2_SEQ_StateSummaryE(unsigned char *p)
{
    switch (((struct Obj23927 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24) {
    case 0:
        BOX2_UI_MoveCursor((char **)p, 0, 10);
        break;
    case 1:
        BOX2_UI_ToggleSlotPair(WORK(p), 1);
        BOX2_UI_MoveCursor((char **)p, 2, 0x25);
        break;
    case 2:
    default:
        if (p[0x16] < 0x1E) {
            BOX2_UI_ToggleSlotPair(WORK(p), 1);
            BOX2_UI_MoveCursor((char **)p, 3, 0x27);
        } else {
            BOX2_UI_MoveCursor((char **)p, 5, 0xC);
        }
        break;
    }
    BOX2_SEQ_SetCursorDraw((char **)p, 0);
    BOX2_SEQ_ShowWindowObject(WORK(p), 0x18);
    BOX2_MAIN_RefreshCursorBox((char *)p);
    if (p[0x16] < 0x1E)
        BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
    BOX2_SEQ_SetSlotActors((char *)p, 2, 0);
    BOX2_UI_RepenTopBar(*(struct WinMgr **)(WORK(p) + 0x74));
    GFL_USE_PlaySeDefaultVolume(0x669);
    return BOX2_SEQ_SetSeqThird((char *)p, (int)((int (*)(unsigned char *))BOX2_MAIN_UpdateWindowMove), BOX2_SEQ_ReturnAfterClear((char *)p, 0xE));
}
