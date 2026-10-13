/*
 * function: func_021B655C
 * address: 0x021B655C
 * packet: pkt_ov174_021B655C
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   ARC_UTIL_LoadHandleMember 0x0204A380 arm
 */
#include "../include/Obj03859.h"
typedef unsigned int   u32;
extern void *ARC_UTIL_LoadHandleMember(void *a0, u32 a1, u32 a2, u32 a3);
void func_021B655C(char *p) {unsigned char *q=ARC_UTIL_LoadHandleMember(((struct Obj03859 *)p)->f18,**(unsigned short * *)&((struct Obj03859 *)p)->f30+62,0,((struct Obj03859 *)p)->f0);((struct Obj03859 *)p)->f38=q;((struct Obj03859 *)p)->f3C=q;((struct Obj03859 *)p)->f40=q+8;if(q[2]==255 && q[3]==255) ((struct Obj03859 *)p)->f8=2;else ((struct Obj03859 *)p)->f8=4;}
