/*
 * file:     unit_021B95A0_p08.c
 * unit:     yes
 * function: func_021BA780, func_021BA7B8, func_021BA7D0, func_021BA81C, func_021BA8BC, func_021BA8D4, func_021BA8E8, func_021BA8F4, func_021BA920, func_021BA95C, func_021BA9AC, func_021BA9C0, func_021BA9D0, func_021BAA20, func_021BAA8C, func_021BAABC
 * address:  0x021BA780
 * region:   ov213
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 *   func_02047CFC 0x02047CFC arm
 *   func_02050B80 0x02050B80 arm
 *   func_02047E54 0x02047E54 arm
 *   func_021BAC7C 0x021BAC7C thumb ov213
 *   func_021BAC88 0x021BAC88 thumb ov213
 *   func_02050BE8 0x02050BE8 arm
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   func_02048A18 0x02048A18 arm
 *   func_02047A60 0x02047A60 arm
 *   func_02050C04 0x02050C04 arm
 *   func_02051758 0x02051758 arm
 *   func_02051648 0x02051648 arm
 *   func_0205121C 0x0205121C arm
 *   func_02051B04 0x02051B04 arm
 *   func_020056BC 0x020056BC thumb
 *   func_02051230 0x02051230 arm
 *   d_021BB324 0x021BB324 data a4
 *   d_021BB330 0x021BB330 data a4
 *   d_021BB360 0x021BB360 data a4
 *   func_02051620 0x02051620 arm
 *   func_02050DB8 0x02050DB8 arm
 *   func_02050ED4 0x02050ED4 arm
 *   func_020515B4 0x020515B4 arm
 *   func_02047788 0x02047788 arm
 *   func_02047554 0x02047554 arm
 *   func_0204755C 0x0204755C arm
 *   func_02047250 0x02047250 arm
 *   func_0206A67C 0x0206A67C arm
 *   func_0206A5B4 0x0206A5B4 arm
 *   func_02047E88 0x02047E88 arm
 *   func_0204779C 0x0204779C arm
 *   func_020477A4 0x020477A4 arm
 *   d_021BB0F8 0x021BB0F8 data a4
 *   func_020480E4 0x020480E4 arm
 *   func_02047910 0x02047910 arm
 *   d_021BB320 0x021BB320 data a4
 *   func_0201AA18 0x0201AA18 thumb
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021BB1A8 0x021BB1A8 data a2
 */
#include "../../matched/include/Obj10929.h"
#include "../../matched/include/Obj10931.h"
#include "../../matched/include/Obj04631.h"
#include "../../matched/include/Obj02925.h"
#include "../../matched/include/Obj10930.h"
#include "../../matched/include/Obj25709.h"
#include "../../matched/include/Obj25710.h"
#include "../../matched/include/Obj25711.h"
#include "../../matched/include/Obj02551.h"
#include "../../matched/include/Obj08420.h"
#include "../../matched/include/Obj08421.h"
#include "../../matched/include/Obj10932.h"
#include "../../matched/include/Obj25712.h"

#define REG3D (*(volatile unsigned short *)0x04000060)
struct Rec;
struct Dst648;
struct G3dSys;
struct Ctx;
typedef unsigned int u32;

typedef struct { u32 x,y,z; } VecFx32;

typedef struct { u32 m[9]; } MtxFx33;

struct Arg { VecFx32 pos,v0c; MtxFx33 m18; };

typedef struct Util Util;

typedef unsigned char  u8;

typedef unsigned short u16;

struct Src648 {u32 f00,f04,f08,f0c,f10,f14,f18,f1c;};

typedef short s16;

typedef struct { void *resTbl; u16 resCount; void *objTbl; u16 objCount; } Setup;

typedef enum { SHADING1 = 1 } GXShading;

typedef int BOOL;

