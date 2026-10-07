/*
 * file:     btl_rec_sel_p06.c
 * unit:     yes
 * function: func_021BA6F0, func_021BA794, func_021BA8DC, func_021BAAB0, func_021BAB0C, func_021BABA4
 * address:  0x021BA6F0
 * region:   ov214
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021BAD08 0x021BAD08 thumb ov214
 *   func_0201C724  0x0201C724  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045808  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_021BA4E8  0x021BA4E8  thumb  ov214
 *   func_021BB2A8 0x021BB2A8 thumb ov214
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0201BABC 0x0201BABC thumb
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0204B84C 0x0204B84C arm
 *   func_0204B800 0x0204B800 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_021B6208 0x021B6208 thumb ov067
 *   func_021B629C 0x021B629C thumb ov067
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021B6284 0x021B6284 thumb ov067
 *   d_021BB4C4 0x021BB4C4 data a1
 */
#include "../../matched/include/Obj00202.h"
#include "../../matched/include/Obj08422.h"

struct PrintSys;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct S;
struct Node;
struct Obj;
typedef unsigned char u8;

typedef struct {
    unsigned short f00;
    unsigned short pad02;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    char pad1c[0x58 - 0x1c];
    int f58;
    char pad5c[0x94 - 0x5c];
    int f94;
    int f98;
    char pad9c[0xa4 - 0x9c];
    int fA4;
    int fA8;
    char padAC[0xbc - 0xac];
    int fBC;
    unsigned short fC0;
} Ent;

typedef struct {
    int f00;
    int f04;
    int f08;
} Obj;

typedef unsigned int   u32;

typedef unsigned short u16;

struct Cell { u32 a,b,c,d,out0,out1,out2,out3,actor; u8 x,y,flag,order; };

struct S { u16 heap,pad2; u8 *owner; u8 pad8[0xBC]; struct Cell cells[2][6]; u32 spare,mode; };

typedef struct {int f0;u32 f4;int f8,fC,f10,f14,f18;u8 b1c,b1d,b1e;} In;

typedef struct {u8 a,b;} Pair;

extern void func_0201C6EC(struct PrintSys *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned);
extern void func_021BAD08(void*,char*);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201C724(int, int, int, int, int, int, int);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021BA4E8(void *unused, struct S *p);
extern u32 func_021BB2A8(u8 *);
extern int func_0201BC3C(void);
extern u32 func_0201BABC(u32,u32,u32,u32);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern void func_021B6208(void*,In*,int,u16);
extern int func_021B629C(void*,int,u16,u16,u8,u16);
extern void func_0204B84C(int,u32);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B92C(struct Obj *,u32);
extern u32 func_0201BB5C(u32,u32,u32,u32);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B3B4(struct Obj *p);
extern void func_021B6284(unsigned int *p);
void func_021BA6F0(void*obj,char*p);
void func_021BA794(Obj *obj, Ent *e, unsigned int v);
void func_021BA8DC(void *unused,struct S *p);
void func_021BAAB0(int unused, int base);
int func_021BAB0C(int a,u16 b,int c,u8 d,u32 e,u32 f,u32 g,u32 h,void*x,u8 i,u8 j,u8 k,u8 l,u8 m);
void func_021BABA4(void*p,void*actor);
void func_021BABB8(int unused,char*p);
extern const Pair d_021BB4C4[];

