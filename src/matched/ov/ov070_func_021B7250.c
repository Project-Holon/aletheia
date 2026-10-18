/*
 * function: ITEMMENU_TaskBagMain
 * address:  0x021B7250
 * packet:   pkt_ov070_021B7250
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   BUTTON_MAN_UpdateSlots  0x02051C88  arm
 *   BLINK_PALANM_Update  0x0202EA40  thumb
 *   ITEMMENU_HandleScrollbarTouch  0x021B63F8  thumb  ov070
 *   ITEMMENU_RedrawList  0x021B6138  thumb  ov070
 *   func_020355C4  0x020355C4  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   ITEMMENU_GetItemCount  0x021B61C8  thumb  ov070
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   ITEMMENU_DrawMoveInfo  0x021B9850  thumb  ov070
 *   ITEMMENU_SetCursorActive  0x021B80C4  thumb  ov070
 *   UI_SetInputMode  0x020355D8  arm
 *   ITEMMENU_StartSideButtonPress  0x021B8C1C  thumb  ov070
 *   ITEMMENU_IsBrowseMode  0x021B811C  thumb  ov070
 *   ITEMMENU_ToggleRegisteredItem  0x021B8134  thumb  ov070
 *   ITEMMENU_TogglePocketSortFlag  0x021B81B8  thumb  ov070
 *   ITEMMENU_ShowInputGuardError  0x021B8080  thumb  ov070
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskInputGuardMessage  0x021B8EA8  thumb  ov070
 *   ITEMMENU_TaskSelectItemFlash  0x021B8B7C  thumb  ov070
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02007CC8  0x02007CC8  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   ITEMMENU_UpdateSideButtonsForMode  0x021BB5DC  thumb  ov070
 *   ITEMMENU_ReturnToListInput  0x021B8B0C  thumb  ov070
 *   ITEMMENU_HandleListKeys  0x021B6554  thumb  ov070
 *   ITEMMENU_MoveCursorToRow  0x021BA6A4  thumb  ov070
 *   KEY_GetRepeat  0x0203633C  arm
 *   ITEMMENU_StartPocketTabPress  0x021B8CE4  thumb  ov070
 *   ITEMMENU_ReturnToBagMainAlias  0x021B8F90  thumb  ov070
 */

typedef unsigned int u32;

typedef struct Obj Obj;

struct Obj {
    unsigned char pad000[0x10];
    int f010;
    unsigned char pad014[0x18 - 0x14];
    void *f018;
    unsigned char pad01C[0x20 - 0x1C];
    unsigned char f020[0x4D8];
    void (*f4F8)(Obj *o);
    unsigned char pad4FC[0x50C - 0x4FC];
    void *f50C;
    unsigned char pad510[0x694 - 0x510];
    void *f694;
    unsigned char pad698[0x6A4 - 0x698];
    void *f6A4;
    unsigned char pad6A8[0x80C - 0x6A8];
    int f80C;
    int f810;
    unsigned char pad814[0x818 - 0x814];
    int f818;
    int f81C;
    unsigned char pad820[0x844 - 0x820];
    int f844;
    unsigned char pad848[0x84C - 0x848];
    int f84C;
    void *f850;
    unsigned char pad854[0x85C - 0x854];
    int f85C;
};

struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern int TOUCHPANEL_GetCont(void);
typedef signed int     s32;
typedef unsigned short u16;
typedef unsigned char  u8;
struct Ctx;
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);
struct Row;
extern s32 BLINK_PALANM_Update(struct Row *p);
extern u32 ITEMMENU_HandleScrollbarTouch(u8 *p);
extern void ITEMMENU_RedrawList(char *p);
extern u8 func_020355C4(void);
extern u32 KEY_GetTrg(void);
extern int ITEMMENU_GetItemCount(u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(unsigned int se);
extern void ITEMMENU_DrawMoveInfo(char *p);
extern void ITEMMENU_SetCursorActive(struct Obj *o, int flag);
extern void UI_SetInputMode(u8 v);
extern void ITEMMENU_StartSideButtonPress(int p, int a, int b);
extern int ITEMMENU_IsBrowseMode(u8 *p);
extern int ITEMMENU_ToggleRegisteredItem(struct Obj *o, int k);
extern void ITEMMENU_TogglePocketSortFlag(u8 *p);
extern void ITEMMENU_ShowInputGuardError(u8 *p);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskInputGuardMessage(int p);
extern void ITEMMENU_TaskSelectItemFlash(int p);
extern void MI_CpuFill8(void *p, int v, int n);
extern void func_02007CC8(u8 *base, void *buf, u32 id, int save);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void ITEMMENU_UpdateSideButtonsForMode(int p, int mode);
extern int ITEMMENU_ReturnToListInput(void *p);
extern int ITEMMENU_HandleListKeys(void *o);
extern void ITEMMENU_MoveCursorToRow(char *p);
extern unsigned int KEY_GetRepeat(void);
extern void ITEMMENU_StartPocketTabPress(int p, int u, int a, int b);
extern void ITEMMENU_ReturnToBagMainAlias(void *o);

void ITEMMENU_TaskBagMain(Obj *o)
{
    unsigned int k;
    int v;

    if (PRINTSYS_QUE_IsFinished(o->f50C) == 0)
        return;
    if (TOUCHPANEL_GetCont() == 0)
        o->f85C = 0;
    BUTTON_MAN_UpdateSlots(o->f694);
    BLINK_PALANM_Update(o->f850);
    if (o->f4F8 != ITEMMENU_TaskBagMain)
        return;
    if (ITEMMENU_HandleScrollbarTouch((u8 *)o) != 0) {
        o->f818 = 0xFFFF;
        ITEMMENU_RedrawList((char *)o);
        return;
    }
    if (o->f85C == 1)
        return;
    if (func_020355C4() == 1) {
        k = KEY_GetTrg();
        if (k == 0)
            return;
        if (ITEMMENU_GetItemCount((u8 *)o) != 0) {
            if ((k & 0xC0A) == 0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                ITEMMENU_DrawMoveInfo((char *)o);
                ITEMMENU_SetCursorActive(o, 1);
                return;
            }
        } else {
            ITEMMENU_SetCursorActive(o, 1);
            if (k & 0xCD)
                return;
        }
    }
    if (KEY_GetTrg() & 2) {
        o->f844 = 1;
        o->f84C = 0;
        UI_SetInputMode(0);
        ITEMMENU_StartSideButtonPress((int)o, 4, 0);
        return;
    }
    if (KEY_GetTrg() & 0x400) {
        if (o->f010 == 2)
            return;
        o->f844 = 0;
        o->f84C = 0;
        UI_SetInputMode(0);
        ITEMMENU_StartSideButtonPress((int)o, 3, 0);
        return;
    }
    if (KEY_GetTrg() & 0x800) {
        if (ITEMMENU_IsBrowseMode((u8 *)o) != 1)
            return;
        if (o->f80C == 4) {
            ITEMMENU_ToggleRegisteredItem(o, o->f810);
            ITEMMENU_RedrawList((char *)o);
        } else {
            ITEMMENU_TogglePocketSortFlag((u8 *)o);
        }
        if (func_020355C4() != 1)
            return;
        ITEMMENU_DrawMoveInfo((char *)o);
        ITEMMENU_SetCursorActive(o, 1);
        return;
    }
    if ((KEY_GetTrg() & 8) && o->f80C != 2 && o->f80C != 3 && ITEMMENU_GetItemCount((u8 *)o) > 1) {
        ITEMMENU_ShowInputGuardError((u8 *)o);
        ITEMMENU_SetCursorActive(o, 1);
        o->f818 = 0xFFFF;
        ITEMMENU_RedrawList((char *)o);
        ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskInputGuardMessage));
        return;
    }
    if (KEY_GetTrg() & 1) {
        if (ITEMMENU_GetItemCount((u8 *)o) > 0) {
            ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskSelectItemFlash));
            return;
        }
    } else if (KEY_GetTrg() & 4) {
        if (o->f80C != 2 && o->f80C != 3 && ITEMMENU_GetItemCount((u8 *)o) > 1) {
            MI_CpuFill8(o->f020, 0, 0x4D8);
            func_02007CC8(o->f018, o->f020, o->f80C, 1);
            CLACT_SetActorAnimSeq(o->f6A4, 2);
            ITEMMENU_UpdateSideButtonsForMode((int)o, 0);
            o->f81C = 1;
            ITEMMENU_ReturnToListInput(o);
        }
        return;
    } else if (ITEMMENU_HandleListKeys(o) != 0) {
        ITEMMENU_MoveCursorToRow((char *)o);
        GFL_USE_PlaySeDefaultVolume(0x548);
        ITEMMENU_RedrawList((char *)o);
        return;
    }
    if (KEY_GetRepeat() & 0x10) {
        v = o->f80C;
        o->f80C = v + 1;
        if (o->f80C >= 5)
            o->f80C = 0;
        UI_SetInputMode(0);
        ITEMMENU_StartPocketTabPress((int)o, v, 1, (int)((void *)ITEMMENU_ReturnToBagMainAlias));
        return;
    }
    if (KEY_GetRepeat() & 0x20) {
        v = o->f80C;
        o->f80C = v - 1;
        if (o->f80C < 0)
            o->f80C = 4;
        UI_SetInputMode(0);
        ITEMMENU_StartPocketTabPress((int)o, v, 0, (int)((void *)ITEMMENU_ReturnToBagMainAlias));
    }
}
