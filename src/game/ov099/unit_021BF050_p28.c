/*
 * file:     unit_021BF050_p28.c
 * unit:     yes
 * function: func_021C24A4, func_021C24D4, func_021C24F0, func_021C2604, func_021C2724, func_021C27D0, func_021C27D4, func_021C27D8
 * address:  0x021C24A4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02005CBC  0x02005CBC  thumb
 *   func_02006734  0x02006734  thumb
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0203D668 0x0203D668 arm
 *   func_021BCB8C 0x021BCB8C thumb ov099
 *   func_02012934 0x02012934 thumb
 *   func_0201283C 0x0201283C thumb
 *   func_0200873C 0x0200873C thumb
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_021BB1A8 0x021BB1A8 thumb ov099
 *   func_021BDE94 0x021BDE94 thumb ov099
 *   func_021BE6F0 0x021BE6F0 thumb ov099
 *   func_0203CD98 0x0203CD98 arm
 *   func_021BA7D8 0x021BA7D8 thumb ov099
 *   func_0203D34C 0x0203D34C arm
 *   func_02157170 0x02157170 thumb ov009
 *   func_021BC0C4 0x021BC0C4 thumb ov099
 *   func_021BB0B4 0x021BB0B4 thumb ov099
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_0202223C 0x0202223C thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0202208C 0x0202208C thumb
 *   func_0204A600 0x0204A600 arm
 *   func_0201DE00 0x0201DE00 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021C2438 0x021C2438 thumb ov099
 *   d_021C3C0C 0x021C3C0C data a4
 *   func_020221A4 0x020221A4 thumb
 *   func_021BA7F8 0x021BA7F8 thumb ov099
 *   func_0200AE08 0x0200AE08 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021BDF7C 0x021BDF7C thumb ov099
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_021BCBB0 0x021BCBB0 thumb ov099
 *   func_021BB224 0x021BB224 thumb ov099
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../../matched/include/Obj01386.h"
#include "../../matched/include/Obj02804.h"
#include "../../matched/include/Obj00825.h"
#include "../../matched/include/Obj03736.h"
#include "../../matched/include/Obj06360.h"

struct BigObj;
struct Obj0203159C;
struct Sub02008700Obj;
struct PrintSys;
struct Tcbl;
struct Reg;
struct S020315D4;
typedef unsigned char u8;

typedef struct {
    char pad[0x1340];
    u8 f1340;
    u8 f1341;
    u8 f1342;
    u8 f1343;
} Work;

typedef unsigned int   u32_021C24A4;

typedef unsigned short u16;

typedef unsigned long  u32_021C24D4;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef unsigned int u32_021C24F0;

typedef int (*Handler)(char *,int);

typedef unsigned int   u32_021C2604;

typedef unsigned int   u32_021C2724;

typedef unsigned long  u32_021C27D0;

typedef int BOOL;

typedef struct {
    char pad[0x18];
    u8 f18;
} S_021C27D0;

typedef unsigned long  u32_021C27D4;

typedef struct {
    char pad[0x18];
    u8 f18;
} S_021C27D4;

typedef unsigned long  u32_021C27D8;

typedef struct {
    char pad[0x17];
    u8 f17;
} S_021C27D8;

extern void func_02005CBC(u32_021C24A4 value, u32_021C24A4 mask);
extern void func_02006734(int v);
extern void func_0203064C(u32_021C24F0, u32_021C24F0, u32_021C24F0);
extern void *func_0203159C(struct Obj0203159C *obj, u32_021C24F0 size, u32_021C24F0 heap);
extern void func_02082BCC(void *, int, int);
extern void func_0203D668(u32_021C24F0);
extern int func_021BCB8C(void *);
extern void *func_02012934(const struct BigObj *p);
extern u32_021C24F0 func_0201283C(const struct BigObj *);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void func_020434DC(u32_021C24F0, u32_021C24F0);
extern void func_02043598(u32_021C24F0, u32_021C24F0);
extern void func_021BB1A8(char *);
extern void func_021BDE94(char *);
extern void func_021BE6F0(char *, int, int);
extern int func_0203CD98(void);
extern void func_021BA7D8(void *p);
extern void func_0203D34C(u32_021C24F0, u32_021C24F0);
extern int func_02157170(int,int);
extern unsigned int func_0200FB24(void);
extern int func_021C2438(char *);
extern void func_021BC0C4(char *);
extern void func_021BB0B4(char *);
extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
extern void func_021C18C8(char *,int,int);
extern void func_0202223C(unsigned int,unsigned int);
extern void func_0202208C(void *,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
extern void func_0204A600(void *);
extern void func_0201DE00(u8 *,u8 *,u8 *);
extern void func_0201DD78(unsigned int,unsigned int,unsigned int);
extern void func_020310C4(struct Tcbl *p);
extern u32_021C2604 func_0201C4E4(struct PrintSys *ps);
extern u32_021C2724 func_020221A4(void);
extern void func_021BA7F8(char *);
extern void func_0200AE08(const struct Reg *src, struct Reg *dest);
extern u32_021C2724 func_020307B0(void *p);
extern void func_021BDF7C(char *);
extern int func_02156A3C(void);
extern void func_021BCBB0(void *);
extern void func_021BB224(char *);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32_021C2724 heap);
void func_021C24A4(Work *w, int v);
void func_021C24D4(u8 *p, int v);
int func_021C24F0(void *obj, int unused, char *args);
int func_021C2604(int task,int *state,int unused,char *p);
int func_021C2724(void *task, int unused, char *output, char *p);
u8 func_021C27D0(S_021C27D0 *s);
void func_021C27D4(S_021C27D4 *s, u8 v);
u8 func_021C27D8(S_021C27D8 *s);
extern const Handler d_021C3C0C[];


void func_021C24A4(Work *w, int v)
{
    if (w->f1342 != v) {
        w->f1341 = w->f1340;
        w->f1343 = 6;
        w->f1342 = v;
        func_02005CBC(v, 0x3f);
        func_02006734(v);
    }
}


/*
 * Stamps the byte at +0x1342 with 0x2A when the selector is 4 and 0x7F otherwise,
 * then copies it down to +0x1341.
 */
