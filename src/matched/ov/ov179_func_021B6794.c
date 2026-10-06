/*
 * function: func_021B6794
 * address: 0x021B6794
 * packet: pkt_ov179_021B6794
 * region: ov179
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_021B6338 0x021B6338 thumb ov179
 */
#include "../include/Obj14394.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_021B6338(void *,int,int);
int func_021B6794(char *p,const int *q) {
 func_02049658(((struct Obj14394 *)p)->f4,q[2],q[1],0,0,1,127);
 if(q[2]==0) func_020498F4(((struct Obj14394 *)p)->f4,q[2],q[1],0,0,0,127);
 func_021B6338(p,q[1],q[2]); return 1;
}
