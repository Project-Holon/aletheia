/*
 * function: TR_AI_GetMoveFlag
 * address:  0x0218A384
 * packet:   pkt_ov096_0218A384
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb  arm9
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void WAZA_TOOL_GetFlag(int, int);
void TR_AI_GetMoveFlag(int a, int b, int c) { WAZA_TOOL_GetFlag(b, c); }
