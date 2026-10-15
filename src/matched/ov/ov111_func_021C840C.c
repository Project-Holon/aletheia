/*
 * function: VIEWER_ACTOR_ResetDragFlags
 * address:  0x021C840C
 * packet:   pkt_ov111_021C840C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void VIEWER_ACTOR_ResetDragFlags(u8 *p) { p[2] = 0; p[3] = 0; }
