/*
 * file:     gsync_state_p13.c
 * unit:     yes
 * function: func_021D7224, func_021D72D8, func_021D7390, func_021D73D8, func_021D7430, func_021D746C, func_021D751C, func_021D7560, func_021D758C, func_021D75D0, func_021D768C, func_021D76B8, func_021D76F0, func_021D7798, func_021D77C4
 * address:  0x021D7224
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02030734 0x02030734 arm
 *   func_02082D44 0x02082D44 arm
 *   d_021DAB78 0x021DAB78 data a1
 *   func_02009290 0x02009290 thumb
 *   func_020092F8 0x020092F8 thumb
 *   func_020093D4 0x020093D4 thumb
 *   func_021D584C 0x021D584C thumb ov123
 *   func_021D57D0 0x021D57D0 thumb ov123
 *   func_021D5960 0x021D5960 thumb ov123
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D62BC 0x021D62BC thumb ov123
 *   func_021D62D0 0x021D62D0 thumb ov123
 *   func_021D6650 0x021D6650 thumb ov123
 *   func_021D6458 0x021D6458 thumb ov123
 *   func_021D652C 0x021D652C thumb ov123
 *   func_021D7204 0x021D7204 thumb ov123
 *   func_021D7180 0x021D7180 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021B97F4 0x021B97F4 thumb ov114
 *   func_021D6E08 0x021D6E08 thumb ov123
 *   func_0203CD98 0x0203CD98 arm
 *   func_021B95D4 0x021B95D4 thumb ov114
 *   func_021B973C 0x021B973C thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_021BE79C 0x021BE79C arm ov114
 *   func_021D66D0 0x021D66D0 thumb ov123
 *   func_02012DD0 0x02012DD0 thumb
 *   func_020056EC 0x020056EC thumb
 *   func_020092D0 0x020092D0 thumb
 *   func_021D6EBC 0x021D6EBC thumb ov123
 *   func_021D7CB4 0x021D7CB4 thumb ov123
 *   func_021D7DE8 0x021D7DE8 thumb ov123
 *   func_021D7C54 0x021D7C54 thumb ov123
 *   func_021D7D18 0x021D7D18 thumb ov123
 *   func_021D5D58 0x021D5D58 thumb ov123
 *   func_021D7858 0x021D7858 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_020090F8 0x020090F8 thumb
 *   func_021D5BA0 0x021D5BA0 thumb ov123
 *   func_0203F1FC 0x0203F1FC arm
 *   func_02009108 0x02009108 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_02012E7C 0x02012E7C thumb
 *   func_0200734C 0x0200734C thumb
 *   func_0200E8E0 0x0200E8E0 thumb
 *   func_0200C5F8 0x0200C5F8 thumb
 */
#include "../../matched/include/Obj01736.h"
#include "../../matched/include/Obj01254.h"
#include "../../matched/include/Obj06464.h"
#include "../../matched/include/Obj04500.h"
#include "../../matched/include/Obj05364.h"
#include "../../matched/include/Obj03269.h"
#include "../../matched/include/Obj06465.h"
#include "../../matched/include/Obj13985.h"
#include "../../matched/include/Obj08110.h"
#include "../../matched/include/Obj13986.h"
#include "../../matched/include/Obj03793.h"
#include "../../matched/include/Obj22959.h"
#include "../../matched/include/Obj08111.h"
#include "../../matched/include/Obj13987.h"
#include "../../matched/include/Obj02475.h"
#include "../../matched/include/Obj22960.h"
#include "../../matched/include/Obj10445.h"
#include "../../matched/include/Obj02837.h"

struct Sub02009210Obj;
struct Sub02009448Obj;
struct Sub02007454Entry;
struct Obj02181;
struct Big;
struct Sub02007324Ctrl;
struct Sub020090B0Obj;
struct MusicalDist;
typedef unsigned short u16;

typedef signed int     s32;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct { u16 f0; char *f4; void (*f8)(char *); } Callback;

