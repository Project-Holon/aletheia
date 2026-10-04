/*
 * function: func_021B967C
 * address: 0x021B967C
 * packet: pkt_ov100_021B967C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082D44 0x02082D44 arm
 *   func_021B95F0 0x021B95F0 thumb ov100
 *   func_0207E468 0x0207E468 arm
 */
#include "../include/Obj13705.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02082D44(const void *,void *,u32);
extern int func_021B95F0(int,int,int);
extern void func_0207E468(int,int,int);
void func_021B967C(int a,int b){if(b){func_02082D44((void *)0x05000400,((struct Obj13705 *)a)->fCB4,0x200);func_021B95F0(a,1,9);}else{func_0207E468(*(int *)&((struct Obj13705 *)a)->fCB4,0,0x120);}}
