/*
 * function: BOX2_SEQ_StateCursorMoveC
 * address:  0x021E75E0
 * packet:   pkt_ov170_021E75E0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of src/matched/BOX2_SEQ_StateItemMenuE.c (the switch tail without the preamble).
 *
 * symbols:
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_UI_IsListOpen 0x021EF5E8 thumb
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   BOX2_UI_MoveCursorBetweenIcons 0x021EEF74 thumb
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb
 *   BOX2_MAIN_ClearCursorBox 0x021DF0BC thumb
 *   BOX2_SEQ_GotoRightPanelA 0x021E9C94 thumb
 *   BOX2_SEQ_GotoRightPanelB 0x021E9CE0 thumb
 *   BOX2_SEQ_GotoBox2Main 0x021E949C thumb
 *   BOX2_SEQ_GotoBox2MainWithSlot 0x021E954C thumb
 *   BOX2_SEQ_SetState 0x021E8FE0 thumb
 *   BOX2_SEQ_SetSeqSecond 0x021E8FD0 thumb
 *   BOX2_UI_CursorInputPage 0x021EEEA4 thumb
 *   BOX2_SEQ_RefreshCursorSlot 0x021ED588 thumb
 *   BOX2_SEQ_StatePushSlot 0x021E78F4 thumb
 *   BOX2_MAIN_SceneWaitScroll 0x021E070C thumb
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb
 *   BOX2_SEQ_DrawFrameList 0x021EB988 thumb
 *   BOX2_UI_OpenListPack 0x021EF57C thumb
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb
 *   BOX2_UI_CloseListPack 0x021EF534 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   d_021EF8EC 0x021EF8EC data a1
 */

typedef struct {
    unsigned char pad0[2];
    unsigned char pad2[0x26];
    unsigned short h28;
    unsigned char b2A;
    unsigned char b2B;
} Top;

typedef struct {
    Top *top;
    unsigned char pad4[0x13 - 4];
    unsigned char b13;
    unsigned char b14;
    unsigned char pad15;
    unsigned char b16;
    unsigned char b17;
    unsigned char pad18[3];
    unsigned char b1B;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char pad1D[0x24 - 0x1D];
    int x24;
    int x28;
    char *work;
} Obj;

struct WinMgr;
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern int BOX2_UI_IsListOpen(struct WinMgr *mgr);
extern void BOX2_MAIN_ChangeBoxFormPreserve(char *p, int b);
typedef unsigned char  u8;
struct Sound;
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern void BOX2_UI_SetCursorPos(char **p, unsigned idx);
extern void BOX2_MAIN_ResetBoxView(char *p);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
extern void BOX2_MAIN_ClearCursorBox(unsigned char *p);
extern int BOX2_SEQ_GotoRightPanelA(char *p, int a, int n);
extern int BOX2_SEQ_GotoRightPanelB(char *p, int a, int n);
extern int BOX2_SEQ_GotoBox2Main(char *p, int a, int b);
extern int BOX2_SEQ_GotoBox2MainWithSlot(Obj *p, int id, int lo, int arg);
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern void BOX2_UI_MoveCursorBetweenIcons(char *w, int k, int v);
extern int BOX2_SEQ_SetState(char *p, int v);
extern int BOX2_SEQ_SetSeqSecond(char *p, int a);

#define OBJ(p) (*(void **)((p)->work + 0x70))
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))

extern unsigned BOX2_UI_CursorInputPage(char *p);
extern void BOX2_SEQ_RefreshCursorSlot(char *p);
extern int BOX2_SEQ_StatePushSlot(char *p);
extern int BOX2_MAIN_SceneWaitScroll(char *p);
extern int BOX2_MAIN_IsWindowMoving(char *p);
extern void BOX2_SEQ_DrawFrameList(Obj *p, const void *e, unsigned n);
extern const unsigned char d_021EF8EC[];
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern void BOX2_SEQ_ShowWindowObject(char *w, int v);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_UI_CloseListPack(struct WinMgr *mgr);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);

