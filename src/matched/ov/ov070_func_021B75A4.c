/*
 * function: ITEMMENU_TaskRegisterResultMessage
 * address:  0x021B75A4
 * packet:   pkt_ov070_021B75A4
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02006238  0x02006238  thumb
 *   func_020362DC  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_020212B0  0x020212B0  thumb
 *   func_0201EF34  0x0201EF34  thumb
 *   func_0201F250  0x0201F250  thumb
 *   ITEMMENU_ShowMessage  0x021BACF0  thumb  ov070
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskOpenActionMenu  0x021B7584  thumb  ov070
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x84C - 0x52C];
    unsigned int f84C;
} Obj;

extern int func_02006238(void);
extern u32 func_020362DC(void);
extern int TOUCHPANEL_GetTrg(void);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u16 func_020212B0(u16 id);
struct WordSet;
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void ITEMMENU_ShowMessage(int p, int mode);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskOpenActionMenu(int p);

void ITEMMENU_TaskRegisterResultMessage(Obj *o)
{
    if (func_02006238() == 1)
        return;
    if ((func_020362DC() & 3) == 0 && TOUCHPANEL_GetTrg() == 0)
        return;
    MSGDATA_ReadString(o->f51C, 0x3E, (void *)o->f524);
    func_0201EF34(o->f520, 0, func_020212B0(o->f84C));
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    ITEMMENU_ShowMessage((int)o, 1);
    ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskOpenActionMenu));
}
