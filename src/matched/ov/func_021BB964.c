/*
 * function: BTL_SERVER_GetFlow
 * address:  0x021BB964
 * packet:   pkt_021BB840
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_GetFlow   0x021BB964  thumb
 *
 * Reads the u32 field at #0x44 of the argument and returns it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021BB964  ldr r0,[r0,#0x44] */
struct Q5 { u8 pad[0x44]; u32 v; };
u32 BTL_SERVER_GetFlow(struct Q5 *p) { return p->v; }

