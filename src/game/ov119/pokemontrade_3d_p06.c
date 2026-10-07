/*
 * file:     pokemontrade_3d_p06.c
 * unit:     yes
 * function: func_021E2484, func_021E24E8, func_021E2680, func_021E26AC, func_021E272C, func_021E293C, func_021E2984, func_021E2A1C, func_021E2A80, func_021E2A98, func_021E2B14, func_021E2B68, func_021E2B78, func_021E2BD0
 * address:  0x021E2484
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
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045334 0x02045334 arm
 *   func_020452E8 0x020452E8 arm
 *   func_021E0E4C 0x021E0E4C thumb ov119
 *   func_021E5EF8 0x021E5EF8 thumb ov119
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_021D8ADC 0x021D8ADC thumb ov119
 *   func_021E6CB8 0x021E6CB8 thumb ov119
 *   func_021E6334 0x021E6334 thumb ov119
 *   func_021E6E7C 0x021E6E7C thumb ov119
 *   func_021E1430 0x021E1430 thumb ov119
 *   func_021E1670 0x021E1670 thumb ov119
 *   func_021E15F8 0x021E15F8 thumb ov119
 *   func_021E6DEC 0x021E6DEC thumb
 *   func_0207D658  0x0207D658  arm
 *   d_021E7924 0x021E7924 data a4
 *   d_021E791C 0x021E791C data a4
 *   d_021E7974 0x021E7974 data a4
 *   d_021E790C 0x021E790C data a4
 *   func_020450F0 0x020450F0 arm
 *   func_021E1778 0x021E1778 thumb ov119
 *   func_021E0E68 0x021E0E68 thumb ov119
 *   func_021E1CA8 0x021E1CA8 thumb ov119
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020457B0 0x020457B0 arm
 *   func_0202800C 0x0202800C thumb
 *   func_02045808 0x02045808 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_021DD2F4 0x021DD2F4 thumb ov119
 *   func_02028148 0x02028148 thumb
 *   func_02035C08 0x02035C08 arm
 *   d_021E792C 0x021E792C data
 *   func_02030EAC 0x02030EAC arm
 *   func_02048BC4 0x02048BC4 arm
 *   func_02048C58 0x02048C58 arm
 *   func_02046858 0x02046858 arm
 *   d_021E799C 0x021E799C data a4
 *   d_021F4560 0x021F4560 data a4
 *   d_021E7B1C 0x021E7B1C data a4
 *   d_020A1DF8 0x020A1DF8 data a2
 *   func_02048C4C 0x02048C4C arm
 *   func_02048AFC 0x02048AFC arm
 *   func_02048B44 0x02048B44 arm
 *   func_02048B6C 0x02048B6C arm
 *   func_02048B20 0x02048B20 arm
 *   func_02048B60 0x02048B60 arm
 *   func_021E3A40 0x021E3A40 thumb ov119
 */
#include "../../matched/include/Obj05331.h"
#include "../../matched/include/Obj10374.h"
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj02172.h"
#include "../../matched/include/Obj08066.h"
#include "../../matched/include/Obj06427.h"

#define I(k) (*(int *)(p+(k)))
#define P(k) (*(void **)(p+(k)))
#define WININ (*(volatile u16 *)0x04001048)
#define WINOUT (*(volatile u16 *)0x0400104a)
#define DISPCNT (*(volatile u32 *)0x04001000)
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct WordSet;
struct Cfg;
struct Obj;
struct U16Vec;
struct PrintSys;
struct Node;
struct LightSet;
struct LightSlot;
struct Light;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed short s16;

typedef struct {int a,b;} Pair;

typedef struct {u32 a,b,c,d;} Quad;

typedef int BOOL;

typedef struct {int a,b,c,d,e,f,g,h;} Config;

typedef struct {int x,y,z;} Vec;

extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020456F8(struct Descriptor *d);
extern void func_02045334(struct Descriptor *);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_021E0E4C(char *p);
extern void func_021E5EF8(void *);
extern void func_0201DD78(u32,u32,u32);
extern u32 func_02017E1C(void *,u32,u32);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern int func_021D8ADC(char *);
extern void func_021E6CB8(char *);
extern void func_021E6334(char *,int,int,void *,int,u32);
extern void func_021E6E7C(int p);
extern void func_021E1430(void *,void *,int,int,int,int,char *);
extern void func_021E1670(void *,void *,int,int,char *,int,int);
extern void func_021E15F8(void *,void *,int,int,char *);
extern void func_021E6DEC(int p);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern int func_020450F0(u32,u8,u32,u32,u8,u8,u8);
extern void func_021E1778(int,int,int,int,char *);
extern void func_021E0E68(char *,void *,int,int,int,int,u16,int);
extern void func_021E1CA8(char *p);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 *func_0202800C(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7, u16 a8);
extern void func_02045808(struct U16Vec *vec);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_0201C6EC(struct PrintSys *p);
extern int func_021DD2F4(char *);
extern void func_02028148(u8 *p);
extern int func_02035C08(const void *);
extern void func_02030EAC(struct Node *n);
extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap);
extern void func_02048C58(struct LightSlot *slots);
extern void func_02046858(const u32 *src);
extern void func_02048C4C(void *);
extern void func_02048AFC(void *,Vec *);
extern void func_02048B44(void *,Vec *);
extern void func_02048B6C(struct Light *l, const u32 *in);
extern void func_02048B20(void *,Vec *);
extern void func_02048B60(struct Light *l, const u32 *in);
extern void func_021E3A40(const u8 *p);
void func_021E2484(char *p,int a);
void func_021E24E8(char *p, int a1);
void func_021E2680(char *p);
void func_021E26AC(void *a0);
void func_021E272C(char *p,int i,void *mon);
void func_021E293C(char *p,int i);
void *func_021E2984(char *p,int a);
void func_021E2A1C(char *p,int a,int b);
int func_021E2A80(void *a0);
void func_021E2A98(void *a,char *p);
void func_021E2B14(int a);
void func_021E2B68(void);
void func_021E2B78(char *p);
void func_021E2BD0(char *p);
void func_021E2C34(char *p);
extern const Pair d_021E7924,d_021E791C,d_021E790C;
extern const Quad d_021E7974;
extern const char d_021E792C[];
extern const Config d_021E7B1C;
extern char d_021E799C[];
extern void *d_021F4560;
extern short d_020A1DF8[];

void func_021E2484(char *p,int a)
{
    func_021E0E4C(p+0x8c4);
    func_021E5EF8(p+0x950);
    func_021E5EF8(p+0x964);
    func_021E5EF8(p+0x978);
    if (((struct Obj05331 *)p)->f6B4) {
        func_02043B5C(func_02045770((struct Descriptor *)((struct Obj05331 *)p)->f6B4),0);
        if(a) {
            func_020456F8((struct Descriptor *)(((struct Obj05331 *)p)->f6B4));
            func_02045334((struct Descriptor *)((struct Obj05331 *)p)->f6B4);
        }
        func_020452E8((struct Descriptor *)(((struct Obj05331 *)p)->f6B4));
        ((struct Obj05331 *)p)->f6B4=0;
    }
}

/*
 * zero: the literal 0 arguments of the first loop are hoisted and spilled to the slot k then reuses; k=0 is written just before the second func_0201DD78 call, not before the loop.
 */
void func_021E24E8(char *p, int a1)
{
    void *arr[2];
    void *mon;
    u32 flag76;
    char *q1,*q2;
    int j,n;
    int k;
    func_021E6CB8(p);
    arr[0]=P(0x834);
    arr[1]=P(0x830);
    func_0201DD78(15,2,0);
    for(j=0;j<2;j++) {
        func_02045CAC(P(0x720),128,P(0x734));
        func_0201F02C(P(0x724),0,arr[j]);
        func_0201F250(P(0x724),P(0x730),P(0x734));
        func_0201C7A4(*(void **)(p+j*16+0x10f4),0,0,P(0x730),P(0x728));
    }
    k=0;
    func_0201DD78(15,2,k);
    for(;k<2;k++) {
        func_0201DD78(1,2,0);
        q1=p+(1-k)*12;
        q2=p+k*16;
        for(n=0;n<3;n++) {
            mon=*(void **)(q1+n*4+0xfd8);
            if(*(int *)(q1+n*4+0xfa4)!=-1) {
                flag76=func_02017E1C(mon,76,0);
                func_021E6334(p,k,n,mon,0,1);
                func_021E1430(mon,*(void **)(q2+n*4+0x10f8),0,0,flag76,func_021D8ADC(p),p);
                if(flag76==0) {
                    func_021E1670(mon,*(void **)(q2+n*4+0x10f8),56,16,p,0,func_021D8ADC(p));
                    func_021E15F8(mon,*(void **)(q2+n*4+0x10f8),0,16,p);
                }
            }
        }
    }
    func_021E6E7C((int)p);
}

void func_021E2680(char *p)
{
    int i;
    for (i=0;i<4;i++) {
        char *q = p+i*4;
        if (((struct Obj10374 *)q)->f1038) {
            func_020452E8(((struct Obj10374 *)q)->f1038);
            ((struct Obj10374 *)q)->f1038=0;
        }
    }
    func_021E6DEC((int)p);
}


