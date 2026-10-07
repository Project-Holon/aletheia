/*
 * file:     unit_021E5680_p04.c
 * unit:     yes
 * function: func_021E6308, func_021E6334, func_021E6440, func_021E64B8, func_021E64DC, func_021E6544, func_021E665C, func_021E66E8, func_021E6700, func_021E6718
 * address:  0x021E6308
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_02049238 0x02049238 arm
 *   func_021E62D4 0x021E62D4 thumb ov119
 *   d_021E7D70 0x021E7D70 data a4
 *   d_021E7DA0 0x021E7DA0 data a4
 *   func_0204B404 0x0204B404 arm
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B454 0x0204B454 arm
 *   func_0207C7B4 0x0207C7B4 arm
 *   _ll_mul 0x0209C054 arm
 *   func_021E7248 0x021E7248 thumb ov119
 *   func_021E729C 0x021E729C thumb ov119
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0207D63C 0x0207D63C arm
 */
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj05335.h"
#include "../../matched/include/Obj05336.h"
#include "../../matched/include/Obj10383.h"
#include "../../matched/include/Obj06430.h"

struct Obj;
struct Vec2;
struct Actor;
struct PtS;
struct Curve;
typedef struct {
    char pad[0x1008];
    int h[2][3];
} Work;

typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { short x,y,z; u8 a,b; } Create;

typedef signed int     s32;

typedef struct { short x,y; } Pt;

typedef signed long long s64;

typedef struct { int x,y,z; } T;

typedef struct { T a,b,c,d,e; int i,n; } S;

extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void *func_020185F0(void *);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_021E62D4(void *,int,int);
extern u32 func_0201BA68(void *);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern int func_0201BBE8(void *);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_02049238(int);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern int func_0207C7B4(int);
extern void func_021E7248(S *,T *,T *,T *,T *,int);
extern int func_021E729C(struct Curve *c);
extern void func_0204B3B4(struct Obj *p);
extern void func_0207D63C(int, int, int, int, int);
void func_021E6308(Work *p, int a, int v);
void func_021E6334(char *p,int i,int j,void *mon,int selected,u32 visible);
void func_021E6440(int p, int a, int b);
void func_021E64B8(void *p);
void func_021E64DC(int p, int i, int j, int x, int y, void *q);
void func_021E6544(char *p);
int func_021E665C(char *p);
void func_021E66E8(void *p);
void func_021E6700(void *p);
void func_021E6718(char *p, int i);
extern const int d_021E7D70[6][2];
extern const int d_021E7DA0[6][2];


void func_021E6308(Work *p, int a, int v)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (p->h[a][i])
            func_0204B3DC((struct Obj *)p->h[a][i], v);
    }
}

/*
 * initialization: both coordinate arms initialize x/y; z/a/b are stored before creation.
 * domain: primary calls 021D9084, 021DD670 and 021E25FA prove i=0..1,j=0..2. Wrappers 021D90AC/C0/D4 supply j=0/1/2; 021DD428 returns -1 or 0..2 and caller rejects -1; 021E24E8 has bounded 2x3 loops. Table row i*3+j=0..5 and byte offset i*12+j*4=0..20.
 * interface: 0204B294's fifth full-word payload is a Create address; its body forwards unchanged to 0204CFDC's request pointer. r0 is consumed after that void-declared wrapper.
 * interface: 020185F0 is an empty forwarder; caller supplies r0 and consumes its unchanged pointer result at 021E6346.
 */
void func_021E6334(char *p,int i,int j,void *mon,int selected,u32 visible)
{
    Create c;
    void *q = func_020185F0(mon);
    void *h = func_020490F4(7,((struct Obj00001 *)p)->f5F4);
    int n;
    func_021E62D4(p,i,j);
    if (selected) {
        c.x=d_021E7D70[i*3+j][0]; c.y=d_021E7D70[i*3+j][1]; n=0;
    } else {
        c.x=d_021E7DA0[i*3+j][0]; c.y=d_021E7DA0[i*3+j][1]; n=1;
    }
    c.z=1; c.a=16; c.b=1;
    *(int *)(p+0x1020+i*12+j*4) = func_0204A6C8((void *)((u32)h),func_0201BA68(q),0,n,((struct Obj00001 *)p)->f5F4);
    *(int *)(p+0x1008+i*12+j*4) = (int)func_0204B294((void *)((struct Obj00001 *)p)->f9C4,*(int *)(p+0x1020+i*12+j*4),*(int *)&((struct Obj00001 *)p)->f890,*(int *)&((struct Obj00001 *)p)->f8C0,&c,n,((struct Obj00001 *)p)->f5F4);
    func_0204B6F4((struct Obj *)(*(int *)(p+0x1008+i*12+j*4)),func_0201BBE8(q),1);
    func_0204B92C((struct Obj *)*(int *)(p+0x1008+i*12+j*4),0);
    func_0204B3DC((struct Obj *)*(int *)(p+0x1008+i*12+j*4),visible);
    func_02049238((int)h);
}

