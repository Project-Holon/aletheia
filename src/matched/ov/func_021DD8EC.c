/*
 * function: BTL_ITEM_RaiseSpDefenseOne
 * address:  0x021DD8EC
 * packet:   pkt_021DC604
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_ITEM_RaiseSpDefenseOne   0x021DD8EC  thumb
 *   BTL_ITEM_RaiseStat   0x021DD9E8  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; movs r2, #4; movs r3, #1; bl BTL_ITEM_RaiseStat; pop {r3, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021DD8EC  shifted 3-arg wrapper -> BTL_ITEM_RaiseStat(..., 0x4, 1) */
void BTL_ITEM_RaiseSpDefenseOne(int a, int b, int c)
{
    BTL_ITEM_RaiseStat(b, c, 0x4, 1);
}

