/*
 * function: BTL_POKEPARAM_IsTransformed
 * address:  0x021D6D54
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_IsTransformed   0x021D6D54  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldrb r0, [r0, #0x1b]; lsls r0, r0, #0x1a; lsrs r0, r0, #0x1f; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D6D54  ldrb r0,[r0,#0x1b]; lsls #0x1a; lsrs #0x1f */
struct R5 { u8 pad[0x1b]; u8 a : 5; u8 b : 1; u8 c : 2; };
int BTL_POKEPARAM_IsTransformed(struct R5 *p) { return p->b; }

