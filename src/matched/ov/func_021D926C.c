/*
 * function: HAND_TOKUSEI_IndirectGuardCause8Block
 * address:  0x021D926C
 * packet:   pkt_021D8A8C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   HAND_TOKUSEI_IndirectGuardCause8Block   0x021D926C  thumb
 *   HAND_TOKUSEI_BlockIndirectDamage   0x021D928C  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #8; bl HAND_TOKUSEI_BlockIndirectDamage; pop {r3, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D926C  shifted 4-arg wrapper -> HAND_TOKUSEI_BlockIndirectDamage(..., 0x8) */
void HAND_TOKUSEI_IndirectGuardCause8Block(int a, int b, int c, int d)
{
    HAND_TOKUSEI_BlockIndirectDamage(b, c, d, 0x8);
}

