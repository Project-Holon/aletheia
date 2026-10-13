/*
 * function: IRC_COMPATIBLE_SetHandler
 * address:  0x021B6A3C
 * packet:   pkt_ov101_021B6A3C
 * region:   ov101
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj13718.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void IRC_COMPATIBLE_SetHandler(u8 *p, u32 v) { ((struct Obj13718 *)p)->f14 = v; ((struct Obj13718 *)p)->f18 = 0; }
