/*
 * file:     intro_g3d.c
 * unit:     yes
 * function: func_021BF67C, func_021BF720, func_021BF744, func_021BF788, func_021BF794, func_021BF7CC, func_021BF7F0, func_021BF804, func_021BF864, func_021BF898, func_021BF8DC, func_021BF9D0, func_021BF9FC, func_021BFA40, func_021BFAE4, func_021BFAE8, func_021BFB2C, func_021BFBA0, func_021BFBC8, func_021BFC24, func_021BFCD0, func_021BFCE0
 * address:  0x021BF67C
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   defaultPos_021C08FC 0x021C08FC data
 *   func_02015CAC 0x02015CAC thumb
 *   func_02015E04 0x02015E04 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   func_02015EB0 0x02015EB0 thumb
 *   func_02015EA0 0x02015EA0 thumb
 *   func_02016028 0x02016028 thumb
 *   func_02015E4C 0x02015E4C thumb
 *   func_02015F2C 0x02015F2C thumb
 *   func_0207D63C 0x0207D63C arm
 *   func_02015FBC 0x02015FBC thumb
 *   func_02015DB0 0x02015DB0 thumb
 *   func_02015DC0 0x02015DC0 thumb
 *   func_02016374 0x02016374 thumb
 *   func_02015C30 0x02015C30 thumb
 *   func_02015C48 0x02015C48 thumb
 *   func_02030734 0x02030734 arm
 *   func_02047CFC 0x02047CFC arm
 *   func_02048A24 0x02048A24 arm
 *   func_02047E88 0x02047E88 arm
 *   func_02048A18 0x02048A18 arm
 *   func_020477A4 0x020477A4 arm
 *   func_020477D4 0x020477D4 arm
 *   site_021C0B00 0x021C0B00 data a1
 *   va 0x021C0914 data a4
 *   vb 0x021C0920 data a4
 *   vc 0x021C0908 data a4
 *   setup 0x021C093C data a4
 *   func_02048AC4 0x02048AC4 arm
 *   func_020480E4 0x020480E4 arm
 *   func_02047E54 0x02047E54 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   func_02047A60 0x02047A60 arm
 *   func_020478B8 0x020478B8 arm
 *   func_0204784C 0x0204784C arm
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_02050B80 0x02050B80 arm
 *   func_02050C04 0x02050C04 arm
 *   func_02051758 0x02051758 arm
 *   func_02051648 0x02051648 arm
 *   func_0205121C 0x0205121C arm
 *   func_02051230 0x02051230 arm
 *   d_021C0B30 0x021C0B30 data a1
 *   d_021C0B18 0x021C0B18 data a4
 *   d_021C0B0C 0x021C0B0C data a4
 *   d_021C0B24 0x021C0B24 data a4
 *   func_02050ED4 0x02050ED4 arm
 *   func_02050BE8 0x02050BE8 arm
 */
#include "../../matched/include/Obj10881.h"
#include "../../matched/include/Obj10882.h"
#include "../../matched/include/Obj14628.h"
#include "../../matched/include/Obj06674.h"
#include "../../matched/include/Obj02921.h"
#include "../../matched/include/Obj08385.h"
#include "../../matched/include/Obj06675.h"
#include "../../matched/include/Obj06676.h"
#include "../../matched/include/Obj25391.h"
#include "../../matched/include/Obj03922.h"
#include "../../matched/include/Obj01974.h"
#include "../../matched/include/Obj14629.h"
#include "../../matched/include/Obj03923.h"

struct Obj;
struct Rec;
struct Stats;
struct Sub150;
struct G3dSys;
struct Owner;
struct Ctx;
struct Light;
struct Arg;
struct AnmCtl;
struct Dst648;
struct Src648;
struct Vec { int v[3]; };

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {u32 x,y,z;} Vec3;

typedef signed int     s32;

typedef struct { int a,b,c,d,e,f,g,h; } Config;

