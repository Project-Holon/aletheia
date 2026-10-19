/*
 * function: BOX2_SEQ_StateItemMenuF
 * address:  0x021E65E4
 * packet:   pkt_ov170_021E65E4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of src/matched/BOX2_SEQ_StateMoveInput.c.
 *
 * symbols:
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   BOX2_MAIN_ActivateKeyCursor 0x021DD238 thumb
 *   BOX2_UI_GetBodySlotHit 0x021EF1A4 thumb
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   BOX2_MAIN_RefreshCurrentBoxMonInfo 0x021DEFEC thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_SEQ_SelectGridSlot 0x021EA39C thumb
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   BOX2_UI_GetPartySlotHit 0x021EF170 thumb
 *   BOX2_UI_CursorInputRight 0x021EE96C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb
 *   BOX2_MAIN_ClearCursorBox 0x021DF0BC thumb
 *   BOX2_SEQ_RefreshHandSlot 0x021ECC1C thumb
 *   BOX2_SEQ_GotoRightPanelA 0x021E9C94 thumb
 *   BOX2_SEQ_GotoRightPanelB 0x021E9CE0 thumb
 *   BOX2_SEQ_GotoBox2MainWithSlot 0x021E954C thumb
 *   BOX2_SEQ_MoveGridCursor 0x021EA514 thumb
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   BOX2_SEQ_SetState 0x021E8FE0 thumb
 *   BOX2_SEQ_SetSeqSecond 0x021E8FD0 thumb
 *   BOX2_SEQ_DrawGridSlotB 0x021EA458 thumb
 */

typedef unsigned int u32;

typedef struct {
    void *top;
    unsigned char pad4[0x13 - 4];
    unsigned char b13;
    unsigned char b14;
    unsigned char b15;
    unsigned char b16;
    unsigned char b17;
    unsigned char b18;
    unsigned char b19;
    unsigned char b1A;
    unsigned char b1B;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char b1D;
    unsigned char pad1E[0x28 - 0x1E];
    int x28;
    char *work;
} Obj;

extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
extern u32 KEY_GetTrg(void);
extern void BOX2_MAIN_ActivateKeyCursor(char *p);
extern unsigned BOX2_UI_GetBodySlotHit(void);
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void BOX2_MAIN_RefreshCurrentBoxMonInfo(char *p, int b);
extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);
extern int BOX2_SEQ_SelectGridSlot(Obj *p, unsigned i);
extern void BOX2_MAIN_ResetBoxView(char *p);
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern unsigned BOX2_UI_GetPartySlotHit(void);
extern unsigned BOX2_UI_CursorInputRight(char *p);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void BOX2_UI_SetCursorPos(char **p, unsigned idx);
extern void BOX2_MAIN_ClearCursorBox(unsigned char *p);
extern void BOX2_SEQ_RefreshHandSlot(unsigned char *p);
extern int BOX2_SEQ_GotoRightPanelA(char *p, int a, int n);
extern int BOX2_SEQ_GotoRightPanelB(char *p, int a, int n);
extern int BOX2_SEQ_GotoBox2MainWithSlot(Obj *p, int id, int lo, int arg);
extern int BOX2_SEQ_MoveGridCursor(Obj *p, unsigned i);
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern int BOX2_SEQ_SetState(char *p, int v);
extern int BOX2_SEQ_SetSeqSecond(char *p, int a);
extern int BOX2_SEQ_DrawGridSlotB(Obj *p, unsigned i);

#define OBJ(p) (*(void **)((p)->work + 0x70))

