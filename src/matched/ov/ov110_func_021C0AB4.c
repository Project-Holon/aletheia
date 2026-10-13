/*
 * function: func_021C0AB4
 * address:  0x021C0AB4
 * packet:   pkt_ov110_021C0AB4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Resolved by the TOUCHBAR_Delete label in ov067 (thumb); cross-overlay target.
 *
 * symbols:
 *   TOUCHBAR_Delete  0x021B639C  thumb  ov067
 */
#include "../include/Obj22408.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void TOUCHBAR_Delete(u8 *p);
void func_021C0AB4(u8 *p) { TOUCHBAR_Delete((u8 *)(((struct Obj22408 *)p)->f54)); }
