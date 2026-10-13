/*
 * function: ITEMMENU_TaskTossConfirmInput
 * address:  0x021B7700
 * packet:   pkt_ov070_021B7700
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
 *   ITEMMENU_CloseYesNoList  0x021BB1AC  thumb  ov070
 *   func_020414EC  0x020414EC  arm
 *   func_020061E4  0x020061E4  thumb
 *   ITEMMENU_RemoveSelectedItems  0x021B7D20  thumb  ov070
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   ITEMMENU_RegisterItemNameCounted  0x021B6204  thumb  ov070
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   ITEMMENU_ShowMessageDefault  0x021BADAC  thumb  ov070
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskBeginReturnToList  0x021B76E4  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   ITEMMENU_UpdateSideButtons  0x021BB3F4  thumb  ov070
 *   func_020355C4  0x020355C4  arm
 *   ITEMMENU_SetCursorActive  0x021B80C4  thumb  ov070
 *   ITEMMENU_ReturnToBagMain  0x021B8AF4  thumb  ov070
 */

typedef struct Obj {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x6A8 - 0x52C];
    void *f6A8;
    unsigned char pad6AC[0x77C - 0x6AC];
    void *f77C;
    unsigned char pad780[0x7F4 - 0x780];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
struct WordSet;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void ITEMMENU_CloseYesNoList(char *p);
extern void func_020414EC(u32 i);
extern void func_020061E4(unsigned int se);
extern void ITEMMENU_RemoveSelectedItems(struct Obj *o, int x);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void ITEMMENU_RegisterItemNameCounted(u8 *p, int a, unsigned int b, int c, int d);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void ITEMMENU_ShowMessageDefault(void *p);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskBeginReturnToList(int p);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void ITEMMENU_UpdateSideButtons(int p, int mode);
extern u8 func_020355C4(void);
extern void ITEMMENU_SetCursorActive(Obj *o, int v);
extern void ITEMMENU_ReturnToBagMain(void *p);

void ITEMMENU_TaskTossConfirmInput(Obj *o)
{
    int r;
    int v;

    if (APP_TASKMENU_IsFinish(o->f77C) == 0)
        return;
    r = APP_TASKMENU_GetCursorPos(o->f77C);
    ITEMMENU_CloseYesNoList((char *)o);
    func_020414EC(3);
    if (r == 0) {
        func_020061E4(0x647);
        ITEMMENU_RemoveSelectedItems(o, o->f7F4);
        MSGDATA_ReadString(o->f51C, 0x36, (void *)o->f524);
        ITEMMENU_RegisterItemNameCounted((u8 *)o, 0, o->f84C, o->f7F4 > 1, 0);
        func_0201EFA4(o->f520, 1, o->f7F4, 3, 0, 1);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        ITEMMENU_ShowMessageDefault(o);
        ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskBeginReturnToList));
    } else {
        func_0204B92C(o->f6A8, 1);
        v = 1;
        ITEMMENU_UpdateSideButtons((int)o, 1);
        if (func_020355C4() != 0)
            v = 0;
        ITEMMENU_SetCursorActive(o, v);
        ITEMMENU_ReturnToBagMain(o);
    }
}