extern void *func_020173F0(unsigned short, unsigned short, unsigned long long, unsigned short);
extern void func_02017100(void *p, struct Stats *out, u32 lvl);
extern u32 func_020307B0(void *p);
extern struct Rec *func_020159C8(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
extern void func_02015CAC(void *p, u32 *src);
extern void func_02015E04(void *);
extern unsigned int func_0203F0A8(void);
extern void func_02015F2C(void *, void *, void (*)(void *, void *), int);
extern void func_02015EB0(void *);
extern void func_02015EA0(void *);
extern void func_02016028(void *, unsigned int);
extern void func_02015E4C(void *);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_02015FBC(char *p, int v);
extern void func_02015DB0(void *);
extern void func_02015DC0(void *);
extern void func_02016374(void *);
extern void func_02015C30(void *p, u32 *out);
extern void func_02015C48(void *p, u32 *src);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void *func_02047CFC(u16,u16,u32);
extern void *func_02048A24(u32,u32,u32,u32,u32,u32,u32,u32,Vec3 *,Vec3 *,Vec3 *,u32);
extern u16 func_02047E88(void *,const void *);
extern u32 func_02048A18(u8 *a0, int i);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern int func_020477D4(struct Owner *owner, u32 index);
extern void func_02048AC4(void *);
extern void func_020480E4(struct Ctx *,u32);
extern void func_02047E54(struct Rec *);
extern void func_02048AD0(struct Light *l);
extern void func_0207ADC4(void *);
extern void func_02047A60(void *a0, struct Arg *a1);
extern void func_020061E4(u32 a);
extern int func_020478B8(void *, int, int);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern void func_02050B80(unsigned);
extern int func_02050C04(int a, int b, int c, int d);
extern int func_02051758(int a0);
extern void func_02051648(struct Dst648 *this, struct Src648 *src, u16 a2, int *a3, int *a4, int *a5, u32 a6);
extern int func_0205121C(unsigned,unsigned,unsigned);
extern void func_02051230(void *,unsigned,unsigned,unsigned);
extern void func_02050ED4(void);
extern void func_02050BE8(void);
void func_021BF67C(char *p, unsigned int a, unsigned int b, unsigned int c, unsigned int species, unsigned char i);
void func_021BF720(u8 *p, int flag, u8 index);
void func_021BF744(char *p, unsigned int i, unsigned int flag, unsigned int v);
unsigned int func_021BF77C(char *p, u8 i);
void func_021BF788(u8 *p, u8 index);
void func_021BF794(u8 *p, u8 index, u32 alpha);
void func_021BF7CC(u8 *p, u8 index, int flag);
void func_021BF7F0(u8 *p);
int func_021BF804(char *p, unsigned int i, int step, int limit);
int func_021BF864(char *p,int delta,int limit);
void func_021BF898(char *p);
char *func_021BF8DC(void *owner,int kind,u32 heap);
void func_021BF9D0(char *p);
void func_021BF9FC(char *p);
int func_021BFA40(char *p);
void func_021BFAE4(char *p, int v);
void func_021BFAE8(char *p, unsigned int v);
int func_021BFB2C(char *p);
int func_021BFBA0(int *p);
void func_021BFBC8(char *p,unsigned value);
char *func_021BFC24(void *owner,unsigned heap);
void func_021BFCD0(char *a);
void func_021BFCE0(int a0);
extern const struct Vec defaultPos_021C08FC;
extern const Vec3 va,vb,vc;
extern const char site_021C0B00[];
extern const char setup[];
extern const char d_021C0B30[];
extern int d_021C0B18[];
extern int d_021C0B0C[],d_021C0B24[];


void func_021BF67C(char *p, unsigned int a, unsigned int b, unsigned int c, unsigned int species, unsigned char i)
{
    char data[36];
    struct Vec pos = defaultPos_021C08FC;
    void *tmp = func_020173F0((unsigned short)species, 0, 0, ((struct Obj10881 *)p)->f0);
    char *base = p + 8;
    unsigned int off = i * 12;
    func_02017100(tmp, (struct Stats *)data, 0);
    func_020307B0(tmp);
    *(void **)(base + off) = func_020159C8(((struct Obj10881 *)p)->f4, a, b, c, (const struct Sub150 *)data);
    func_02015CAC(*(void **)(base + off), (u32 *)(&pos));
    func_02015E04(*(void **)(base + off));
    *(unsigned int *)(p + off + 12) = 0;
    *(unsigned int *)(p + off + 16) = 1;
    ((struct Obj10881 *)p)->f68 = 20 * (unsigned int)(((unsigned long long)func_0203F0A8() * 5) >> 32) + 200;
    func_02015F2C(*(void **)(base + off), base + off, (void (*)(void *, void *))func_021BF7F0, 0);
}

void func_021BF720(u8 *p, int flag, u8 index)
{
    if(flag==1)func_02015EB0(*(void **)((u32)p+(u32)index*12+8));
    else func_02015EA0(*(void **)((u32)p+(u32)index*12+8));
}


/*
 * 10-byte getter follower 0x021BF77C is included; function_starts seed. Enum zero separates field and argument clears.
 */
void func_021BF744(char *p, unsigned int i, unsigned int flag, unsigned int v)
{
    char *base = p + 8;
    unsigned int off = i * 12;
    enum { Zero } zero;
    func_02016028(*(void **)(base + off), flag);
    func_02015E4C(*(void **)(base + off));
    zero = Zero;
    *(unsigned int *)(p + off + 12) = zero;
    *(unsigned int *)(p + off + 16) = v;
    func_02015F2C(*(void **)(base + off), base + off, (void (*)(void *, void *))func_021BF7F0, 0);
}


unsigned int func_021BF77C(char *p, u8 i)
{
    return *(unsigned int *)(p + i * 12 + 12);
}


void func_021BF788(u8 *p, u8 index)
{
    *(int *)((u8 *)((u32)p+(u32)index*12)+12)=0;
}

/*
 * prototype: The shifts at 021BF7B8/021BF7BC narrow the outgoing alpha to u8.
 */
void func_021BF794(u8 *p, u8 index, u32 alpha)
{
    func_0207D63C((void *)0x04000050,1,9,0,0);
    if(alpha>31)alpha=31;
    func_02015FBC(*(char **)((u32)p+(u32)index*12+8),(u8)alpha);
}

void func_021BF7CC(u8 *p, u8 index, int flag)
{
    if(flag!=0)func_02015DB0(*(void **)((u32)p+(u32)index*12+8));
    else func_02015DC0(*(void **)((u32)p+(u32)index*12+8));
}

void func_021BF7F0(u8 *p)
{
    ((struct Obj10882 *)p)->f4=1;
    if(((struct Obj10882 *)p)->f8==1)func_02016374(((struct Obj10882 *)p)->f0);
}


int func_021BF804(char *p, unsigned int i, int step, int limit)
{
    struct Vec pos;
    char *base = p + 8;
    unsigned int off = i * 12;
    int done;
    func_02015C30(*(void **)(base + off), (u32 *)(&pos));
    done = 1;
    pos.v[0] += step;
    if (pos.v[0] != limit)
    {
        if ((step > 0 && pos.v[0] > limit) || (step < 0 && pos.v[0] < limit))
            pos.v[0] = limit;
        else
            done = 0;
    }
    func_02015C48(*(void **)(base + off), (u32 *)(&pos));
    if (*(unsigned int *)(p + off + 12) == 1)
        func_02015E04(*(void **)(base + off));
    return done;
}

/*
 * extent: two zero alignment bytes at 0x021BF896 follow; no follower.
 */
int func_021BF864(char *p,int delta,int limit) { u32 v[3]; int done; func_02015C30(((struct Obj14628 *)p)->f14,v); v[1]-=delta; if((int)v[1]<=limit) { v[1]=limit;done=1; } else done=0;func_02015C48(((struct Obj14628 *)p)->f14,v);return done; }


void func_021BF898(char *p)
{
    if (((struct Obj06674 *)p)->f18 != 0)
    {
        if (((struct Obj06674 *)p)->f68 == 0)
        {
            ((struct Obj06674 *)p)->f68 = 20 * (unsigned int)(((unsigned long long)func_0203F0A8() * 5) >> 32) + 200;
            func_021BF744(p, 1, 0, 1);
            return;
        }
        func_02015E04(((struct Obj06674 *)p)->f14);
        --((struct Obj06674 *)p)->f68;
    }
}

char *func_021BF8DC(void *owner,int kind,u32 heap)
{
    Vec3 a,b,c;
    char *p;
    void *obj;
    p=func_02030734(heap,48,1,site_021C0B00,162);
    ((struct Obj02921 *)p)->f4=heap;
    ((struct Obj02921 *)p)->f0=owner;
    ((struct Obj02921 *)p)->f8=func_02047CFC(10,16,heap);
    a=va;b=vb;c=vc;
    ((struct Obj02921 *)p)->fC=func_02048A24(2,24576,(u32)-24576,(u32)-32768,32768,4096,4194304,4096,&a,&b,&c,heap);
    if(kind!=7){
        ((struct Obj02921 *)p)->f10=func_02047E88(((struct Obj02921 *)p)->f8,setup);
        obj=(void *)func_02048A18(((struct Obj02921 *)p)->f8,((struct Obj02921 *)p)->f10);
        func_020477A4(obj,3);func_020477A4(obj,4);
        func_020477D4(obj,0);func_020477D4(obj,1);func_020477D4(obj,2);
    }else ((struct Obj02921 *)p)->f10=0xffff;
    ((struct Obj02921 *)p)->f18=1;
    return p;
}

void func_021BF9D0(char *p) { u16 id; func_02048AC4(((struct Obj08385 *)p)->fC); id=((struct Obj08385 *)p)->f10; if(id!=65535) func_020480E4(*(struct Ctx * *)&((struct Obj08385 *)p)->f8,id);func_02047E54(*(struct Rec * *)&((struct Obj08385 *)p)->f8);func_020307B0(p); }


void func_021BF9FC(char *p)
{
    struct Transform { int pos[3]; int scale[3]; int matrix[9]; } t;
    func_02048AD0(((struct Obj06675 *)p)->fC);
    if (((struct Obj06675 *)p)->f14 != 0 && ((struct Obj06675 *)p)->f18 != 0)
    {
        t.pos[0] = 0;
        t.pos[1] = 0;
        t.pos[2] = 0;
        t.scale[0] = 4096;
        t.scale[1] = 4096;
        t.scale[2] = 4096;
        func_0207ADC4(t.matrix);
        func_02047A60((void *)func_02048A18(((struct Obj06675 *)p)->f8, ((struct Obj06675 *)p)->f10), (struct Arg *)(&t));
    }
}


int func_021BFA40(char *p)
{
    switch (((struct Obj06676 *)p)->f24)
    {
    case 0:
        func_0207D63C((void *)0x04000050, 1, 9, 0, 0);
        func_020061E4(0x555);
        ++((struct Obj06676 *)p)->f24;
    case 1:
    {
        void *obj = (void *)func_02048A18(((struct Obj06676 *)p)->f8, ((struct Obj06676 *)p)->f10);
        int a = func_020478B8(obj, 3, 4096);
        int b = func_020478B8(obj, 4, 4096);
        if (a == 0 && b == 0)
        {
            func_020477D4(obj, 3);
            func_020477D4(obj, 4);
            func_020477A4(obj, 0);
            func_020477A4(obj, 1);
            func_020477A4(obj, 2);
            func_021BFBC8(p, 60);
            ++((struct Obj06676 *)p)->f24;
        }
        break;
    }
    case 2:
        return 1;
    }
    return 0;
}




void func_021BFAE4(char *p, int v)
{
    ((struct Obj25391 *)p)->f14 = v;
}


void func_021BFAE8(char *p, unsigned int v)
{
    ((struct Obj03922 *)p)->f1C = v;
    ((struct Obj03922 *)p)->f20 = 0;
    switch (v)
    {
    case 0:
        ((struct Obj03922 *)p)->f28 = 60;
        ((struct Obj03922 *)p)->f1C = 1;
        break;
    case 1: ((struct Obj03922 *)p)->f28 = 70; break;
    case 2: ((struct Obj03922 *)p)->f28 = 50; break;
    case 3: ((struct Obj03922 *)p)->f28 = 50; break;
    case 4: ((struct Obj03922 *)p)->f28 = 70; break;
    }
}


int func_021BFB2C(char *p)
{
    switch (((struct Obj01974 *)p)->f1C)
    {
    case 0: break;
    case 1:
        --((struct Obj01974 *)p)->f28;
        func_021BFBC8(p, ((struct Obj01974 *)p)->f28);
        if (((struct Obj01974 *)p)->f28 == 50) return 1;
        break;
    case 2:
        ++((struct Obj01974 *)p)->f28;
        func_021BFBC8(p, ((struct Obj01974 *)p)->f28);
        if (((struct Obj01974 *)p)->f28 == 70) return 1;
        break;
    case 3:
        --((struct Obj01974 *)p)->f28;
        func_021BFBC8(p, ((struct Obj01974 *)p)->f28);
        if (((struct Obj01974 *)p)->f28 == 0) return 1;
        break;
    case 4:
        ++((struct Obj01974 *)p)->f28;
        func_021BFBC8(p, ((struct Obj01974 *)p)->f28);
        if (((struct Obj01974 *)p)->f28 == 120) return 1;
        break;
    }
    return 0;
}


int func_021BFBA0(int *p)
{
    if (p[7] == 3) {
        p[10] = p[10] + 1;
        func_021BFBC8((char *)p, p[10]);
    } else {
        p[10] = p[10] - 1;
        func_021BFBC8((char *)p, p[10]);
    }
    return p[10] == 60;
}

void func_021BFBC8(char *p,unsigned value)
{
    void *ctl;
    int frame;
    float f;
    ctl=(void *)func_02048A18(((struct Obj14629 *)p)->f8,((struct Obj14629 *)p)->f10);
    if(value!=0) f=0.5f+(float)(value<<12);
    else f=(float)(value<<12)-0.5f;
    frame=(int)f;
    func_0204784C(ctl,0,&frame);
    func_0204784C(ctl,1,&frame);
    func_0204784C(ctl,2,&frame);
}

char *func_021BFC24(void *owner,unsigned heap)
{
    Config config;
    char *p;
    func_02050B80(heap);
    p=func_02030734(heap,18444,1,d_021C0B30,86);
    ((struct Obj03923 *)p)->f8=(void *)func_02050C04((int)(p+12),18432,1,heap);
    ((struct Obj03923 *)p)->f4=owner;
    ((struct Obj03923 *)p)->f0=heap;
    config.a=2;
    config.b=16384;
    config.c=-16384;
    config.d=-12288;
    config.e=12288;
    config.f=4096;
    config.g=4194304;
    config.h=4096;
    func_02051758((int)(((struct Obj03923 *)p)->f8));
    func_02051648(((struct Obj03923 *)p)->f8,(struct Src648 *)(&config),8192,d_021C0B18,d_021C0B0C,d_021C0B24,((struct Obj03923 *)p)->f0);
    func_02051230(((struct Obj03923 *)p)->f8,func_0205121C(6,6,((struct Obj03923 *)p)->f0),1,0);
    return p;
}


void func_021BFCD0(char *a)
{
    func_02050ED4();
    func_020307B0(a);
}

void func_021BFCE0(int a0) { func_02050BE8(); }
