/*
 * function: func_021ECE60
 * address:  0x021ECE60
 * packet:   pkt_ov093_021ECE60
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_Clear  0x02043B5C  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 */
#include "../include/Obj02796.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
typedef unsigned int   u32;
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);

void func_021ECE60(u8 *a, int b)
{
    BMP_Clear((struct CharBuf *)(((struct Obj02796 *)a)->f4), 0xc);
    GF_FONT_SetTextColor(1, 9, 0xc);
    PRINTSYS_Print((void *)(((struct Obj02796 *)a)->f4), 0, 0, (void *)b, (void *)(((struct Obj02796 *)a)->f24));
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj02796 *)a)->f0);
    a[0x13f] = 0;
    ((struct Obj02796 *)a)->f148 = 0;
    ((struct Obj02796 *)a)->f14A = 0;
    ((struct Obj02796 *)a)->f14C = 0;
    a[0x13e] = 1;
    a[0x141] = 0;
}
