/*
 * function: GSYNC_MENU_PrintMessage
 * address: 0x021D4EF0
 * packet: pkt_ov123_021D4EF0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj02473.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
typedef signed short   s16;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern signed char MSG_SPEED_GetWait(void);
extern void *PRINTSYS_PrintStream(void *, int, int, void *, void *, void *, void *, int, u16, int);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void GSYNC_MENU_PrintMessage(char *p, int n, int flag)
{
    void *obj;
    if (((struct Obj02473 *)p)->f224 == 0)
        ((struct Obj02473 *)p)->f224 = (void *)BMP_WIN_Create(5, 1, 3, 30, (u8)n, 13, 1);
    obj = ((struct Obj02473 *)p)->f224;
    BMP_Clear(BMP_WIN_GetBmp(obj), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    if (flag) {
        void *value;
        value = (void *)MSG_SPEED_GetWait();
        ((struct Obj02473 *)p)->f228 = PRINTSYS_PrintStream(obj, 0, 0, ((struct Obj02473 *)p)->f38, ((struct Obj02473 *)p)->f30, value, ((struct Obj02473 *)p)->f230, 2, ((struct Obj02473 *)p)->fC, 15);
    } else {
        PRINTSYS_Print(BMP_WIN_GetBmp(obj), 0, 0, ((struct Obj02473 *)p)->f38, ((struct Obj02473 *)p)->f30);
    }
    BMP_MENUWORK_DrawWindow(obj, 1, (u16)(((struct Obj02473 *)p)->f3C), 12);
    BMP_WIN_TransferChars(obj);
    BMP_WIN_MakeScreen(obj);
    func_02041B6C(5);
}
