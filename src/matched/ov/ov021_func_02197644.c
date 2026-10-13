/*
 * function: IRCBATTLEMENU_PrintMessage
 * address:  0x02197644
 * packet:   pkt_ov021_02197644
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_Create  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   func_0201F73C  0x0201F73C  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00094.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
typedef signed short   s16;
struct Cfg;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern signed char func_02012FFC(void);
extern u32 PRINTSYS_PrintStream(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32);

void IRCBATTLEMENU_PrintMessage(u8 *a, u32 b)
{
    u32 t;

    if (*(u32 *)&((struct Obj00094 *)a)->f2B0 == 0) {
        *(u32 *)&((struct Obj00094 *)a)->f2B0 = BMP_WIN_Create(5, 1, 3, 30, 4, 11, 1);
    }
    t = *(u32 *)&((struct Obj00094 *)a)->f2B0;
    BMP_Clear((struct CharBuf *)((u32)func_02045770((struct Descriptor *)t)), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    if (b == 0) {
        *(u32 *)&((struct Obj00094 *)a)->f2B4 = PRINTSYS_PrintStream(t, 0, 0, ((struct Obj00094 *)a)->f38, ((struct Obj00094 *)a)->f2C, func_02012FFC(), ((struct Obj00094 *)a)->f2B8, 2, ((struct Obj00094 *)a)->f10, 15);
    } else {
        PRINTSYS_Print((void *)((u32)func_02045770((struct Descriptor *)t)), 0, 0, (void *)(((struct Obj00094 *)a)->f38), (void *)(((struct Obj00094 *)a)->f2C));
        *(u32 *)&((struct Obj00094 *)a)->f2B4 = 0;
    }
    func_0201F73C((void *)t, 1, (u16)((struct Obj00094 *)a)->f3C, 12);
    BMP_WIN_TransferChars((struct Descriptor *)t);
    BMP_WIN_MakeScreen((struct Cfg *)t);
    func_02041B6C(5);
}
