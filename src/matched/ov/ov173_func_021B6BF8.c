/*
 * function: func_021B6BF8
 * address: 0x021B6BF8
 * packet: pkt_ov173_021B6BF8
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: separate u8 width result from u8 coordinate x; otherwise 16 bytes
 *   differ from index/font/x register rotation. Both cases preserve byte
 *   width narrowing and signed division by two before coordinate wrap.
 * domain: all nine direct ov173 calls use align 0..2; sites 021B6CE2=2,
 *   6D00=0,6D36=0,6D90=0,6E24=0,6F88=1,7242=1,728C=1,72B8=0.
 *   At 6DC4 r7 copies zero r4 and stays invariant; at 6F5E r4 becomes 1.
 *   No defined coordinate exists in the original outside this domain.
 * extent: 138 bytes code; +0x8A 00 00 alignment padding, next labelled
 *   function 021B6C84 at +0x8C. No follower or unit.
 * symbols:
 *   func_0201D304 0x0201D304 thumb
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 */
#include "../include/Obj10668.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor;
struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_PrintColor(void *, s16, s16, void *, u8, u16);
u32 func_021B6BF8(char *p, int index, u8 font, u16 w, int align, u8 y)
{
    u8 x;
    u8 width;
    switch (align) {
    case 0: x = 0; break;
    case 1:
        width = (u8)func_0201D304(((struct Obj10668 *)p)->f4C, font, 0);
        x = (u8)((u8)(BMP_WIN_GetWidth(*(void **)(p + index * 4 + 4)) * 8) - width);
        break;
    case 2:
        width = (u8)func_0201D304(((struct Obj10668 *)p)->f4C, font, 0);
        x = (u8)(((int)(u8)(BMP_WIN_GetWidth(*(void **)(p + index * 4 + 4)) * 8) - width) / 2);
        break;
    }
    return PRINTSYS_PrintColor(BMP_WIN_GetBmp(*(void **)(p + index * 4 + 4)), x, y, ((struct Obj10668 *)p)->f4C, font, w);
}
