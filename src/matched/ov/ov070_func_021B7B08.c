/*
 * function: ITEMMENU_TaskSellAskConfirm
 * address:  0x021B7B08
 * packet:   pkt_ov070_021B7B08
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ITEMMENU_OpenYesNoList  0x021BB0F8  thumb  ov070
 *   ITEMMENU_GetSellTotal  0x021B619C  thumb  ov070
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   ITEMMENU_ShowMessageDefault  0x021BADAC  thumb  ov070
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskSellConfirmInput  0x021B7B80  thumb  ov070
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
    unsigned char pad546[0x7F4 - 0x546];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj;

extern void ITEMMENU_OpenYesNoList(int p);
extern int ITEMMENU_GetSellTotal(int a, int b, unsigned int id);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, unsigned int index, void *dest);
typedef unsigned int   u32;
struct WordSet;
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void ITEMMENU_ShowMessageDefault(void *p);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskSellConfirmInput(struct Obj *o);

void ITEMMENU_TaskSellAskConfirm(Obj *o)
{
    int v;

    ITEMMENU_OpenYesNoList((int)o);
    v = ITEMMENU_GetSellTotal(o->f84C, o->f7F4, o->f544);
    MSGDATA_ReadString(o->f51C, 0x4F, (void *)o->f524);
    func_0201EFA4(o->f520, 0, v, 7, 0, 1);
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    ITEMMENU_ShowMessageDefault(o);
    ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskSellConfirmInput));
}