void func_021BA6F0(void*obj,char*p)
{
    void*h;
    *(int *)&((struct Obj00202 *)p)->fAC=0;
    *(int *)&((struct Obj00202 *)p)->fB0=0;
    func_0201C6EC((struct PrintSys *)(((struct Obj00202 *)p)->f14));
    func_02043B5C(func_02045770(*(void* *)&((struct Obj00202 *)p)->f94),0);
    h=*(void* *)&((struct Obj00202 *)p)->f94;
    func_02045334(h);func_02045374(h);func_02041B6C(func_02045730(h));
    ((struct Obj00202 *)p)->fA4=1;
    func_0201C6EC((struct PrintSys *)(((struct Obj00202 *)p)->f18));
    func_02043B5C(func_02045770(*(void* *)&((struct Obj00202 *)p)->f98),0);
    h=*(void* *)&((struct Obj00202 *)p)->f98;
    func_02045334(h);func_02045374(h);func_02041B6C(func_02045730(h));
    ((struct Obj00202 *)p)->fA8=1;
    if(((struct Obj00202 *)p)->f3C)func_021BAD08(obj,p);
    ((struct Obj00202 *)p)->fBC=0;
    ((struct Obj00202 *)p)->fC0=0;
}


void func_021BA794(Obj *obj, Ent *e, unsigned int v)
{
    int state;
    int flag;
    int tmp;
    int h;
    int p;
    int x;
    int h2;
    int p2;
    int q;

    if (obj->f08 == 0)
        return;

    if (v > 0xa) {
        flag = 0x440;
        state = 1;
    } else {
        flag = 0xc80;
        state = 2;
    }

    if (state != e->fBC) {
        tmp = (int)func_02045770((struct Descriptor *)e->f94);
        func_02043B5C((struct CharBuf *)tmp, 0);
        tmp = (int)func_02045770((struct Descriptor *)e->f98);
        func_02043B5C((struct CharBuf *)tmp, 0);
    } else if (v != e->fC0) {
        tmp = (int)func_02045770((struct Descriptor *)e->f98);
        func_02043B5C((struct CharBuf *)tmp, 0);
    }

    if (state != e->fBC) {
        func_0201C6EC((struct PrintSys *)e->f14);
        h = (int)func_02045EC0((struct MsgBank *)e->f58, 0x10);
        p = (int)func_02045770((struct Descriptor *)e->f94);
        func_0201C724(e->f14, p, 4, 1, h, e->f08, flag);
        e->fA4 = 0;
        func_02045808((struct U16Vec *)h);
    }

    if (state != e->fBC || v != e->fC0) {
        x = (int)func_0201EC64(e->f00);
        h2 = (int)func_02045EC0((struct MsgBank *)e->f58, 0x12);
        p2 = (int)func_020457B0(8, e->f00);
        func_0201C6EC((struct PrintSys *)e->f18);
        func_0201EFA4((struct WordSet *)x, 1, v, 2, 2, 1);
        func_0201F250((struct WordSet *)x, (void *)p2, (void *)h2);
        q = (int)func_02045770((struct Descriptor *)e->f98);
        func_0201C724(e->f18, q, 2, 2, p2, e->f08, flag);
        e->fA8 = 0;
        func_02045808((struct U16Vec *)p2);
        func_02045808((struct U16Vec *)h2);
        func_0201ED04((struct WordSet *)x);
    }

    e->fBC = state;
    e->fC0 = v;
    func_021BA4E8(obj, (struct S *)e);
}

/*
 * layout: two rows of six 0x28-byte cells, observed nested-loop bounds.
 * prototypes: BAB0C owning matched source; B2A8 own same-region getter.
 * extent: 466-byte function followed by two zero alignment bytes at 021BAAAE.
 * lever: order-byte store inside each branch preserves original address CSE
 * and shared-tail layout; factoring it outside produced 430 bytes / DIFF316.
 */
