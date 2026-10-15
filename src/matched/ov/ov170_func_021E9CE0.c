/*
 * function: BOX2_SEQ_GotoRightPanelB
 * address:  0x021E9CE0
 * packet:   pkt_ov170_021E9CE0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_StopSeq 0x021DD16C thumb
 *   BOX2_UI_IsListOpen 0x021EF5E8 thumb
 *   BOX2_UI_OpenListPack 0x021EF57C thumb
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_IsSeqStep 0x021E0128 thumb
 */

struct WinMgr;
extern void BOX2_MAIN_StopSeq(unsigned char *p, int dir);
extern int BOX2_UI_IsListOpen(struct WinMgr *mgr);
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern void BOX2_SEQ_ShowWindowObject(char *w, int v);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_UI_ShowWindowA(char *w);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsSeqStep(char *p);

#define WORK(p) (*(char **)((p) + 0x2C))

int BOX2_SEQ_GotoRightPanelB(char *p, int a, int n)
{
    BOX2_MAIN_StopSeq((unsigned char *)p, 1);
    if (BOX2_UI_IsListOpen(*(struct WinMgr **)(WORK(p) + 0x74)) == 1) {
        BOX2_UI_OpenListPack(*(struct WinMgr **)(WORK(p) + 0x74));
        BOX2_SEQ_ShowWindowObject(WORK(p), 0x18);
        BOX2_MAIN_RefreshCursorBox(p);
        if (a == 1)
            BOX2_UI_ShowWindowA(WORK(p));
    }
    return BOX2_SEQ_SetSeqThird(p, (int)BOX2_MAIN_IsSeqStep, n);
}
