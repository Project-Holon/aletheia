/*
 * function: ITEMMENU_TaskSelectItem
 * address:  0x021B7128
 * packet:   pkt_ov070_021B7128
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ITEMMENU_GetCursorIndex  0x021B61B8  thumb  ov070
 *   ITEMMENU_GetSlot  0x021B616C  thumb  ov070
 *   func_02020FE4  0x02020FE4  thumb
 *   PALANM_IsOutsideReservedIdRange  0x020213E0  thumb
 *   func_0202136C  0x0202136C  thumb
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   ITEMMENU_RegisterItemName  0x021B61F4  thumb  ov070
 *   func_0201F250  0x0201F250  thumb
 *   ITEMMENU_ShowMessageDefault  0x021BADAC  thumb  ov070
 *   ITEMMENU_UpdateSideButtons  0x021BB3F4  thumb  ov070
 *   ITEMMENU_SetBackButtonAnim  0x021BB580  thumb  ov070
 *   ITEMMENU_TaskReturnToListAfterMessage  0x021B7688  thumb  ov070
 *   ITEMMENU_TaskGiveItem  0x021B795C  thumb  ov070
 *   ITEMMENU_OpenActionMenu  0x021B832C  thumb  ov070
 *   ITEMMENU_ShowItemUseMessage  0x021BADB8  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   ITEMMENU_HandleActionMenuChoice  0x021B6EF8  thumb  ov070
 */

typedef unsigned short u16;

typedef struct Obj {
    unsigned char pad000[0x10];
    int f010;
    unsigned char pad014[0x51C - 0x014];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x6A8 - 0x546];
    void *f6A8;
    unsigned char pad6AC[0x844 - 0x6AC];
    int f844;
    unsigned char pad848[0x84C - 0x848];
    unsigned int f84C;
} Obj;

extern int ITEMMENU_GetCursorIndex(unsigned char *p);
extern void *ITEMMENU_GetSlot(unsigned char *p, int i);
extern unsigned int func_02020FE4(u16 id, unsigned int sel, u16 heap);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct WordSet;
extern u32 PALANM_IsOutsideReservedIdRange(u16 v);
extern unsigned int func_0202136C(u16 v);
extern void ITEMMENU_SetTask(char *p, int k);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void ITEMMENU_RegisterItemName(u8 *p, int a, unsigned int b);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void ITEMMENU_ShowMessageDefault(void *p);
extern void ITEMMENU_UpdateSideButtons(int p, int mode);
extern void ITEMMENU_SetBackButtonAnim(char *p, int v);
extern void ITEMMENU_TaskReturnToListAfterMessage(struct Obj *o);
extern void ITEMMENU_TaskGiveItem(struct Obj *o);
extern void ITEMMENU_OpenActionMenu(struct Obj *p);
extern void ITEMMENU_ShowItemUseMessage(char *p, unsigned v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void ITEMMENU_HandleActionMenuChoice(u8 *p);

void ITEMMENU_TaskSelectItem(Obj *o)
{
    u16 *p;
    int s;

    p = ITEMMENU_GetSlot((unsigned char *)o, ITEMMENU_GetCursorIndex((unsigned char *)o));
    o->f84C = 0;
    if (p != 0)
        o->f84C = *p;
    s = o->f010;
    if (s == 2) {
        if (func_02020FE4(o->f84C, 3, o->f544) == 0 && PALANM_IsOutsideReservedIdRange(o->f84C) == 1) {
            if (func_0202136C(o->f84C) != 0)
                o->f844 = 0x12;
            else
                o->f844 = 3;
            ITEMMENU_SetTask((char *)o, 0);
            return;
        }
        MSGDATA_ReadString(o->f51C, 0x2F, (void *)o->f524);
        ITEMMENU_RegisterItemName((u8 *)o, 0, o->f84C);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        ITEMMENU_ShowMessageDefault(o);
        ITEMMENU_UpdateSideButtons((int)o, 0);
        ITEMMENU_SetBackButtonAnim((char *)o, 0);
        ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskReturnToListAfterMessage));
    } else if (s == 5) {
        o->f844 = 1;
        ITEMMENU_SetTask((char *)o, 0);
    } else if (s == 4) {
        ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskGiveItem));
    } else {
        ITEMMENU_OpenActionMenu((struct Obj *)o);
        ITEMMENU_ShowItemUseMessage((char *)o, o->f84C);
        ITEMMENU_ShowMessageDefault(o);
        func_0204B92C(o->f6A8, 0);
        ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_HandleActionMenuChoice));
    }
}
