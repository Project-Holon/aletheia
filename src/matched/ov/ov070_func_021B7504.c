/*
 * function: ITEMMENU_TaskActionMenuInput
 * address:  0x021B7504
 * packet:   pkt_ov070_021B7504
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *   ITEMMENU_ClearMessageWindow  0x021BA9AC  thumb  ov070
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   func_020414EC  0x020414EC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   ITEMMENU_UpdateSideButtons  0x021BB3F4  thumb  ov070
 *   func_020355C4  0x020355C4  arm
 *   ITEMMENU_HideMoveInfo  0x021B9AAC  thumb  ov070
 *   ITEMMENU_SetCursorActive  0x021B80C4  thumb  ov070
 *   ITEMMENU_ReturnToBagMain  0x021B8AF4  thumb  ov070
 *   ITEMMENU_CloseYesNoList  0x021BB1AC  thumb  ov070
 */

typedef struct Obj {
    unsigned char pad000[0x6A8];
    void *f6A8;
    unsigned char pad6AC[0x77C - 0x6AC];
    void *f77C;
    unsigned char pad780[0x844 - 0x780];
    int f844;
} Obj;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void ITEMMENU_ClearMessageWindow(char *p);
extern void ITEMMENU_SetTask(char *p, int k);
extern void func_020414EC(u32 i);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void ITEMMENU_UpdateSideButtons(int p, int mode);
extern u8 func_020355C4(void);
extern void ITEMMENU_HideMoveInfo(char *p);
extern void ITEMMENU_SetCursorActive(Obj *o, int v);
extern void ITEMMENU_ReturnToBagMain(void *p);
extern void ITEMMENU_CloseYesNoList(char *p);

void ITEMMENU_TaskActionMenuInput(Obj *o)
{
    if (APP_TASKMENU_IsFinish(o->f77C) == 0)
        return;
    if (APP_TASKMENU_GetCursorPos(o->f77C) == 0) {
        ITEMMENU_ClearMessageWindow((char *)o);
        o->f844 = 6;
        ITEMMENU_SetTask((char *)o, 0);
    } else {
        ITEMMENU_ClearMessageWindow((char *)o);
        func_020414EC(3);
        func_0204B92C(o->f6A8, 1);
        ITEMMENU_UpdateSideButtons((int)o, 1);
        if (func_020355C4() == 1) {
            ITEMMENU_HideMoveInfo((char *)o);
            ITEMMENU_SetCursorActive(o, 0);
        } else {
            ITEMMENU_SetCursorActive(o, 1);
        }
        ITEMMENU_ReturnToBagMain(o);
    }
    ITEMMENU_CloseYesNoList((char *)o);
}
