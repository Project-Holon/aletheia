/*
 * function: BOX2_SEQ_StateSummaryInput
 * address:  0x021E2CBC
 * packet:   pkt_ov170_021E2CBC
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   BOX2_MAIN_PlayCursorSound 0x021DD238 thumb
 *   BOX2_UI_GetPartySlotHit 0x021EF170 thumb
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   BOX2_UI_SetMiniIconVisible 0x021EE008 thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   BOX2_SEQ_SelectSlotD 0x021EA064 thumb
 *   BOX2_UI_SelectSlot 0x021EE754 thumb
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb
 *   BOX2_UI_GetExitButtonPoint 0x021EF1D4 thumb
 *   BOX2_SEQ_CreateC 0x021EA808 thumb
 *   BOX2_UI_CursorInputLeft 0x021EE850 thumb
 *   BOX2_MAIN_ClearCursorBox 0x021DF0BC thumb
 *   BOX2_SEQ_RefreshHandSlot 0x021ECC1C thumb
 *   BOX2_SEQ_GotoRightPanelA 0x021E9C94 thumb
 *   BOX2_SEQ_GotoRightPanelB 0x021E9CE0 thumb
 *   BOX2_SEQ_GotoBox2Main 0x021E949C thumb
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   BOX2_SEQ_GotoBox2MainWithSlot 0x021E954C thumb
 *   BOX2_SEQ_ScrollListToSlot 0x021EA14C thumb
 *   BOX2_MAIN_SelectBox 0x021DD1C4 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_SEQ_OpenBoxDown 0x021E1A28 thumb
 *   BOX2_SEQ_OpenBoxUp 0x021E19D4 thumb
 *   BOX2_SEQ_SetState 0x021E8FE0 thumb
 *   BOX2_SEQ_SetSeqSecond 0x021E8FD0 thumb
 *   BOX2_SEQ_DrawListSlot 0x021EA798 thumb
 *   BOX2_SEQ_SwapSlotActors 0x021ECB84 thumb
 *   BOX2_SEQ_SelectBoxSlot 0x021EA114 thumb
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

typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
extern u32 KEY_GetTrg(void);
extern void BOX2_MAIN_PlayCursorSound(char *p);
extern unsigned BOX2_UI_GetPartySlotHit(void);
extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);
extern void BOX2_UI_SetMiniIconVisible(char *p, int a, int b);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void BOX2_MAIN_ChangeBoxFormPreserve(char *p, int b);
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern int BOX2_SEQ_SelectSlotD(unsigned char *p, int i, int v);
extern void BOX2_UI_SelectSlot(unsigned char *p, unsigned r);
extern void BOX2_UI_SetCursorPos(char **p, unsigned idx);
extern void BOX2_MAIN_ResetBoxView(char *p);
extern int BOX2_UI_GetExitButtonPoint(unsigned *a, unsigned *b);
extern void BOX2_SEQ_CreateC(char *p);
extern unsigned BOX2_UI_CursorInputLeft(char *p);
extern void BOX2_MAIN_ClearCursorBox(unsigned char *p);
extern void BOX2_SEQ_RefreshHandSlot(unsigned char *p);
extern int BOX2_SEQ_GotoRightPanelA(char *p, int a, int n);
extern int BOX2_SEQ_GotoRightPanelB(char *p, int a, int n);
extern int BOX2_SEQ_GotoBox2Main(char *p, int a, int b);
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern int BOX2_SEQ_GotoBox2MainWithSlot(Obj *p, int id, int lo, int arg);
extern int BOX2_SEQ_ScrollListToSlot(unsigned char *p, unsigned i, int v);
extern void BOX2_MAIN_SelectBox(char *p, int a);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_SEQ_OpenBoxDown(char *p);
extern int BOX2_SEQ_OpenBoxUp(char *p);
extern int BOX2_SEQ_SetState(char *p, int v);
extern int BOX2_SEQ_SetSeqSecond(char *p, int a);
extern int BOX2_SEQ_DrawListSlot(unsigned char *p, int sel);
extern void BOX2_SEQ_SwapSlotActors(char *w, unsigned i);
extern int BOX2_SEQ_SelectBoxSlot(char *p, int a);

#define OBJ(p) (*(void **)((p)->work + 0x70))

int BOX2_SEQ_StateSummaryInput(Obj *p)
{
    unsigned r;
    unsigned x;
    unsigned y;
    if (p->hi == 1) {
        p->lo = 0;
        p->hi = 0;
        return BOX2_SEQ_ReturnAfterClear((char *)p, 0x16);
    }
    if ((KEY_GetTrg() & 4) && p->lo != 0 && p->b18 == 0) {
        BOX2_MAIN_PlayCursorSound((char *)p);
        p->lo = 0;
        return BOX2_SEQ_ReturnAfterClear((char *)p, 0x16);
    }
    if (p->b18 == 0) {
        r = BOX2_UI_GetPartySlotHit();
        if (r != -1) {
            CURSOR_MOVE_SetState(OBJ(p), 0);
            BOX2_UI_SetMiniIconVisible((char *)p, 0, 0);
            if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->b14, 0xA9, 0)) {
                GFL_USE_PlaySeDefaultVolume(0x666);
                TOUCHPANEL_GetPointTrg((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
                BOX2_MAIN_ChangeBoxFormPreserve((char *)p, r);
                CURSOR_MOVE_SetCurrent(OBJ(p), r);
                return BOX2_SEQ_SelectSlotD((unsigned char *)p, r, 0x15);
            }
            CURSOR_MOVE_SetCurrent(OBJ(p), r);
            BOX2_UI_SelectSlot((unsigned char *)p, r);
            *(int *)(p->work + 0xA168) = r;
            BOX2_UI_SetCursorPos((char **)p, r);
            BOX2_MAIN_ResetBoxView((char *)p);
            return 0x15;
        }
    }
    if (BOX2_UI_GetExitButtonPoint(&x, &y) == 1) {
        *(unsigned *)(p->work + 0xA184) = y;
        p->x28 = 0x15;
        BOX2_SEQ_CreateC((char *)p);
        return 0xF;
    }
    r = BOX2_UI_CursorInputLeft((char *)p);
    switch (r) {
    case 0x1E:
        BOX2_UI_SetMiniIconVisible((char *)p, 0, 0);
        if (p->b18 != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        BOX2_MAIN_ResetBoxView((char *)p);
        return BOX2_SEQ_ReturnAfterClear((char *)p, 0x5D);
    case 0x1F:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_UI_SetMiniIconVisible((char *)p, 0, 0);
        CURSOR_MOVE_SetCurrent(OBJ(p), 0x1E);
        BOX2_UI_SetCursorPos((char **)p, 0x1E);
        BOX2_UI_SelectSlot((unsigned char *)p, 0x1E);
        *(int *)(p->work + 0xA168) = 0x1E;
        if (p->b18 == 0)
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        else
            BOX2_SEQ_RefreshHandSlot((unsigned char *)p);
        return BOX2_SEQ_GotoRightPanelA((char *)p, 0, 0x15);
    case 0x20:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_UI_SetMiniIconVisible((char *)p, 0, 0);
        CURSOR_MOVE_SetCurrent(OBJ(p), 0x1E);
        BOX2_UI_SetCursorPos((char **)p, 0x1E);
        BOX2_UI_SelectSlot((unsigned char *)p, 0x1E);
        *(int *)(p->work + 0xA168) = 0x1E;
        if (p->b18 == 0)
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        else
            BOX2_SEQ_RefreshHandSlot((unsigned char *)p);
        return BOX2_SEQ_GotoRightPanelB((char *)p, 0, 0x15);
    case 0x27:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (p->b18 == 0)
            BOX2_MAIN_ResetBoxView((char *)p);
        return BOX2_SEQ_GotoBox2Main((char *)p, 0xA, BOX2_SEQ_ReturnAfterClear((char *)p, 0x19));
    case 0x28:
        if (p->b18 == 0) {
            unsigned char v = CURSOR_MOVE_GetCurrent(OBJ(p));
            if (v >= 0x1E || BOX2_MAIN_GetPartyValueAt((void ***)p, v, p->b14, 0xA9, 0) == 0)
                break;
            p->b16 = v;
            p->b17 = p->b14;
            p->b13 = 2;
        } else {
            p->b13 = 3;
            p->b1D = CURSOR_MOVE_GetCurrent(OBJ(p));
        }
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2MainWithSlot(p, 8, 1, 0x4F);
    case 0x29:
        if (p->b18 != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->lo = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot(p, 6, 9, BOX2_SEQ_ReturnAfterClear((char *)p, 0x16));
    case 0x2A:
        if (p->lo == 0 || p->b18 != 0)
            break;
        p->lo = 0;
        return BOX2_SEQ_ReturnAfterClear((char *)p, 0x16);
    case -2:
        if (p->b18 == 1)
            return BOX2_SEQ_ScrollListToSlot((unsigned char *)p, 0xFF, 0x15);
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->lo = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot(p, 6, 9, BOX2_SEQ_ReturnAfterClear((char *)p, 0x16));
    case -8:
        if (CURSOR_MOVE_GetCurrent(OBJ(p)) != 0x22)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_SelectBox((char *)p, -1);
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_OpenBoxDown, 0x15);
    case -7:
        if (CURSOR_MOVE_GetCurrent(OBJ(p)) != 0x25)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_SelectBox((char *)p, 1);
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_OpenBoxUp, 0x15);
    case -6:
        if (CURSOR_MOVE_GetCurrent(OBJ(p)) != 0x1E)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelA((char *)p, 0, 0x15);
    case -5:
        if (CURSOR_MOVE_GetCurrent(OBJ(p)) != 0x1E)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelB((char *)p, 0, 0x15);
    case -3: {
        unsigned char v;
        GFL_USE_PlaySeDefaultVolume(0x548);
        v = CURSOR_MOVE_GetCurrent(OBJ(p));
        if (p->b18 == 0) {
            if (v < 0x1E)
                BOX2_MAIN_ChangeBoxFormPreserve((char *)p, v);
            else
                BOX2_MAIN_ResetBoxView((char *)p);
        }
        if (v >= 0x22 && v <= 0x25)
            BOX2_UI_SetMiniIconVisible((char *)p, v - 0x22, 1);
        else
            BOX2_UI_SetMiniIconVisible((char *)p, 0, 0);
        return BOX2_SEQ_SetSeqSecond((char *)p, BOX2_SEQ_SetState((char *)p, 0x15));
    }
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case 0x21:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_SelectBox((char *)p, -1);
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_OpenBoxDown, 0x15);
    case 0x26:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_SelectBox((char *)p, 1);
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_OpenBoxUp, 0x15);
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
        BOX2_UI_SetMiniIconVisible((char *)p, r - 0x22, 1);
        if (p->b18 == 1)
            return BOX2_SEQ_ScrollListToSlot((unsigned char *)p, r + 2, 0x15);
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ResetBoxView((char *)p);
        *(unsigned char *)(p->work + 0xA17F) = p->b19 + r - 0x22;
        if (*(unsigned char *)(p->work + 0xA17F) >= p->b15)
            *(unsigned char *)(p->work + 0xA17F) -= p->b15;
        if (*(unsigned char *)(p->work + 0xA17F) != p->b14)
            return BOX2_SEQ_DrawListSlot((unsigned char *)p, 0);
        break;
    case -1:
        break;
    default:
        BOX2_UI_SetMiniIconVisible((char *)p, 0, 0);
        if (p->b18 == 1)
            return BOX2_SEQ_ScrollListToSlot((unsigned char *)p, r, 0x15);
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->b14, 0xA9, 0)) {
            p->b16 = r;
            p->b17 = p->b14;
            BOX2_SEQ_SwapSlotActors(p->work, p->b16);
            return BOX2_SEQ_SelectBoxSlot((char *)p, p->b16);
        }
        break;
    }
    return 0x15;
}
