/*
 * function: BTL_SLOT_GetCount
 * address:  0x021B9B94
 * packet:   pkt_021B85A0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SLOT_GetCount   0x021B9B94  thumb
 *
 * Reads the u8 field at #0x18 of the argument and returns it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

struct Q1 { u32 items[6]; u8 count; };
/* 021B9B94  ldrb r0,[r0,#0x18] */
u8 BTL_SLOT_GetCount(struct Q1 *p) { return p->count; }

