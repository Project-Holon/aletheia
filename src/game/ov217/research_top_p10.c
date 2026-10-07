/*
 * file:     research_top_p10.c
 * unit:     yes
 * function: func_021BBF04, func_021BBF1C, func_021BBF28, func_021BBF3C, func_021BBF4C, func_021BBF60, func_021BC014, func_021BC06C, func_021BC07C, func_021BC0E8, func_021BC128, func_021BC168, func_021BC1AC, func_021BC200, func_021BC250, func_021BC264, func_021BC274, func_021BC280, func_021BC2B8, func_021BC2CC, func_021BC2D8, func_021BC2FC, func_021BC30C, func_021BC330, func_021BC338, func_021BC380, func_021BC3AC, func_021BC3B8, func_021BC3D4, func_021BC3E0, func_021BC3EC, func_021BC3F8, func_021BC400, func_021BC40C, func_021BC41C, func_021BC428, func_021BC43C, func_021BC480, func_021BC490, func_021BC4A0, func_021BC4B4, func_021BC50C, func_021BC55C, func_021BC574, func_021BC580, func_021BC5A8, func_021BC5B8, func_021BC5D4, func_021BC5F0, func_021BC5FC, func_021BC600, func_021BC608, func_021BC610, func_021BC628, func_021BC634, func_021BC638, func_021BC63C, func_021BC640
 * address:  0x021BBF04
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BBC50  0x021BBC50  thumb  ov217
 *   func_02041648  0x02041648  arm
 *   func_021BC720 0x021BC720 thumb ov217
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021C0F5C 0x021C0F5C thumb ov217
 *   d_021C309E 0x021C309E data a1
 *   d_021C3094 0x021C3094 data a1
 *   d_021C30D0 0x021C30D0 data a1
 *   d_021C30A8 0x021C30A8 data a1
 *   d_021C3080 0x021C3080 data a1
 *   d_021C308A 0x021C308A data a1
 *   func_021C0FF8  0x021C0FF8  thumb  ov217
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _ffix 0x0209C494 arm
 *   _dflt 0x0209B750 arm
 *   _dmul 0x0209B2E8 arm
 *   _dfix 0x0209C508 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_02040804  0x02040804  arm
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_021BC6DC  0x021BC6DC  thumb  ov217
 *   func_02021ED8  0x02021ED8  thumb
 *   func_021C09D8 0x021C09D8 thumb ov217
 *   func_021C29F8 0x021C29F8 thumb ov217
 *   d_021C326C 0x021C326C data a4
 *   d_021C3270 0x021C3270 data a4
 *   func_021C2A00  0x021C2A00  thumb  ov217
 *   func_021C2A10  0x021C2A10  thumb  ov217
 *   func_021C29F0  0x021C29F0  thumb  ov217
 *   func_021C09D0  0x021C09D0  thumb  ov217
 *   func_021C09B4  0x021C09B4  thumb  ov217
 */
#include "../../matched/include/Obj05558.h"
#include "../../matched/include/Obj00025.h"
#include "../../matched/include/Obj00801.h"
#include "../../matched/include/Obj25855.h"
#include "../../matched/include/Obj01084.h"
#include "../../matched/include/Obj14732.h"
#include "../../matched/include/Obj25856.h"
#include "../../matched/include/Obj25858.h"
#include "../../matched/include/Obj25861.h"
#include "../../matched/include/Obj25862.h"
#include "../../matched/include/Obj25864.h"
#include "../../matched/include/Obj25865.h"
#include "../../matched/include/Obj25866.h"
#include "../../matched/include/Obj25867.h"
#include "../../matched/include/Obj25868.h"
#include "../../matched/include/Obj25869.h"
#include "../../matched/include/Obj25870.h"

struct Obj;
struct Vec2;
struct S02021D50;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef enum { PLANE_NONE=0,PLANE_OUT=31,PLANE_IN=19 } Plane;

typedef enum { FALSE=0,TRUE=1 } Bool;

struct Vec2 { s16 x,y; };

typedef enum { ZERO = 0 } Origin;