extern struct Sub02009448Obj *func_02009448(void *sys);
extern u32 func_020307B0(void *p);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern u32 func_020173EC(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 *func_02009290(struct Sub02009210Obj *obj);
extern void func_02082D44(void *,void *,int);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02019CA0(void *p, u32 v);
extern void *func_020185F4(void *p);
extern int func_020074D8(void **save, const struct Sub02007454Entry *src);
extern void func_020092F8(struct Sub02009210Obj *obj, u8 value);
extern void func_020093D4(struct Sub02009210Obj *obj, s32 value);
extern int func_02012DD0(u8 *p);
extern void func_021D584C(char *);
extern void func_021D57D0(void *p, int msg, int n, void *mon);
extern void func_021D5960(char *,int,int);
extern void func_021D62B4(u8 *p, unsigned int i);
extern void func_021D62BC(u8 *p, int i, u32 v);
extern void func_021D62D0(u8 *p, int i, int v);
extern void func_021D6650(u8 *p, int flag);
extern int func_020185F0(void *);
extern void func_021D6458(struct Obj02181 *p, void *n, int i);
extern void func_021D652C(char *);
extern void func_020061E4(u32 a);
extern void func_021D7204(u8 *p);
extern void func_021D7180(int a);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern int func_021B99DC(u8 *p);
extern int func_021B9790(u8 *p);
extern u8 *func_021B97F4(u8 *p);
extern int func_021D6E08(char *,int);
extern int func_0203CD98(void);
extern int func_021B95D4(int index, u8 *p);
extern int func_021B973C(char *p);
extern int func_021B9748(u8 *p);
extern int func_021BE79C(void *handle, void *value_p, unsigned long length);
extern void func_021D66D0(u8 *,int);
extern u32 func_020056EC(u32 range);
extern int func_021D6EBC(u8 *p);
extern int func_021D7CB4(int a, u8 *p);
extern void func_021D7DE8(u8 *p, int a, u8 *records);
extern void func_021D7C54(void *p, char *q);
extern void func_020092D0(struct Sub02009210Obj *obj, u8 value);
extern void func_021D7D18(u8 *p, int unused, int species, int gender, int form, int n, int value);
extern void func_02009348(struct Sub02009210Obj *obj, int i, u16 a, u8 b);
extern int func_02012DAC(int a0);
extern int func_021D5D58(char *p);
extern void func_021D7858(int a);
extern void func_021D6FF0(char *p);
extern void *func_02012EBC(struct Big *p);
extern int func_02012E7C(char *p, int a1);
extern void func_0200734C(struct Sub02007324Ctrl *,unsigned int);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern void func_020090F8(struct Sub020090B0Obj *obj, unsigned char value);
extern int func_021D5BA0(char *p);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern int func_020072CC(int,int,u16,int,int);
extern void func_0200E8E0(void *obj, u32 value);
extern void func_02012E4C(u8 *,u32);
extern void func_02009108(struct Sub020090B0Obj *obj, u16 value);
extern u32 func_0200C5F8(struct MusicalDist *p);
extern struct MusicalDist *func_0200C5C8(void *sys, const void *src, u32 size, u32 heap);
void func_021D7224(char *p);
void func_021D72D8(char *p);
void func_021D7390(char *p);
void func_021D73D8(char *p);
void func_021D7430(u8 *p);
void func_021D746C(int a);
void func_021D751C(int a);
void func_021D7560(u8 *p);
void func_021D758C(u8 *a);
void func_021D75D0(int a);
void func_021D768C(u8 *p);
void func_021D76B8(char *p);
void func_021D76F0(int a);
void func_021D7798(u8 *p);
void func_021D77C4(int a,int n);
extern const char d_021DAB78[];

/*
 * lever: update the call-result local in both clamp arms to preserve its register.
 */
void func_021D7224(char *p)
{
    void *g;
    void *q;
    int size;
    int n;
    g=func_02009448(((struct Obj01736 *)p)->f28);
    if (((struct Obj01736 *)p)->fC) {
        func_020307B0(((struct Obj01736 *)p)->fC);
        ((struct Obj01736 *)p)->fC=0;
    }
    if (func_020076D0(((struct Obj01736 *)p)->f24,(int *)(p+0x48),(int *)(p+0x4c))) {
        q=func_02030734(((struct Obj01736 *)p)->f0,func_020173EC(),1,d_021DAB78,0x245);
        size=func_020173EC();
        func_02082D44(func_02009290(g),q,size);
        if (((struct Obj01736 *)p)->f6C) {
            n=func_02017E1C(q,158,0);
            if (n==100) ((struct Obj01736 *)p)->f6C=0;
            if (n+((struct Obj01736 *)p)->f6C>100) {
                ((struct Obj01736 *)p)->f6C=100-n;
                n=100;
            } else {
                n+=((struct Obj01736 *)p)->f6C;
            }
            func_02019CA0(q,n);
        }
        func_020074D8(((struct Obj01736 *)p)->f24,(const struct Sub02007454Entry *)((int)func_020185F4(q)));
        ((struct Obj01736 *)p)->fC=q;
        func_020092F8(g,0);
        func_020093D4(g,((struct Obj01736 *)p)->f7C);
    }
}

void func_021D72D8(char *p)
{
    Callback cb;
    func_02009448(((struct Obj01254 *)p)->f28);
    if (func_02012DD0(((struct Obj01254 *)p)->f2C)==2) {
        ((struct Obj01254 *)p)->fAD=0;
        ((struct Obj01254 *)p)->fAB=0;
        ((struct Obj01254 *)p)->fAE=0;
        func_021D584C(*(char * *)&((struct Obj01254 *)p)->f18);
        func_021D57D0(*(char * *)&((struct Obj01254 *)p)->f18,45,0,(void *)(*(int *)&((struct Obj01254 *)p)->fC));
        func_021D5960(*(char * *)&((struct Obj01254 *)p)->f18,1,4);
        func_021D62B4((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),0);
        func_021D62BC((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),6,7);
        func_021D62BC((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),0,1);
        cb.f0=0; cb.f4=p; cb.f8=(void (*)(char *))func_021D7204;
        func_021D62D0((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),0,(int)&cb);
        func_021D6650((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),0);
        func_021D6458((struct Obj02181 *)(*(char * *)&((struct Obj01254 *)p)->f14),(void *)func_020185F0(((struct Obj01254 *)p)->fC),0);
        func_021D652C(*(char * *)&((struct Obj01254 *)p)->f14);
        func_020061E4(0x658);
        func_021D6EE0((u8 *)p,(int)func_021D7180,0x295);
    }
}

void func_021D7390(char *p)
{
    if (func_021D6E08(p,func_021B99DC(((struct Obj06464 *)p)->f10))==0) {
        if (func_021B9790(((struct Obj06464 *)p)->f10)==0) {
            func_021B97F4(((struct Obj06464 *)p)->f10);
            func_02009448(((struct Obj06464 *)p)->f28);
            ((struct Obj06464 *)p)->fAE=1;
            func_021D6EE0((u8 *)p,(int)func_021D72D8,0x2ae);
        }
    }
}

void func_021D73D8(char *p)
{
    if (((struct Obj04500 *)p)->f78) {
        --((struct Obj04500 *)p)->f78;
        return;
    }
    if (func_0203CD98()) {
        if (func_021B95D4(8,((struct Obj04500 *)p)->f10)) {
            p[2]=1;
            p[3]=0;
            func_021BE79C((void *)func_021B973C(((struct Obj04500 *)p)->f10),(void *)((unsigned int)(p+2)),4);
            if (func_021B9748(((struct Obj04500 *)p)->f10)==0)
                func_021D6EE0((u8 *)p,(int)func_021D7390,0x2cd);
        }
    }
}

void func_021D7430(u8 *p) { if(((struct Obj05364 *)p)->f70<100) ++((struct Obj05364 *)p)->f70; func_021D66D0(*(u8 * *)&((struct Obj05364 *)p)->f14,((struct Obj05364 *)p)->f70); if(func_02012DD0(((struct Obj05364 *)p)->f2C)==1) { ((struct Obj05364 *)p)->f78=func_020056EC(190); func_021D6EE0((u8 *)p,(int)func_021D73D8,0x2e6); } }

void func_021D746C(int a)
{
    int b;
    int i;
    u8 *p;
    b=(int)func_02009448((void *)(((struct Obj03269 *)a)->f28));
    ((struct Obj03269 *)a)->fAB=1;
    func_021D7224((char *)a);
    if(func_021D6EBC((u8 *)a)==0) {
        func_021D7CB4(b,(u8 *)(((struct Obj03269 *)a)->f38));
        func_021D7DE8((u8 *)a,b,(u8 *)(((struct Obj03269 *)a)->f38));
        func_021D7C54((void *)b,(char *)(((struct Obj03269 *)a)->f38));
        func_020092D0((struct Sub02009210Obj *)b,*(u8 *)(((struct Obj03269 *)a)->f38+0x5a));
    } else {
        p=*(u8 * *)&((struct Obj03269 *)a)->f20+0xc;
        func_021D7D18((u8 *)a,b,((struct Obj06465 *)p)->f2,p[7],p[6],((struct Obj06465 *)p)->f4,func_020056EC(8));
        for(i=0;i<20;i++) func_02009348((struct Sub02009210Obj *)b,i,*(u16 *)(p+8+i*2),p[0x30+i]);
    }
    ((struct Obj03269 *)a)->fAD=1;
    func_02012DAC(((struct Obj03269 *)a)->f2C);
    func_021D6EE0((u8 *)a,(int)func_021D7430,0x311);
}

void func_021D751C(int a)
{
    if (func_021D5D58((char *)(((struct Obj13985 *)a)->f8))) {
        func_021D6EE0((u8 *)a, (int)func_021D7858, 0x319);
        return;
    }
    ((struct Obj13985 *)a)->f80 = 0xfff0;
    func_021D6EE0((u8 *)a, (int)func_021D6FF0, 0x31d);
}

void func_021D7560(u8 *p) { p[165]=0; func_020307B0(((struct Obj08110 *)p)->f40); p[174]=0; ((struct Obj08110 *)p)->f40=0; func_021D6EE0((u8 *)p,(int)func_021D751C,0x328); }

void func_021D758C(u8 *a)
{
    int b = (int)func_02012EBC((struct Big *)(((struct Obj13986 *)a)->f2C));
    if(func_02012E7C((char *)(((struct Obj13986 *)a)->f2C),4)==2) {
        func_0200734C((struct Sub02007324Ctrl *)b,4);
        func_020090F8((struct Sub020090B0Obj *)func_02009210((void *)b),1);
        func_021D6EE0(a,(int)func_021D7560,0x333);
    }
}

void func_021D75D0(int a)
{
    u16 checksum;
    int b;
    u8 *p;
    int x;
    b=(int)func_02012EBC((struct Big *)(((struct Obj03793 *)a)->f2C));
    p=(u8 *)func_021D5BA0((char *)(((struct Obj03793 *)a)->f8));
    checksum=func_0203F1FC(p,0x2600);
    if(checksum!=((struct Obj22959 *)p)->f2600) {
        ((struct Obj03793 *)a)->f80=0xfff0;
        func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x345);
        return;
    }
    ((struct Obj03793 *)a)->fAE=1;
    x=(int)func_02030734(((struct Obj03793 *)a)->f0,0x3000,0,d_021DAB78,0x34a);
    ((struct Obj03793 *)a)->f40=x;
    func_020072CC(b,4,((struct Obj03793 *)a)->f0,x,0x3000);
    func_02082D44(p,(void *)x,0x2600);
    func_02009108((struct Sub020090B0Obj *)func_02009210((void *)b),checksum);
    func_02012E4C((u8 *)((struct Obj03793 *)a)->f2C,4);
    func_021D6EE0((u8 *)a,(int)func_021D758C,0x355);
}

