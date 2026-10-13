/*
 * function: HAND_ITEM_RaiseSpAttackOne
 * address:  0x021DD8D0
 * packet:   pkt_021DC604
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_ITEM_RaiseSpAttackOne   0x021DD8D0  thumb
 *   HAND_ITEM_RaiseStat   0x021DD9E8  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; movs r2, #3; movs r3, #1; bl HAND_ITEM_RaiseStat; pop {r3, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021DD8D0  shifted 3-arg wrapper -> HAND_ITEM_RaiseStat(..., 0x3, 1) */
void HAND_ITEM_RaiseSpAttackOne(int a, int b, int c)
{
    HAND_ITEM_RaiseStat(b, c, 0x3, 1);
}

