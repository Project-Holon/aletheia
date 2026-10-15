/*
 * function: WORLDTRADE_SEARCH_StateGenderMenuInput
 * address: 0x021FED6C
 * packet: pkt_ov135_021FED6C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_INPUT_MenuUpdate 0x021F99F0 thumb ov135
 *   WORLDTRADE_SEARCH_SetBlendEffect 0x021FF570 thumb ov135
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   BMP_Clear 0x02043B5C arm
 *   WORLDTRADE_DEPOSIT_PrintModeLabelAligned 0x021F8098 thumb ov135
 *   BMP_WIN_GetBmp  0x02045770  arm  arm9
 */
#include "../include/Obj02861.h"
typedef unsigned short u16;
extern int WORLDTRADE_INPUT_MenuUpdate(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void WORLDTRADE_SEARCH_SetBlendEffect(u32 v);
extern void BMP_MENUWORK_DrawWindowBorder(void *, unsigned);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void WORLDTRADE_DEPOSIT_PrintModeLabelAligned(void *, void *, int, int, unsigned, int, u16, void *);
int WORLDTRADE_SEARCH_StateGenderMenuInput(char *p)
{
    unsigned r;
    void *w;
    r = WORLDTRADE_INPUT_MenuUpdate(((struct Obj02861 *)p)->fDE4);
    switch (r) {
    case -2:
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        BMP_MENUWORK_DrawWindowBorder(((struct Obj02861 *)p)->fD40, 0);
        w = ((struct Obj02861 *)p)->fD40;
        BMP_WIN_TransferChars(w);
        BMP_WIN_MakeScreen(w);
        func_020409B4(BMP_WIN_GetBgLayer(w));
        ((struct Obj02861 *)p)->f28 = 0;
        break;
    case 0:
    case 1:
    case 2:
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        ((struct Obj02861 *)p)->fB58 = r + 1;
        ((struct Obj02861 *)p)->f28 = 0;
        BMP_Clear(BMP_WIN_GetBmp(((struct Obj02861 *)p)->fD9C), 0);
        WORLDTRADE_DEPOSIT_PrintModeLabelAligned(((struct Obj02861 *)p)->fD9C, ((struct Obj02861 *)p)->fB6C, ((struct Obj02861 *)p)->fB58, 1, 0, 0, 0x3c40, p + 0xfa0);
        break;
    }
    return 2;
}
