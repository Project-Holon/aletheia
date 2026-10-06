/*
 * function: func_021BAC08
 * address: 0x021BAC08
 * packet: pkt_ov100_021BAC08
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021BA5F4 0x021BA5F4 thumb ov100
 *   func_02040DA8 0x02040DA8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020403F4 0x020403F4 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045808 0x02045808 arm
 *   func_02040588 0x02040588 arm
 *   func_02027FD8 0x02027FD8 thumb
 *   func_021BA640 0x021BA640 thumb ov100
 */
#include "../include/Obj05267.h"
typedef unsigned int   u32;
struct Rec;
struct TaskMenuState;
struct U16Vec;
extern void func_0201DD68(void);
extern void func_021BA5F4(unsigned a);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020403F4(u32 i);
extern void func_02045C04(struct Rec *rec);
extern void func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern void func_02040588(u32 which, u32 enable);
extern void func_02027FD8(struct TaskMenuState *s);
extern void func_021BA640(int);
void func_021BAC08(int a) {
 func_0201DD68();
 func_021BA5F4(a);
 func_02040DA8(5,1,0);
 {
  unsigned int v=((struct Obj05267 *)a)->f304;
  unsigned int w=v>>16;
  func_0203FB44(5,(unsigned short)v,(unsigned short)w);
 }
 func_020403F4(5);
 func_02045C04((struct Rec *)(((struct Obj05267 *)a)->f288));
 func_0201D83C((void *)(((struct Obj05267 *)a)->f290));
 func_02045808((struct U16Vec *)(((struct Obj05267 *)a)->f294));
 func_02045808((struct U16Vec *)(((struct Obj05267 *)a)->f298));
 func_02040588(5,0);
 func_02027FD8((struct TaskMenuState *)(((struct Obj05267 *)a)->fCC4));
 func_021BA640(a);
}
