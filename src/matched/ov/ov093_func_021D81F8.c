/*
 * function: BTL_CALC_PeekMoveTarget
 * address: 0x021D81F8
 * packet: pkt_ov093_021D81F8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F6368 0x021F6368 data a4
 *   BTL_CALC_DecideMoveTarget 0x021D80BC thumb ov093
 */

#include "../include/G_B.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern struct B d_021F6368; extern int BTL_CALC_DecideMoveTarget(void *,int,int,u16); int BTL_CALC_PeekMoveTarget(void *p,int a,int m,u16 move,struct B *b) { int v; *b=d_021F6368; v=BTL_CALC_DecideMoveTarget(p,a,m,move); d_021F6368=*b; return v; }
