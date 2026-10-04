/*
 * function: func_021B974C
 * address: 0x021B974C
 * packet: pkt_ov100_021B974C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B570 0x0204B570 arm
 */
#include "../include/Obj06361.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short s16;
struct Point { s16 x,y; u16 z; u8 id,mode; };
struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
struct Obj;
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern void func_0204B3DC(struct Obj *,unsigned int);
typedef unsigned int   u32;
struct Actor;
extern void func_0204B570(struct Actor *actor, u32 value);
void func_021B974C(int a,int b,int c,int d,int e)
{
 struct Point p;
 if(*(int *)(a+0x2c8+d*4)==0) {
  p.x=b; p.y=c; p.z=e; p.id=d; p.mode=2;
  *(int *)(a+0x2c8+d*4)=(int)func_0204B294((void *)((struct Obj06361 *)a)->f2B4,((struct Obj06361 *)a)->f2BC,((struct Obj06361 *)a)->f2B8,((struct Obj06361 *)a)->f2C0,&p,0,((struct Obj06361 *)a)->f278);
  func_0204B92C((struct Obj *)*(int *)(a+0x2c8+d*4),1);
  func_0204B3DC((struct Obj *)*(int *)(a+0x2c8+d*4),1);
  func_0204B570((struct Actor *)(*(int *)(a+0x2c8+d*4)),2);
 }
}
