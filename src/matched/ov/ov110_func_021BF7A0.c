/*
 * function: PMS_INPUT_GetScrollDelta
 * address:  0x021BF7A0
 * packet:   pkt_ov110_021BF7A0
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching PMS_WORDLIST_GetScrollDelta in ov110 (pkt_ov110_021BEDE0).
 *
 * symbols:
 *   PMS_WORDLIST_GetScrollDelta  0x021BEDE0  thumb  ov110
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u32 PMS_WORDLIST_GetScrollDelta(u8 *p);
int PMS_INPUT_GetScrollDelta(u8 *p) { return PMS_WORDLIST_GetScrollDelta(p + 0x54); }
