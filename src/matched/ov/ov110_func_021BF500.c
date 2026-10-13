/*
 * function: PMS_INPUT_ClearSubHandler
 * address:  0x021BF500
 * packet:   pkt_ov110_021BF500
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj22384.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void PMS_INPUT_ClearSubHandler(u8 *p) { ((struct Obj22384 *)p)->f30 = 0; }
