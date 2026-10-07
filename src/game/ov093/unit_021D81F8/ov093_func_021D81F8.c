/*
 * function: func_021D81F8
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
 *   func_021D80BC 0x021D80BC thumb ov093
 */

#include "../../../matched/include/G_B.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern struct B d_021F6368; extern int func_021D80BC(void *,int,int,u16); int func_021D81F8(void *p,int a,int m,u16 move,struct B *b) { int v; *b=d_021F6368; v=func_021D80BC(p,a,m,move); d_021F6368=*b; return v; }
