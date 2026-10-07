/*
 * file:     script_command_p08.c
 * unit:     yes
 * function: func_021FBE64, func_021FBE90, func_021FBF74, func_021FBFA8, func_021FBFDC, func_021FC014, func_021FC080, func_021FC0AC, func_021FC178, func_021FC1D4, func_021FC22C, func_021FC268, func_021FC34C, func_021FC380, func_021FC490, func_021FC4CC, func_021FC53C
 * address:  0x021FBE64
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DAC 0x021F9DAC thumb ov132
 *   func_021F9DB0 0x021F9DB0 thumb ov132
 *   func_021F9DB8 0x021F9DB8 thumb ov132
 *   func_021F6B80 0x021F6B80 thumb ov112
 *   func_021F6BC0 0x021F6BC0 thumb ov112
 *   func_021F6B9C 0x021F6B9C thumb ov112
 *   func_021F6BB0 0x021F6BB0 thumb ov112
 *   func_02030734 0x02030734 arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   d_021FDD00 0x021FDD00 data a4
 *   func_021FAE4C 0x021FAE4C thumb ov132
 *   func_021FADF8 0x021FADF8 thumb ov132
 *   func_021F9DC0 0x021F9DC0 thumb ov132
 *   func_021F9EDC 0x021F9EDC thumb ov132
 *   func_021F9DCC 0x021F9DCC thumb ov132
 *   func_021F9DC4 0x021F9DC4 thumb ov132
 *   func_021F9F58 0x021F9F58 thumb ov132
 *   func_021F9F74 0x021F9F74 thumb ov132
 *   func_021F9FB4 0x021F9FB4 thumb ov132
 *   func_021FAEE8 0x021FAEE8 thumb ov132
 *   func_021F9DD4 0x021F9DD4 thumb ov132
 *   func_021F6E78 0x021F6E78 thumb ov112
 *   func_021F6F14 0x021F6F14 thumb ov112
 *   func_021F6F1C 0x021F6F1C thumb ov112
 *   func_021F9DE8 0x021F9DE8 thumb ov132
 *   func_021F95E8 0x021F95E8 thumb ov132
 *   func_021F9DDC 0x021F9DDC thumb ov132
 *   func_021F6EE4 0x021F6EE4 thumb ov112
 *   func_021F6EF4 0x021F6EF4 thumb ov112
 *   func_021F6F04 0x021F6F04 thumb ov112
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_021F9DF4 0x021F9DF4 thumb ov132
 *   func_021F8044 0x021F8044 thumb ov112
 *   func_0207C9D0 0x0207C9D0 arm
 *   func_021FAEA8 0x021FAEA8 thumb ov132
 *   func_021F93D8 0x021F93D8 thumb ov132
 */
#include "../../matched/include/Obj14116.h"
#include "../../matched/include/Obj14117.h"
#include "../../matched/include/Obj02193.h"
#include "../../matched/include/Obj05402.h"
#include "../../matched/include/Obj08167.h"
#include "../../matched/include/Obj08168.h"
#include "../../matched/include/Obj10557.h"
#include "../../matched/include/Obj14118.h"
#include "../../matched/include/Obj10558.h"
#include "../../matched/include/Obj14119.h"
#include "../../matched/include/Obj05403.h"
#include "../../matched/include/Obj23258.h"
#include "../../matched/include/Obj10559.h"
#include "../../matched/include/Obj23259.h"
#include "../../matched/include/Obj01741.h"
#include "../../matched/include/Obj02486.h"
#include "../../matched/include/Obj10560.h"
#include "../../matched/include/Obj02851.h"
#include "../../matched/include/Obj10562.h"
#include "../../matched/include/Obj08169.h"
#include "../../matched/include/Obj14120.h"
#include "../../matched/include/Obj02194.h"
#include "../../matched/include/Obj05404.h"
#include "../../matched/include/Obj08170.h"
#include "../../matched/include/Obj08171.h"
#include "../../matched/include/Obj02487.h"
#include "../../matched/include/Obj04519.h"
#include "../../matched/include/Obj04520.h"
#include "../../matched/include/Obj06492.h"
#include "../../matched/include/Obj14121.h"
#include "../../matched/include/Obj10563.h"
#include "../../matched/include/Obj23260.h"

