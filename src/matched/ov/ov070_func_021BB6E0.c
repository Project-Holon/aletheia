/*
 * function: ITEMMENU_PrintToWindow
 * address:  0x021BB6E0
 * packet:   pkt_ov070_021BB6E0
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Prints str into the window obj with the print context at p+0x50C and the
 * font at p+0x530, then marks the window dirty. x is a u16 parameter
 * narrowed to s16 at the call: an int x spilled r3 late and reloaded it
 * early (same size, scheduling-only DIFF).
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 */
#include "../include/Obj01516.h"

typedef unsigned int u32;
typedef signed short s16;
typedef unsigned short u16;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

void ITEMMENU_PrintToWindow(int p, u32 *obj, u32 str, u16 x, s16 y, u16 color)
{
    u32 print = ((struct Obj01516 *)p)->f50C;

    PRINTSYS_PrintQueColor((void *)print, (u32)BMP_WIN_GetBmp((struct Descriptor *)*obj), (s16)x, y, str, ((struct Obj01516 *)p)->f530, color);
    *((unsigned char *)obj + 4) = 1;
}
