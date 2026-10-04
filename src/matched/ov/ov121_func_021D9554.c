/*
 * function: func_021D9554
 * address: 0x021D9554
 * packet: pkt_ov121_021D9554
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0200A21C 0x0200A21C thumb
 */
#include "../include/Obj13943.h"
extern int func_0200A21C(void);
int func_021D9554(char *p,int n) {
 if(func_0200A21C()!=0 && n==0 && (((struct Obj13943 *)p)->fCC==0 || (((struct Obj13943 *)p)->fCC&0x200000)!=0)) return 1;
 return 0;
}
