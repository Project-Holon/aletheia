/*
 * function: func_021CD9DC
 * address:  0x021CD9DC
 * packet:   pkt_021CC95C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CD9DC   0x021CD9DC  thumb
 *
 * Reads the u16 field at #0x22 of the argument and returns it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021CD9DC  ldrh r0,[r0,#0x22] */
struct QD { u8 pad[0x22]; u16 v; };
u16 func_021CD9DC(struct QD *p) { return p->v; }

