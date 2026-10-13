/*
 * function: PMS_INPUT_VIEW_UpdateWordwinFocus
 * address:  0x021BAED0
 * packet:   pkt_ov110_021BAED0
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMSIV_WORDWIN_SetVisible  0x021BFC20  thumb  ov110
 */
#include "../include/Obj22352.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void PMSIV_WORDWIN_SetVisible(u8 *p, unsigned visible);
void PMS_INPUT_VIEW_UpdateWordwinFocus(u8 *p, u8 *a1, void *a2) { PMSIV_WORDWIN_SetVisible((u8 *)(((struct Obj22352 *)p)->f5C), 1); }
