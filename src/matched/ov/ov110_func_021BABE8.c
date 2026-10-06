/*
 * function: func_021BABE8
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
 * +0008 ABS32 func_021BC6DC          -> unresolved: 021BC6DC (arm, from name) has no witness outside 021BABE8..021BABF4; 16 overlays overlap this address (ov016, ov021, ov088, ov091, ov093, ov099, ov110, ov114, ov172, ov208, ov209, ov210, ov211, ov216, ov217, ov223), none resolvable without a region hint on the symbols: line
 
 * symbols:
 *   func_021BC6DC  0x021BC6DC  thumb  ov110
 *
 * UNBLOCKED: func_021BC6DC is now an EXACT entry in layout/matched/ov110;
 * the call site resolves as matched, verdict promoted to EXACT.
*/
#include "../include/Obj22336.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern unsigned int func_021BC6DC(void *p);
int func_021BABE8(u8 *p) { return func_021BC6DC((void *)(((struct Obj22336 *)p)->f54)); }
