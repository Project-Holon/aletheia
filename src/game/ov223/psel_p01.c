/*
 * file:     psel_p01.c
 * unit:     yes
 * function: func_021B95A0, func_021B95B0, func_021B9600, func_021B9608, func_021B9674, func_021B96E0, func_021B9740
 * address:  0x021B95A0
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020115EC  0x020115EC  thumb
 *   func_02030734 0x02030734 arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   site 0x021BCB00 data a4
 *   func_020307B0 0x020307B0 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204E6E0 0x0204E6E0 arm
 *   func_0204E6F4 0x0204E6F4 arm
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   callbacks 0x021BC84C data a4
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021BAF30 0x021BAF30 thumb ov223
 *   func_021BC4F4 0x021BC4F4 thumb ov223
 *   func_021BC508 0x021BC508 thumb ov223
 *   func_021B97F8 0x021B97F8 thumb ov223
 *   func_021BC514 0x021BC514 thumb ov223
 *   func_02040588 0x02040588 arm
 */
#include "../../matched/include/Obj03961.h"
#include "../../matched/include/Obj03962.h"
#include "../../matched/include/Obj03380.h"

struct Obj0203159C;
struct S020315D4;
struct PrintSys;
typedef unsigned int u32;

typedef unsigned short u16;

struct Record { u16 id,pad; u32 translation[3],scale[3],matrix[9],flag; };

typedef unsigned char u8;

typedef int s32;

extern int func_020115EC(int, int);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_0207ADC4(void *);
extern u32 func_020307B0(void *p);
extern void func_0204E720(u32,int,int,int);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,u32,u32);
extern u32 func_0204E6E0(void);
extern void func_0204E6F4(int);
extern u8 func_020355C4(void);
extern void func_020355D8(u32 v);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021BAF30(int *);
extern void func_021BC4F4(char *);
extern void func_021BC508(unsigned char *p);
extern void func_021B97F8(char *p);
extern void func_021BC514(unsigned char *p);
extern void func_02040588(unsigned char which, unsigned char enable);
int func_021B95A0(int a0, int a1);
struct Record *func_021B95B0(u32 heap,u32 count);
void func_021B9600(void *p);
int func_021B9608(void *a,int unused,void *c);
int func_021B9674(void *a, int unused1, int unused2, u8 *ctx);
int func_021B96E0(void *a,int *state,void *b,char *p);
void func_021B9740(void *unused,char *p);
extern const char site[];


int func_021B95A0(int a0, int a1)
{
    return func_020115EC(a0, a1 / 2);
}

struct Record *func_021B95B0(u32 heap,u32 count)
{
    struct Record *p;
    u16 i;
    p=func_02030734(heap,count*sizeof(struct Record),1,site,654);
    for(i=0;i<count;i++) {
        p[i].translation[0]=0;
        p[i].translation[1]=0;
        p[i].translation[2]=0;
        p[i].scale[0]=4096;
        p[i].scale[1]=4096;
        p[i].scale[2]=4096;
        func_0207ADC4(p[i].matrix);
    }
    return p;
}

void func_021B9600(void *p) { func_020307B0(p); }

int func_021B9608(void *a,int unused,void *c)
{
    char *p;
    func_0204E720(3,16,16,0);
    func_0203064C(1,135,1<<20);
    p=func_0203159C(a,2168,135);
    func_02082BCC(p,0,2168);
    ((struct Obj03961 *)p)->f0=135;
    ((struct Obj03961 *)p)->f4=c;
    ((struct Obj03961 *)p)->f874=func_0204E6E0();
    func_0204E6F4(1);
    ((struct Obj03961 *)p)->f8=func_020355C4();
    ((struct Obj03961 *)p)->f228=4;
    ((struct Obj03961 *)p)->f22C=4;
    ((struct Obj03961 *)p)->f230=0;
    ((struct Obj03961 *)p)->fC=0;
    return 1;
}

int func_021B9674(void *a, int unused1, int unused2, u8 *ctx)
{
    u16 v;
    func_0204E720(0xC, 0x10, 0x10, 0);
    func_020355D8(*(u32 *)(ctx + 8));
    func_0204E6F4(*(u32 *)(ctx + 0x874));
    switch (*(u32 *)(ctx + 0x228)) {
    case 0:
        ***(u16 ***)(ctx + 4) = 0;
        break;
    case 1:
        v = 1;
    st:
        ***(u16 ***)(ctx + 4) = v;
        break;
    case 2:
        v = 2;
        goto st;
    default:
        ***(u16 ***)(ctx + 4) = 0;
        break;
    }
    *(u32 *)(*(u8 **)(ctx + 4) + 4) = *(u32 *)(ctx + 0x228);
    func_020315D4(a);
    func_020306F0(0x87);
    return 1;
}

extern int (*callbacks[])(char *,int *);

int func_021B96E0(void *a,int *state,void *b,char *p)
{
    int old=*state;
    *state=callbacks[*state](p,(int *)(p+12));
    if(*state!=13) {
        if(*state!=old) ((struct Obj03962 *)p)->fC=0;
    } else return 1;
    if(*state>=2&&*state<=11) {
        func_0201C4E4(((struct Obj03962 *)p)->f1C);
        func_021BAF30((int *)p);
        func_021BC4F4(*(char * *)&((struct Obj03962 *)p)->f14);
        func_021BC508(((struct Obj03962 *)p)->f14);
        func_021B97F8(p);
        func_021BC514(((struct Obj03962 *)p)->f14);
    }
    return 0;
}

void func_021B9740(void *unused,char *p)
{
    if(((struct Obj03380 *)p)->f24&1) func_02040588(3,1);
    if(((struct Obj03380 *)p)->f24&2) func_02040588(3,0);
    if(((struct Obj03380 *)p)->f24&4) {func_02040588(3,1);func_02040588(2,1);}
    if(((struct Obj03380 *)p)->f24&8) {func_02040588(3,0);func_02040588(2,0);}
    if(((struct Obj03380 *)p)->f24&16) {func_02040588(7,1);func_02040588(6,1);func_02040588(5,1);}
    if(((struct Obj03380 *)p)->f24&32) {func_02040588(7,0);func_02040588(6,0);func_02040588(5,0);}
    if(((struct Obj03380 *)p)->f24&64) func_02040588(3,1);
    if(((struct Obj03380 *)p)->f24&128) func_02040588(3,0);
    ((struct Obj03380 *)p)->f24=0;
}