extern void func_0207D63C(void *,int,int,int,int),func_02050B80(unsigned);
extern void *func_02047CFC(unsigned,unsigned,unsigned);
extern void func_02047E54(struct Rec *p);
extern void func_021BAC7C(char *p);
extern void func_021BAC88(char *p);
extern void func_02050BE8(void);
extern void MTX_Identity33_(MtxFx33 *p);
extern u32 func_02048A18(u8 *a0, int i);
extern void func_02047A60(void *a0, struct Arg *a1);
extern int func_02050C04(int a,int b,int c,int d);
extern int func_02051758(int a);
extern void func_02051648(struct Dst648 *p,struct Src648 *src,u16 a2,int *a3,int *a4,int *a5,u32 heap);
extern int func_0205121C(u32 a,u32 b,u32 c);
extern u16 func_02051B04(void *res);
extern u32 func_020056BC(void);
extern void func_02051230(u8 *o,u32 a1,u32 a2,u32 a3);
extern void func_02051620(u8 *);
extern void func_02050DB8(u8 *);
extern void func_02050ED4(void);
extern int func_020515B4(void *,int,int);
extern int func_02047788(int *),func_02047554(int *),func_0204755C(int *);
extern int func_02047250(char *);
extern void func_0206A67C(char *);
extern int func_0206A5B4(char *,char *,u32,u32);
extern u16 func_02047E88(Util *util, const Setup *setup);
extern int func_0204779C(int *p);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_020480E4(struct Ctx *,u32);
extern int func_02047910(void *a, int idx, int amount);
extern unsigned func_0201AA18(void *list);
extern void func_020434DC(unsigned, unsigned);
extern void func_0207DC44(BOOL, int, int, int);
extern void func_0207DD24(unsigned short, int, int, int, BOOL);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(unsigned, unsigned);
void func_021BA780(char *p,void *state,short heap);
void func_021BA7B8(char *p);
void func_021BA7D0(unsigned char *p);
void func_021BA81C(u8 *p,unsigned code);
void func_021BA8BC(char *p, int object);
void func_021BA8D4(char *p);
int func_021BA8E8(char *p,int b,int c);
void func_021BA8F4(char *p,int v);
int func_021BA920(int *p,u32 b,u32 c);
void func_021BA95C(unsigned char *p, int index);
void func_021BA9AC(char *p);
void func_021BA9C0(void *a);
int func_021BA9D0(unsigned char *p);
void func_021BAA20(unsigned char *p);
int func_021BAA8C(char *p);
void func_021BAABC(void);
extern int d_021BB324[],d_021BB330[],d_021BB360[];
extern const Setup d_021BB0F8[];
extern int d_021BB320;
extern const unsigned short d_021BB1A8[][4];

void func_021BA780(char *p,void *state,short heap){func_0207D63C((void *)0x04000050,1,31,0,0);((struct Obj10929 *)p)->f0=state;((struct Obj10929 *)p)->f4=heap;((struct Obj10929 *)p)->f8=func_02047CFC(16,20,heap);func_02050B80(heap);}

void func_021BA7B8(char *p){func_021BA9C0(p);func_021BA8D4(p);func_02047E54(((struct Obj10931 *)p)->f8);}

void func_021BA7D0(unsigned char *p)
{
    struct Arg arg;
    void *object;
    func_021BAC7C(((struct Obj04631 *)p)->f0);
    if(((struct Obj04631 *)p)->f10) func_02050BE8();
    if(p[15]) {
        arg.pos.x=0; arg.pos.y=0; arg.pos.z=0;
        arg.v0c.x=0x1000; arg.v0c.y=0x1000; arg.v0c.z=0x1000;
        MTX_Identity33_(&arg.m18);
        object=(void *)func_02048A18((u8 *)(*(Util * *)&((struct Obj04631 *)p)->f8),((struct Obj04631 *)p)->fC);
        func_02047A60(object,&arg);
    }
    func_021BAC88(((struct Obj04631 *)p)->f0);
}

void func_021BA81C(u8 *p,unsigned code)
{
    struct Src648 config;
    int resource;
    u32 context;
    if(*(int *)&((struct Obj02925 *)p)->f10) func_021BA8BC((char *)p,*(int *)&((struct Obj02925 *)p)->f10);
    *(int *)&((struct Obj02925 *)p)->f10=func_02050C04((int)(p+20),0x4800,1,((struct Obj02925 *)p)->f4);
    config.f04=0x3000;
    config.f08=-0x3000;
    config.f00=2;
    config.f0c=-0x4000;
    config.f10=0x4000;
    config.f14=0x1000;
    config.f18=0x400000;
    config.f1c=0;
    func_02051758(*(int *)&((struct Obj02925 *)p)->f10);
    func_02051648(*(struct Dst648 * *)&((struct Obj02925 *)p)->f10,&config,0x2000,d_021BB330,d_021BB324,d_021BB360,((struct Obj02925 *)p)->f4);
    resource=func_0205121C(0xB5,code,((struct Obj02925 *)p)->f4);
    p[0x4814]=func_02051B04((void *)resource);
    context=func_020056BC();
    func_02051230(*(u8 * *)&((struct Obj02925 *)p)->f10,resource,0,context);
}

void func_021BA8BC(char *p, int object) { func_02051620(*(u8 * *)&((struct Obj10930 *)p)->f10); func_02050DB8(*(u8 * *)&((struct Obj10930 *)p)->f10); *(u32 *)&((struct Obj10930 *)p)->f10=0; }

void func_021BA8D4(char *p) { if(*(u8 * *)&((struct Obj10931 *)p)->f10) func_02050DB8(*(u8 * *)&((struct Obj10931 *)p)->f10); func_02050ED4(); }

int func_021BA8E8(char *p,int b,int c) { return func_020515B4(((struct Obj25709 *)p)->f10,b,c); }

/*
 * The original truncates the second call argument to u16; the extern preserves that width.
 */
void func_021BA8F4(char *p,int v) { int i; for(i=0;i<((struct Obj25710 *)p)->f4814;i++) func_021BA8E8(p,(u16)i,v); }

