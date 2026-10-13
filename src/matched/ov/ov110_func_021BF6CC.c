/*
 * function: PMS_INPUT_SetExitState
 * address:  0x021BF6CC
 * packet:   pkt_ov110_021BF6CC
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void PMS_INPUT_SetExitState(u8 *p, u8 a, u8 b) { p[0] = b; p[1] = a; }
