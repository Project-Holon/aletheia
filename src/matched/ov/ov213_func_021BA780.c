/*
 * function: func_021BA780
 * address: 0x021BA780
 * packet: pkt_ov213_021BA780
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 *   func_02047CFC 0x02047CFC arm
 *   func_02050B80 0x02050B80 arm
 */
#include "../include/Obj10929.h"
extern void func_0207D63C(void *,int,int,int,int),func_02050B80(unsigned);extern void *func_02047CFC(unsigned,unsigned,unsigned);
void func_021BA780(char *p,void *state,short heap){func_0207D63C((void *)0x04000050,1,31,0,0);((struct Obj10929 *)p)->f0=state;((struct Obj10929 *)p)->f4=heap;((struct Obj10929 *)p)->f8=func_02047CFC(16,20,heap);func_02050B80(heap);}