void func_021E26AC(void *a0)
{
    u32 v;

    func_0207D658(0x04001050, 0x1A, -8);

    v = (*(volatile u16 *)0x04001048 & ~0x3F) | 0x1F;
    *(volatile u16 *)0x04001048 = v | 0x20;
    *(volatile u16 *)0x04001040 = 0x00FF;
    *(volatile u16 *)0x04001044 = 0x00C0;
    v = (*(volatile u16 *)0x04001048 & ~0x3F00) | 0x1F00;
    *(volatile u16 *)0x04001048 = v | 0x2000;
    *(volatile u16 *)0x04001042 = 0xFF00;
    *(volatile u16 *)0x04001046 = 0x00C0;
    v = (*(volatile u16 *)0x0400104A & ~0x3F) | 0x1F;
    *(volatile u16 *)0x0400104A = v;
    *(volatile u32 *)0x04001000 =
        (*(volatile u32 *)0x04001000 & 0xFFFF1FFF) | 0x6000;
}

/*
 * lever: each final handle index is recomputed through a 32-bit long local;
 * an int copy CSEs the shift and shortens the function by four bytes.
 */
void func_021E272C(char *p,int i,void *mon)
{
    Pair a=d_021E7924;
    Pair b=d_021E791C;
    Quad colors=d_021E7974;
    Pair c=d_021E790C;
    u32 flag;
    int layer,idx2;
    u32 col,col2;
    int index;
    char *items,*items2;
    flag=func_02017E1C(mon,76,0);
    index=i*4;
    if(*(int *)(p+i*4+0x5c4)) {
        func_020452E8((struct Descriptor *)(*(int *)(p+i*4+0x5c4)));
        func_020452E8((struct Descriptor *)(*(int *)(p+i*4+0x5cc)));
    }
    layer=*(int *)((char *)&a+index);
    items=p+0x5c4;
    *(int *)(items+index)=func_020450F0(1,layer,0,14,5,5,0);
    items2=p+0x5cc;
    *(int *)(items2+index)=func_020450F0(1,layer,17,13,2,5,0);
    idx2=i*2;
    col=((u32 *)&colors)[idx2];
    func_02043B5C(func_02045770((struct Descriptor *)*(int *)(items+index)),(u8)(col|(col<<4)));
    col2=((u32 *)&colors)[idx2+1];
    func_02043B5C(func_02045770((struct Descriptor *)*(int *)(items2+index)),(u8)(col2|(col2<<4)));
    func_0201DD78(1,2,(u8)col);
    {
        void *window=func_02045770((struct Descriptor *)*(int *)(items+index));
        func_021E1430(mon,window,16,4,flag,func_021D8ADC(p),p);
    }
    if(flag==0) {
        char *first=p+0x5c4;
        void *window=func_02045770((struct Descriptor *)*(int *)(first+index));
        func_021E1670(mon,window,80,4,p,1,func_021D8ADC(p));
        func_021E15F8(mon,func_02045770((struct Descriptor *)*(int *)(first+index)),16,19,p);
        func_0201DD78(1,2,(u8)col2);
        func_021E1778((int)mon,*(int *)(items2+index),0,0,p);
        func_021E0E68(p+0x8c4+(i+1)*20,mon,((struct Obj00001 *)p)->f9C4,*(int *)((char *)&b+index)+16,16,0,((struct Obj00001 *)p)->f5F4,*(int *)((char *)&c+index));
    } else func_021E1CA8(p);
    {
        char *first=p+0x5c4;
        char *second=p+0x5cc;
        long endindex=(long)i*4;
        func_02045334((struct Descriptor *)*(int *)(first+endindex));
        func_02045334((struct Descriptor *)*(int *)(second+endindex));
        func_02045374((struct Cfg *)(*(int *)(first+endindex)));
        func_02045374((struct Cfg *)(*(int *)(second+endindex)));
    }
    func_02041B6C(1);
    *(u8 *)(p+i+0x11e2)=120;
}

void func_021E293C(char *p,int i)
{
    if (*(int *)(p+0x5c4+4*i)) {
        func_020452E8((struct Descriptor *)(*(int *)(p+0x5c4+4*i)));
        func_020452E8((struct Descriptor *)(*(int *)(p+0x5cc+4*i)));
        func_021E0E4C(p+0x8c4+20*(i+1));
        *(int *)(p+0x5c4+4*i)=0;
        *(int *)(p+0x5cc+4*i)=0;
    }
}

void *func_021E2984(char *p,int a) {
    void *t;
    t=func_020457B0(100,((struct Obj02172 *)p)->f5F4);
    ((struct Obj02172 *)p)->f650=t;
    func_02045CAC(((struct Obj02172 *)p)->f720,a,t);
    ((struct Obj02172 *)p)->f654=0x39e3;
    ((struct Obj02172 *)p)->f658=0;
    ((struct Obj02172 *)p)->f648=func_0202800C((u32)(((struct Obj02172 *)p)->f6B0),(u32)(p+0x650),8,21,16,3,0,1,((struct Obj02172 *)p)->f5F4);
    func_02045808(((struct Obj02172 *)p)->f650);
    func_0204B3DC(((struct Obj02172 *)p)->fF04,0);
    func_021B6558((unsigned char *)(((struct Obj02172 *)p)->f9C0),8,0);
    return ((struct Obj02172 *)p)->f648;
}

