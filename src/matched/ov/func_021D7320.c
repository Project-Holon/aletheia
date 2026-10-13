/*
 * function: BTL_EVENT_SetFactorSkipCheck
 * address:  0x021D7320
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_SetFactorSkipCheck   0x021D7320  thumb
 *
 * Stores the second argument (a u32) into the field at #0xc.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D7320  str r1,[r0,#0xc] */
struct QS { u8 pad[0xc]; u32 v; };
void BTL_EVENT_SetFactorSkipCheck(struct QS *p, u32 v) { p->v = v; }