struct S_021BC280 { char pad[0x4c]; int f4c; };

struct S_021BC2D8 { char pad[0x34]; int f34; int f38; int f3c; int f40; int f44; int f48; };

struct S_021BC30C { char pad[0x34]; int f34; int f38; };

struct S_021BC380 { char pad[0x34]; int f34; };

typedef struct PalAnmObj PalAnmObj;

struct Ent { unsigned int a; unsigned short b; unsigned short pad; unsigned int c[3]; };

extern u8 func_021BBC50(u8 *p);
extern u32 func_02041648(u8 channel);
extern u32 func_021BC720(void *p,u32 index);
extern void func_0204B3DC(struct Obj *p,u32 value);
extern void func_0204B404(struct Obj *p,const struct Vec2 *delta,u32 which);
extern void func_0204B92C(struct Obj *p,u32 value);
extern u32 func_021C0F5C(u32 object,u32 value);
extern u32 func_021C0FF8();
extern int _s32_div_f(int, int);
extern void func_02041EE4(unsigned layer,unsigned mode,unsigned value);
extern u32 func_02040804(u32 layer);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0209C0A4(u32, u32);
extern unsigned int func_021BC6DC(void *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern int func_0202173C(PalAnmObj *, u16, u16, s16, u8, u8, u16, void *);
extern u32 func_02021ED8(const char *ptr);
extern void func_021C09D8(u8 *p, u32 i);
extern void func_021C29F8(u8 *p, u32 b, u16 c);
extern void func_021C2A00(u32 a0);
extern u32 func_021C2A10();
extern void func_021C29F0(int);
extern void func_021C09D0(u32);
extern void func_02021D50(struct S02021D50 *p);
extern void func_020419E4();
extern void func_0204A648();
extern u32 func_021C09B4(void *p);
u32 func_021BBF04(u32 a0, u32 a1);
u32 func_021BBF1C(u32 unused, u32 v);
int func_021BBF28(unsigned char *p, unsigned int slot);
int func_021BBF3C(unsigned char *p, unsigned char index);
int func_021BBF4C(unsigned char *p, unsigned int index);
void func_021BBF60(u8 *p);
void func_021BC014(u8 *p);
int func_021BC06C(char *p);
int func_021BC07C(u8 *p, u8 index);
u32 func_021BC0E8(u32 a0);
u32 func_021BC128(u32 a0);
void func_021BC168(u32 a0);
int func_021BC1AC(void *p);
int func_021BC200(void *p,int position);
void func_021BC250(void *p);
int func_021BC264(void *p);
void func_021BC274(void *p);
void func_021BC280(struct S_021BC280 *p);
void func_021BC2B8(void *p);
void func_021BC2CC(void *p, u32 a, u32 b, u32 c);
void func_021BC2D8(struct S_021BC2D8 *p);
int func_021BC2FC(void *p);
void func_021BC30C(struct S_021BC30C *p, int v);
void func_021BC330(void *p, u32 v);
void func_021BC338(u8 *p);
void func_021BC380(struct S_021BC380 *p);
int func_021BC3AC(void);
void func_021BC3B8(u32 a0);
u32 func_021BC3D4(void);
u32 func_021BC3E0(void);
void func_021BC3EC(u32 a0);
u32 func_021BC3F8(u32 v);
u32 func_021BC400(u32 v);
int func_021BC40C(void *p);
u32 func_021BC41C(void *p);
int func_021BC428(void *p);
void func_021BC43C(u8 *p);
void func_021BC480(void);
void func_021BC490(void);
int func_021BC4A0(void);
void func_021BC4B4(char *p);
void func_021BC50C(char *p);
u32 func_021BC55C(u32 a0);
void func_021BC574(u8 **p, u32 i);
void func_021BC580(char *p, int i);
void func_021BC5A8(u8 *a0, int a1);
u32 func_021BC5B8(u32 a0, u32 a1);
void func_021BC5D4(int *p);
void func_021BC5F0(u8 *a0);
u32 func_021BC5FC(void *p);
void func_021BC600(void *p);
void func_021BC608(void *p);
void func_021BC610(u32 a0, u32 a1);
u32 func_021BC628(u8 *a0);
void func_021BC634(void *p, u16 v);
void func_021BC638(void *p, u32 v);
u32 func_021BC63C(void *p);
void func_021BC640(void *p, u32 v);
extern const u8 d_021C309E[],d_021C3094[],d_021C30D0[],d_021C30A8[],d_021C3080[],d_021C308A[];
extern const struct Ent d_021C326C[];

/*
 * Returns 2, or 1 when func_021BBC50() reports the caller's own a1.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BBF04(u32 a0, u32 a1)
{
    u8 v = 2;
    if (a1 == func_021BBC50((u8 *)a0)) {
    v -= 1;
    }
    return v;
}


u32 func_021BBF1C(u32 unused, u32 v)
{
    return (u8)(v * 3);
}


int func_021BBF28(unsigned char *p, unsigned int slot)
{
    int t = func_021BBF04((unsigned int)p, slot) << 3;
    return t - func_02041648(2);
}


/*
 * Addresses are Black-image addresses.
 */
int func_021BBF3C(unsigned char *p, unsigned char index)
{
    int t = func_021BBF1C((unsigned int)p, index) << 3;
    return t - func_021BC3AC();
}


int func_021BBF4C(unsigned char *p, unsigned int index)
{
    int t = (func_021BBF1C((unsigned int)p, index) << 3) + 0x17;
    return t - func_021BC3AC();
}

static inline void outside(Plane wnd,Bool effect)
{
    u32 tmp;
    tmp=(*(volatile u16 *)0x0400004A & ~63u) | (u32)wnd;
    if(effect)tmp|=32;
    *(volatile u16 *)0x0400004A=(u16)tmp;
}

static inline void inside(Plane wnd,Bool effect)
{
    u32 tmp;
    tmp=(*(volatile u16 *)0x04000048 & ~63u) | (u32)wnd;
    if(effect)tmp|=32;
    *(volatile u16 *)0x04000048=(u16)tmp;
}

void func_021BBF60(u8 *p)
{
    int active;
    int top,bottom;
    int x1,x2,y1,y2;
    active=0;
    top=func_021BBF3C(p,0);
    bottom=func_021BBF4C(p,9);
    if(top>0) {
        active=1;x1=0;x2=240;y1=0;y2=top-1;
    } else if(bottom<192) {
        active=1;x1=0;x2=240;y1=bottom+1;y2=192;
    }
    if(active) {
        *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000 & 0xFFFF1FFF)|0x2000;
        *(volatile u16 *)0x04000040=(u16)(((x1<<8)&0xFF00)|(x2&0xFF));
        *(volatile u16 *)0x04000044=(u16)(((y1<<8)&0xFF00)|(y2&0xFF));
        outside(PLANE_OUT,TRUE);
        inside(PLANE_IN,TRUE);
    } else {
        *(volatile u32 *)0x04000000=*(volatile u32 *)0x04000000 & 0xFFFF1FFF;
    }
}

