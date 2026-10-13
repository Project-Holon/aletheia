/*
 * function: IRC_COMPATIBLE_SetFinished
 * address:  0x021B6A44
 * packet:   pkt_ov101_021B6A44
 * region:   ov101
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj22109.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void IRC_COMPATIBLE_SetFinished(u8 *p) { ((struct Obj22109 *)p)->f1C = 1; }
