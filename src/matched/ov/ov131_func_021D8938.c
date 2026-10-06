/*
 * function: func_021D8938
 * address: 0x021D8938
 * packet: pkt_ov131_021D8938
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note (2026-10-02): the func_021D9440 call is inside the loop (its arg is i), so &d/&g is recomputed
 *   per group; hi/lo are enum locals so (0x19<<22)+(2<<16) is not folded.
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021D9440 0x021D9440 thumb ov131
 *   func_02043754 0x02043754 arm
 *   func_021DBAD0 0x021DBAD0 thumb ov131
 *   func_021DBCA4 0x021DBCA4 thumb ov131
 */
#include "../include/Obj04509.h"
#include "../include/Obj10514.h"
#include "../include/Obj10515.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Desc {u16 x,y,z;u8 kind,flag;};
enum E {E_0};
struct Grid {void *f0;u16 f4;s16 f6;u32 f8;u32 f12;u8 f16;u8 f17;u16 f18;u32 f20;};
struct Obj;
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern s16 func_021D9440(u8 *,u32);
struct Bmp;
extern struct Bmp *func_02043754(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern u8 *func_021DBAD0(u8 *a, const u8 *b);
extern void func_021DBCA4(u8 *p, int v);
void func_021D8938(u8 *a,u8 *p)
{
    struct Desc d;
    struct Grid g;
    enum E hi,lo;
    u32 base;
    u8 i;
    d.x=0;d.y=0;d.kind=10;d.flag=0;d.z=0;
    ((struct Obj10514 *)p)->f54=func_0204B294((void *)((struct Obj04509 *)a)->f174,((struct Obj04509 *)a)->fF8,((struct Obj04509 *)a)->fC4,((struct Obj04509 *)a)->f12C,&d,0,((struct Obj04509 *)a)->f0);
    func_0204B3DC(((struct Obj10514 *)p)->f54,0);
    g.f4=8;
    g.f8=((struct Obj04509 *)a)->fB8;
    g.f12=0;
    g.f16=0;
    hi=0x19;
    lo=2;
    g.f17=lo;
    g.f18=0;
    g.f20=0;
    base=(hi<<22)+(lo<<16);
    for(i=0;i<10;i++){
        u8 *e;
        g.f6=func_021D9440(p,i);
        e=p+i*0x14;
        g.f0=((struct Obj10515 *)e)->f7C=func_02043754((void *)(base-(i+1)*0x660),0x11,3,0x20,((struct Obj04509 *)a)->f0);
        ((struct Obj10515 *)e)->f80=func_021DBAD0(((struct Obj10514 *)p)->f6C,(const u8 *)(&g));
        func_021DBCA4(((struct Obj10515 *)e)->f80,0);
    }
}
