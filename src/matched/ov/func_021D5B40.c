/*
 * function: BTL_POKEPARAM_GetItem
 * address:  0x021D5B40
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetItem   0x021D5B40  thumb
 *
 * Reads the u16 field at #0x12 of the argument and returns it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D5B40  ldrh r0,[r0,#0x12] */
struct QI { u8 pad[0x12]; u16 v; };
u16 BTL_POKEPARAM_GetItem(struct QI *p) { return p->v; }

