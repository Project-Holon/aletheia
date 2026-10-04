/*
 * function: func_021BB784
 * address: 0x021BB784
 * packet: pkt_ov110_021BB784
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after return.
 * symbols:
 *   func_021BC93C 0x021BC93C thumb ov110
 */
#include "../include/Obj22366.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_021BC93C(u8 *);
int func_021BB784(u8 *p) { if (((struct Obj22366 *)p)->f10==0 && func_021BC93C(p+24)!=0) return 1; return 0; }
