/*
 * function: HAND_ITEM_WeakenDamageIce
 * address:  0x021DDB44
 * packet:   pkt_021D8684
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_ITEM_WeakenDamageIce   0x021DDB44  thumb
 *   HAND_ITEM_WeakenHitOfType   0x021DDCD8  thumb
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0xe; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl HAND_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021DDB44  shape F2: two stack constants (0xe, 0) */
void HAND_ITEM_WeakenDamageIce(int a, int b, int c, int d)
{
    HAND_ITEM_WeakenHitOfType(a, b, c, d, 0xe, 0);
}

