/*
 * function: func_021CC95C
 * address:  0x021CC95C
 * packet:   pkt_021CC95C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CC95C   0x021CC95C  thumb
 *
 * Stores the second argument (a u32) into the field at offset 0.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021CC95C  str r1,[r0] */
void func_021CC95C(u32 *p, u32 v) { *p = v; }

