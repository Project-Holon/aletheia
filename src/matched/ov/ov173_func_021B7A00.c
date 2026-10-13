/*
 * function: func_021B7A00
 * address: 0x021B7A00
 * packet: pkt_ov173_021B7A00
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * abi: B294 returns the Obj pointer stored and used by this caller.
 * symbols:
 *   func_021B7658 0x021B7658 thumb ov173
 *   func_021B76C8 0x021B76C8 thumb ov173
 *   func_020275E4 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   d_021B85E0 0x021B85E0 data a4
 */
#include "../include/Obj00180.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {short x,y;u16 unused,z;u32 a,b,c,d,e,f,g,h,i;} Row;
typedef struct {short x,y;u16 z;u8 a,b;} Position;
extern const Row d_021B85E0[];
extern void func_021B7658(u8 *p, void *a1);
extern void func_021B76C8(char *,void *);
extern u32 func_020275E4(void);
extern void *func_020490F4(u32 id, u32 heap);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
void func_021B7A00(char *p,void *arg)
{
    u32 i;
    Position pos;
    func_021B7658((u8 *)p,arg);
    func_021B76C8(p,arg);
    ((struct Obj00180 *)p)->f13C=func_020490F4(func_020275E4(),79);
    for(i=0;i<14;i++) {
        pos.x=d_021B85E0[i].x;
        pos.y=d_021B85E0[i].y;
        pos.z=d_021B85E0[i].z;
        pos.a=d_021B85E0[i].a;
        pos.b=d_021B85E0[i].h;
        *(void **)(p+i*4+0x104)=CLACT_CreateActor((void *)((struct Obj00180 *)p)->f100,*(u32 *)(p+d_021B85E0[i].d*4+0x70),*(u32 *)(p+d_021B85E0[i].e*4+0x94),*(u32 *)(p+d_021B85E0[i].f*4+0xb8),&pos,d_021B85E0[i].c,79);
        func_0204B92C(*(void **)(p+i*4+0x104),0);
    }
    func_0204B92C(((struct Obj00180 *)p)->f138,1);
    func_0204B92C(((struct Obj00180 *)p)->f10C,1);
    func_0204B92C(((struct Obj00180 *)p)->f108,1);
    func_0204B92C(((struct Obj00180 *)p)->f104,1);
}
