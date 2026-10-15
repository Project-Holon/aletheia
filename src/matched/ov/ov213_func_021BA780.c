/*
 * function: COMM_BTL_DEMO_MAIN_InitGraphics
 * address: 0x021BA780
 * packet: pkt_ov213_021BA780
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 *   G3D_UTIL_Create 0x02047CFC arm
 *   PARTICLE_InitManager 0x02050B80 arm
 */
#include "../include/Obj10929.h"
extern void func_0207D63C(void *,int,int,int,int),PARTICLE_InitManager(unsigned);extern void *G3D_UTIL_Create(unsigned,unsigned,unsigned);
void COMM_BTL_DEMO_MAIN_InitGraphics(char *p,void *state,short heap){func_0207D63C((void *)0x04000050,1,31,0,0);((struct Obj10929 *)p)->f0=state;((struct Obj10929 *)p)->f4=heap;((struct Obj10929 *)p)->f8=G3D_UTIL_Create(16,20,heap);PARTICLE_InitManager(heap);}
