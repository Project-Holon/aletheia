/*
 * function: func_021CD97C
 * address:  0x021CD97C
 * packet:   pkt_021CC95C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CD97C   0x021CD97C  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: push {r3, lr}; ldr r1, [r0, #0x28]; blx r1; pop {r3, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021CD97C  push {r3,lr}; ldr r1,[r0,#0x28]; blx r1; pop {r3,pc} */
struct R2 { u8 pad[0x28]; void (*fn)(struct R2 *); };
void func_021CD97C(struct R2 *p) { p->fn(p); }

