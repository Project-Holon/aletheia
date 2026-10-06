/*
 * function: func_021FC380
 * address: 0x021FC380
 * packet: pkt_ov132_021FC380
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   func_021F9DD4 0x021F9DD4 thumb ov132
 *   func_021F9DDC 0x021F9DDC thumb ov132
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_021F9DF4 0x021F9DF4 thumb ov132
 *   func_021F8044 0x021F8044 thumb ov112
 *   func_021F6EF4 0x021F6EF4 thumb ov112
 *   func_0207C9D0 0x0207C9D0 arm
 *   func_02030734 0x02030734 arm
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FC490 0x021FC490 thumb ov132
 *   d_021FDD00 0x021FDD00 data a4
 */
#include "../include/Obj02487.h"
#include "../include/Obj04519.h"
#include "../include/Obj04520.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x,y,z; } Vec;
struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
extern int func_021FB1F4(char *,int);
extern void *func_021F9DD4(void *);
extern void *func_021F9DDC(void *,u8);
extern void *func_021F9DA0(char *p);
extern void *func_021F9DA4(char *p, u32 i);
extern void *func_021F9DF4(void *p);
extern void func_021F8044(void *unused, u32 *p, u32 *q);
extern void func_021F6EF4(void *unused, u32 *p, const u32 *q);
extern void func_0207C9D0(const Vec *,const Vec *,Vec *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void *func_021FADA0(char *,u32,u32,u32);
extern void func_021FC490(int,char *);
extern const char d_021FDD00[];
int func_021FC380(int unused,char *p)
{
 char *owner,*q;
 Vec pos,delta;
 u16 duration;
 u32 f,e,d,b,c,a;
 void *ctx,*target,*scene,*obj;
 u8 i;
 owner=*(char * *)&((struct Obj04519 *)p)->f0;
 a=func_0201134C(((struct Obj04519 *)p)->f4);
 b=func_021FB1F4(p,func_0201134C(((struct Obj04519 *)p)->f4));
 c=func_0201134C(((struct Obj04519 *)p)->f4);
 d=func_0201134C(((struct Obj04519 *)p)->f4);
 e=func_0201134C(((struct Obj04519 *)p)->f4);
 f=func_0201134C(((struct Obj04519 *)p)->f4);
 ctx=func_021F9DD4(((struct Obj04520 *)owner)->f34);
 target=func_021F9DDC(((struct Obj04520 *)owner)->f34,a);
 scene=func_021F9DA0(((struct Obj04520 *)owner)->f34);
 duration=c;
 for(i=0;i<4;i++) {
  obj=func_021F9DA4(((struct Obj04520 *)owner)->f34,i);
  if(b&(1<<i)) {
   if(c==0) {
    func_021F8044(scene,obj,(u32 *)(&pos));
    delta.x=d;delta.y=e;delta.z=f;
    func_0207C9D0(&pos,&delta,&pos);
    func_021F6EF4(ctx,target,(const u32 *)(&pos));
   } else {
    func_021F9DF4(((struct Obj04520 *)owner)->f34);
    q=func_02030734(((struct Obj04520 *)owner)->f0,0x30,0,d_021FDD00,0x74D);
    *(char * *)&((struct Obj02487 *)q)->f28=owner;
    ((struct Obj02487 *)q)->f0=i;
    ((struct Obj02487 *)q)->f4=target;
    ((struct Obj02487 *)q)->f8=((struct Obj04520 *)owner)->f34;
    ((struct Obj02487 *)q)->fC=obj;
    ((struct Obj02487 *)q)->f1E=0;
    ((struct Obj02487 *)q)->f10=d;((struct Obj02487 *)q)->f14=e;((struct Obj02487 *)q)->f18=f;
    ((struct Obj02487 *)q)->f1C=duration;
    ((struct Obj02487 *)q)->f2C=func_021FADA0(owner,(u32)func_021FC490,(u32)q,7);
   }
  }
 }
 return 0;
}
