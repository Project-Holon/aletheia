/*
 * function: PMS_INPUT_VIEW_GetEditEntry
 * address:  0x021BABF4
 * packet:   pkt_ov110_021BABF4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching PMSIV_EDIT_GetSlotWordId in ov110 (pkt_ov110_021BC6E0).
 *
 * symbols:
 *   PMSIV_EDIT_GetSlotWordId  0x021BC6E0  thumb  ov110
 */
#include "../include/Obj22337.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u16 PMSIV_EDIT_GetSlotWordId(u8 *p, int i);
int PMS_INPUT_VIEW_GetEditEntry(u8 *p, int i) { return PMSIV_EDIT_GetSlotWordId(*(u8 * *)&((struct Obj22337 *)p)->f54, i); }
