/*
 * function: IRC_RESULT_GetScreenActorUnit
 * address:  0x021B78D4
 * packet:   pkt_ov105_021B78D4
 * region:   ov105
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching IRC_RESULT_GetActorUnit in ov105 (pkt_ov105_021B7C1C).
 *
 * symbols:
 *   IRC_RESULT_GetActorUnit  0x021B7C1C  thumb  ov105
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u32 IRC_RESULT_GetActorUnit(u32 *p);
u32 IRC_RESULT_GetScreenActorUnit(u8 *p) { return IRC_RESULT_GetActorUnit((u32 *)(p + 4)); }
