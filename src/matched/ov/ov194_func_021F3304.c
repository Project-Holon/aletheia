/*
 * function: func_021F3304
 * address: 0x021F3304
 * packet: pkt_ov194_021F3304
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj05512.h"
struct Descriptor;
extern void *func_02045770(struct Descriptor *); extern int func_0201C6C4(int,int); extern void func_02045334(struct Descriptor *d);
int func_021F3304(char *p) {
 int q;
 q=((struct Obj05512 *)p)->fF8;
 if(((struct Obj05512 *)p)->fF0) {
 if(func_0201C6C4(q,(int)func_02045770((struct Descriptor *)*(int *)&((struct Obj05512 *)p)->fEC))==0) {
 func_02045334(((struct Obj05512 *)p)->fEC);((struct Obj05512 *)p)->fF0=0;
 }}
 if(((struct Obj05512 *)p)->fF0==0)return 1;return 0;
}
