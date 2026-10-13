/*
 * function: PMS_INPUT_VIEW_SetEditText
 * address:  0x021BAC00
 * packet:   pkt_ov110_021BAC00
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 PMSIV_EDIT_GetSlotRect          -> unresolved: 021BC320 (arm, from name) has no witness outside 021BAC00..021BAC0C; 16 overlays overlap this address (ov016, ov021, ov088, ov091, ov093, ov099, ov110, ov114, ov172, ov208, ov209, ov210, ov211, ov216, ov217, ov223), none resolvable without a region hint on the symbols: line
 
 * symbols:
 *   PMSIV_EDIT_GetSlotRect  0x021BC320  thumb  ov110
 *
 * UNBLOCKED: PMSIV_EDIT_GetSlotRect is now an EXACT entry in layout/matched/ov110;
 * the call site resolves as matched, verdict promoted to EXACT.
*/
#include "../include/Obj22338.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void PMSIV_EDIT_GetSlotRect(void *a, u8 *b, int n);
void PMS_INPUT_VIEW_SetEditText(u8 *p, u8 *b, u8 n) { PMSIV_EDIT_GetSlotRect(((struct Obj22338 *)p)->f54, b, n); }
