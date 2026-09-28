/*
 * function: func_021CD95C
 * address:  0x021CD95C
 * packet:   pkt_021CC95C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CD95C   0x021CD95C  thumb
 *
 * Stores the second argument (a u32) into the field at #0x54.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021CD95C  str r1,[r0,#0x54] */
struct QA { u8 pad[0x54]; u32 v; };
void func_021CD95C(struct QA *p, u32 v) { p->v = v; }

