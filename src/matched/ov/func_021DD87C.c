/*
 * function: HAND_ITEM_RaiseAttackOne
 * address:  0x021DD87C
 * packet:   pkt_021DC604
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_ITEM_RaiseAttackOne   0x021DD87C  thumb
 *   HAND_ITEM_RaiseStat   0x021DD9E8  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; movs r2, #1; movs r3, #1; bl HAND_ITEM_RaiseStat; pop {r3, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021DD87C  shifted 3-arg wrapper -> HAND_ITEM_RaiseStat(..., 0x1, 1) */
void HAND_ITEM_RaiseAttackOne(int a, int b, int c)
{
    HAND_ITEM_RaiseStat(b, c, 0x1, 1);
}

