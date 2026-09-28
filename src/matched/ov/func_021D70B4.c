/*
 * function: func_021D70B4
 * address:  0x021D70B4
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D70B4   0x021D70B4  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: lsls r1, r1, #2; adds r0, r0, r1; ldr r0, [r0, #0x1c]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D70B4  lsls r1,#2; adds r0,r0,r1; ldr r0,[r0,#0x1c] */
u32 func_021D70B4(u8 *p, int i) { return *(u32 *)(p + i * 4 + 0x1c); }

