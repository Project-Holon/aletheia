/*
 * function: BOX2_SEQ_StateItemMenuD
 * address:  0x021E557C
 * packet:   pkt_ov170_021E557C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of src/matched/ov170_func_021E2650.c.  The image computes r + 0x1E
 * separately for BOX2_MAIN_ChangeBoxFormPreserve and for the call after it; the (int) cast on
 * the first keeps the two expressions apart so they are not CSEd.
 *
 * symbols:
 *   BOX2_UI_GetHandSlotHit 0x021EF194 thumb
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BOX2_UI_IsListOpen 0x021EF5E8 thumb
 *   BOX2_SEQ_DrawFrameList 0x021EB988 thumb
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb
 *   BOX2_SEQ_SelectPartySlotC 0x021E9FA8 thumb
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb
 *   BOX2_UI_OpenListPack 0x021EF57C thumb
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb
 *   BOX2_UI_UpdateCursorInputA 0x021EE474 thumb
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb
 *   BOX2_SEQ_GotoBox2Main 0x021E949C thumb
 *   BOX2_SEQ_GotoBox2MainWithSlot 0x021E954C thumb
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   BOX2_UI_MoveCursorBetweenIcons 0x021EEF74 thumb
 *   BOX2_SEQ_SetState 0x021E8FE0 thumb
 *   BOX2_SEQ_SetSeqSecond 0x021E8FD0 thumb
 *   BOX2_SEQ_GotoSlotHandlerB 0x021EA020 thumb
 *   d_021EF950 0x021EF950 data a1
 */

typedef struct {
    unsigned char pad0[2];
    unsigned char pad2[0x26];
    unsigned short h28;
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
extern unsigned BOX2_UI_GetHandSlotHit(void);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int BOX2_UI_IsListOpen(struct WinMgr *mgr);
extern void BOX2_SEQ_DrawFrameList(Obj *p, const void *e, unsigned n);
extern void BOX2_MAIN_ChangeBoxFormPreserve(char *p, int b);
extern int BOX2_SEQ_SelectPartySlotC(Obj *p, int i);
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern void BOX2_UI_SetCursorPos(char **p, unsigned idx);
extern void BOX2_MAIN_ResetBoxView(char *p);
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern void BOX2_SEQ_ShowWindowObject(char *w, int v);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowMoving(char *p);
extern unsigned BOX2_UI_UpdateCursorInputA(char *p);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
extern int BOX2_SEQ_GotoBox2Main(char *p, int a, int b);
extern int BOX2_SEQ_GotoBox2MainWithSlot(Obj *p, int id, int lo, int arg);
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern void BOX2_UI_MoveCursorBetweenIcons(char *w, int k, int v);
extern int BOX2_SEQ_SetState(char *p, int v);
extern int BOX2_SEQ_SetSeqSecond(char *p, int a);
extern int BOX2_SEQ_GotoSlotHandlerB(Obj *p, int i, int v);
extern const unsigned char d_021EF950[];

#define OBJ(p) (*(void **)((p)->work + 0x70))
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))

int BOX2_SEQ_StateItemMenuD(Obj *p)
{
    unsigned r = BOX2_UI_GetHandSlotHit();
    if (r != -1) {
        CURSOR_MOVE_SetState(OBJ(p), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
            if (BOX2_UI_IsListOpen(MGR(p)) == 0)
                BOX2_SEQ_DrawFrameList(p, d_021EF950, 5);
            BOX2_MAIN_ChangeBoxFormPreserve((char *)p, (int)r + 0x1E);
            return BOX2_SEQ_SelectPartySlotC(p, r + 0x1E);
        }
        CURSOR_MOVE_SetCurrent(OBJ(p), r);
        BOX2_UI_SetCursorPos((char **)p, r + 0x3C);
        BOX2_MAIN_ResetBoxView((char *)p);
        if (BOX2_UI_IsListOpen(MGR(p)) == 1) {
            BOX2_UI_OpenListPack(MGR(p));
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            BOX2_SEQ_ShowWindowObject(p->work, 0x18);
            BOX2_MAIN_RefreshCursorBox((char *)p);
            return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowMoving, 0x31);
        }
        return 0x31;
    }
    r = BOX2_UI_UpdateCursorInputA((char *)p);
    switch (r) {
    case 6:
        GFL_USE_PlaySeDefaultVolume(0x556);
        p->top->h28 = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot(p, 7, 8, 0x10);
    case 7:
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->top->h28 = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot(p, 6, 9, 0x68);
    case 8:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((char *)p, 1, BOX2_SEQ_ReturnAfterClear((char *)p, 0x34));
    case 9:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->x24 = 9;
        return BOX2_SEQ_GotoBox2Main((char *)p, 2, 0x4F);
    case 10:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((char *)p, 3, BOX2_SEQ_ReturnAfterClear((char *)p, 0x55));
    case 11:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((char *)p, 4, BOX2_SEQ_ReturnAfterClear((char *)p, 0x59));
    case 12: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = p->b16 - 0x1E;
        BOX2_UI_MoveCursorBetweenIcons(p->work, k, CURSOR_MOVE_GetCurrent(OBJ(p)));
        CURSOR_MOVE_SetCurrent(OBJ(p), k);
        return BOX2_SEQ_GotoBox2Main((char *)p, 5, 0x32);
    }
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent(OBJ(p));
        if (v < 6)
            BOX2_MAIN_ChangeBoxFormPreserve((char *)p, v + 0x1E);
        else if (v != 8 && v != 9 && v != 10 && v != 11 && v != 12)
            BOX2_MAIN_ResetBoxView((char *)p);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((char *)p, BOX2_SEQ_SetState((char *)p, 0x31));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen(MGR(p)) == 1) {
            unsigned char k = p->b16 - 0x1E;
            BOX2_UI_MoveCursorBetweenIcons(p->work, k, CURSOR_MOVE_GetCurrent(OBJ(p)));
            CURSOR_MOVE_SetCurrent(OBJ(p), k);
            return BOX2_SEQ_GotoBox2Main((char *)p, 5, 0x32);
        }
        p->top->h28 = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot(p, 6, 9, 0x68);
    case -1:
    case -5:
    case -6:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            BOX2_SEQ_DrawFrameList(p, d_021EF950, 5);
            BOX2_MAIN_ChangeBoxFormPreserve((char *)p, (int)r + 0x1E);
            BOX2_UI_MoveCursorBetweenIcons(p->work, 8, CURSOR_MOVE_GetCurrent(OBJ(p)));
            CURSOR_MOVE_SetCurrent(OBJ(p), 8);
            return BOX2_SEQ_GotoSlotHandlerB(p, r + 0x1E, 0x31);
        }
        break;
    }
    return 0x31;
}
