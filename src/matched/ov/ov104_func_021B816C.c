/*
 * function: IRC_RHYTHM_StartCountdown
 * address:  0x021B816C
 * packet:   pkt_ov104_021B816C
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Zeroes +0x0c/+0x10 and stores 1 at +0x14.
 */
#include "../include/Obj10246.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void IRC_RHYTHM_StartCountdown(u8 *p) { ((struct Obj10246 *)p)->fC = 0; ((struct Obj10246 *)p)->f10 = 0; ((struct Obj10246 *)p)->f14 = 1; }
