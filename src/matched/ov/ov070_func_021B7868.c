/*
 * function: ITEMMENU_TaskTossQuantityInput
 * address:  0x021B7868
 * packet:   pkt_ov070_021B7868
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ITEMMENU_IsMessageFinished  0x021BADF0  thumb  ov070
 *   ITEMMENU_HandleQuantityInput  0x021B7DF4  thumb  ov070
 *   ITEMMENU_CheckTouchRelease  0x021B8DAC  thumb  ov070
 *   KEY_GetTrg  0x020362DC  arm
 *   func_020355D8  0x020355D8  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   ITEMMENU_HideQuantityWindows  0x021B7DD0  thumb  ov070
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   ITEMMENU_RegisterItemNameCounted  0x021B6204  thumb  ov070
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   ITEMMENU_ShowMessageDefault  0x021BADAC  thumb  ov070
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskOpenTossConfirm  0x021B77E4  thumb  ov070
 *   ITEMMENU_StartSideButtonPress  0x021B8C1C  thumb  ov070
 *   ITEMMENU_TaskReopenListFromQuantity  0x021B8DCC  thumb  ov070
 */

typedef unsigned int u32;

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

struct MsgBank;
extern int ITEMMENU_IsMessageFinished(int p);
extern int ITEMMENU_HandleQuantityInput(Obj *o);
extern int ITEMMENU_CheckTouchRelease(void);
extern u32 KEY_GetTrg(void);
typedef unsigned char  u8;
struct WordSet;
extern void func_020355D8(u8 v);
extern void GFL_USE_PlaySeDefaultVolume(unsigned int id);
extern void ITEMMENU_HideQuantityWindows(u8 *p);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void ITEMMENU_RegisterItemNameCounted(u8 *p, int a, unsigned int b, int c, int d);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void ITEMMENU_ShowMessageDefault(void *p);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskOpenTossConfirm(int p);
extern void ITEMMENU_StartSideButtonPress(int p, int a, int b);
extern void ITEMMENU_TaskReopenListFromQuantity(char *p);

void ITEMMENU_TaskTossQuantityInput(Obj *o)
{
    int r;

    if (ITEMMENU_IsMessageFinished((int)o) == 0)
        return;
    if (ITEMMENU_HandleQuantityInput(o) == 1)
        return;
    r = ITEMMENU_CheckTouchRelease();
    if (r == -1) {
        if (KEY_GetTrg() & 1) {
            r = 0;
            func_020355D8(0);
        } else if (KEY_GetTrg() & 2) {
            func_020355D8(0);
            r = 1;
        }
    }
    if (r == 0) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        ITEMMENU_HideQuantityWindows((u8 *)o);
        MSGDATA_ReadString(o->f51C, 0x37, (void *)o->f524);
        ITEMMENU_RegisterItemNameCounted((u8 *)o, 0, o->f84C, o->f7F4 > 1, 0);
        WORDSET_SetSlotNumber(o->f520, 1, o->f7F4, 3, 0, 1);
        WORDSET_CopyTaggedText(o->f520, o->f528, (void *)o->f524);
        ITEMMENU_ShowMessageDefault(o);
        ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskOpenTossConfirm));
        return;
    }
    if (r == 1) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        ITEMMENU_StartSideButtonPress((int)o, 4, (int)((void *)ITEMMENU_TaskReopenListFromQuantity));
    }
}