struct Cursor;
struct Comm;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { int x,y,z; } Vec;

extern unsigned int func_0201134C(struct Cursor *);
extern void *func_021F9DAC(void *);
extern unsigned int *func_021F9DB0(void *,unsigned char);
extern void func_021F9DB8(void *p, void *v, u32 i);
extern void func_021F6B80(unsigned int *,unsigned int *);
extern void func_021F6BC0(char *,unsigned int *,unsigned int);
extern void func_021F6B9C(void *,u32 *,u32 *);
extern void func_021F6BB0(void *,u32 *,u32 *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_0207CA00(void *,void *,void *);
extern void *func_021FADA0(char *,u32,u32,u32);
extern int func_021FAE4C(char *,int *);
extern void func_021FADF8(char *p, char *q);
extern void *func_021F9DC0(void *p);
extern char *func_021F9EDC(char *,unsigned int);
extern void func_021F9DCC(void *p, void *v, u32 i);
extern void *func_021F9DC4(void *,u8);
extern void func_021F9F58(u8 *,u8 *);
extern void func_021F9F74(void *, u16, void *);
extern void func_021F9FB4(char *p, int i);
extern int func_021FAEE8(char *p);
extern u32 func_02005728(u32 range);
extern void *func_021F9DD4(void *);
extern u8 *func_021F6E78(u8 *p, int v);
extern void func_021F6F14(void *a, char *p, u16 b, u8 c);
extern void func_021F6F1C(void *a, char *p, u32 b, u32 c);
extern void func_021F9DE8(void *,void *,u8);
extern void func_021F95E8(char *p);
extern void *func_021F9DDC(void *,u8);
extern void func_021F6EE4(void *,u8 *);
extern void func_021F6EF4(void *unused, u32 *p, const u32 *q);
extern void func_021F6F04(void *,char *,Vec *);
extern int func_021FB1F4(char *,int);
extern void *func_021F9DA0(char *p);
extern void *func_021F9DA4(char *p, u32 i);
extern void *func_021F9DF4(void *p);
extern void func_021F8044(void *unused, u32 *p, u32 *q);
extern void func_0207C9D0(const Vec *,const Vec *,Vec *);
extern int func_021FAEA8(char *,void *);
extern void func_021F93D8(u8 *,u16,u32);
int func_021FBE64(int unused,char *p);
int func_021FBE90(int unused,char *p);
void func_021FBF74(int unused,char *p);
int func_021FBFA8(int unused,char *p);
int func_021FBFDC(int unused,char *p);
int func_021FC014(int unused, char *p);
int func_021FC080(int unused,char *p);
int func_021FC0AC(int unused,char *p);
void func_021FC178(int a, char *p);
int func_021FC1D4(int a,char **p);
int func_021FC22C(int unused,char *p);
int func_021FC268(int unused,char *p);
void func_021FC34C(int unused,char *p);
int func_021FC380(int unused,char *p);
void func_021FC490(int unused,char *p);
int func_021FC4CC(int a,char **p);
int func_021FC53C(int unused,char *p);
extern const char d_021FDD00[];

int func_021FBE64(int unused,char *p) { char *obj; unsigned int n; void *ctx; obj=*(char * *)&((struct Obj14116 *)p)->f0;n=func_0201134C(*(struct Cursor * *)&((struct Obj14116 *)p)->f4);ctx=func_021F9DAC(((struct Obj14117 *)obj)->f34);func_021F6BC0(ctx,func_021F9DB0(((struct Obj14117 *)obj)->f34,n),0);return 0; }

int func_021FBE90(int unused,char *p)
{
    char *owner,*q;
    u32 pos[3];
    int delta[3];
    u32 e,d,c,b,a;
    u32 *target;
    void *ctx;
    owner=*(char * *)&((struct Obj05402 *)p)->f0;
    a=func_0201134C(((struct Obj05402 *)p)->f4);
    b=func_0201134C(((struct Obj05402 *)p)->f4);
    c=func_0201134C(((struct Obj05402 *)p)->f4);
    d=func_0201134C(((struct Obj05402 *)p)->f4);
    e=func_0201134C(((struct Obj05402 *)p)->f4);
    ctx=func_021F9DAC(((struct Obj08167 *)owner)->f34);
    target=func_021F9DB0(((struct Obj08167 *)owner)->f34,a);
    if (b==0) {
        pos[0]=c;pos[1]=d;pos[2]=e;
        func_021F6B9C(ctx,target,pos);
    } else {
        q=func_02030734(((struct Obj08167 *)owner)->f0,56,0,d_021FDD00,0x601);
        *(char * *)&((struct Obj02193 *)q)->f30=owner;
        *(u32 * *)&((struct Obj02193 *)q)->f0=target;
        ((struct Obj02193 *)q)->f4=((struct Obj08167 *)owner)->f34;
        ((struct Obj02193 *)q)->f2E=0;
        func_021F6BB0(ctx,target,(u32 *)(q+8));
        ((struct Obj02193 *)q)->f14=c;((struct Obj02193 *)q)->f18=d;((struct Obj02193 *)q)->f1C=e;
        ((struct Obj02193 *)q)->f2C=b;
        func_0207CA00(q+20,q+8,delta);
        ((struct Obj02193 *)q)->f20=delta[0]/(int)b;
        ((struct Obj02193 *)q)->f24=delta[1]/(int)b;
        ((struct Obj02193 *)q)->f28=delta[2]/(int)b;
        ((struct Obj02193 *)q)->f34=func_021FADA0(owner,(u32)func_021FBF74,(u32)q,10);
    }
    return 0;
}

void func_021FBF74(int unused,char *p) { int pos[3]; void *ctx; int result;ctx=func_021F9DAC(((struct Obj08168 *)p)->f4);result=func_021FAE4C(p+4,pos);func_021F6B9C(ctx,*(unsigned int * *)&((struct Obj08168 *)p)->f0,(unsigned int *)pos);if(result==1)func_021FADF8(((struct Obj08168 *)p)->f30,((struct Obj08168 *)p)->f34);}

/*
 * prototype: Own 021F9EDC source takes u16; original caller passes the
 * full word b+0x33 without truncation, so the extern parameter is widened.
 */
int func_021FBFA8(int unused,char *p) { char *obj; unsigned int a,b; char *entry;obj=*(char * *)&((struct Obj10557 *)p)->f0;a=func_0201134C(*(struct Cursor * *)&((struct Obj10557 *)p)->f4);b=func_0201134C(*(struct Cursor * *)&((struct Obj10557 *)p)->f4);entry=func_021F9EDC(func_021F9DC0(((struct Obj14118 *)obj)->f34),b+0x33);func_021F9DCC(((struct Obj14118 *)obj)->f34,entry,(unsigned char)a);return 0; }

int func_021FBFDC(int unused,char *p) { char *o; u32 a; void *ctx; o=*(char * *)&((struct Obj14119 *)p)->f0; a=func_0201134C(*(struct Cursor * *)&((struct Obj14119 *)p)->f4); ctx=func_021F9DC0(((struct Obj10558 *)o)->f34); func_021F9F58(ctx,func_021F9DC4(((struct Obj10558 *)o)->f34,a)); func_021F9DCC(((struct Obj10558 *)o)->f34,0,(u8)a); return 0; }

int func_021FC014(int unused, char *p)
{
    char *obj;
    int a, b, c, d, e;
    void *target;
    struct { int x, y, z; } vec;
    obj = *(char * *)&((struct Obj05403 *)p)->f0;
    a = func_0201134C(((struct Obj05403 *)p)->f4);
    b = func_0201134C(((struct Obj05403 *)p)->f4);
    c = func_0201134C(((struct Obj05403 *)p)->f4);
    d = func_0201134C(((struct Obj05403 *)p)->f4);
    e = func_0201134C(((struct Obj05403 *)p)->f4);
    target = func_021F9DC4(((struct Obj23258 *)obj)->f34, (u8)a);
    vec.x = c / 16;
    vec.y = (0xC0000 - d) / 16;
    vec.z = e;
    func_021F9F74(target, (u16)b, &vec);
    return 0;
}

int func_021FC080(int unused,char *p) { char *o; u32 a,b; o=*(char * *)&((struct Obj10559 *)p)->f0; a=func_0201134C(*(struct Cursor * *)&((struct Obj10559 *)p)->f4); b=func_0201134C(*(struct Cursor * *)&((struct Obj10559 *)p)->f4); func_021F9FB4(func_021F9DC4(((struct Obj23259 *)o)->f34,a),(u16)b); return 0; }

int func_021FC0AC(int unused,char *p)
{
    char *owner,*q;
    void *target;
    u32 j,i,h,g,f,e,d,c,b,a;
    owner=*(char * *)&((struct Obj02486 *)p)->f0;
    a=func_0201134C(((struct Obj02486 *)p)->f4);
    b=func_0201134C(((struct Obj02486 *)p)->f4);
    c=func_0201134C(((struct Obj02486 *)p)->f4);
    d=func_0201134C(((struct Obj02486 *)p)->f4);
    e=func_0201134C(((struct Obj02486 *)p)->f4);
    f=func_0201134C(((struct Obj02486 *)p)->f4);
    g=func_0201134C(((struct Obj02486 *)p)->f4);
    h=func_0201134C(((struct Obj02486 *)p)->f4);
    i=func_0201134C(((struct Obj02486 *)p)->f4);
    j=func_0201134C(((struct Obj02486 *)p)->f4);
    target=func_021F9DC4(((struct Obj10560 *)owner)->f34,a);
    q=func_02030734(((struct Obj10560 *)owner)->f0,56,0,d_021FDD00,0x691);
    *(char * *)&((struct Obj01741 *)q)->f30=owner;
    ((struct Obj01741 *)q)->f10=target;
    ((struct Obj01741 *)q)->f2C=b;
    ((struct Obj01741 *)q)->f14=e;
    ((struct Obj01741 *)q)->f18=f;
    ((struct Obj01741 *)q)->f1C=g;
    ((struct Obj01741 *)q)->f20=h-e;
    ((struct Obj01741 *)q)->f24=i-f;
    ((struct Obj01741 *)q)->f28=j-g;
    ((struct Obj01741 *)q)->f0=((struct Obj10560 *)owner)->f34;
    ((struct Obj01741 *)q)->f4=0;
    ((struct Obj01741 *)q)->f8=c;
    ((struct Obj01741 *)q)->fC=d;
    ((struct Obj01741 *)q)->f34=func_021FADA0(owner,(u32)func_021FC178,(u32)q,10);
    return 0;
}

void func_021FC178(int a, char *p)
{
    u32 v[3];
    int s;
    s=func_021FAEE8(p);
    if(s==2) {
        func_021FADF8(((struct Obj02851 *)p)->f30,((struct Obj02851 *)p)->f34);
        return;
    }
    if(s==1) {
        v[0]=(((struct Obj02851 *)p)->f14+func_02005728((u32)(((struct Obj02851 *)p)->f20)))>>4;
        v[1]=(0xc0000-(((struct Obj02851 *)p)->f18+func_02005728((u32)(((struct Obj02851 *)p)->f24))))>>4;
        v[2]=((struct Obj02851 *)p)->f1C+func_02005728((u32)(((struct Obj02851 *)p)->f28));
        func_021F9F74(((struct Obj02851 *)p)->f10,((struct Obj02851 *)p)->f2C,v);
    }
}

int func_021FC1D4(int a,char **p)
{
    char *q;
    u32 x,y;
    void *r,*s;
    q=p[0];
    x=func_0201134C((struct Cursor *)p[1]);
    y=func_0201134C((struct Cursor *)p[1]);
    r=func_021F9DD4(((struct Obj10562 *)q)->f34);
    s=func_021F6E78(r,1);
    func_021F6F14(r,s,0x3ff,0x10);
    func_021F6F1C(r,s,y,0);
    func_021F9DE8(((struct Obj10562 *)q)->f34,s,x);
    func_021F95E8(((struct Obj10562 *)q)->f34);
    return 0;
}

int func_021FC22C(int unused,char *p) { char *o; u32 a; void *ctx; o=*(char * *)&((struct Obj14120 *)p)->f0; a=func_0201134C(*(struct Cursor * *)&((struct Obj14120 *)p)->f4); ctx=func_021F9DD4(((struct Obj08169 *)o)->f34); func_021F6EE4(ctx,func_021F9DDC(((struct Obj08169 *)o)->f34,a)); func_021F9DE8(((struct Obj08169 *)o)->f34,0,a); func_021F95E8(((struct Obj08169 *)o)->f34); return 0; }

int func_021FC268(int unused,char *p)
{
    char *owner,*q;
    Vec pos;
    int delta[3];
    u32 e,d,c,b,a;
    void *target;
    void *ctx;
    owner=*(char * *)&((struct Obj05404 *)p)->f0;
    a=func_0201134C(((struct Obj05404 *)p)->f4);
    b=func_0201134C(((struct Obj05404 *)p)->f4);
    c=func_0201134C(((struct Obj05404 *)p)->f4);
    d=func_0201134C(((struct Obj05404 *)p)->f4);
    e=func_0201134C(((struct Obj05404 *)p)->f4);
    ctx=func_021F9DD4(((struct Obj08170 *)owner)->f34);
    target=func_021F9DDC(((struct Obj08170 *)owner)->f34,a);
    if (b==0) {
        pos.x=c;pos.y=d;pos.z=e;
        func_021F6EF4(ctx,target,(const u32 *)(&pos));
    } else {
        q=func_02030734(((struct Obj08170 *)owner)->f0,56,0,d_021FDD00,0x704);
        *(char * *)&((struct Obj02194 *)q)->f30=owner;
        *(u32 * *)&((struct Obj02194 *)q)->f0=target;
        ((struct Obj02194 *)q)->f4=((struct Obj08170 *)owner)->f34;
        ((struct Obj02194 *)q)->f2E=0;
        func_021F6F04(ctx,target,(Vec *)(q+8));
        ((struct Obj02194 *)q)->f14=c;((struct Obj02194 *)q)->f18=d;((struct Obj02194 *)q)->f1C=e;
        ((struct Obj02194 *)q)->f2C=b;
        func_0207CA00(q+20,q+8,delta);
        ((struct Obj02194 *)q)->f20=delta[0]/(int)b;
        ((struct Obj02194 *)q)->f24=delta[1]/(int)b;
        ((struct Obj02194 *)q)->f28=delta[2]/(int)b;
        ((struct Obj02194 *)q)->f34=func_021FADA0(owner,(u32)func_021FC34C,(u32)q,10);
    }
    return 0;
}

void func_021FC34C(int unused,char *p) { int pos[3]; void *ctx; int result; ctx=func_021F9DD4(((struct Obj08171 *)p)->f4); result=func_021FAE4C(p+4,pos); func_021F6EF4(ctx,*(u32 * *)&((struct Obj08171 *)p)->f0,(u32 *)pos); if(result==1) func_021FADF8(*(char * *)&((struct Obj08171 *)p)->f30,*(char * *)&((struct Obj08171 *)p)->f34); }

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

void func_021FC490(int unused,char *p) { int pos[3]; void *ctx; int result; ctx=func_021F9DD4(((struct Obj06492 *)p)->f8); func_021F9DF4(((struct Obj06492 *)p)->f8); result=func_021FAEA8(p+8,pos); func_021F6EF4(ctx,*(u32 * *)&((struct Obj06492 *)p)->f4,(u32 *)pos); if(result==1) func_021FADF8(*(char * *)&((struct Obj06492 *)p)->f28,*(char * *)&((struct Obj06492 *)p)->f2C); }

/*
 * follower: two-byte zero alignment padding at 021FC53A.
 */
int func_021FC4CC(int a,char **p)
{
    char *q;
    u32 v,w,x,y,z;
    void *r,*s;
    q=p[0];
    v=func_0201134C((struct Cursor *)p[1]);
    w=func_0201134C((struct Cursor *)p[1]);
    x=func_0201134C((struct Cursor *)p[1]);
    y=func_0201134C((struct Cursor *)p[1]);
    z=func_0201134C((struct Cursor *)p[1]);
    r=func_021F9DD4(((struct Obj14121 *)q)->f34);
    s=func_021F9DDC(((struct Obj14121 *)q)->f34,v);
    func_021F6F14(r,s,(u8)w|((u8)x<<5)|((u8)y<<10),z);
    return 0;
}

int func_021FC53C(int unused,char *p) { char *o; u32 a,b; o=*(char * *)&((struct Obj10563 *)p)->f0; a=func_0201134C(*(struct Cursor * *)&((struct Obj10563 *)p)->f4); b=func_0201134C(*(struct Cursor * *)&((struct Obj10563 *)p)->f4); func_021F93D8(*(u8 * *)&((struct Obj23260 *)o)->f34,a,b); return 0; }