void func_021C24D4(u8 *p, int v)
{
    if (v == 4) {
        p[0x1342] = 0x2A;
    } else {
        p[0x1342] = 0x7F;
    }

    p[0x1341] = p[0x1342];
}

int func_021C24F0(void *obj, int unused, char *args)
{
    char *p;
    func_0203064C(1, 0x8021, 0xa4000);
    p = func_0203159C(obj, 0x1360, 0x21);
    func_02082BCC(p, 0, 0x1360);
    func_0203D668((u32_021C24F0)p);
    ((struct Obj01386 *)p)->f8 = ((struct Obj02804 *)args)->f0;
    ((struct Obj01386 *)p)->fC0 = ((struct Obj02804 *)args)->f8;
    *(u32_021C24F0 *)&((struct Obj01386 *)p)->fC4 = ((struct Obj02804 *)args)->f4;
    ((struct Obj01386 *)p)->fCC = func_021BCB8C(((struct Obj01386 *)p)->fC4);
    ((struct Obj01386 *)p)->fC8 = func_02012934(*(struct BigObj * *)&((struct Obj01386 *)p)->fC4);
    ((struct Obj01386 *)p)->f4 = func_0201283C(*(struct BigObj * *)&((struct Obj01386 *)p)->fC4);
    ((struct Obj01386 *)p)->fD8 = (u32_021C24F0)func_0200873C((void *)(((struct Obj02804 *)args)->f8));
    ((struct Obj01386 *)p)->f1D8 = *(u32_021C24F0 *)&((struct Obj02804 *)args)->fC;
    ((struct Obj01386 *)p)->f135C = ((struct Obj02804 *)args)->f49;
    if (((struct Obj02804 *)args)->fC == 1) {
        ((struct Obj02804 *)args)->fC = 0;
        func_021C24D4((u8 *)p, 4);
    } else if (((struct Obj02804 *)args)->fC != 0) {
        func_021C24D4((u8 *)p, 4);
    } else {
        func_021C24D4((u8 *)p, 1);
    }
    ((struct Obj01386 *)p)->f1D0 = 0;
    ((struct Obj01386 *)p)->f1F0 = -1;
    *(char * *)&((struct Obj01386 *)p)->f248 = args;
    func_020434DC(15, 0);
    func_02043598(15, 0);
    func_021BB1A8(p);
    ((struct Obj01386 *)p)->f1CC = 0;
    func_021BDE94(p);
    if (((struct Obj02804 *)args)->fC == 0) func_021BE6F0(p, 1, 2);
    if (func_0203CD98() != 0) {
        func_021BA7D8(p);
        func_0203D34C(1, 0x21);
    }
    return 1;
}

