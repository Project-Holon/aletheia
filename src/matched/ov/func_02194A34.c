/*
 * function: TALKMSGWIN_ClearWindowFrame
 * address:  0x02194A34
 * packet:   pkt_02194A34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   TALKMSGWIN_ClearFrame  0x02195E90  thumb  ov021
 *   func_020409B4  0x020409B4  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17941.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020409B4(u32);
struct FrameStyle;
extern void TALKMSGWIN_ClearFrame(struct FrameStyle *style, void *win);

int TALKMSGWIN_ClearWindowFrame(u32 a, u32 b)
{
TALKMSGWIN_ClearFrame((struct FrameStyle *)a, (void *)b);
return func_020409B4(((((struct Obj17941 *)((u8 *)(a)))->f10 << 24) >> 24));
}