void func_021E2A1C(char *p,int a,int b) {
    if (!func_0201C6B4(((struct Obj00001 *)p)->f740)) func_0201C6EC(((struct Obj00001 *)p)->f740);
    if(a) func_0204B3DC(((struct Obj00001 *)p)->fF04,1);
    if(b) func_021B6558((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),8,func_021DD2F4(p));
    if(((struct Obj00001 *)p)->f648) {
        func_02028148(((struct Obj00001 *)p)->f648);
        ((struct Obj00001 *)p)->f648=0;
        func_02041B6C(6);
    }
}

int func_021E2A80(void *a0)
{
    if (func_02035C08(d_021E792C) == 0) return 1;
    return 0;
}

static inline void W1Inside(int wnd,BOOL effect) {
    u32 tmp=(WININ & ~0x3f00)|((u32)wnd<<8);
    if(effect) tmp|=0x2000;
    WININ=(u16)tmp;
}

static inline void W0Inside(int wnd,BOOL effect) {
    u32 tmp=(WININ & ~0x3f)|((u32)wnd);
    if(effect) tmp|=0x20;
    WININ=(u16)tmp;
}

static inline void Outside(int wnd,BOOL effect) {
    u32 tmp=(WINOUT & ~0x3f)|((u32)wnd);
    if(effect) tmp|=0x20;
    WINOUT=(u16)tmp;
}

static inline void Position1(int x1,int y1,int x2,int y2) {
    *(volatile u16 *)0x04001042=(u16)(((x1<<8)&0xff00)|(x2&0xff));
    *(volatile u16 *)0x04001046=(u16)(((y1<<8)&0xff00)|(y2&0xff));
}

static inline void Position0(int x1,int y1,int x2,int y2) {
    *(volatile u16 *)0x04001040=(u16)(((x1<<8)&0xff00)|(x2&0xff));
    *(volatile u16 *)0x04001044=(u16)(((y1<<8)&0xff00)|(y2&0xff));
}

static inline void Visible(int window) {DISPCNT=(DISPCNT&~0xe000)|(window<<13);}

/*
 * volatile: WININ re-read at 021E2A9E and 021E2AB6; WINOUT and DISPCNT hardware read-modify-write, WIN0/1 positions hardware stores.
 */
void func_021E2A98(void *a,char *p) {
    W1Inside(0x10,0);
    Position1(0x30,0,0xd0,0x20);
    W0Inside(0x11,0);
    Position0(0xe0,0xa9,0xff,0xc0);
    Outside(0x1f,1);
    Visible(3);
    p[0x11f9]=0;
    func_02030EAC(a);
}

void func_021E2B14(int a) {
    Config c;
    d_021F4560=func_02048BC4((const struct LightSet *)d_021E799C,a);
    func_02048C58(d_021F4560);
    c=d_021E7B1C;
    c.b=d_020A1DF8[12]; c.c=d_020A1DF8[13];
    func_02046858((const u32 *)(&c));
}

void func_021E2B68(void)
{
    func_02048C4C(d_021F4560);
}

void func_021E2B78(char *p) {
    Vec a;
    Vec b;
    a.x=0; a.y=0x2b000; a.z=0xf1000;
    b.x=0; b.y=0x2b000; b.z=0;
    func_02048AFC(((struct Obj08066 *)p)->f83C,&a);
    func_02048B44(((struct Obj08066 *)p)->f83C,&b);
    a.z-=0x1000;
    func_02048B6C(((struct Obj08066 *)p)->f83C,(const u32 *)(&a.z));
    b.x=0; b.y=0x1000; b.z=0;
    func_02048B20(((struct Obj08066 *)p)->f83C,&b);
}

void func_021E2BD0(char *p) {
    Vec a;
    Vec b;
    int c=0x1f40000;
    int d=0x1000;
    a.x=0; a.y=0x3000; a.z=0xf000;
    b.x=0; b.y=0; b.z=0;
    func_02048AFC(((struct Obj06427 *)p)->f83C,&a);
    func_02048B44(((struct Obj06427 *)p)->f83C,&b);
    func_02048B60(((struct Obj06427 *)p)->f83C,(const u32 *)(&d));
    func_02048B6C(((struct Obj06427 *)p)->f83C,(const u32 *)(&c));
    b.x=0; b.y=0x10000; b.z=0x1000;
    func_02048B20(((struct Obj06427 *)p)->f83C,&b);
}

void func_021E2C34(char *p) {func_021E3A40((const u8 *)p);}
