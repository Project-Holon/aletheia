/*
 * function: IRC_RESULT_GetScreenActor
 * address:  0x021B78C8
 * packet:   pkt_ov105_021B78C8
 * region:   ov105
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching IRC_RESULT_GetActor in ov105 (pkt_ov105_021B7C14).
 *
 * symbols:
 *   IRC_RESULT_GetActor  0x021B7C14  thumb  ov105
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u32 IRC_RESULT_GetActor(u8 *p, int i);
u32 IRC_RESULT_GetScreenActor(u8 *p, int i) { return IRC_RESULT_GetActor(p + 4, i); }
