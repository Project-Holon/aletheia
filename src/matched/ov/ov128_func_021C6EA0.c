/*
 * function: Wf2dmapFriend_InitTopBar
 * address: 0x021C6EA0
 * packet: pkt_ov128_021C6EA0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   Wf2dmapFriend_InitListScreen 0x021C7140 thumb ov128
 */
#include "../include/Obj14034.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u8 func_020355C4(void);
struct P;
extern void Wf2dmapFriend_InitListScreen(struct P *p, u8 *a, u8 *ctx, u16 heap);
void Wf2dmapFriend_InitTopBar(u8 *p,u8 *q,u8 *r,u16 heap) {((struct Obj14034 *)q)->f0=func_020355C4();Wf2dmapFriend_InitListScreen((struct P *)p,q,r,heap);}
