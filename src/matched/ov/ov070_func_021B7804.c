/*
 * function: ITEMMENU_TaskTossAskQuantity
 * address:  0x021B7804
 * packet:   pkt_ov070_021B7804
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ITEMMENU_ShowQuantityWindows  0x021B7D9C  thumb  ov070
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   ITEMMENU_RegisterItemNameCounted  0x021B6204  thumb  ov070
 *   func_0201F250  0x0201F250  thumb
 *   ITEMMENU_ShowMessageDefault  0x021BADAC  thumb  ov070
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskTossQuantityInput  0x021B7868  thumb  ov070
 */

typedef struct Obj {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x7F4 - 0x52C];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj;

typedef unsigned char  u8;
extern void ITEMMENU_ShowQuantityWindows(u8 *p, int v);
typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void ITEMMENU_RegisterItemNameCounted(u8 *p, int a, unsigned int b, int c, int d);
struct WordSet;
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void ITEMMENU_ShowMessageDefault(void *p);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskTossQuantityInput(struct Obj *o);

void ITEMMENU_TaskTossAskQuantity(Obj *o)
{
    o->f7F4 = 1;
    ITEMMENU_ShowQuantityWindows((u8 *)o, 1);
    MSGDATA_ReadString(o->f51C, 0x35, (void *)o->f524);
    ITEMMENU_RegisterItemNameCounted((u8 *)o, 0, o->f84C, 1, 0);
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    ITEMMENU_ShowMessageDefault(o);
    ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskTossQuantityInput));
}