/*
 * arity: BF28/BF3C forward entry r0/r1 to BF04/BF1C; preserve both, with observed u8 argument truncation.
 */
void func_021BC014(u8 *p)
{
    struct Vec2 point;
    u32 index;
    struct Obj *obj;
    index=func_021BBC50(p);
    obj=(struct Obj *)func_021BC720(p,2);
    if(index==255) {
        func_0204B3DC(obj,0);
        return;
    }
    point.x=func_021BBF28(p,(u8)index);
    point.y=func_021BBF3C(p,index)+10;
    func_0204B404(obj,&point,0);
    func_0204B92C(obj,1);
    func_0204B3DC(obj,1);
}


int func_021BC06C(char *p)
{
    return func_021BC07C((u8 *)p, ((struct Obj05558 *)p)->f32);
}

/*
 * arity: original visibly supplies r1 to C0F5C; preserve second argument omitted by legacy source.
 */
int func_021BC07C(u8 *p, u8 index)
{
    func_021C0F5C(((struct Obj05558 *)p)->fE4,d_021C309E[index]);
    func_021C0F5C(((struct Obj05558 *)p)->fE8,d_021C3094[index]);
    func_021C0F5C(((struct Obj05558 *)p)->fEC,d_021C30D0[d_021C30A8[index]]);
    func_021C0F5C(((struct Obj05558 *)p)->fF0,d_021C30D0[d_021C3080[index]]);
    return func_021C0F5C(((struct Obj05558 *)p)->fF4,d_021C30D0[d_021C308A[index]]);
}

