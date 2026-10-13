/*
 * function: func_02200BAC
 * address:  0x02200BAC
 * packet:   pkt_02200BAC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Create  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_021F9218  0x021F9218  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */
#include "../include/Obj00345.h"

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct Cfg;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_021F9218(void *win, void *bank, int idx, void *g);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 v);

void func_02200BAC(u8 *p, u32 k)
{
    u32 v;

    ((struct Obj00345 *)p)->fDE0 = BMP_WIN_Create(4, 0xc, 0x13, 0x12, 4, 1, 1);
    BMP_Clear((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00345 *)p)->fDE0)), 0);
    func_021F9218((void *)(((struct Obj00345 *)p)->fDE0), (void *)(((struct Obj00345 *)p)->fB6C), k, p + 0xfa0);
    v = ((struct Obj00345 *)p)->fDE0;
    BMP_WIN_TransferChars((struct Descriptor *)v);
    BMP_WIN_MakeScreen((struct Cfg *)v);
    func_02041B6C(func_02045730((struct Descriptor *)v));
}
