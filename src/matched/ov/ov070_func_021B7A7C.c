/*
 * function: ITEMMENU_TaskSellQuantityInput
 * address:  0x021B7A7C
 * packet:   pkt_ov070_021B7A7C
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
 *   func_020362DC  0x020362DC  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020061E4  0x020061E4  thumb
 *   ITEMMENU_HideQuantityWindows  0x021B7DD0  thumb  ov070
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_StartSideButtonPress  0x021B8C1C  thumb  ov070
 *   ITEMMENU_TaskSellAskConfirm  0x021B7B08  thumb  ov070
 *   ITEMMENU_TaskReturnFromQuantity  0x021B8E08  thumb  ov070
 */

typedef unsigned int u32;

typedef struct Obj Obj;

extern int ITEMMENU_IsMessageFinished(int p);
typedef unsigned char  u8;
extern int ITEMMENU_HandleQuantityInput(struct Obj *o);
extern int ITEMMENU_CheckTouchRelease(void);
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern void func_020061E4(unsigned int id);
extern void ITEMMENU_HideQuantityWindows(u8 *p);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_StartSideButtonPress(int p, int a, int b);
extern void ITEMMENU_TaskSellAskConfirm(struct Obj *o);
extern void ITEMMENU_TaskReturnFromQuantity(unsigned char *p);

void ITEMMENU_TaskSellQuantityInput(Obj *o)
{
    int r;

    if (ITEMMENU_IsMessageFinished((int)o) == 0)
        return;
    if (ITEMMENU_HandleQuantityInput(o) == 1)
        return;
    r = ITEMMENU_CheckTouchRelease();
    if (r == -1) {
        if (func_020362DC() & 1) {
            r = 0;
            func_020355D8(0);
        } else if (func_020362DC() & 2) {
            func_020355D8(0);
            r = 1;
        }
    }
    if (r == 0) {
        func_020061E4(0x54C);
        ITEMMENU_HideQuantityWindows((u8 *)o);
        ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskSellAskConfirm));
        return;
    }
    if (r == 1) {
        func_020061E4(0x551);
        ITEMMENU_StartSideButtonPress((int)o, 4, (int)((void *)ITEMMENU_TaskReturnFromQuantity));
    }
}
