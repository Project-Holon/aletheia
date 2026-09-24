/*
 * function: func_021D5B44
 * address:  0x021D5B44
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5B44   0x021D5B44  thumb
 *
 * Stores the second argument (a u16) into the field at #0x12.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

struct QI { u8 pad[0x12]; u16 v; };
/* 021D5B44  strh r1,[r0,#0x12] */
void func_021D5B44(struct QI *p, u16 v) { p->v = v; }

