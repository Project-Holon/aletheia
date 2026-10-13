/*
 * function: HAND_ITEM_JabocaBerryRememberPhysicalAttacker
 * address:  0x021DE0DC
 * packet:   pkt_021DD614
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_ITEM_JabocaBerryRememberPhysicalAttacker   0x021DE0DC  thumb
 *   HAND_ITEM_RememberAttackerOfCategory   0x021DE108  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #1; str r4, [sp]; bl HAND_ITEM_RememberAttackerOfCategory; add sp, #4; pop {r3, r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021DE0DC  stack-arg wrapper: HAND_ITEM_RememberAttackerOfCategory(a, b, c, d, 0x1) */
void HAND_ITEM_JabocaBerryRememberPhysicalAttacker(int a, int b, int c, int d) { HAND_ITEM_RememberAttackerOfCategory(a, b, c, d, 0x1); }

