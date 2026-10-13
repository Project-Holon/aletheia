/*
 * function: BTL_POKEPARAM_IsLevelUpPending
 * address:  0x021D67D0
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_IsLevelUpPending   0x021D67D0  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldrb r0, [r0, #0x1b]; lsls r0, r0, #0x18; lsrs r0, r0, #0x1f; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D67D0  ldrb r0,[r0,#0x1b]; lsls #0x18; lsrs #0x1f */
struct R3 { u8 pad[0x1b]; u8 a : 7; u8 b : 1; };
int BTL_POKEPARAM_IsLevelUpPending(struct R3 *p) { return p->b; }

