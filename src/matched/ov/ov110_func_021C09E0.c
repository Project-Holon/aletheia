/*
 * function: PMS_SELECT_GRAPHIC_ResetBgBlink
 * address:  0x021C09E0
 * packet:   pkt_ov110_021C09E0
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clears the u16 at +0x0c.  Inferred extent runs long (unlabelled follower).
 */
#include "../include/Obj22407.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void PMS_SELECT_GRAPHIC_ResetBgBlink(u8 *p) { ((struct Obj22407 *)p)->fC = 0; }
