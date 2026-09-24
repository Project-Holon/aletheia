/*
 * function: func_021C8138
 * address:  0x021C8138
 * packet:   pkt_021C7CD4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C8138   0x021C8138  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0, #0x10]; lsls r0, r0, #0x10; lsrs r0, r0, #0x10; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021C8138  ldr r0,[r0,#0x10]; lsls r0,#0x10; lsrs r0,#0x10 */
struct Q7 { u8 pad[0x10]; u32 v; };
u16 func_021C8138(struct Q7 *p) { return (u16)p->v; }