void func_021E6440(int p, int a, int b) {
    int i,j;
    Pt pos;
    for (i=0;i<2;i++) {
        for (j=0;j<3;j++) {
            if (*(int *)(p+i*12+j*4+0x1008)) {
                pos.x=d_021E7DA0[i*3+j][0]; pos.y=d_021E7DA0[i*3+j][1];
                if (i==a && j==b) pos.y-=4;
                func_0204B404((struct Obj *)(*(int *)(p+i*12+j*4+0x1008)),(const struct Vec2 *)(&pos),1);
            }
        }
    }
}


void func_021E64B8(void *p)
{
    int j, i;

    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            func_021E62D4(p, i, j);
}

void func_021E64DC(int p, int i, int j, int x, int y, void *q) {
    Create c;
    c.x=x; c.y=y; c.z=1; c.a=0; c.b=0;
    ((struct Obj05335 *)p)->fF20=(int)func_0204B294((void *)((struct Obj05335 *)p)->f9C4,*(int *)(p+i*20+j*4+0x9cc),((struct Obj05335 *)p)->f87C,((struct Obj05335 *)p)->f8AC,&c,1,((struct Obj05335 *)p)->f5F4);
    func_0204B6F4((struct Obj *)(((struct Obj05335 *)p)->fF20),func_0201BBE8(q),1);
}

static inline int mul(int a,int b) { return (int)(((s64)a*b+0x800LL)>>12); }

/*
 * initialization: 0204B454 writes both signed coordinates; all four vector arguments are fully assigned before 021E7248 reads each three-word object.
 * arithmetic: coordinate products fit signed32 for every signed-short input; fixed-point scalar sums use modulo32 ADD. Signed32 products plus 0x800 fit signed64 for every possible input.
 */
void func_021E6544(char *p)
{
    T end,third,second,first;
    Pt pos;
    int x,y,dx,dy,speed;
    func_0204B454((struct Actor *)((struct Obj05336 *)p)->fF20,(struct PtS *)&pos,1);
    dx=(pos.x-((struct Obj05336 *)p)->fF6C)*4096;
    dy=(pos.y-((struct Obj05336 *)p)->fF6E)*4096;
    first.x=pos.x*4096; first.y=pos.y*4096; first.z=0;
    second.x=(pos.x*2-((struct Obj05336 *)p)->fF6C)*4096;
    second.y=(pos.y*2-((struct Obj05336 *)p)->fF6E)*4096; second.z=0;
    end.x=28*4096; end.y=0; end.z=0;
    x=first.x-end.x; y=first.y/2;
    speed=func_0207C7B4((int)((u32)mul(x,x)+(u32)mul(y,y)))/15;
    third.x=(int)((u32)x+(u32)mul(dx,speed)); third.y=(int)((u32)y+(u32)mul(dy,speed)); third.z=0;
    func_021E7248((S *)(p+0x1190),&first,&second,&third,&end,19);
    ((struct Obj05336 *)p)->f11DC=21;
}

int func_021E665C(char *p) {
    Pt pos;
    if (((struct Obj00001 *)p)->f11DC) {
        --((struct Obj00001 *)p)->f11DC;
        if (!((struct Obj00001 *)p)->f11DC) return 1;
        func_0204B454((struct Actor *)((struct Obj00001 *)p)->fF20,(struct PtS *)&pos,1);
        if (pos.y<0) ((struct Obj00001 *)p)->f11DC=1;
        if (((struct Obj00001 *)p)->f11DC==1) func_021E66E8(p);
        else {
            func_021E729C((struct Curve *)(p+0x1190));
            pos.x=((struct Obj00001 *)p)->f1190/4096;
            pos.y=((struct Obj00001 *)p)->f1194/4096;
            func_0204B404((struct Obj *)(((struct Obj00001 *)p)->fF20),(const struct Vec2 *)(&pos),1);
        }
    }
    return 0;
}


void func_021E66E8(void *p)
{
    if (((struct Obj10383 *)p)->fF20) {
        func_0204B3B4((struct Obj *)(((struct Obj10383 *)p)->fF20));
        ((struct Obj10383 *)p)->fF20 = 0;
    }
}


void func_021E6700(void *p)
{
    func_0207D63C(0x04001050, 0, 15, 8, 8);
}

void func_021E6718(char *p, int i) {
    Create c;
    if (!*(int *)(p+0x10bc+i*4)) {
        c.x=i*24+8; c.y=144; c.z=i+11; c.a=50; c.b=1;
        *(int *)(p+0x10bc+i*4)=(int)func_0204B294((void *)((struct Obj06430 *)p)->f9C4,((struct Obj06430 *)p)->f894,((struct Obj06430 *)p)->f880,((struct Obj06430 *)p)->f8B0,&c,1,((struct Obj06430 *)p)->f5F4);
    }
    func_0204B92C((struct Obj *)*(int *)(p+0x10bc+i*4),1);
    func_0204B3DC((struct Obj *)*(int *)(p+0x10bc+i*4),1);
}
