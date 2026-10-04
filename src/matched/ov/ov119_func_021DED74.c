/*
 * function: func_021DED74
 * address: 0x021DED74
 * packet: pkt_ov119_021DED74
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202208C 0x0202208C thumb
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DED58 0x021DED58 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern int func_021D8A24(void *);
extern void func_021D8E84(void *,int);
extern void func_021DED58(void *);
void func_021DED74(void *p) {
 if(!func_021D8A24(p) || ((struct Obj00001 *)p)->f1060) {
  func_0202208C(0,0,0,0,6,1,((struct Obj00001 *)p)->f5F4);
  func_021D8E84(p,(int)func_021DED58);
 }
}
