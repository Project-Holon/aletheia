/*
 * function: HAND_TOKUSEI_IndirectGuardCause2_ShowMessage
 * address:  0x021DC614
 * packet:   pkt_021DC604
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_TOKUSEI_IndirectGuardCause2_ShowMessage   0x021DC614  thumb
 *   HAND_TOKUSEI_ShowIndirectGuardMessage   0x021D92CC  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #0xcc; bl HAND_TOKUSEI_ShowIndirectGuardMessage; pop {r3, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021DC614  shifted 4-arg wrapper -> HAND_TOKUSEI_ShowIndirectGuardMessage(..., 0xcc) */
void HAND_TOKUSEI_IndirectGuardCause2_ShowMessage(int a, int b, int c, int d)
{
    HAND_TOKUSEI_ShowIndirectGuardMessage(b, c, d, 0xcc);
}

