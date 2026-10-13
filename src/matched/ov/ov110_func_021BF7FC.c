/*
 * function: PMS_INPUT_GetInitialCount
 * address:  0x021BF7FC
 * packet:   pkt_ov110_021BF7FC
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMSI_SEARCH_HasResults  0x021BB1C0  thumb  ov110
 */
#include "../include/Obj22399.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u8 PMSI_SEARCH_HasResults(u8 *p);
u8 PMS_INPUT_GetInitialCount(u8 *p) { return PMSI_SEARCH_HasResults((u8 *)(((struct Obj22399 *)p)->f1C)); }
