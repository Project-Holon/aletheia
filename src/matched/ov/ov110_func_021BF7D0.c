/*
 * function: PMS_INPUT_GetTasks
 * address:  0x021BF7D0
 * packet:   pkt_ov110_021BF7D0
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj22394.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

u32 PMS_INPUT_GetTasks(u8 *p) { return ((struct Obj22394 *)p)->f7C; }