int BOX2_SEQ_StateCursorMoveC(Obj *p)
{
    unsigned r = BOX2_UI_CursorInputPage((char *)p);
    switch (r) {
    case 0x1E:
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        break;
    case 0x1F:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        CURSOR_MOVE_SetCurrent(OBJ(p), 0x1E);
        BOX2_UI_SetCursorPos((char **)p, 0x1E);
        return BOX2_SEQ_GotoRightPanelA((char *)p, 0, 0x4B);
    case 0x20:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        CURSOR_MOVE_SetCurrent(OBJ(p), 0x1E);
        BOX2_UI_SetCursorPos((char **)p, 0x1E);
        return BOX2_SEQ_GotoRightPanelB((char *)p, 0, 0x4B);
    case 0x21:
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->top->h28 = 0;
        p->top->b2A = 0xFF;
        p->top->b2B = 0xFF;
        return BOX2_SEQ_GotoBox2MainWithSlot(p, 6, 9, 0x68);
    case 0x22:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((char *)p, 4, BOX2_SEQ_ReturnAfterClear((char *)p, 0x4D));
    case 0x23: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = p->b16;
        BOX2_UI_MoveCursorBetweenIcons(p->work, k, CURSOR_MOVE_GetCurrent(OBJ(p)));
        CURSOR_MOVE_SetCurrent(OBJ(p), k);
        return BOX2_SEQ_GotoBox2Main((char *)p, 5, 0x4E);
    }
    case -6:
        if (CURSOR_MOVE_GetCurrent(OBJ(p)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
            return BOX2_SEQ_GotoRightPanelA((char *)p, 0, 0x4B);
        }
        break;
    case -5:
        if (CURSOR_MOVE_GetCurrent(OBJ(p)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
            return BOX2_SEQ_GotoRightPanelB((char *)p, 0, 0x4B);
        }
        break;
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent(OBJ(p));
        if (v < 0x1E)
            BOX2_MAIN_ChangeBoxFormPreserve((char *)p, v);
        else if (v != 0x22 && v != 0x23)
            BOX2_MAIN_ResetBoxView((char *)p);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((char *)p, BOX2_SEQ_SetState((char *)p, 0x4B));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen(MGR(p)) == 1) {
            unsigned char k = p->b16;
            BOX2_UI_MoveCursorBetweenIcons(p->work, k, CURSOR_MOVE_GetCurrent(OBJ(p)));
            CURSOR_MOVE_SetCurrent(OBJ(p), k);
            return BOX2_SEQ_GotoBox2Main((char *)p, 5, 0x4E);
        }
        p->top->h28 = 0;
        p->top->b2A = 0xFF;
        p->top->b2B = 0xFF;
        return BOX2_SEQ_GotoBox2MainWithSlot(p, 6, 9, 0x68);
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->b14, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            p->b16 = r;
            BOX2_SEQ_DrawFrameList(p, d_021EF8EC, 2);
            BOX2_MAIN_ChangeBoxFormPreserve((char *)p, r);
            BOX2_SEQ_RefreshCursorSlot((char *)p);
            CURSOR_MOVE_SetCurrent(OBJ(p), 0x22);
            if (BOX2_UI_IsListOpen(MGR(p)) == 1)
                return BOX2_SEQ_StatePushSlot((char *)p);
            BOX2_UI_MoveCursorBetweenIcons(p->work, 0x22, r);
            BOX2_UI_CloseListPack(MGR(p));
            return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_SceneWaitScroll, BOX2_SEQ_SetState((char *)p, 0x4C));
        }
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ChangeBoxFormPreserve((char *)p, r);
        if (BOX2_UI_IsListOpen(MGR(p)) == 1) {
            BOX2_UI_OpenListPack(MGR(p));
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            BOX2_SEQ_ShowWindowObject(p->work, 0x18);
            BOX2_MAIN_RefreshCursorBox((char *)p);
            return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowMoving, 0x4B);
        }
        break;
    }
    return 0x4B;
}
