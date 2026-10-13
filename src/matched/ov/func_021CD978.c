/*
 * function: BTL_CLIENT_GetNetChannel
 * address:  0x021CD978
 * packet:   pkt_021CC95C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_GetNetChannel   0x021CD978  thumb
 *
 * Reads the u32 field at #0x50 of the argument and returns it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021CD978  ldr r0,[r0,#0x50] */
struct QB { u8 pad[0x50]; u32 v; };
u32 BTL_CLIENT_GetNetChannel(struct QB *p) { return p->v; }

