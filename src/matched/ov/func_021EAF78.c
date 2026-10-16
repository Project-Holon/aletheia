/*
 * function: BTLV_SCU_SetMessageParam
 * address:  0x021EAF78
 * packet:   pkt_021E8CFC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCU_SetMessageParam   0x021EAF78  thumb
 *
 * Stores the second argument (a u8) into the field at #2.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021EAF78  strb r1,[r0,#2] */
void BTLV_SCU_SetMessageParam(u8 *p, u8 v) { p[2] = v; }

