/*
 * unit: yes
 * function: BOX2_SEQ_SetBox2MainD, BOX2_SEQ_StateCloseItemC
 * address: 0x021E79C8
 * packet: pkt_ov170_021E79C8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_UI_OpenListPack 0x021EF57C thumb ov170
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb ov170
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb ov170
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb ov170
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb ov170
 *   BOX2_MAIN_SceneWaitScroll 0x021E070C thumb ov170
 *   BOX2_SEQ_SetState 0x021E8FE0 thumb ov170
 *   BOX2_SEQ_GotoBox2Ui 0x021E95CC thumb ov170
 */
struct WinMgr;
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern void BOX2_SEQ_ShowWindowObject(char *w, int v);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_SceneWaitScroll(char *p);
extern int BOX2_SEQ_SetState(char *p, int v);
extern int BOX2_SEQ_GotoBox2Ui(unsigned char *p, unsigned char v);
#define WORK(p) (*(char **)((p) + 0x2C))
void BOX2_SEQ_SetBox2MainD(unsigned char *p)
{
    BOX2_UI_OpenListPack(*(struct WinMgr **)(WORK(p) + 0x74));
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    BOX2_SEQ_ShowWindowObject(WORK(p), 0x18);
    BOX2_MAIN_RefreshCursorBox((char *)p);
    BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_SceneWaitScroll, BOX2_SEQ_SetState((char *)p, 0x4B));
}
int BOX2_SEQ_StateCloseItemC(unsigned char *p)
{
    return BOX2_SEQ_GotoBox2Ui(p, 0);
}
