/*
 * function: BTL_SERVER_FLOW_ItemEffectRaiseDefense
 * address:  0x021CC0A8
 * packet:   pkt_021CBF30
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_ItemEffectRaiseDefense   0x021CC0A8  thumb
 *   BTL_SERVER_FLOW_ItemEffectRaiseStatStage   0x021CC438  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #2; str r4, [sp]; bl BTL_SERVER_FLOW_ItemEffectRaiseStatStage; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021CC0A8  stack-arg wrapper: BTL_SERVER_FLOW_ItemEffectRaiseStatStage(a, b, c, d, 0x2) */
void BTL_SERVER_FLOW_ItemEffectRaiseDefense(int a, int b, int c, int d) { BTL_SERVER_FLOW_ItemEffectRaiseStatStage(a, b, c, d, 0x2); }

