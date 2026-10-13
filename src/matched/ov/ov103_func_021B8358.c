/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_SetFinished
 * address:  0x021B8358
 * packet:   pkt_ov103_021B8358
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj22191.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void IRC_COMPATIBLE_TOUCH_TEST_SetFinished(u8 *p) { ((struct Obj22191 *)p)->f730 = 1; }