int BOX2_SEQ_StateItemMenuF(Obj *p)
{
    unsigned r;
    if (p->hi == 1) {
        p->lo = 0;
        p->hi = 0;
        return BOX2_SEQ_ReturnAfterClear((char *)p, 0x41);
    }
    if ((KEY_GetTrg() & 4) && p->lo != 0 && p->b18 == 0) {
        BOX2_MAIN_ActivateKeyCursor((char *)p);
        p->lo = 0;
        return BOX2_SEQ_ReturnAfterClear((char *)p, 0x41);
    }
    if (p->b18 == 0) {
        r = BOX2_UI_GetBodySlotHit();
        if (r != -1) {
            CURSOR_MOVE_SetState(OBJ(p), 0);
            if (BOX2_MAIN_GetPartyValueAt((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
                BOX2_MAIN_RefreshCurrentBoxMonInfo((char *)p, (int)r + 0x1E);
                BOX2_SEQ_SetActorDrawEnable(p->work, 4, 0);
                return BOX2_SEQ_SelectGridSlot(p, r + 0x1E);
            }
            BOX2_MAIN_ResetBoxView((char *)p);
            CURSOR_MOVE_SetCurrent(OBJ(p), r + 0x1E);
            return 0x40;
        }
        r = BOX2_UI_GetPartySlotHit();
        if (r != -1) {
            CURSOR_MOVE_SetState(OBJ(p), 0);
            if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->b14, 0xA9, 0)) {
                BOX2_MAIN_RefreshCurrentBoxMonInfo((char *)p, r);
                BOX2_SEQ_SetActorDrawEnable(p->work, 4, 0);
                return BOX2_SEQ_SelectGridSlot(p, r);
            }
            BOX2_MAIN_ResetBoxView((char *)p);
            CURSOR_MOVE_SetCurrent(OBJ(p), r);
            return 0x40;
        }
    }
    r = BOX2_UI_CursorInputRight((char *)p);
    switch (r) {
    case 0x24:
        if (p->b18 != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        BOX2_MAIN_ResetBoxView((char *)p);
        return BOX2_SEQ_ReturnAfterClear((char *)p, 0x5D);
    case 0x25:
        GFL_USE_PlaySeDefaultVolume(0x548);
        CURSOR_MOVE_SetCurrent(OBJ(p), 0x24);
        BOX2_UI_SetCursorPos((char **)p, 0x24);
        if (p->b18 == 0)
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        else
            BOX2_SEQ_RefreshHandSlot((unsigned char *)p);
        return BOX2_SEQ_GotoRightPanelA((char *)p, 0, 0x40);
    case 0x26:
        GFL_USE_PlaySeDefaultVolume(0x548);
        CURSOR_MOVE_SetCurrent(OBJ(p), 0x24);
        BOX2_UI_SetCursorPos((char **)p, 0x24);
        if (p->b18 == 0)
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        else
            BOX2_SEQ_RefreshHandSlot((unsigned char *)p);
        return BOX2_SEQ_GotoRightPanelB((char *)p, 0, 0x40);
    case 0x29:
        if (p->b18 != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->lo = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot(p, 6, 9, BOX2_SEQ_ReturnAfterClear((char *)p, 0x41));
    case 0x2A:
        if (p->lo == 0 || p->b18 != 0)
            break;
        p->lo = 0;
        return BOX2_SEQ_ReturnAfterClear((char *)p, 0x41);
    case -2:
        if (p->b18 == 1)
            return BOX2_SEQ_MoveGridCursor(p, 0xFF);
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->lo = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot(p, 6, 9, BOX2_SEQ_ReturnAfterClear((char *)p, 0x41));
    case -6:
        if (CURSOR_MOVE_GetCurrent(OBJ(p)) != 0x24)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelA((char *)p, 0, 0x40);
    case -5:
        if (CURSOR_MOVE_GetCurrent(OBJ(p)) != 0x24)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelB((char *)p, 0, 0x40);
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        if (p->b18 == 0) {
            unsigned char v = CURSOR_MOVE_GetCurrent(OBJ(p));
            if (v < 0x24)
                BOX2_MAIN_RefreshCurrentBoxMonInfo((char *)p, v);
            else
                BOX2_MAIN_ResetBoxView((char *)p);
        }
        return BOX2_SEQ_SetSeqSecond((char *)p, BOX2_SEQ_SetState((char *)p, 0x40));
    case -1:
    case -7:
    case -8:
    case 0x27:
    case 0x28:
        break;
    default:
        if (p->b18 == 1)
            return BOX2_SEQ_MoveGridCursor(p, r);
        return BOX2_SEQ_DrawGridSlotB(p, r);
    }
    return 0x40;
}
