/*
 * function: ITEMMENU_TaskSellConfirmInput
 * address:  0x021B7B80
 * packet:   pkt_ov070_021B7B80
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ITEMMENU_IsMessageFinished  0x021BADF0  thumb  ov070
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *   ITEMMENU_CloseYesNoList  0x021BB1AC  thumb  ov070
 *   ITEMMENU_GetSellTotal  0x021B619C  thumb  ov070
 *   ITEMMENU_RemoveSelectedItems  0x021B7D20  thumb  ov070
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   MISC_AddMoney  0x0200C278  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   ITEMMENU_PrintMoney  0x021BAFC4  thumb  ov070
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   ITEMMENU_RegisterItemNameCounted  0x021B6204  thumb  ov070
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   ITEMMENU_ShowMessageDefault  0x021BADAC  thumb  ov070
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskWaitMessageDismiss  0x021B7C88  thumb  ov070
 *   func_020355C4  0x020355C4  arm
 *   ITEMMENU_SetCursorActive  0x021B80C4  thumb  ov070
 *   ITEMMENU_TaskReturnToListFromQuantity  0x021B7CD0  thumb  ov070
 */

typedef unsigned short u16;

typedef struct Obj {
    void *f000;
    unsigned char pad004[0x51C - 0x004];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x77C - 0x546];
    void *f77C;
    unsigned char pad780[0x7F4 - 0x780];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj;

extern int ITEMMENU_IsMessageFinished(int p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
struct WordSet;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
struct Blk34;
struct MsgBank;
extern void ITEMMENU_CloseYesNoList(char *p);
extern int ITEMMENU_GetSellTotal(int a, int b, unsigned int id);
extern void ITEMMENU_RemoveSelectedItems(struct Obj *o, int x);
extern void *GAME_DATA_GetMiscSave(int *p);
extern u32 MISC_AddMoney(struct Blk34 *p, u32 v);
extern void GFL_USE_PlaySeDefaultVolume(unsigned int id);
extern void ITEMMENU_PrintMoney(u8 *p);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void ITEMMENU_RegisterItemNameCounted(u8 *p, int a, unsigned int b, int c, int d);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void ITEMMENU_ShowMessageDefault(void *p);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskWaitMessageDismiss();
extern u8 func_020355C4(void);
extern void ITEMMENU_SetCursorActive(Obj *o, int v);
extern void ITEMMENU_TaskReturnToListFromQuantity(struct Obj *o);

void ITEMMENU_TaskSellConfirmInput(Obj *o)
{
    int r;
    int v;

    if (ITEMMENU_IsMessageFinished((int)o) == 0)
        return;
    if (APP_TASKMENU_IsFinish(o->f77C) == 0)
        return;
    r = APP_TASKMENU_GetCursorPos(o->f77C);
    ITEMMENU_CloseYesNoList((char *)o);
    switch (r) {
    case 0:
        v = ITEMMENU_GetSellTotal(o->f84C, o->f7F4, o->f544);
        ITEMMENU_RemoveSelectedItems(o, o->f7F4);
        MISC_AddMoney((struct Blk34 *)((unsigned int)GAME_DATA_GetMiscSave(o->f000)), v);
        GFL_USE_PlaySeDefaultVolume(0x655);
        ITEMMENU_PrintMoney((u8 *)o);
        MSGDATA_ReadString(o->f51C, 0x50, (void *)o->f524);
        ITEMMENU_RegisterItemNameCounted((u8 *)o, 0, o->f84C, o->f7F4 > 1, 0);
        WORDSET_SetSlotNumber(o->f520, 1, v, 7, 0, 1);
        WORDSET_CopyTaggedText(o->f520, o->f528, (void *)o->f524);
        ITEMMENU_ShowMessageDefault(o);
        ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskWaitMessageDismiss));
        break;
    case 1:
        ITEMMENU_SetCursorActive(o, func_020355C4() == 0);
        ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskReturnToListFromQuantity));
        break;
    }
}
