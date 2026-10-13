/*
 * function: IRC_RHYTHM_IsParticleActive
 * address:  0x021B8E8C
 * packet:   pkt_ov104_021B8E8C
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj22235.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

u32 IRC_RHYTHM_IsParticleActive(u8 *p) { return ((struct Obj22235 *)p)->f8; }
