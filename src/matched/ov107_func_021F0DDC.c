/*
 * function: func_021F0DDC
 * address:  0x021F0DDC
 * packet:   pkt_ov107_021F0DDC
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021F6EAC  0x021F6EAC  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u8 d_021F6EAC[];
u32 func_021F0DDC(void) { return *(u32 *)(d_021F6EAC + 0x18); }
