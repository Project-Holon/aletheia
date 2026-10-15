/*
 * function: BOX2_SEQ_StateItemMenuC
 * address:  0x021E4F60
 * packet:   pkt_ov170_021E4F60
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   BOX2_SEQ_GotoBox2MainPlaySe 0x021EA9F4 thumb
 *   BOX2_UI_GetPartySlotHit 0x021EF170 thumb
 *   func_020260F4 0x020260F4 thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BOX2_UI_IsListOpen 0x021EF5E8 thumb
 *   BOX2_SEQ_DrawFrameList 0x021EB988 thumb
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb
 *   BOX2_SEQ_SelectSlotA 0x021E9D2C thumb
 *   func_020260E4 0x020260E4 thumb
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb
 *   BOX2_UI_OpenListPack 0x021EF57C thumb
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb
 *   BOX2_UI_UpdateCursorInputB 0x021EE57C thumb
 *   BOX2_SEQ_SelectSlotC 0x021E9DF8 thumb
 *   BOX2_SEQ_SelectSlotB 0x021E9D98 thumb
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb
 *   BOX2_MAIN_ClearCursorBox 0x021DF0BC thumb
 *   BOX2_SEQ_GotoRightPanelA 0x021E9C94 thumb
 *   BOX2_SEQ_GotoRightPanelB 0x021E9CE0 thumb
 *   BOX2_SEQ_GotoBox2Main 0x021E949C thumb
 *   BOX2_SEQ_GotoBox2MainWithSlot 0x021E954C thumb
 *   func_020260E0 0x020260E0 thumb
 *   BOX2_UI_MoveCursorBetweenIcons 0x021EEF74 thumb
 *   BOX2_SEQ_GotoBox2MainNoSe 0x021EAA3C thumb
 *   BOX2_SEQ_SetState 0x021E8FE0 thumb
 *   BOX2_SEQ_SetSeqSecond 0x021E8FD0 thumb
 *   BOX2_SEQ_GotoSlotHandlerA 0x021E9E7C thumb
 *   d_021EF9B4 0x021EF9B4 data a1
 */

typedef unsigned int u32;

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
extern u32 KEY_GetTrg(void);
extern int BOX2_SEQ_GotoBox2MainPlaySe(Obj *p, int v);
extern unsigned BOX2_UI_GetPartySlotHit(void);
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int BOX2_UI_IsListOpen(struct WinMgr *mgr);
extern void BOX2_SEQ_DrawFrameList(Obj *p, const void *e, unsigned n);
extern void BOX2_MAIN_ChangeBoxFormPreserve(char *p, int b);
extern int BOX2_SEQ_SelectSlotA(Obj *p, int i);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void BOX2_UI_SetCursorPos(char **p, unsigned idx);
extern void BOX2_MAIN_ResetBoxView(char *p);
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern void BOX2_SEQ_ShowWindowObject(char *w, int v);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_UI_ShowWindowA(char *w);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowMoving(char *p);
extern unsigned BOX2_UI_UpdateCursorInputB(char *p);
extern int BOX2_SEQ_SelectSlotC(Obj *p, int i);
extern int BOX2_SEQ_SelectSlotB(Obj *p, int i);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
extern void BOX2_MAIN_ClearCursorBox(unsigned char *p);
extern int BOX2_SEQ_GotoRightPanelA(char *p, int a, int n);
extern int BOX2_SEQ_GotoRightPanelB(char *p, int a, int n);
extern int BOX2_SEQ_GotoBox2Main(char *p, int a, int b);
extern int BOX2_SEQ_GotoBox2MainWithSlot(Obj *p, int id, int lo, int arg);
extern u8 func_020260E0(struct Sound *obj);
extern void BOX2_UI_MoveCursorBetweenIcons(char *w, int k, int v);
extern int BOX2_SEQ_GotoBox2MainNoSe(Obj *p, int v);
extern int BOX2_SEQ_SetState(char *p, int v);
extern int BOX2_SEQ_SetSeqSecond(char *p, int a);
extern int BOX2_SEQ_GotoSlotHandlerA(Obj *p, int i, int v);
extern const unsigned char d_021EF9B4[];

