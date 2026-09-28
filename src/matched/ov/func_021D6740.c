/*
 * function: func_021D6740
 * address:  0x021D6740
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D6740   0x021D6740  thumb
 *
 * Reads the u16 field at #0x14 of the argument and returns it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

struct QK { u8 pad[0x12]; u16 a; u16 b; };
/* 021D6740  ldrh r0,[r0,#0x14] */
u16 func_021D6740(struct QK *p) { return p->b; }

