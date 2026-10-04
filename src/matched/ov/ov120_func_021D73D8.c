/*
 * function: func_021D73D8
 * address: 0x021D73D8
 * packet: pkt_ov120_021D73D8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204BA00 0x0204BA00 arm
 *   func_02043534 0x02043534 arm
 *   func_021D73B0 0x021D73B0 thumb ov120
 */
#include "../include/Obj00625.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Record { u16 x,y,z; u8 a,b; } Record;
typedef struct Callback { u16 n; u8 *p; void (*f)(u8 *); } Callback;
struct Obj;
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204BA00(void *,Callback *);
extern void func_02043534(u32);
extern void func_021D73B0(u8 *);
void func_021D73D8(u8 *p)
{
    Callback c;
    Record r;
    r.x=128; r.y=52; r.z=27; r.a=2; r.b=1;
    ((struct Obj00625 *)p)->f12C=func_0204B294((void *)((struct Obj00625 *)p)->f10,((struct Obj00625 *)p)->f2C,((struct Obj00625 *)p)->f1C,((struct Obj00625 *)p)->f78,&r,0,((struct Obj00625 *)p)->fF4);
    func_0204B92C(((struct Obj00625 *)p)->f12C,1);
    func_0204B3DC(((struct Obj00625 *)p)->f12C,1);
    r.z=11; r.a=1;
    ((struct Obj00625 *)p)->f130=func_0204B294((void *)((struct Obj00625 *)p)->f10,((struct Obj00625 *)p)->f2C,((struct Obj00625 *)p)->f1C,((struct Obj00625 *)p)->f78,&r,0,((struct Obj00625 *)p)->fF4);
    func_0204B92C(((struct Obj00625 *)p)->f130,1);
    func_0204B3DC(((struct Obj00625 *)p)->f130,1);
    c.n=0; c.p=p; c.f=func_021D73B0;
    func_0204BA00(((struct Obj00625 *)p)->f130,&c);
    func_02043534(31);
}
