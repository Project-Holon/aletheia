/*
 * function: PMS_INPUT_VIEW_GetWordwinItem
 * address:  0x021BAD20
 * packet:   pkt_ov110_021BAD20
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMSIV_WORDWIN_GetThumbRow  0x021BFE60  thumb  ov110
 */
#include "../include/Obj22346.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern unsigned PMSIV_WORDWIN_GetThumbRow(u8 *p, unsigned n);
unsigned PMS_INPUT_VIEW_GetWordwinItem(u8 *p, unsigned n) { return PMSIV_WORDWIN_GetThumbRow(*(u8 * *)&((struct Obj22346 *)p)->f5C, n); }
