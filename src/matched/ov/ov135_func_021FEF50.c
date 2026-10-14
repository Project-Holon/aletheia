/*
 * function: WORLDTRADE_SEARCH_StateConditionMenuInput
 * address: 0x021FEF50
 * packet: pkt_ov135_021FEF50
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_INPUT_MenuUpdate 0x021F99F0 thumb ov135
 *   WORLDTRADE_SEARCH_SetBlendEffect 0x021FF570 thumb ov135
 *   func_0201F7A8 0x0201F7A8 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   BMP_Clear 0x02043B5C arm
 *   WORLDTRADE_ENTER_ClearFlags 0x021F88B0 thumb ov135
 *   WORLDTRADE_DEPOSIT_PrintMessageLine 0x021F8010 thumb ov135
 *   d_02202EAC 0x02202EAC data a4
 *   BMP_WIN_GetBmp  0x02045770  arm  arm9
 */
#include "../include/Obj02204.h"
typedef unsigned short u16;
extern int WORLDTRADE_INPUT_MenuUpdate(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void WORLDTRADE_SEARCH_SetBlendEffect(u32 v);
extern void func_0201F7A8(void *, unsigned);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern const int d_02202EAC;
extern void WORLDTRADE_ENTER_ClearFlags(u8 *p, u32 n);
extern void WORLDTRADE_DEPOSIT_PrintMessageLine(void *, void *, void *, unsigned, unsigned, unsigned, u16, void *);
int WORLDTRADE_SEARCH_StateConditionMenuInput(char *p)
{
    int r;
    void *w;
    r = WORLDTRADE_INPUT_MenuUpdate(((struct Obj02204 *)p)->fDE4);
    if (r == -1) {
    } else if (r == -2 || r == d_02202EAC + 1) {
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        func_0201F7A8(((struct Obj02204 *)p)->fD40, 0);
        w = ((struct Obj02204 *)p)->fD40;
        BMP_WIN_TransferChars(w);
        BMP_WIN_MakeScreen(w);
        func_020409B4(BMP_WIN_GetBgLayer(w));
        ((struct Obj02204 *)p)->f28 = 0;
    } else {
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        WORLDTRADE_ENTER_ClearFlags((u8 *)p, r);
        ((struct Obj02204 *)p)->f28 = 0;
        BMP_Clear(BMP_WIN_GetBmp(((struct Obj02204 *)p)->fDDC), 0);
        WORLDTRADE_DEPOSIT_PrintMessageLine(((struct Obj02204 *)p)->fDDC, ((struct Obj02204 *)p)->fB7C, ((struct Obj02204 *)p)->fB6C, ((struct Obj02204 *)p)->fF84, 0, 0, 0x3c40, p + 0xfa0);
    }
    return 2;
}