u32 func_021BC0E8(u32 a0)
{
    func_021C0FF8(((struct Obj00025 *)((u8*)a0))->fE4, 0);
    func_021C0FF8(((struct Obj00025 *)((u8*)a0))->fE8, 0);
    func_021C0FF8(((struct Obj00025 *)((u8*)a0))->fEC, 0);
    func_021C0FF8(((struct Obj00025 *)((u8*)a0))->fF0, 0);
    return func_021C0FF8(((struct Obj00025 *)((u8*)a0))->fF4, 0);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC128(u32 a0)
{
    func_021C0FF8(((struct Obj00025 *)((u8*)a0))->fE4, 1);
    func_021C0FF8(((struct Obj00025 *)((u8*)a0))->fE8, 1);
    func_021C0FF8(((struct Obj00025 *)((u8*)a0))->fEC, 1);
    func_021C0FF8(((struct Obj00025 *)((u8*)a0))->fF0, 1);
    return func_021C0FF8(((struct Obj00025 *)((u8*)a0))->fF4, 1);
}

/*
 * Packs a 0xF8 message (second halfword from func_021BC1AC()) and pushes
 * it through the +0x0c channel, on the path where func_021BC428() is clear.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC168(u32 a0)
{
    u8 s[4];
    u32 v1 = func_021BC720((void *)a0, 0);
    if (func_021BC428((void *)a0) == 0) {
    func_0204B3DC((struct Obj *)v1, 0);
    return;
    }
    ((struct Obj00801 *)((u8*)s))->f0 = 248;
    *(u16 *)&((struct Obj00801 *)(((u8*)s)))->f2 = func_021BC1AC((void *)a0);
    func_0204B404((struct Obj *)v1, (const struct Vec2 *)s, 0);
    func_0204B3DC((struct Obj *)v1, 1);
}

/*
 * 021BC40C forwards live r0 to 021BC6DC's +0x30 getter despite legacy void prototype.
 */
int func_021BC1AC(void *p)
{
    int scroll;
    int height;
    float top;
    float span;
    int result;
    scroll=func_021BC3AC();
    height=func_021BC40C(p);
    scroll+=24;
    height+=24;
    top=(float)scroll;
    span=(float)height;
    result=(int)(32.0f+128.0f*(top/span));
    if(result<32)result=32;
    if(result>160)result=160;
    return result;
}

int func_021BC200(void *p,int position)
{
    float ratio;
    int height;
    float zero;
    Origin origin;
    if(position<32)position=32;
    if(position>160)position=160;
    ratio=(float)(position-32)/128.0f;
    height=func_021BC40C(p)+24;
    origin=ZERO;
    zero=(float)origin;
    return (int)(zero+ratio*(float)height);
}


/*
 * Accumulate +0x50 into +0x4c, zeroing the total when the product is not positive.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC250(void *p)
{
    s32 a = *(u32 *)&((struct Obj00025 *)p)->f4C;
    s32 b = ((struct Obj00025 *)p)->f50;
    s32 t = a + b;
    if (a * t <= 0) {
        t = 0;
    }
    *(u32 *)&((struct Obj00025 *)p)->f4C = t;
}


/*
 * Flag test: nonzero u32 at +0x4c as 1/0.
 *
 * Addresses are Black-image addresses.
 */
int func_021BC264(void *p)
{
    if (((struct Obj25855 *)p)->f4C != 0) {
        return 1;
    }
    return 0;
}


void func_021BC274(void *p)
{
    int a = *(u32 *)&((struct Obj00025 *)p)->f34;
    int b = ((struct Obj00025 *)p)->f38;
    *(u32 *)&((struct Obj00025 *)p)->f4C = a - b;
}


void func_021BC280(struct S_021BC280 *p)
{
    double d = p->f4c;
    int v;
    d *= 1.5;
    v = d;
    p->f4c = v;
    if (v > 9) {
        p->f4c = 9;
    } else if (v < -9) {
        p->f4c = -9;
    }
}


void func_021BC2B8(void *p)
{
    if (((struct Obj00025 *)p)->f4C < 0) {
        ((struct Obj00025 *)p)->f50 = 1;
    } else {
        ((struct Obj00025 *)p)->f50 = -1;
    }
}


void func_021BC2CC(void *p, u32 a, u32 b, u32 c)
{
    ((struct Obj01084 *)p)->f3C = a;
    ((struct Obj01084 *)p)->f40 = b;
    *(u32 *)&((struct Obj01084 *)p)->f44 = c;
    *(u32 *)&((struct Obj01084 *)p)->f48 = 0;
}


void func_021BC2D8(struct S_021BC2D8 *p)
{
    int base = p->f3c;
    int n = p->f48 + 1;
    p->f48 = n;
    func_021BC330(p, base + (p->f40 - base) * n / p->f44);
}


int func_021BC2FC(void *p)
{
    if (((struct Obj01084 *)p)->f44 > ((struct Obj01084 *)p)->f48) {
        return 0;
    }
    return 1;
}


void func_021BC30C(struct S_021BC30C *p, int v)
{
    if (v < 0) {
        v = 0;
    }
    if ((int)func_021BC41C(p) < v) {
        v = (int)func_021BC41C(p);
    }
    p->f38 = p->f34;
    p->f34 = v;
}


void func_021BC330(void *p, u32 v)
{
    ((struct Obj14732 *)p)->f38 = v;
    ((struct Obj14732 *)p)->f34 = v;
}

void func_021BC338(u8 *p)
{
    int position;
    int low;
    int high;
    position=((struct Obj25856 *)p)->f34;
    low=func_021BC3D4();
    high=func_021BC3E0();
    if(position<low) {
        position-=24;
        func_02041EE4(2,3,position);
        func_02041EE4(3,3,position);
    } else if(high<position) {
        position-=168;
        func_02041EE4(2,3,position);
        func_02041EE4(3,3,position);
    }
}


void func_021BC380(struct S_021BC380 *p)
{
    int v = p->f34 - 24;
    if (v < -24) {
        v = -24;
    }
    if (func_021BC40C(p) < v) {
        v = func_021BC40C(p);
    }
    func_021BC3B8(v);
}


int func_021BC3AC(void)
{
    return func_02040804(2);
}

void func_021BC3B8(u32 a0)
{
    func_02040618(2, 3, a0);
    func_02040618(3, 3, a0);
}

u32 func_021BC3D4(void)
{
    return func_021BC3AC() + 24;
}

/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC3E0(void)
{
    return func_021BC3AC() + 168;
}


/*
 * Tail-call veneer: forwards arg(s) a0, 24 to func_0209C0A4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC3EC(u32 a0)
{
    func_0209C0A4(a0, 24);
}


/*
 * Twenty-four times the argument.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC3F8(u32 v)
{
    return v * 24;
}

u32 func_021BC400(u32 v)
{
    return func_021BC3F8(v) + 23;
}


int func_021BC40C(void *p)
{
    return (int)func_021BC6DC(p) * 0x18 - 0xa8;
}

u32 func_021BC41C(void *p)
{
    return func_021BC40C(p) + 168;
}


int func_021BC428(void *p)
{
    return (int)func_021BC6DC(p) * 0x18 > 0x90;
}

void func_021BC43C(u8 *p)
{
    int i;
    int x;
    int y;
    for(i=0;i<=9;i++) {
        x=func_021BBF28(p,(u8)i);
        y=func_021BBF3C(p,i);
        p[i*4+0x66]=x;
        p[i*4+0x67]=x+0xd8;
        p[i*4+0x64]=y;
        p[i*4+0x65]=y+0x18;
    }
}

void func_021BC480(void)
{
    func_0204E720(3, 16, 0, 0);
}

void func_021BC490(void)
{
    func_0204E720(3, 0, 16, 0);
}

/*
 * Returns 1 when ARM func_0204E804() is 0.
 *
 * Addresses are Black-image addresses.
 */
int func_021BC4A0(void)
{
    return func_0204E804() == 0;
}

void func_021BC4B4(char *p)
{
    func_0202173C(*(PalAnmObj * *)&((struct Obj00025 *)p)->f98, 1, 0xBBFF, 2, 0, 10, 0, ((struct Obj00025 *)p)->f150);
    func_0202173C(*(PalAnmObj * *)&((struct Obj00025 *)p)->f98, 4, 0xCF, 2, 0, 10, 0, ((struct Obj00025 *)p)->f150);
    ((struct Obj00025 *)p)->f15C = 1;
}

void func_021BC50C(char *p)
{
    func_0202173C(*(PalAnmObj * *)&((struct Obj00025 *)p)->f98, 1, 0xBBFF, 2, 10, 0, 0, ((struct Obj00025 *)p)->f150);
    func_0202173C(*(PalAnmObj * *)&((struct Obj00025 *)p)->f98, 4, 0xCF, 2, 10, 0, 0, ((struct Obj00025 *)p)->f150);
    ((struct Obj00025 *)p)->f15C = 0;
}

u32 func_021BC55C(u32 a0)
{
    if (func_02021ED8((const char *)(((struct Obj25858 *)((u8*)a0))->f98)) == 0) {
    return 1;
    }
    return 0;
}


void func_021BC574(u8 **p, u32 i)
{
    func_021C09D8(*p, i);
}


void func_021BC580(char *p, int i)
{
    func_021C29F8((u8 *)(*(int *)(p + 0x9c + i * 4)), d_021C326C[i].a, d_021C326C[i].b);
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 156)), (a1)*4 to func_021C2A00.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC5A8(u8 *a0, int a1)
{
    func_021C2A00((u32)(*(u32*)(a0 + (a1)*4 + 156)));
}

