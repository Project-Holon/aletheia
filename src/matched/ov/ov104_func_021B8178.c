/*
 * function: IRC_RHYTHM_IsCountdownFinished
 * address:  0x021B8178
 * packet:   pkt_ov104_021B8178
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj22226.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

u32 IRC_RHYTHM_IsCountdownFinished(u8 *p) { return ((struct Obj22226 *)p)->f18; }
