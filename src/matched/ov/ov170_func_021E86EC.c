/*
 * function: BOX2_SEQ_StateMoveMenuB
 * address: 0x021E86EC
 * packet: pkt_ov170_021E86EC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb ov170
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb ov170
 *   BOX2_UI_OpenListPack 0x021EF57C thumb ov170
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb ov170
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_RefreshBoxUiAndWait 0x021EA83C thumb ov170
 *   BOX2_UI_SetMiniIconVisible 0x021EE008 thumb ov170
 *   BOX2_UI_MoveCursor 0x021EE364 thumb ov170
 *   BOX2_SEQ_PrintIndexedMessage 0x021EBC28 thumb ov170
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb ov170
 */
struct WinMgr;
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern void BOX2_SEQ_ShowWindowObject(char *w, int v);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowMoving(char *p);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern int BOX2_SEQ_RefreshBoxUiAndWait(char *p, int a);
extern void BOX2_UI_SetMiniIconVisible(char *p, int a, int b);
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
extern void BOX2_SEQ_PrintIndexedMessage(unsigned char *p, int a, int b);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
#define WORK(p) (*(char **)((p) + 0x2C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
int BOX2_SEQ_StateMoveMenuB(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        *(unsigned char *)(WORK(p) + 0xA17A) = 1;
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_ShowWindowObject(WORK(p), 0x18);
        BOX2_MAIN_RefreshCursorBox((char *)p);
        BOX2_UI_OpenListPack(*(struct WinMgr **)(WORK(p) + 0x74));
        STEP(p)++;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowMoving, 0x60);
    case 1:
        p[0x19] = p[0x14];
        STEP(p)++;
        GFL_USE_PlaySeDefaultVolume(0x669);
        return BOX2_SEQ_RefreshBoxUiAndWait((char *)p, 0x60);
    case 2:
        STEP(p) = 0;
        BOX2_UI_SetMiniIconVisible((char *)p, 0, 1);
        BOX2_UI_MoveCursor((char **)p, 0xC, 1);
        *(int *)(WORK(p) + 0xA168) = 1;
        BOX2_SEQ_PrintIndexedMessage(p, 1, 0x19);
        BOX2_UI_DeleteSlotObjects((char *)p, 0, 1, 1);
        return 0x61;
    }
    return 0x60;
}
