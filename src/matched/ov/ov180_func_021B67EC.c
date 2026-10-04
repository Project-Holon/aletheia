/*
 * function: func_021B67EC
 * address: 0x021B67EC
 * packet: pkt_ov180_021B67EC
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02050C04 0x02050C04 arm
 *   func_0205121C 0x0205121C arm
 *   func_02051230 0x02051230 arm
 */
#include "../include/Obj14400.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern int func_02050C04(int a, int b, int c, int d);
extern int func_0205121C(u32 a, u32 b, u32 c);
extern void func_02051230(void *,void *,int,int);
void func_021B67EC(char *p){((struct Obj14400 *)p)->f2C=(void *)func_02050C04((int)(p+18480),18432,1,141);func_02051230(((struct Obj14400 *)p)->f2C,(void *)func_0205121C(216,51,141),1,0);}
