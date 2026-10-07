/*
 * file:     local_tvt_sys_p02.c
 * unit:     yes
 * function: func_021B6A90, func_021B6AF8, func_021B6B5C, func_021B6BC4, func_021B6C2C, func_021B6C5C, func_021B6C70, func_021B6D00, func_021B6D3C, func_021B6F2C, func_021B6F3C, func_021B7004, func_021B7180, func_021B71A0, func_021B71B8, func_021B7350, func_021B7360, func_021B7364
 * address:  0x021B6A90
 * region:   ov174
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021B7398  0x021B7398  data  a4
 *   func_021B6704 0x021B6704 thumb ov174
 *   func_021B68F8 0x021B68F8 thumb ov174
 *   func_021B6A04 0x021B6A04 thumb ov174
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_02012944 0x02012944 thumb
 *   func_021B68E8 0x021B68E8 thumb ov174
 *   func_021B6754 0x021B6754 thumb ov174
 *   func_021B6994 0x021B6994 thumb ov174
 *   func_021B7378 0x021B7378 thumb ov174
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02030734 0x02030734 arm
 *   func_020124F4 0x020124F4 thumb
 *   func_0203630C 0x0203630C arm
 *   func_021B6100 0x021B6100 thumb ov174
 *   d_021B74AC 0x021B74AC data
 *   func_021B61C4 0x021B61C4 thumb ov174
 *   func_02012704 0x02012704 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_021B622C  0x021B622C  thumb  ov174
 *   func_02005728 0x02005728 thumb
 *   func_02008550 0x02008550 thumb
 *   d_021B74BC 0x021B74BC data
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02045334 0x02045334 arm
 *   func_020056EC 0x020056EC thumb
 *   func_0204B95C 0x0204B95C arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B918 0x0204B918 arm
 *   func_0204B974 0x0204B974 arm
 *   d_021B7485 0x021B7485 data a1
 *   d_021B7481 0x021B7481 data a1
 *   func_02049BDC 0x02049BDC arm
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   d_021B7484 0x021B7484 data a1
 *   d_021B7480 0x021B7480 data a1
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_02049DF4 0x02049DF4 arm
 *   func_02082A90  0x02082A90  arm
 *   d_021B7380 0x021B7380 data ov174 a1
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C724 0x0201C724 thumb
 */
#include "../../matched/include/Obj08268.h"
#include "../../matched/include/Obj24202.h"
#include "../../matched/include/Obj24203.h"
#include "../../matched/include/Obj01167.h"
#include "../../matched/include/Obj10673.h"
#include "../../matched/include/Obj00681.h"
#include "../../matched/include/Obj24204.h"
#include "../../matched/include/Obj01422.h"
#include "../../matched/include/Obj01759.h"
#include "../../matched/include/Obj24205.h"
#include "../../matched/include/Obj03860.h"
#include "../../matched/include/Obj00152.h"
#include "../../matched/include/Obj00185.h"
#include "../../matched/include/Obj24206.h"
#include "../../matched/include/Obj24207.h"
#include "../../matched/include/Obj05453.h"
#include "../../matched/include/Obj00476.h"
#include "../../matched/include/Obj14322.h"
#include "../../matched/include/Obj24208.h"
#include "../../matched/include/Obj24209.h"
#include "../../matched/include/Obj24210.h"
#include "../../matched/include/Obj10674.h"

struct WordSet;
struct Obj0203159C;
struct S020315D4;
struct Sub0200852CObj;
struct Obj;
struct Descriptor;
struct PrintSys;
struct Actor;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct StrObj;
struct U16Vec;
typedef struct Obj Obj;

struct Obj {
    unsigned char pad00[0x0C];
    unsigned char state;
    unsigned char pad0D[0x34 - 0x0D];
    int pending;
    unsigned char pad38[0x40 - 0x38];
    unsigned char *steps;
    unsigned char pad44[0x89 - 0x44];
    unsigned char stepIdx;
};

typedef struct Ent {
    void (*init)(Obj *);
    int (*update)(Obj *);
} Ent;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct E { u8 a, b; u16 c; };

