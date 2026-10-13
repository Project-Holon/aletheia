/*
 * function: func_021C8F2C
 * address: 0x021C8F2C
 * packet: pkt_ov212_021C8F2C
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PROCSYS_Main 0x02031330 arm
 *   d_021C9944 0x021C9944 data a4
 */
#include "../include/Obj08415.h"
extern unsigned PROCSYS_Main(void *);extern unsigned char d_021C9944[];
int func_021C8F2C(int a,int b,int c,unsigned char *p){if(((struct Obj08415 *)p)->f1C==9)return 1;((struct Obj08415 *)p)->f8=PROCSYS_Main(((struct Obj08415 *)p)->f4);((struct Obj08415 *)p)->f1C=(*(unsigned (**)(unsigned char *))(d_021C9944+*(unsigned *)(p+28)*4))(p);return 0;}
