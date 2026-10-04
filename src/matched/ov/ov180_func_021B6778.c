/*
 * function: func_021B6778
 * address: 0x021B6778
 * packet: pkt_ov180_021B6778
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02050C04 0x02050C04 arm
 *   func_0205121C 0x0205121C arm
 *   func_02051230 0x02051230 arm
 *   d_021B8108 0x021B8108 data a4
 */
#include "../include/Obj10718.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern int d_021B8108;
extern int func_02050C04(int a, int b, int c, int d);
extern int func_0205121C(u32 a, u32 b, u32 c);
extern void func_02051230(void *,void *,int,int);
void func_021B6778(char *p){((struct Obj10718 *)p)->f28=(void *)func_02050C04((int)(p+48),18432,1,141);func_02051230(((struct Obj10718 *)p)->f28,(void *)func_0205121C(216,*(int *)((u32)&d_021B8108+((struct Obj10718 *)p)->f915A*4),141),1,0);}