struct P { u8 pad0[0x40]; struct E *tbl; u8 pad1[0x89 - 0x44]; u8 idx; };

typedef signed char s8;

typedef signed short s16_021B6F2C;

typedef signed int s32;

typedef struct { short x, y; u16 id; u8 a, b; } Request;

typedef short s16_021B71B8;

typedef struct { u8 x,y; } Pair;

typedef signed short s16_021B7364;

extern void func_021B6704(u8 *p, int index);
extern void func_021B68F8(u8 *p, int a);
extern void func_021B6A04(u8 *p, int a);
extern u32 func_0201ED04(struct WordSet *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern u8 *func_02012944(void *p);
extern int func_021B68E8(char *);
extern void func_021B6754(char *);
extern void func_021B6994(u8 *p);
extern void func_021B7378(char *);
extern void func_0203064C(unsigned int src, unsigned int dst, unsigned int size);
extern void *func_0203159C(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020124F4(u16);
extern unsigned int func_0203630C(void);
extern void func_021B6100(u8 *p);
extern void func_021B61C4(unsigned char *),func_02012704(unsigned char *),func_020307B0(void *),func_020315D4(struct S020315D4 *),func_020306F0(unsigned int);
extern int func_021B622C(u8 *p);
extern u32 func_02005728(u32 range);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_0204B3B4(struct Obj *);
extern void func_0204ADA4(unsigned),func_0204A8D4(unsigned),func_0204AFD8(unsigned);
extern void func_020452E8(struct Descriptor *);
extern void func_020307B0(void *);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_02045334(struct Descriptor *d);
extern unsigned func_020056EC(unsigned);
extern void func_0204B95C(struct Actor *a);
extern void func_0204B9A0(struct Actor *a);
extern void func_0204B974(struct Actor *a);
extern u32 func_0204B98C(struct Actor *a);
extern u16 func_0204B918(struct Obj *p);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);
extern int func_0204ACEC(void *, u32, u32, u32, u16);
extern int func_0204A6C8(void *, u32, u32, u32, u16);
extern int func_0204AF28(void *, u32, u32, u32);
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void *func_02049DF4(void *,unsigned,unsigned,unsigned,unsigned short);
extern void func_02082A90(int, int, int);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C724(void *,u32,u32,u32,u32,u32,u16);
void func_021B6A90(Obj *o);
void func_021B6AF8(u8 *p);
int func_021B6B5C(char *p);
void func_021B6B8C(char *p);
int func_021B6B94(char *p);
int func_021B6BC4(void *ctx,int unused,char *arg);
int func_021B6C2C(struct S020315D4 *a,unsigned unused,int own,unsigned char *p);
int func_021B6C5C(int a, int b, int c, int d);
char *func_021B6C70(char *p,int index);
void func_021B6D00(unsigned char *unused,char *p);
void func_021B6D3C(u8 *p,u8 *q);
void func_021B6F24(u8 *unused,u8 *q,int unused2);
int func_021B6F2C(int unused, char *p);
void func_021B6F3C(char *p,u8 *q);
void func_021B7004(u8 *p, u8 *q);
void func_021B7180(char *p, char *q, int id);
void func_021B71A0(int a, int *b, int c, int d, int e);
void func_021B71B8(u8 *p,u8 *q);
void func_021B7350(int a, int *p);
unsigned func_021B7360(unsigned char *p);
void func_021B7364(char *p, int v);
extern const Ent g_021B7398[];
extern char d_021B74AC[];
extern char d_021B74BC[];
extern const u8 d_021B7485[],d_021B7481[];
extern const u8 d_021B7484[],d_021B7480[];
extern const Pair d_021B7380[];


void func_021B6A90(Obj *o)
{
    unsigned int cur = o->steps[o->stepIdx * 4];

    if (o->pending == 1) {
        o->pending = 0;
        g_021B7398[cur].init(o);
    }
    if (g_021B7398[cur].update(o) == 1) {
        unsigned int next;
        o->stepIdx++;
        next = o->steps[o->stepIdx * 4];
        if (next != 0) {
            g_021B7398[next].init(o);
            return;
        }
        o->state = 2;
    }
}

/*
 * lever: Write the table element access twice (tbl[idx].b and tbl[idx].c) with no element pointer local; the index shift then schedules before the table load.
 */
void func_021B6AF8(u8 *p)
{
    u32 a = ((struct P *)p)->tbl[((struct P *)p)->idx].b;
    u32 b = (u8)((struct P *)p)->tbl[((struct P *)p)->idx].c;
    p[0x88] = a;
    func_021B6704(p, a);
    if (a < 2) {
        func_021B68F8(p, 1);
    } else {
        func_021B68F8(p, 0);
    }
    if (*(void **)(p + 0x74) != 0) {
        func_0201ED04(*(void **)(p + 0x74));
    }
    *(void **)(p + 0x74) = func_0201EC64(*(u16 *)p);
    func_0201F02C(*(void **)(p + 0x74), 0, func_02012944(*(void **)(*(u8 **)(p + 0x30) + 4)));
    func_021B6A04(p, b);
}

int func_021B6B5C(char *p)
{
    if(func_021B68E8(p)==1) {
        func_021B6754(p);
        func_021B6994((u8 *)p);
        func_021B7378(*(char **)(p+0x1c+((struct Obj24202 *)p)->f88*4));
        return 1;
    }
    return 0;
}

void func_021B6B8C(char *p)
{
    ((struct Obj24203 *)p)->f8A=0;
}

/*
 * volatile: counter at +0x8a is read at 021B6BAA and reread at 021B6BB6 after store 021B6BB2.
 * Extent includes clear-counter stub 021B6B8C and counter query 021B6B94.
 */
int func_021B6B94(char *p)
{
    u8 threshold=*(u16 *)(*(char * *)&((struct Obj08268 *)p)->f40+((struct Obj08268 *)p)->f89*4+2);
    ++*(volatile u16 *)&((struct Obj08268 *)p)->f8A;
    if(*(volatile u16 *)&((struct Obj08268 *)p)->f8A>threshold) return 1;
    return 0;
}

int func_021B6BC4(void *ctx,int unused,char *arg)
{
    char *p;
    func_0203064C(1,0x55,0x40000);
    p=func_0203159C(ctx,0x8c,0x55);
    if(arg==0) {
        arg=func_02030734(0x55,8,0,d_021B74AC,0x3b8);
        ((struct Obj10673 *)arg)->f4=func_020124F4(1);
        ((struct Obj10673 *)arg)->f0=1;
        if(func_0203630C() & 0x100) ((struct Obj10673 *)arg)->f0=5;
    }
    ((struct Obj01167 *)p)->f0=0x55;
    *(char * *)&((struct Obj01167 *)p)->f30=arg;
    func_021B6100((u8 *)p);
    return 1;
}

int func_021B6C2C(struct S020315D4 *a,unsigned unused,int own,unsigned char *p) {func_021B61C4(p);if(own==0){func_02012704(*(unsigned char * *)&((struct Obj24204 *)(*(char * *)&((struct Obj00681 *)p)->f30))->f4);func_020307B0(((struct Obj00681 *)p)->f30);}func_020315D4(a);func_020306F0(85);return 1;}


int func_021B6C5C(int a, int b, int c, int d)
{
    return func_021B622C((u8 *)d) == 1;
}

char *func_021B6C70(char *p,int index)
{
    char *q;
    if((*(u8 **)(p+0x3c))[index]==0xff) return 0;
    q=func_02030734(((struct Obj01422 *)p)->f0,0x3c,0,d_021B74BC,0x7a);
    ((struct Obj01759 *)q)->f0=index;
    ((struct Obj01759 *)q)->f2=(*(u8 **)(p+0x3c))[index];
    ((struct Obj01759 *)q)->f3=(*(u8 * *)&((struct Obj01422 *)p)->f3C+index)[4];
    ((struct Obj01759 *)q)->f4=0;
    ((struct Obj01759 *)q)->f5=0;
    ((struct Obj01759 *)q)->f14=0;
    ((struct Obj01759 *)q)->f34=0;
    ((struct Obj01759 *)q)->f30=func_02005728(0x4b);
    if(((struct Obj01759 *)q)->f2==0 && func_02008550((const struct Sub0200852CObj *)func_02012944(((struct Obj24205 *)(*(char * *)&((struct Obj01422 *)p)->f30))->f4))==1) ((struct Obj01759 *)q)->f2=5;
    func_021B7004((u8 *)p,(u8 *)q);
    func_021B6F3C(p,(u8 *)q);
    func_021B71B8((u8 *)p,(u8 *)q);
    ((struct Obj01759 *)q)->f8=0;
    ((struct Obj01759 *)q)->f10=0;
    ((struct Obj01759 *)q)->f6=func_02005728(40);
    ((struct Obj01759 *)q)->f38=0;
    return q;
}

void func_021B6D00(unsigned char *unused,char *p) {func_0204B3B4(*(struct Obj * *)&((struct Obj03860 *)p)->f28);func_0204B3B4(*(struct Obj * *)&((struct Obj03860 *)p)->f2C);func_0204ADA4(((struct Obj03860 *)p)->f1C);func_0204A8D4(((struct Obj03860 *)p)->f20);func_0204AFD8(((struct Obj03860 *)p)->f24);func_020452E8(*(struct Descriptor * *)&((struct Obj03860 *)p)->f18);if(((struct Obj03860 *)p)->f10)func_020307B0(((struct Obj03860 *)p)->f10);func_020307B0(p);}

void func_021B6D3C(u8 *p,u8 *q)
{
    unsigned size;
    unsigned pal;
    unsigned base;
    unsigned step;
    if(((struct Obj00152 *)p)->f8==2) size=0x6000; else size=0x3000;
    if(p[13]==0) pal=0;else pal=0xC000;
    if(((struct Obj00152 *)p)->f8==2) base=0;else base=0x1C00;
    switch(((struct Obj00185 *)q)->f8) {
    case 1:
        q[1]=0;
        func_021B7180((char *)p,(char *)q,q[4]+d_021B7485[q[2]*3]);
        ((struct Obj00185 *)q)->f8=2;
        break;
    case 2:
        step=q[1]*0x3000u;
        func_021B71A0((int)p,(int *)q,base+step,pal+(step+(size*q[0]+0x10000)),0x3000);
        q[1]++;
        if(q[1]*0x3000u>=size) {
            ((struct Obj00185 *)q)->f8=3;
            func_020307B0(((struct Obj00185 *)q)->f10);
            ((struct Obj00185 *)q)->f10=0;
        }
        break;
    case 3:
        q[1]=0;
        func_021B7180((char *)p,(char *)q,(q[5]+d_021B7481[q[3]*2])+(((struct Obj00152 *)p)->f10*2));
        ((struct Obj00185 *)q)->f8=4;
        break;
    case 4:
        step=q[1]*0x3000u;
        func_021B71A0((int)p,(int *)q,base+step,pal+(step+(size*q[0]+0x28000)),0x3000);
        q[1]++;
        if(q[1]*0x3000u>=size) {
            ((struct Obj00185 *)q)->f8=5;
            func_020307B0(((struct Obj00185 *)q)->f10);
            ((struct Obj00185 *)q)->f10=0;
        }
        break;
    case 0:
        break;
    }
    if(q[6]<40) q[6]++;
    else if(((struct Obj00185 *)q)->f8==5 || ((struct Obj00185 *)q)->f8==0) {
        q[6]=0;
        q[4]=q[4]==0?1:0;
        q[5]=q[5]==0?1:0;
    }
    if(((struct Obj00185 *)q)->f14==1 && func_0201C6B4(((struct Obj00152 *)p)->f78)==1) {
        func_02045334(((struct Obj00185 *)q)->f18);
        ((struct Obj00185 *)q)->f14=0;
    }
    ((struct Obj00185 *)q)->f30+=(u16)(func_020056EC(2)+1);
    if(((struct Obj00185 *)q)->f30>=150) {
        func_0204B95C(((struct Obj00185 *)q)->f28);
        func_0204B9A0(((struct Obj00185 *)q)->f28);
        ((struct Obj00185 *)q)->f30=0;
    }
    if(((struct Obj00185 *)q)->f34==1 || ((struct Obj00185 *)q)->f38!=0) {
        if(func_0204B98C(((struct Obj00185 *)q)->f2C)==0) func_0204B95C(((struct Obj00185 *)q)->f2C);
    } else {
        if(func_0204B98C(((struct Obj00185 *)q)->f2C)==1 && func_0204B918(((struct Obj00185 *)q)->f2C)==0)
            func_0204B974(((struct Obj00185 *)q)->f2C);
    }
    if(((struct Obj00185 *)q)->f38!=0) (((struct Obj00185 *)q)->f38)--;
}

/*
 * extent: trailing store-and-return follower 021B6F24 included in this unit; 021B6F2A..021B6F2C is alignment padding.
 */
void func_021B6F24(u8 *unused,u8 *q,int unused2)
{
    ((struct Obj24206 *)q)->f8=1;
}


int func_021B6F2C(int unused, char *p)
{
    return ((struct Obj24207 *)p)->f8 == 5;
}

void func_021B6F3C(char *p,u8 *q)
{
    u8 height=24;
    if(((struct Obj05453 *)p)->f8!=2) height=12;
    func_02049BDC(((struct Obj05453 *)p)->f18,d_021B7484[q[2]*3],2,0,0x4000+q[0]*0x200,0x200,((struct Obj05453 *)p)->f0);
    func_02049BDC(((struct Obj05453 *)p)->f18,((struct Obj05453 *)p)->f10+d_021B7480[q[3]*2],2,0,0x6000+q[0]*0x200,0x200,((struct Obj05453 *)p)->f0);
    func_020413B0(2,(q[0]%2)*16,(q[0]/2)*height,16,height,q[0]);
    func_020413B0(3,(q[0]%2)*16,(q[0]/2)*height,16,height,q[0]);
    func_02041B6C(3);
    func_02041B6C(2);
}

/*
 * prototype: 0204B294 leaves its forwarder's result in r0, captured at
 *   021B712A and 021B715A; the returned object pointer is stored as a word.
 */
void func_021B7004(u8 *p, u8 *q)
{
    int step;
    int base;
    Request req;
    if (((struct Obj01422 *)p)->f8 == 2) { step = 0x6000; base = 0; }
    else { step = 0x3000; base = 0x1c00; }
    func_021B7180((char *)p, (char *)q, (d_021B7481 + 4)[q[2] * 3]);
    func_021B71A0((int)p, (int *)q, base, step * q[0] + 0x10000, step);
    func_020307B0(((struct Obj00476 *)q)->f10);
    func_021B7180((char *)p, (char *)q, d_021B7481[q[3] * 2] + ((struct Obj01422 *)p)->f10 * 2);
    func_021B71A0((int)p, (int *)q, base, step * q[0] + 0x28000, step);
    func_020307B0(((struct Obj00476 *)q)->f10);
    *(int *)&((struct Obj00476 *)q)->f1C = func_0204ACEC(((struct Obj01422 *)p)->f18, (d_021B7481 + 5)[q[2] * 3], 0, (u16)((q[0] * 2 + 4) << 5), ((struct Obj01422 *)p)->f0);
    *(int *)&((struct Obj00476 *)q)->f20 = func_0204A6C8(((struct Obj01422 *)p)->f18, (d_021B7481 + 5)[q[2] * 3] + 1, 0, 0, ((struct Obj01422 *)p)->f0);
    *(int *)&((struct Obj00476 *)q)->f24 = func_0204AF28(((struct Obj01422 *)p)->f18, (d_021B7481 + 5)[q[2] * 3] + 2, (d_021B7481 + 5)[q[2] * 3] + 3, ((struct Obj01422 *)p)->f0);
    req.a = 10; req.b = 1;
    req.x = (q[0] % 2) * 128 + 64;
    req.y = (q[0] / 2) * 96 + 48;
    if (((struct Obj01422 *)p)->f8 == 2) req.y += 56;
    req.id = 0;
    *(u32 *)&((struct Obj00476 *)q)->f28 = (u32)func_0204B294((void *)((struct Obj01422 *)p)->f50, ((struct Obj00476 *)q)->f20, ((struct Obj00476 *)q)->f1C, ((struct Obj00476 *)q)->f24, &req, 0, ((struct Obj01422 *)p)->f0);
    func_0204B3DC(((struct Obj00476 *)q)->f28, 1);
    func_0204B92C(((struct Obj00476 *)q)->f28, 1);
    func_0204B974(((struct Obj00476 *)q)->f28);
    req.id = 1;
    *(u32 *)&((struct Obj00476 *)q)->f2C = (u32)func_0204B294((void *)((struct Obj01422 *)p)->f50, ((struct Obj00476 *)q)->f20, ((struct Obj00476 *)q)->f1C, ((struct Obj00476 *)q)->f24, &req, 0, ((struct Obj01422 *)p)->f0);
    func_0204B3DC(((struct Obj00476 *)q)->f2C, 1);
    func_0204B92C(((struct Obj00476 *)q)->f2C, 1);
    func_0204B974(((struct Obj00476 *)q)->f2C);
}

void func_021B7180(char *p, char *q, int id) {((struct Obj24208 *)q)->f10=func_02049DF4(((struct Obj14322 *)p)->f18,id,0,(unsigned)(q+12),((struct Obj14322 *)p)->f0);}


void func_021B71A0(int a, int *b, int c, int d, int e)
{
    func_02082A90(*(int *)((char *)(((struct Obj24209 *)b)->fC) + 0x14) + c,
                  d + 0x06000000, e);
}

void func_021B71B8(u8 *p,u8 *q)
{
    void *s;
    void *dst;
    void *ws;
    u8 *save;
    *(u32 *)(q+0x18)=func_020450F0(0,(u8)(d_021B7380[q[0]].x+2),(u8)(d_021B7380[q[0]].y+1),12,2,12,1);
    func_02043B5C(func_02045770(*(void **)(q+0x18)),0);
    func_02045334(*(void **)(q+0x18));
    func_02045374(*(void **)(q+0x18));
    func_020409B4(0);
    s=func_02045EC0(*(void **)(p+0x68),q[2]);
    if(q[2]==0 || q[2]==5){
        dst=func_020457B0(128,*(u16 *)p);
        save=func_02012944(*(void **)(*(u8 **)(p+0x30)+4));
        ws=func_0201EC64(*(u16 *)p);
        func_0201F02C(ws,0,save);
        func_0201F250(ws,dst,s);
        func_02045808(s);
        func_0201ED04(ws);
        s=dst;
    }
    q[7]=func_0201D304(s,*(u32 *)(p+0x60),0);
    func_0201C724(*(void **)(p+0x78),(u32)func_02045770(*(void **)(q+0x18)),(s16_021B71B8)((96-q[7])/2+1),1,(u32)s,*(u32 *)(p+0x60),0x3c00);
    func_0201C724(*(void **)(p+0x78),(u32)func_02045770(*(void **)(q+0x18)),(s16_021B71B8)((96-q[7])/2-1),1,(u32)s,*(u32 *)(p+0x60),0x3c00);
    func_0201C724(*(void **)(p+0x78),(u32)func_02045770(*(void **)(q+0x18)),(s16_021B71B8)((96-q[7])/2),2,(u32)s,*(u32 *)(p+0x60),0x3c00);
    func_0201C724(*(void **)(p+0x78),(u32)func_02045770(*(void **)(q+0x18)),(s16_021B71B8)((96-q[7])/2),0,(u32)s,*(u32 *)(p+0x60),0x3c00);
    func_0201C724(*(void **)(p+0x78),(u32)func_02045770(*(void **)(q+0x18)),(s16_021B71B8)((96-q[7])/2),1,(u32)s,*(u32 *)(p+0x60),0x400);
    func_02045808(s);
    *(u32 *)(q+0x14)=1;
}


void func_021B7350(int a, int *p)
{
    func_02045374((struct Cfg *)(((struct Obj24210 *)p)->f18));
    func_02041B6C(0);
}

unsigned func_021B7360(unsigned char *p) {return p[7];}


void func_021B7364(char *p, int v)
{
    if (((struct Obj10674 *)p)->f34 == 1 && v == 0)
        ((struct Obj10674 *)p)->f38 = 0x46;
    ((struct Obj10674 *)p)->f34 = v;
}
