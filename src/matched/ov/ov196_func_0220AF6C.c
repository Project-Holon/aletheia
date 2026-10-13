/*
 * function: func_0220AF6C
 * address: 0x0220AF6C
 * packet: pkt_ov196_0220AF6C
 * region: ov196
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B92C 0x0204B92C arm
 */
#include "../include/Obj24987.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {u16 x,y,z;u8 a,b;} Pos;
extern int CLACT_CreateActor(int, int, int, int, void *, int, u16);
typedef unsigned int   u32;
struct Obj;
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
struct Obj;
extern void func_0204B92C(struct Obj *p, unsigned int v);
void func_0220AF6C(char *p, int a, int b, int c, int d)
{
    Pos pos;
    unsigned i;
    pos.x=0;pos.y=0;pos.a=0;pos.b=1;
    for(i=0;i<4;i++) {
        pos.z=i;
        *(int *)(p+i*4)=CLACT_CreateActor(a,b,c,d,&pos,1,((struct Obj24987 *)p)->f10);
        func_0204B6F4((struct Obj *)(*(int *)(p+i*4)),0,1);
        func_0204B92C((struct Obj *)*(int *)(p+i*4),1);
    }
}
