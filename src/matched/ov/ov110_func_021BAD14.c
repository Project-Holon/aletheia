/*
 * function: PMS_INPUT_VIEW_SetWordwinScrollOffset
 * address:  0x021BAD14
 * packet:   pkt_ov110_021BAD14
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMSIV_WORDWIN_SetThumbY  0x021BFE24  thumb  ov110
 */
#include "../include/Obj22345.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void PMSIV_WORDWIN_SetThumbY(u8 *p, int y);
void PMS_INPUT_VIEW_SetWordwinScrollOffset(u8 *p, u32 v) { PMSIV_WORDWIN_SetThumbY((u8 *)(((struct Obj22345 *)p)->f5C), v); }
