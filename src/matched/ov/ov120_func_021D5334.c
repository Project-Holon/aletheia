/*
 * function: GTSNEGO_DISP_HandleListInput
 * address: 0x021D5334
 * packet: pkt_ov120_021D5334
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_DISP_GetTouchbar 0x021D6988 thumb ov120
 *   GTSNEGO_MSG_UpdatePrintStream 0x021D7AF4 thumb ov120
 *   TOUCHBAR_IsBusy 0x021B6498 thumb ov067
 *   GTSNEGO_MSG_StepScroll 0x021D702C thumb ov120
 *   GTSNEGO_MSG_DrawTileRows 0x021D6D10 thumb ov120
 *   GTSNEGO_MSG_ShiftListUp 0x021D82F8 thumb ov120
 *   GTSNEGO_DISP_GetEntryClamped 0x021D4F98 thumb ov120
 *   GTSNEGO_MSG_ScrollListUp 0x021D7260 thumb ov120
 *   GTSNEGO_MSG_ShiftListDown 0x021D824C thumb ov120
 *   GTSNEGO_MSG_ScrollListDown 0x021D7220 thumb ov120
 *   func_020355C4 0x020355C4 arm
 *   KEY_GetTrg 0x020362DC arm
 *   GTSNEGO_DISP_SetCursorState 0x021D69F4 thumb ov120
 *   UI_SetInputMode 0x020355D8 arm
 *   KEY_GetRepeat 0x0203633C arm
 *   GTSNEGO_DISP_ListCursorDown 0x021D5284 thumb ov120
 *   GTSNEGO_DISP_ListCursorUp 0x021D5230 thumb ov120
 *   GTSNEGO_MSG_ClearScrollState 0x021D7020 thumb ov120
 *   GTSNEGO_MSG_ScrollAllRows 0x021D70C8 thumb ov120
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GTSNEGO_MSG_SetIconY 0x021D733C thumb ov120
 *   GTSNEGO_MSG_SetCursorAnimSeq 0x021D6A9C thumb ov120
 *   GTSNEGO_DISP_DeleteMenuWindow 0x021D5318 thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_ShowListMessage 0x021D51D4 thumb ov120
 *   GTSNEGO_DISP_OnListConfirmDone 0x021D52D4 thumb ov120
 *   GTSNEGO_DISP_EndList 0x021D5208 thumb ov120
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   GTSNEGO_MSG_SetCursorIndex 0x021D6E70 thumb ov120
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   GTSNEGO_MSG_SetIconYClamped 0x021D7374 thumb ov120
 *   GTSNEGO_MSG_PrintListRange 0x021D82A8 thumb ov120
 *   GTSNEGO_MSG_FillListRange 0x021D72A0 thumb ov120
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   func_02040588 0x02040588 arm
 *   GTSNEGO_MSG_TeardownActorList 0x021D6D48 thumb ov120
 *   GTSNEGO_MSG_ClearRows 0x021D7D3C thumb ov120
 *   d_021D88D8 0x021D88D8 data
 *   d_021D88C8 0x021D88C8 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Ctx {
    u8 pad0[0x2C];
    void *f2C;
    u8 pad30[4];
    void *f34;
    u8 pad38[4];
    u8 *f3C;
    void *f40;
    u8 pad44[0x148 - 0x44];
    int f148;
    u8 pad14C[4];
    int f150;
    u8 pad154[4];
    int f158;
    u8 pad15C[8];
    int f164;
} Ctx;
extern u32 GTSNEGO_DISP_GetTouchbar(u8 *p);
struct S;
extern int GTSNEGO_MSG_UpdatePrintStream(char *p);
extern int TOUCHBAR_IsBusy(u8 *p);
extern int GTSNEGO_MSG_StepScroll(u8 *p, int *out);
extern void GTSNEGO_MSG_DrawTileRows(u8 *p, void *list, int first);
extern void GTSNEGO_MSG_ShiftListUp(char *p);
extern void *GTSNEGO_DISP_GetEntryClamped(void **p, int i);
extern void GTSNEGO_MSG_ScrollListUp(u8 *p, void *q);
extern void GTSNEGO_MSG_ShiftListDown(char *p);
extern void GTSNEGO_MSG_ScrollListDown(u8 *p, void *q);
extern u8 func_020355C4(void);
extern u32 KEY_GetTrg(void);
extern void GTSNEGO_DISP_SetCursorState(u8 *p, void *q, u32 n);
extern void UI_SetInputMode(u8 v);
extern u32 KEY_GetRepeat(void);
extern int GTSNEGO_DISP_ListCursorDown(u8 *p);
extern int GTSNEGO_DISP_ListCursorUp(u8 *p);
extern void GTSNEGO_MSG_ClearScrollState(u8 *p);
extern void GTSNEGO_MSG_ScrollAllRows(u8 *p, int flag);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern void GTSNEGO_MSG_SetIconY(u8 *p, int index, int count);
extern int GTSNEGO_MSG_SetCursorAnimSeq(u8 *p, u32 n);
extern void GTSNEGO_DISP_DeleteMenuWindow(u8 *p);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_ShowListMessage(u8 *p);
extern void GTSNEGO_DISP_OnListConfirmDone(u8 *p);
extern void GTSNEGO_DISP_EndList(u8 *p);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern int TOUCHPANEL_HitTrg(const void *t);
extern void GTSNEGO_MSG_SetCursorIndex(void *unused, int *p, int n);
extern int TOUCHPANEL_HitCont(const void *t);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int GTSNEGO_MSG_SetIconYClamped(char *p, int y, int count);
extern void GTSNEGO_MSG_PrintListRange(char *p, void *q, int start);
extern void GTSNEGO_MSG_FillListRange(u8 *p, void *list, int n);
extern void TOUCHBAR_Update(struct S *p);
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void GTSNEGO_MSG_TeardownActorList(u8 *p);
extern void GTSNEGO_MSG_ClearRows(char *p);
extern const u8 d_021D88D8[];
extern const u8 d_021D88C8[];
void GTSNEGO_DISP_HandleListInput(Ctx *p)
{
    int out;
    int r;
    int acc = 0;
    int i;
    int sel;
    int x, y;
    out = 0;
    r = GTSNEGO_DISP_GetTouchbar(p->f3C);
    if (GTSNEGO_MSG_UpdatePrintStream(p->f40) == 0)
        return;
    if (TOUCHBAR_IsBusy((u8 *)r) != 0)
        goto end;
    r = GTSNEGO_MSG_StepScroll(p->f3C, &out);
    if (out == 1) {
        GTSNEGO_MSG_DrawTileRows(p->f3C, p->f2C, p->f158 - 2);
        GTSNEGO_MSG_ShiftListUp(p->f40);
        GTSNEGO_MSG_ScrollListUp(p->f3C, GTSNEGO_DISP_GetEntryClamped(p->f2C, p->f158 - 2));
    } else if (out == 2) {
        GTSNEGO_MSG_DrawTileRows(p->f3C, p->f2C, p->f158 - 2);
        GTSNEGO_MSG_ShiftListDown(p->f40);
        GTSNEGO_MSG_ScrollListDown(p->f3C, GTSNEGO_DISP_GetEntryClamped(p->f2C, p->f158 + 3));
    }
    if (r != 0)
        return;
    if (func_020355C4() == 1 && KEY_GetTrg() != 0) {
        GTSNEGO_DISP_SetCursorState(p->f3C, 0, p->f164);
        UI_SetInputMode(0);
        return;
    }
    if (KEY_GetRepeat() == 0x100) {
        acc = 0;
        for (i = 0; i < 3; i++) {
            r = GTSNEGO_DISP_ListCursorDown((u8 *)p);
            acc |= r;
            GTSNEGO_MSG_ClearScrollState(p->f3C);
            if (r == 0)
                break;
            if (r == 1) {
                i--;
            } else {
                GTSNEGO_MSG_ScrollAllRows(p->f3C, 1);
                GTSNEGO_MSG_DrawTileRows(p->f3C, p->f2C, p->f158 - 2);
                GTSNEGO_MSG_ShiftListDown(p->f40);
                GTSNEGO_MSG_ScrollListDown(p->f3C, GTSNEGO_DISP_GetEntryClamped(p->f2C, p->f158 + 3));
                GTSNEGO_DISP_SetCursorState(p->f3C, 0, p->f164);
            }
        }
    }
    if (KEY_GetRepeat() == 0x200) {
        acc = 0;
        for (i = 0; i < 3; i++) {
            r = GTSNEGO_DISP_ListCursorUp((u8 *)p);
            acc |= r;
            GTSNEGO_MSG_ClearScrollState(p->f3C);
            if (r == 0)
                break;
            if (r == 1) {
                i--;
            } else {
                GTSNEGO_DISP_SetCursorState(p->f3C, 0, p->f164);
                GTSNEGO_MSG_ScrollAllRows(p->f3C, 0);
                GTSNEGO_MSG_DrawTileRows(p->f3C, p->f2C, p->f158 - 2);
                GTSNEGO_MSG_ShiftListUp(p->f40);
                GTSNEGO_MSG_ScrollListUp(p->f3C, GTSNEGO_DISP_GetEntryClamped(p->f2C, p->f158 - 2));
            }
        }
    }
    if (KEY_GetRepeat() == 0x40)
        acc = GTSNEGO_DISP_ListCursorUp((u8 *)p);
    if (KEY_GetRepeat() == 0x80)
        acc = GTSNEGO_DISP_ListCursorDown((u8 *)p);
    if (acc != 0) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        GTSNEGO_MSG_SetIconY(p->f3C, p->f158 + p->f164 - 6, p->f150);
        GTSNEGO_DISP_SetCursorState(p->f3C, 0, p->f164);
        return;
    }
    if (KEY_GetTrg() == 1) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        GTSNEGO_MSG_SetCursorAnimSeq(p->f3C, p->f164);
        p->f148 = p->f158 + p->f164 - 6;
        GTSNEGO_DISP_DeleteMenuWindow((u8 *)p);
        GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_ShowListMessage, 0x760);
        return;
    }
    if (KEY_GetTrg() == 8) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        APP_TASKMENU_WIN_SetDecide(p->f34, 1);
        GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_OnListConfirmDone, 0x766);
        return;
    }
    sel = TOUCHPANEL_HitTrg(d_021D88D8);
    switch (sel) {
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        APP_TASKMENU_WIN_SetDecide(p->f34, 1);
        GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_OnListConfirmDone, 0x770);
        return;
    case 2:
        if (p->f150 < 3)
            break;
    case 1:
        if (p->f150 < 2)
            break;
    case 0:
        UI_SetInputMode(1);
        p->f164 = sel + 6;
        GTSNEGO_DISP_SetCursorState(p->f3C, 0, p->f164);
        GTSNEGO_MSG_SetCursorAnimSeq(p->f3C, p->f164);
        p->f148 = p->f158 + p->f164 - 6;
        GTSNEGO_MSG_SetCursorIndex(p->f3C, &p->f150, sel);
        GTSNEGO_MSG_SetIconY(p->f3C, p->f158 + p->f164 - 6, p->f150);
        GFL_USE_PlaySeDefaultVolume(0x54C);
        GTSNEGO_DISP_DeleteMenuWindow((u8 *)p);
        GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_ShowListMessage, 0x78B);
        return;
    }
    if (TOUCHPANEL_HitCont(d_021D88C8) != 0)
        goto end;
    if (TOUCHPANEL_GetPointCont((u32 *)(&x), (u32 *)(&y)) == 1) {
        r = GTSNEGO_MSG_SetIconYClamped((char *)p->f3C, y, p->f150);
        if (p->f158 != r) {
            p->f158 = r;
            GTSNEGO_MSG_PrintListRange(p->f40, p->f2C, r - 2);
            GTSNEGO_MSG_FillListRange(p->f3C, p->f2C, p->f158 - 2);
            GTSNEGO_MSG_DrawTileRows(p->f3C, p->f2C, p->f158 - 2);
            GFL_USE_PlaySeDefaultVolume(0x548);
        }
    }
    return;
end:
    TOUCHBAR_Update((struct S *)GTSNEGO_DISP_GetTouchbar(p->f3C));
    if (TOUCHBAR_GetPressedButtonIdIfDone((u8 *)GTSNEGO_DISP_GetTouchbar(p->f3C)) == 1) {
        func_02040588(4, 0);
        func_02040588(6, 0);
        GTSNEGO_DISP_DeleteMenuWindow((u8 *)p);
        GTSNEGO_DISP_SetCursorState(p->f3C, p->f34, 9);
        GTSNEGO_MSG_TeardownActorList(p->f3C);
        GTSNEGO_MSG_ClearRows(p->f40);
        GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_EndList, 0x7AD);
    }
}
