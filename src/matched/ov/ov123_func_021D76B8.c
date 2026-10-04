/*
 * function: func_021D76B8
 * address: 0x021D76B8
 * packet: pkt_ov123_021D76B8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_02012E7C 0x02012E7C thumb
 *   func_0200734C 0x0200734C thumb
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D768C 0x021D768C thumb ov123
 */
#include "../include/Obj13987.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;
extern void *func_02012EBC(struct Big *p);
extern int func_02012E7C(char *p, int a1);
struct Sub02007324Ctrl;
extern void func_0200734C(struct Sub02007324Ctrl *ctrl,u32 id);
extern void func_021D6EE0(char *,int,int);
extern void func_021D768C(u8 *);
void func_021D76B8(char *p) { int v; v=(int)func_02012EBC((struct Big *)(((struct Obj13987 *)p)->f2C)); if(func_02012E7C((char *)(((struct Obj13987 *)p)->f2C),7)==2) { func_0200734C((struct Sub02007324Ctrl *)v,7); func_021D6EE0(p,(int)func_021D768C,0x36a); } }
