/*
 * function: PMS_INPUT_SetSearchArg
 * address:  0x021BF7D4
 * packet:   pkt_ov110_021BF7D4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMSI_SEARCH_BuildInputText  0x021BB00C  thumb  ov110
 */
#include "../include/Obj22395.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void PMSI_SEARCH_BuildInputText(void *p, void *q);
void PMS_INPUT_SetSearchArg(u8 *p, void *q) { PMSI_SEARCH_BuildInputText(((struct Obj22395 *)p)->f1C, q); }
