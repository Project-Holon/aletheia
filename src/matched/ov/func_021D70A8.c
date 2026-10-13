/*
 * function: BTL_EVENT_GetFactorKey
 * address:  0x021D70A8
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetFactorKey   0x021D70A8  thumb
 *
 * Reads the u16 field at #0x38 of the argument and returns it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D70A8  ldrh r0,[r0,#0x38] */
struct QQ { u8 pad[0x38]; u16 v; };
u16 BTL_EVENT_GetFactorKey(struct QQ *p) { return p->v; }

