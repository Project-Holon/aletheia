/*
 * function: TR_AI_GetMoveParam
 * address:  0x0218A378
 * packet:   pkt_ov096_0218A378
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb  arm9
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void WAZA_TOOL_GetParam(int, int);
void TR_AI_GetMoveParam(int a, int b, int c) { WAZA_TOOL_GetParam(b, c); }
