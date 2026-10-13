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
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 */
#include "../include/Obj06361.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short s16;
struct Point { s16 x,y; u16 z; u8 id,mode; };
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
typedef unsigned int   u32;
struct Actor;
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);
void func_021B974C(int a,int b,int c,int d,int e)
{
 struct Point p;
 if(*(int *)(a+0x2c8+d*4)==0) {
  p.x=b; p.y=c; p.z=e; p.id=d; p.mode=2;
  *(int *)(a+0x2c8+d*4)=(int)CLACT_CreateActor((void *)((struct Obj06361 *)a)->f2B4,((struct Obj06361 *)a)->f2BC,((struct Obj06361 *)a)->f2B8,((struct Obj06361 *)a)->f2C0,&p,0,((struct Obj06361 *)a)->f278);
  CLACT_SetActorAutoAnim((struct Obj *)*(int *)(a+0x2c8+d*4),1);
  CLACT_SetActorDrawEnable((struct Obj *)*(int *)(a+0x2c8+d*4),1);
  CLACT_SetActorAffineMode((struct Actor *)(*(int *)(a+0x2c8+d*4)),2);
 }
}
