/*
 * function: HAND_WAZA_AromatherapyOnUncategorizedMoveNoTarget
 * address:  0x021E492C
 * packet:   pkt_021E492C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_WAZA_AromatherapyOnUncategorizedMoveNoTarget   0x021E492C  thumb
 *   HAND_WAZA_CureParty   0x021E4958  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #0x70; str r4, [sp]; bl HAND_WAZA_CureParty; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021E492C  stack-arg wrapper: HAND_WAZA_CureParty(a, b, c, d, 0x70) */
void HAND_WAZA_AromatherapyOnUncategorizedMoveNoTarget(int a, int b, int c, int d) { HAND_WAZA_CureParty(a, b, c, d, 0x70); }

