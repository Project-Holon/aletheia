/*
 * function: NAMEIN_GRAPHIC_SetGridMode
 * address: 0x021F3364
 * packet: pkt_ov194_021F3364
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 */
#include "../include/Obj00117.h"
extern void func_0207D63C(void *,int,int,int,int);
int NAMEIN_GRAPHIC_SetGridMode(char *p,int mode) {
 int flag;
 if(((struct Obj00117 *)p)->f114!=mode) {
 ((struct Obj00117 *)p)->f114=mode;((struct Obj00117 *)p)->f10A=0;((struct Obj00117 *)p)->f10C=0;((struct Obj00117 *)p)->f110=1;
 flag=0;
 if(mode==3 || ((struct Obj00117 *)p)->f100==3)flag=1;
 ((struct Obj00117 *)p)->f118=flag;
 if(flag)func_0207D63C((void *)0x04000050,14,47,16,16);
 else func_0207D63C((void *)0x04000050,10,47,16,16);
 return 1;
 }return 0;
}
