/*
 * function: func_021BF71C
 * address:  0x021BF71C
 * packet:   pkt_ov110_021BF71C
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Field getter, u16 at +0x48.  The inferred extent runs long because the
 * follower has no func_ label; bytes are identical.
 */
#include "../include/Obj22389.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

u16 func_021BF71C(u8 *p) { return ((struct Obj22389 *)p)->f48; }
