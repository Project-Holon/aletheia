/*
 * function: func_021C09E0
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

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void func_021C09E0(u8 *p) { *(u16 *)(p + 0xc) = 0; }
