/*
 * function: PMS_INPUT_VIEW_GetEditValue
 * address:  0x021BABE8
 * packet:   pkt_ov110_021BABE8
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 PMSIV_EDIT_GetSlotCount          -> unresolved: 021BC6DC (arm, from name) has no witness outside 021BABE8..021BABF4; 16 overlays overlap this address (ov016, ov021, ov088, ov091, ov093, ov099, ov110, ov114, ov172, ov208, ov209, ov210, ov211, ov216, ov217, ov223), none resolvable without a region hint on the symbols: line
 
 * symbols:
 *   PMSIV_EDIT_GetSlotCount  0x021BC6DC  thumb  ov110
 *
 * UNBLOCKED: PMSIV_EDIT_GetSlotCount is now an EXACT entry in layout/matched/ov110;
 * the call site resolves as matched, verdict promoted to EXACT.
*/
#include "../include/Obj22336.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern unsigned int PMSIV_EDIT_GetSlotCount(void *p);
int PMS_INPUT_VIEW_GetEditValue(u8 *p) { return PMSIV_EDIT_GetSlotCount((void *)(((struct Obj22336 *)p)->f54)); }