void func_021D768C(u8 *p) { p[166]=0; func_020307B0(((struct Obj08111 *)p)->f3C); p[174]=0; ((struct Obj08111 *)p)->f3C=0; func_021D6EE0((u8 *)p,(int)func_021D751C,0x360); }

void func_021D76B8(char *p) { int v; v=(int)func_02012EBC((struct Big *)(((struct Obj13987 *)p)->f2C)); if(func_02012E7C((char *)(((struct Obj13987 *)p)->f2C),7)==2) { func_0200734C((struct Sub02007324Ctrl *)v,7); func_021D6EE0((u8 *)p,(int)func_021D768C,0x36a); } }

void func_021D76F0(int a)
{
    int b;
    u8 *p;
    int x;
    u16 checksum;
    b=(int)func_02012EBC((struct Big *)(((struct Obj02475 *)a)->f2C));
    p=(u8 *)func_021D5BA0((char *)(((struct Obj02475 *)a)->f8));
    checksum=func_0203F1FC(p,0x6200);
    if(checksum!=((struct Obj22960 *)p)->f6200) {
        ((struct Obj02475 *)a)->f80=0xfff0;
        func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x378);
        return;
    }
    ((struct Obj02475 *)a)->fAE=1;
    x=(int)func_02030734(((struct Obj02475 *)a)->f0,0x6800,0,d_021DAB78,0x37d);
    *(int *)&((struct Obj02475 *)a)->f3C=x;
    func_020072CC(b,7,((struct Obj02475 *)a)->f0,*(int *)&((struct Obj02475 *)a)->f3C,0x6800);
    func_02082D44(p,((struct Obj02475 *)a)->f3C,0x6200);
    func_0200E8E0((void *)(*(int *)&((struct Obj02475 *)a)->f3C),1);
    func_02012E4C((u8 *)((struct Obj02475 *)a)->f2C,7);
    func_021D6EE0((u8 *)a,(int)func_021D76B8,0x383);
}

void func_021D7798(u8 *p) { if(func_0200C5F8(((struct Obj10445 *)p)->f30)) { p[174]=0; ((struct Obj10445 *)p)->f30=0; func_021D6EE0((u8 *)p,(int)func_021D751C,0x38e); } }

void func_021D77C4(int a,int n)
{
    u8 *p;
    int h;
    u16 checksum;
    ((struct Obj02837 *)a)->fA4=0;
    p=(u8 *)func_021D5BA0((char *)(((struct Obj02837 *)a)->f8));
    h=n/2;
    if(n>0x1fc0e) {
        ((struct Obj02837 *)a)->f80=0xfff0;
        func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x39d);
        return;
    }
    checksum=func_0203F1FC(p,n);
    if(checksum!=*(u16 *)(p+h*2)) {
        ((struct Obj02837 *)a)->f80=0xfff0;
        func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x3a3);
        return;
    }
    ((struct Obj02837 *)a)->fAE=1;
    ((struct Obj02837 *)a)->f30=(int)func_0200C5C8((void *)(((struct Obj02837 *)a)->f2C),p,n,((struct Obj02837 *)a)->f0);
    func_021D6EE0((u8 *)a,(int)func_021D7798,0x3a9);
}