/*
 * EXACT* tail: two zero alignment bytes after the function.
 */
int func_021BA920(int *p,u32 b,u32 c) { int *q; char *a,*h,*r; q=(int *)func_02047788(p); a=(char *)func_02047554(q); h=*(char * *)&((struct Obj25711 *)((char *)func_0204755C(q)))->f4; r=(char *)func_02047250(a); func_0206A67C(h); return func_0206A5B4(h,r,b,c)&1; }

/*
 * width: 477A4 index u16: original narrows at 021BA994-021BA998.
 */
void func_021BA95C(unsigned char *p, int index)
{
    int *object;
    int i, count;
    if (p[15]) func_021BA9AC((char *)p);
    ((struct Obj02551 *)p)->fC=func_02047E88(*(Util * *)&((struct Obj02551 *)p)->f8, &d_021BB0F8[index]);
    p[15]=1;
    object=(int *)func_02048A18((u8 *)(*(Util * *)&((struct Obj02551 *)p)->f8), ((struct Obj02551 *)p)->fC);
    count=func_0204779C(object);
    for(i=0;i<count;i++) func_020477A4((struct G3dSys *)object,(u16)i);
}

void func_021BA9AC(char *p) { func_020480E4(*(struct Ctx * *)&((struct Obj02551 *)p)->f8,((struct Obj02551 *)p)->fC); ((struct Obj02551 *)p)->fF=0; ((struct Obj02551 *)p)->fE=0; }


void func_021BA9C0(void *a)
{
    if (((struct Obj02551 *)a)->fF)
        func_021BA9AC(a);
}

int func_021BA9D0(unsigned char *p)
{
    int result=1;
    int *object;
    int count,i;
    if(p[14]) return 0;
    object=(int *)func_02048A18((u8 *)(*(Util * *)&((struct Obj08420 *)p)->f8), ((struct Obj08420 *)p)->fC);
    count=func_0204779C(object);
    for(i=0;i<count;i++) {
        result=func_02047910(object,(u16)i,d_021BB320<<12);
        if(!result) p[14]=1;
    }
    return result;
}

/*
 * extent: 021BAA8A..021BAA8C is two zero alignment bytes, no follower.
 */
void func_021BAA20(unsigned char *p)
{
    int i;
    if(((struct Obj10932 *)p)->f44==1) {
        int j;
        unsigned char *row;
        for(i=0;i<2;i++) {
            row=p+16*i;
            for(j=0;j<(int)func_0201AA18(((struct Obj08421 *)row)->f0);j++) row[10+j]=0;
        }
        return;
    }
    if(((struct Obj10932 *)p)->f44==3) {
        unsigned char *row;
        int j;
        for(i=0;i<4;i++) {
            row=p+16*i;
            for(j=0;j<(int)func_0201AA18(((struct Obj08421 *)row)->f0);j++) row[10+j]=0;
        }
    }
}

int func_021BAA8C(char *p) { void *q; u8 *flags; int i,n; q=((struct Obj25712 *)p)->f0; n=0; flags=(u8 *)p+10; for(i=0;i<(int)func_0201AA18(q);i++) if(flags[i]<=1) n++; return n; }

static inline void Shading(GXShading mode) { REG3D = (unsigned short)((REG3D & ~0x3002) | (mode << 1)); }

static inline void AntiAlias(BOOL enable) { if (enable) REG3D = (unsigned short)((REG3D & ~0x3000) | 0x10); else REG3D &= (unsigned short)~0x3010; }

static inline void AlphaTest(BOOL enable, int ref) { if (enable) { REG3D = (unsigned short)((REG3D & ~0x3000) | 4); *(volatile unsigned short *)0x04000340 = ref; } else REG3D &= (unsigned short)~0x3004; }

static inline void AlphaBlend(BOOL enable) { if (enable) REG3D = (unsigned short)((REG3D & ~0x3000) | 8); else REG3D &= (unsigned short)~0x3008; }

static inline void EdgeMarking(BOOL enable) { if (enable) REG3D = (unsigned short)((REG3D & ~0x3000) | 0x20); else REG3D &= (unsigned short)~0x3020; }

void func_021BAABC(void)
{
    unsigned i;
    func_020434DC(1, 1);
    *(volatile unsigned short *)0x04000008 = (unsigned short)((*(volatile unsigned short *)0x04000008 & ~3) | 1);
    Shading(SHADING1);
    AntiAlias(0);
    AlphaTest(0, 0);
    AlphaBlend(1);
    EdgeMarking(0);
    func_0207DC44(0, 0, 0, 0);
    func_0207DD24(0, 0, 0x7FFF, 63, 0);
    *(volatile unsigned *)0x04000580 = 0xBFFF0000;
    for (i = 0; i < 4; i++) func_02046A94((unsigned char)i, d_021BB1A8[i]);
    func_02046BE0(1, 0);
}
