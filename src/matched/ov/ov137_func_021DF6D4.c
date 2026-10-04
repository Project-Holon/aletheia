/*
 * function: func_021DF6D4
 * address: 0x021DF6D4
 * packet: pkt_ov137_021DF6D4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021E0130 0x021E0130 thumb ov137
 */
#include "../include/Obj14227.h"
typedef unsigned char u8;
struct Entry;
struct Link;
extern struct Entry *func_020399A8(void);extern void func_02039C68(struct Link *,unsigned int,unsigned int);extern void func_021E0130(u8 *,int);
int func_021DF6D4(u8 *p){void *ctx=func_020399A8();if(!((struct Obj14227 *)p)->f18)func_02039C68(ctx,206,40);func_021E0130(p,10);((struct Obj14227 *)p)->f0=48;return 0;}