/*
 * Reports whether the a1-th entry of the +0x9c handle array is still
 * active.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC5B8(u32 a0, u32 a1)
{
    if (func_021C2A10(*(u32*)(((u8*)a0 + ((u32)a1 << 2) + 156))) == 0) {
    return 1;
    }
    return 0;
}


void func_021BC5D4(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        func_021C29F0(p[i + 0x27]);
}


void func_021BC5F0(u8 *a0)
{
    func_021C09D0((u32)(((struct Obj25861 *)a0)->f0));
}


u32 func_021BC5FC(void *p)
{
    return ((struct Obj25862 *)p)->f54;
}


/*
 * Increment the u32 at +0x54.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC600(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x54);
    *c += 1;
}


/*
 * Clear the u32 at +0x54.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC608(void *p)
{
    ((struct Obj25864 *)p)->f54 = 0;
}

void func_021BC610(u32 a0, u32 a1)
{
    func_020419E4();
    func_0204A648();
    func_02021D50((struct S02021D50 *)(((struct Obj25865 *)((u8*)a1 + 0))->f98));
}


u32 func_021BC628(u8 *a0)
{
    return func_021C09B4((void *)((u32)(((struct Obj25866 *)a0)->f0)));
}


/*
 * Field setter, u16 at +8.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC634(void *p, u16 v)
{
    ((struct Obj25867 *)p)->f8 = v;
}


/*
 * Field setter, u32 at +0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC638(void *p, u32 v)
{
    ((struct Obj25868 *)p)->f0 = v;
}


u32 func_021BC63C(void *p)
{
    return ((struct Obj25869 *)p)->f0;
}


/*
 * Field setter, u32 at +4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC640(void *p, u32 v)
{
    ((struct Obj25870 *)p)->f4 = v;
}
