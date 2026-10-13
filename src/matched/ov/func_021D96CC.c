/*
 * function: HAND_TOKUSEI_SickGuard_ShowBlockedMessage
 * address:  0x021D96CC
 * packet:   pkt_021D8A8C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   HAND_TOKUSEI_SickGuard_ShowBlockedMessage   0x021D96CC  thumb
 *   HAND_TOKUSEI_ShowSickGuardMessage   0x021D9670  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #0xd2; str r4, [sp]; bl HAND_TOKUSEI_ShowSickGuardMessage; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D96CC  stack-arg wrapper: HAND_TOKUSEI_ShowSickGuardMessage(a, b, c, d, 0xd2) */
void HAND_TOKUSEI_SickGuard_ShowBlockedMessage(int a, int b, int c, int d) { HAND_TOKUSEI_ShowSickGuardMessage(a, b, c, d, 0xd2); }

