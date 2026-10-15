/*
 * function: BOX2_SEQ_SetBox2UiC
 * address:  0x021E498C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_OpenListPack  0x021EF57C  thumb  ov170
 *   BOX2_SEQ_SetSlotDim  0x021ED6E4  thumb  ov170
 *   BOX2_SEQ_ShowWindowObject  0x021EBA5C  thumb  ov170
 *   BOX2_MAIN_RefreshCursorBox  0x021DD14C  thumb  ov170
 *   BOX2_UI_ShowWindowA  0x021EF670  thumb  ov170
 *   BOX2_UI_ShowWindowB  0x021EF68C  thumb  ov170
 *   BOX2_SEQ_SetState  0x021E8FE0  thumb  ov170
 *   BOX2_SEQ_SetSeqThird  0x021E8FC0  thumb  ov170
 *
 * Wrapper family member: BOX2_UI_ShowWindowA and state 0x23.
 */
#include "../include/Obj00000.h"


struct WinMgr;
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern void BOX2_SEQ_ShowWindowObject(char *p, int i);
extern void BOX2_MAIN_RefreshCursorBox(char *);
extern void BOX2_UI_ShowWindowA(char *p);
extern void BOX2_UI_ShowWindowB(char *p);
extern int BOX2_SEQ_SetState(char *, int);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
void BOX2_SEQ_SetBox2UiC(char *p)
{
    BOX2_UI_OpenListPack(*(struct WinMgr **)(*(int *)&((struct Obj00000 *)p)->f2C + 0x74));
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    BOX2_SEQ_ShowWindowObject((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 0x18);
    BOX2_MAIN_RefreshCursorBox(p);
    BOX2_UI_ShowWindowA((char *)(*(int *)&((struct Obj00000 *)p)->f2C));
    BOX2_SEQ_SetSeqThird(p, 0x21E070D, BOX2_SEQ_SetState(p, 0x23));
}
