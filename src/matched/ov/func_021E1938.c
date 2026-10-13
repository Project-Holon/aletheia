/*
 * function: HAND_WAZA_CounterOnMoveFailCheck
 * address:  0x021E1938
 * packet:   pkt_021E1938
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   HAND_WAZA_CounterOnMoveFailCheck   0x021E1938  thumb
 *   HAND_WAZA_RetaliateOnMoveFailCheck   0x021E19F8  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #1; bl HAND_WAZA_RetaliateOnMoveFailCheck; pop {r3, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021E1938  shifted 4-arg wrapper -> HAND_WAZA_RetaliateOnMoveFailCheck(..., 0x1) */
void HAND_WAZA_CounterOnMoveFailCheck(int a, int b, int c, int d)
{
    HAND_WAZA_RetaliateOnMoveFailCheck(b, c, d, 0x1);
}