void func_021BA8DC(void *unused,struct S *p)
{
    int handle=func_021BB2A8(p->owner);
    u8 i,j;
    for(i=0;i<2;i++) for(j=0;j<6;j++) {
        p->cells[i][j].d=0;
        p->cells[i][j].flag=1;
    }
    for(i=0;i<2;i++) for(j=0;j<6;j++) {
        if(p->mode) {
            if(i==0) { *(u8 *)((u32)p+240*i+40*j+0xE8)=100+24*j; *(u8 *)((u32)p+240*i+40*j+0xE9)=64; *(u8 *)((u32)p+240*i+40*j+0xEB)=6-j; }
            else { *(u8 *)((u32)p+240*i+40*j+0xE8)=36+24*j; *(u8 *)((u32)p+240*i+40*j+0xE9)=112; *(u8 *)((u32)p+240*i+40*j+0xEB)=6-j; }
        } else {
            if(i==0) {
                if(j<3) { *(u8 *)((u32)p+240*i+40*j+0xE8)=172+24*j; *(u8 *)((u32)p+240*i+40*j+0xE9)=64; *(u8 *)((u32)p+240*i+40*j+0xEB)=6-j; }
                else { *(u8 *)((u32)p+240*i+40*j+0xE8)=172+24*(j-3); *(u8 *)((u32)p+240*i+40*j+0xE9)=88; *(u8 *)((u32)p+240*i+40*j+0xEB)=6-j; }
            } else {
                if(j<3) { *(u8 *)((u32)p+240*i+40*j+0xE8)=36+24*j; *(u8 *)((u32)p+240*i+40*j+0xE9)=88; *(u8 *)((u32)p+240*i+40*j+0xEB)=6-j; }
                else { *(u8 *)((u32)p+240*i+40*j+0xE8)=36+24*(j-3); *(u8 *)((u32)p+240*i+40*j+0xE9)=112; *(u8 *)((u32)p+240*i+40*j+0xEB)=6-j; }
            }
        }
    }
    for(i=0;i<2;i++) for(j=0;j<6;j++) {
        if(p->cells[i][j].a) {
            p->cells[i][j].actor=func_021BAB0C(handle,p->heap,0,0,
                p->cells[i][j].a,p->cells[i][j].b,p->cells[i][j].c,p->cells[i][j].d,
                &p->cells[i][j].out0,p->cells[i][j].x,p->cells[i][j].y,
                p->cells[i][j].flag,1,p->cells[i][j].order);
        }
    }
}


void func_021BAAB0(int unused, int base)
{
    unsigned char j, i;

    for (j = 0; j < 2; j++) {
        char *p = (char *)base + j * 0xf0;
        char *q = (char *)base + 0xd4 + j * 0xf0;
        for (i = 0; i < 6; i++) {
            if (*(int *)(p + 0xc4 + i * 0x28) != 0) {
                func_021BABA4(q + i * 0x28, (void *)(*(int *)(p + 0xe4 + i * 0x28)));
            }
        }
    }
}

int func_021BAB0C(int a,u16 b,int c,u8 d,u32 e,u32 f,u32 g,u32 h,void*x,u8 i,u8 j,u8 k,u8 l,u8 m)
{
    In in;
    int actor;
    in.f0=c;
    in.f4=1;
    in.f8=7;
    in.fC=func_0201BC3C();
    in.f10=func_0201BABC(e,f,g,h);
    in.f14=func_0201BC40();
    in.f18=func_0201BCB4();
    in.b1c=d;
    in.b1d=0;
    in.b1e=3;
    func_021B6208(x,&in,a,b);
    actor=func_021B629C(x,a,i,j,k,b);
    func_0204B84C(actor,l);
    func_0204B800((struct Node *)actor,m);
    func_0204B92C((struct Obj *)actor,1);
    func_0204B6F4((struct Obj *)actor,func_0201BB5C(e,f,g,h),0);
    return actor;
}

/*
 * function_starts: 0x021BABB8
 * note: Cleared BABB8 follower occupies 60 bytes through BABF4. The pools
 * at BABEC/BABF0 point to the two fields of the same byte-pair table.
 */
void func_021BABA4(void*p,void*actor)
{
    func_0204B3B4(actor);
    func_021B6284(p);
}

void func_021BABB8(int unused,char*p)
{
    u8 i=((struct Obj08422 *)p)->f2B0;
    if(i>=0x29)i=0;
    ((struct Obj08422 *)p)->f2A4=d_021BB4C4[i].a;
    if(d_021BB4C4[i].b==0)((struct Obj08422 *)p)->f2A8=1;
    else ((struct Obj08422 *)p)->f2A8=0;
}
