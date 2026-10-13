/*
 * function: PMS_INPUT_GetSearchState
 * address:  0x021BF808
 * packet:   pkt_ov110_021BF808
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching PMSI_SEARCH_GetInputCount in ov110 (pkt_ov110_021BAFDC).
 *
 * symbols:
 *   PMSI_SEARCH_GetInputCount  0x021BAFDC  thumb  ov110
 */
#include "../include/Obj22400.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u8 PMSI_SEARCH_GetInputCount(u8 *p);
int PMS_INPUT_GetSearchState(u8 *p) { return PMSI_SEARCH_GetInputCount((u8 *)(((struct Obj22400 *)p)->f1C)); }