#define OBJ(p) (*(void **)((p)->work + 0x70))
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))

int BOX2_SEQ_StateItemMenuC(Obj *p)
{
    unsigned r;
    r = BOX2_UI_GetPartySlotHit();
    if (r != -1) {
        func_020260F4(OBJ(p), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->b14, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
            if (BOX2_UI_IsListOpen(MGR(p)) == 0)
                BOX2_SEQ_DrawFrameList(p, d_021EF9B4, 5);
            BOX2_MAIN_ChangeBoxFormPreserve((char *)p, r);
            return BOX2_SEQ_SelectSlotC(p, r);
        }
        func_020260E4(OBJ(p), r);
        BOX2_UI_SetCursorPos((char **)p, r);
        BOX2_MAIN_ResetBoxView((char *)p);
        if (BOX2_UI_IsListOpen(MGR(p)) == 1) {
            BOX2_UI_OpenListPack(MGR(p));
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            BOX2_SEQ_ShowWindowObject(p->work, 0x18);
            BOX2_MAIN_RefreshCursorBox((char *)p);
            return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowMoving, 0x2C);
        }
        return 0x2C;
    }
    r = BOX2_UI_UpdateCursorInputB((char *)p);
    switch (r) {
    case 0x1E:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        BOX2_MAIN_ResetBoxView((char *)p);
        return BOX2_SEQ_ReturnAfterClear((char *)p, 0x5D);
    case 0x1F:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        BOX2_UI_SetCursorPos((char **)p, 0x1E);
        return BOX2_SEQ_GotoRightPanelA((char *)p, 0, 0x2C);
    case 0x20:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        BOX2_UI_SetCursorPos((char **)p, 0x1E);
        return BOX2_SEQ_GotoRightPanelB((char *)p, 0, 0x2C);
    case 0x21:
        GFL_USE_PlaySeDefaultVolume(0x556);
        p->top->h28 = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot(p, 7, 8, 0x10);
    case 0x22:
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->top->h28 = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot(p, 6, 9, 0x68);
    case 0x23:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((char *)p, 1, BOX2_SEQ_ReturnAfterClear((char *)p, 0x2E));
    case 0x24:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->b17 = p->b14;
        p->x24 = 0x24;
        return BOX2_SEQ_GotoBox2Main((char *)p, 2, 0x4F);
    case 0x25:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((char *)p, 3, BOX2_SEQ_ReturnAfterClear((char *)p, 0x55));
    case 0x26:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((char *)p, 4, BOX2_SEQ_ReturnAfterClear((char *)p, 0x59));
    case 0x27: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = p->b16;
        BOX2_UI_MoveCursorBetweenIcons(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return BOX2_SEQ_GotoBox2Main((char *)p, 5, 0x2D);
    }
    case -6:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
            return BOX2_SEQ_GotoRightPanelA((char *)p, 0, 0x2C);
        }
        break;
    case -5:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
            return BOX2_SEQ_GotoRightPanelB((char *)p, 0, 0x2C);
        }
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 0x1E)
            BOX2_MAIN_ChangeBoxFormPreserve((char *)p, v);
        else if (v != 0x23 && v != 0x24 && v != 0x25 && v != 0x26 && v != 0x27)
            BOX2_MAIN_ResetBoxView((char *)p);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((char *)p, BOX2_SEQ_SetState((char *)p, 0x2C));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen(MGR(p)) == 1) {
            unsigned char k = p->b16;
            BOX2_UI_MoveCursorBetweenIcons(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return BOX2_SEQ_GotoBox2Main((char *)p, 5, 0x2D);
        }
        p->top->h28 = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot(p, 6, 9, 0x68);
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->b14, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            BOX2_SEQ_DrawFrameList(p, d_021EF9B4, 5);
            BOX2_MAIN_ChangeBoxFormPreserve((char *)p, r);
            BOX2_UI_MoveCursorBetweenIcons(p->work, 0x23, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), 0x23);
            return BOX2_SEQ_GotoSlotHandlerA(p, r, 0x2C);
        }
        break;
    }
    return 0x2C;
}
