/*
 * function: BOX2_SEQ_StateCursorMoveB
 * address:  0x021E6EC0
 * packet:   pkt_ov170_021E6EC0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of src/matched/BOX2_SEQ_StateItemMenuE.c and BOX2_SEQ_StateMoveMove.c.
 *
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   BOX2_SEQ_GotoBox2MainPlaySe 0x021EA9F4 thumb
 *   BOX2_UI_GetHandSlotHit 0x021EF194 thumb
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BOX2_UI_IsListOpen 0x021EF5E8 thumb
 *   BOX2_MAIN_RefreshCurrentBoxMonInfo 0x021DEFEC thumb
 *   BOX2_SEQ_DeleteGridSlot 0x021EA598 thumb
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   BOX2_UI_MoveCursorBetweenIcons 0x021EEF74 thumb
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   BOX2_SEQ_SetBox2UiF 0x021E7258 thumb
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb
 *   BOX2_UI_UpdateCursorInputF 0x021EEB40 thumb
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb
 *   BOX2_SEQ_GotoBox2Main 0x021E949C thumb
 *   BOX2_SEQ_GotoBox2MainWithSlot 0x021E954C thumb
 *   BOX2_SEQ_GotoBox2MainNoSe 0x021EAA3C thumb
 *   BOX2_SEQ_SetState 0x021E8FE0 thumb
 *   BOX2_SEQ_SetSeqSecond 0x021E8FD0 thumb
 *   BOX2_SEQ_SetCursorMoveB 0x021EA66C thumb
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
extern unsigned BOX2_UI_GetHandSlotHit(void);
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int BOX2_UI_IsListOpen(struct WinMgr *mgr);
extern void BOX2_MAIN_RefreshCurrentBoxMonInfo(char *p, int b);
extern int BOX2_SEQ_DeleteGridSlot(Obj *p, int i);
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern void BOX2_UI_SetCursorPos(char **p, unsigned idx);
extern void BOX2_MAIN_ResetBoxView(char *p);
extern int BOX2_SEQ_SetBox2UiF(char *p);
extern unsigned BOX2_UI_UpdateCursorInputF(char *p);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
extern int BOX2_SEQ_GotoBox2Main(char *p, int a, int b);
extern int BOX2_SEQ_GotoBox2MainWithSlot(Obj *p, int id, int lo, int arg);
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern void BOX2_UI_MoveCursorBetweenIcons(char *w, int k, int v);
extern int BOX2_SEQ_GotoBox2MainNoSe(Obj *p, int v);
extern int BOX2_SEQ_SetState(char *p, int v);
extern int BOX2_SEQ_SetSeqSecond(char *p, int a);
extern int BOX2_SEQ_SetCursorMoveB(Obj *p, int i);

#define OBJ(p) (*(void **)((p)->work + 0x70))
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))

int BOX2_SEQ_StateCursorMoveB(Obj *p)
{
    unsigned r;
    if (KEY_GetTrg() & 4) {
        r = BOX2_SEQ_GotoBox2MainPlaySe(p, 0x3F);
        if (p->lo == 1) {
            unsigned char v = CURSOR_MOVE_GetCurrent(OBJ(p));
            if (v < 6)
                p->b16 = v + 0x1E;
            else
                p->b16 = 0x1E;
        }
        return r;
    }
    r = BOX2_UI_GetHandSlotHit();
    if (r != -1) {
        CURSOR_MOVE_SetState(OBJ(p), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
            BOX2_MAIN_RefreshCurrentBoxMonInfo((char *)p, (int)r + 0x1E);
            return BOX2_SEQ_DeleteGridSlot(p, r + 0x1E);
        }
        BOX2_MAIN_ResetBoxView((char *)p);
        if (BOX2_UI_IsListOpen(MGR(p)) == 1) {
            BOX2_UI_MoveCursorBetweenIcons(p->work, (unsigned char)r, CURSOR_MOVE_GetCurrent(OBJ(p)));
            CURSOR_MOVE_SetCurrent(OBJ(p), r + 0x1E);
            return BOX2_SEQ_SetBox2UiF((char *)p);
        }
        CURSOR_MOVE_SetCurrent(OBJ(p), r);
        BOX2_UI_SetCursorPos((char **)p, r);
        return 0x46;
    }
    r = BOX2_UI_UpdateCursorInputF((char *)p);
    switch (r) {
    case 6:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((char *)p, 10, BOX2_SEQ_ReturnAfterClear((char *)p, 0x1C));
    case 7:
        GFL_USE_PlaySeDefaultVolume(0x556);
        p->top->h28 = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot(p, 7, 8, 0x10);
    case 8:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_GotoBox2MainWithSlot(p, 6, 9, BOX2_SEQ_ReturnAfterClear((char *)p, 0x1C));
    case 9:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->lo = 0;
        return BOX2_SEQ_GotoBox2Main((char *)p, 3, BOX2_SEQ_ReturnAfterClear((char *)p, 0x3F));
    case 10:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (*(unsigned short *)(p->work + 0xA16C) == 0) {
            p->b13 = 1;
            p->x24 = 10;
            return BOX2_SEQ_GotoBox2Main((char *)p, 4, BOX2_SEQ_ReturnAfterClear((char *)p, 0x50));
        }
        return BOX2_SEQ_GotoBox2Main((char *)p, 4, BOX2_SEQ_ReturnAfterClear((char *)p, 0x50));
    case 11: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = p->b16 - 0x1E;
        BOX2_UI_MoveCursorBetweenIcons(p->work, k, CURSOR_MOVE_GetCurrent(OBJ(p)));
        CURSOR_MOVE_SetCurrent(OBJ(p), k);
        return BOX2_SEQ_GotoBox2Main((char *)p, 5, 0x47);
    }
    case 12:
        r = BOX2_SEQ_GotoBox2MainNoSe(p, 0x3F);
        if (p->lo == 1) {
            unsigned char v = CURSOR_MOVE_GetCurrent(OBJ(p));
            if (v < 6)
                p->b16 = v + 0x1E;
            else
                p->b16 = 0x1E;
        }
        return r;
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent(OBJ(p));
        if (v < 6)
            BOX2_MAIN_RefreshCurrentBoxMonInfo((char *)p, v + 0x1E);
        else if (v == 6)
            BOX2_MAIN_ResetBoxView((char *)p);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((char *)p, BOX2_SEQ_SetState((char *)p, 0x46));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen(MGR(p)) == 1) {
            unsigned char k = p->b16 - 0x1E;
            BOX2_UI_MoveCursorBetweenIcons(p->work, k, CURSOR_MOVE_GetCurrent(OBJ(p)));
            CURSOR_MOVE_SetCurrent(OBJ(p), k);
            return BOX2_SEQ_GotoBox2Main((char *)p, 5, 0x47);
        }
        return BOX2_SEQ_GotoBox2MainWithSlot(p, 6, 9, BOX2_SEQ_ReturnAfterClear((char *)p, 0x1C));
    case -1:
    case -5:
    case -6:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            return BOX2_SEQ_SetCursorMoveB(p, r + 0x1E);
        }
        break;
    }
    return 0x46;
}