int func_021C2604(int task,int *state,int unused,char *p) {
 u8 r,g,b;
 Handler fn;
 if(func_0203CD98()!=0) {
  switch(func_02157170(1,1)) {
   case 4:
    func_021BC0C4(p);func_021BB0B4(p);func_0203D7B0(0);func_0203D7BC(0);func_021C18C8(p,1,2);
    ((struct Obj00825 *)p)->f1E0=20;((struct Obj00825 *)p)->f1CC=0x39;return 0;
   case 2:
    func_0202223C(0,0);func_0202223C(1,0);((struct Obj00825 *)p)->f1D0=1;return 1;
  }
 }
 if(func_0200FB24()==0) {
  fn=d_021C3C0C[((struct Obj00825 *)p)->f1CC];
  if(fn!=0) {
   *state=fn(p,*state);
   if(*state==2) {func_0202208C(0,0,0,0,6,1,0x21);return 1;}
  }
 }
 if(((struct Obj00825 *)p)->f110!=0) func_0204A600(((struct Obj00825 *)p)->f110);
 if(((struct Obj00825 *)p)->f1B8!=0) {
  func_0201DE00(&r,&g,&b);func_0201DD78(1,2,15);func_020310C4(((struct Obj00825 *)p)->f1C0);func_0201DD78(r,g,b);func_0201C4E4(((struct Obj00825 *)p)->f1B8);
 }
 if(((struct Obj00825 *)p)->f1B4!=0) func_0201C4E4(((struct Obj00825 *)p)->f1B4);
 func_021C2438(p);return 0;
}

int func_021C2724(void *task, int unused, char *output, char *p)
{
    if (!func_021C2438(p)) return 0;
    if (!func_020221A4()) return 0;
    if (func_0203CD98()) func_021BA7F8(p);
    ((struct Obj06360 *)output)->f49 = ((struct Obj03736 *)p)->f135C;
    if (((struct Obj03736 *)p)->f1348) {
        func_0200AE08(((struct Obj03736 *)p)->f1348, ((struct Obj06360 *)output)->f1C);
        func_020307B0(((struct Obj03736 *)p)->f1348);
        ((struct Obj03736 *)p)->f1348 = 0;
    }
    func_021BC0C4(p);
    func_021BDF7C(p);
    ((struct Obj06360 *)output)->f47 = ((struct Obj03736 *)p)->f242;
    ((struct Obj06360 *)output)->fC = ((struct Obj03736 *)p)->f1D0;
    if (func_0203CD98()) ((struct Obj06360 *)output)->f10 = func_02156A3C();
    func_021BCBB0(((struct Obj03736 *)p)->fCC);
    func_021BB224(p);
    func_020315D4(task);
    func_020306F0(33);
    return 1;
}


/*
 * Byte getter at +0x18.
 */
u8 func_021C27D0(S_021C27D0 *s)
{
    return s->f18;
}


/*
 * Byte setter at +0x18, the pair of func_021C27D0.
 */
void func_021C27D4(S_021C27D4 *s, u8 v)
{
    s->f18 = v;
}


/*
 * Byte getter at +0x17.
 */
u8 func_021C27D8(S_021C27D8 *s)
{
    return s->f17;
}
