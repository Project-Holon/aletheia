/*
 * function: ITEMMENU_TaskGiveItem
 * address:  0x021B795C
 * packet:   pkt_ov070_021B795C
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B92C  0x0204B92C  arm
 *   func_02020FE4  0x02020FE4  thumb
 *   ITEMMENU_UpdateSideButtons  0x021BB3F4  thumb  ov070
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   ITEMMENU_RegisterItemName  0x021B61F4  thumb  ov070
 *   func_0201F250  0x0201F250  thumb
 *   ITEMMENU_ShowMessageDefault  0x021BADAC  thumb  ov070
 *   ITEMMENU_SetBackButtonAnim  0x021BB580  thumb  ov070
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskWaitMessageDismiss  0x021B7C88  thumb  ov070
 *   ITEMMENU_EnterQuantityMode  0x021BB08C  thumb  ov070
 *   ITEMMENU_GetCursorIndex  0x021B61B8  thumb  ov070
 *   ITEMMENU_GetSlot  0x021B616C  thumb  ov070
 *   ITEMMENU_TaskSellAskConfirm  0x021B7B08  thumb  ov070
 *   ITEMMENU_ShowQuantityWindows  0x021B7D9C  thumb  ov070
 *   ITEMMENU_TaskSellQuantityInput  0x021B7A7C  thumb  ov070
 */

typedef unsigned short u16;

typedef struct Obj {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x6A8 - 0x546];
    void *f6A8;
    unsigned char pad6AC[0x7F4 - 0x6AC];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj;

typedef unsigned int   u32;
struct WordSet;
extern void func_0204B92C(struct Obj *p, u32 v);
extern unsigned int func_02020FE4(u16 id, unsigned int sel, u16 heap);
struct MsgBank;
extern void ITEMMENU_UpdateSideButtons(int p, int mode);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
typedef unsigned char  u8;
extern void ITEMMENU_RegisterItemName(u8 *p, int a, unsigned int b);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void ITEMMENU_ShowMessageDefault(void *p);
extern void ITEMMENU_SetBackButtonAnim(char *p, int v);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskWaitMessageDismiss();
extern void ITEMMENU_EnterQuantityMode(char *p);
extern int ITEMMENU_GetCursorIndex(u8 *p);
extern u16 *ITEMMENU_GetSlot(Obj *o, int k);
extern void ITEMMENU_TaskSellAskConfirm(struct Obj *o);
extern void ITEMMENU_ShowQuantityWindows(u8 *p, int v);
extern void ITEMMENU_TaskSellQuantityInput();

void ITEMMENU_TaskGiveItem(Obj *o)
{
    unsigned int a;
    unsigned int b;

    func_0204B92C(o->f6A8, 0);
    a = func_02020FE4(o->f84C, 0, o->f544);
    b = func_02020FE4(o->f84C, 3, o->f544);
    if (a == 0 || b != 0) {
        ITEMMENU_UpdateSideButtons((int)o, 0);
        MSGDATA_ReadString(o->f51C, 0x4D, (void *)o->f524);
        ITEMMENU_RegisterItemName((u8 *)o, 0, o->f84C);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        ITEMMENU_ShowMessageDefault(o);
        ITEMMENU_SetBackButtonAnim((char *)o, 0);
        ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskWaitMessageDismiss));
        return;
    }
    o->f7F4 = 1;
    ITEMMENU_EnterQuantityMode((char *)o);
    ITEMMENU_UpdateSideButtons((int)o, 0);
    if (ITEMMENU_GetSlot(o, ITEMMENU_GetCursorIndex((u8 *)o))[1] == 1) {
        ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskSellAskConfirm));
        return;
    }
    ITEMMENU_ShowQuantityWindows((u8 *)o, 2);
    MSGDATA_ReadString(o->f51C, 0x4E, (void *)o->f524);
    ITEMMENU_RegisterItemName((u8 *)o, 0, o->f84C);
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    ITEMMENU_ShowMessageDefault(o);
    ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskSellQuantityInput));
}
