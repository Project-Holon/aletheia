/*
 * file:     unit_021B6100.c
 * unit:     yes
 * function: func_021B6100, func_021B6434, func_021B64CC, func_021B6500, func_021B66D4, func_021B6804, func_021B6818, func_021B6848, func_021B68D8, func_021B6954, func_021B6994, func_021B69FC, func_021B6A3C, func_021B6A70, func_021B6AAC, func_021B6C08, func_021B6C5C, func_021B6DD0, func_021B7050, func_021B71D4, func_021B734C, func_021B73C4
 * address:  0x021B6100
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082A7C 0x02082A7C arm
 *   func_021E8DC4 0x021E8DC4 thumb ov093
 *   func_021E88CC 0x021E88CC thumb ov093
 *   func_020057C4 0x020057C4 thumb
 *   func_020057AC 0x020057AC thumb
 *   func_02008374 0x02008374 thumb
 *   func_020083AC 0x020083AC thumb
 *   func_020083C8 0x020083C8 thumb
 *   func_021EF958 0x021EF958 thumb ov093
 *   func_021B93E0 0x021B93E0 thumb ov093
 *   func_021BA82C 0x021BA82C thumb ov093
 *   func_0203F258 0x0203F258 arm
 *   func_021D7840 0x021D7840 thumb ov093
 *   func_021CD6EC 0x021CD6EC thumb ov093
 *   func_021D7F88 0x021D7F88 thumb ov093
 *   func_021D8230 0x021D8230 thumb ov093
 *   func_021D4150 0x021D4150 thumb ov093
 *   func_021D804C 0x021D804C thumb ov093
 *   func_021D4270 0x021D4270 thumb ov093
 *   func_021D4230 0x021D4230 thumb ov093
 *   func_021EEA30 0x021EEA30 thumb ov093
 *   func_021B9DB8 0x021B9DB8 thumb ov093
 *   func_021BA094 0x021BA094 thumb ov093
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 *   func_021B9114  0x021B9114  thumb  ov093
 *   func_021BA54C  0x021BA54C  thumb  ov093
 *   func_021BA6C0  0x021BA6C0  thumb  ov093
 *   func_021BA878  0x021BA878  thumb  ov093
 *   func_021BA2E4  0x021BA2E4  thumb  ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021EE894 0x021EE894 thumb ov093
 *   func_0207D55C 0x0207D55C arm
 *   func_0207D534 0x0207D534 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02006740 0x02006740 thumb
 *   func_021EF980 0x021EF980 thumb ov093
 *   func_021D4D5C 0x021D4D5C thumb ov093
 *   func_021D7894 0x021D7894 thumb ov093
 *   func_021BA0CC 0x021BA0CC thumb ov093
 *   func_021B9DE8 0x021B9DE8 thumb ov093
 *   func_021EEA54 0x021EEA54 thumb ov093
 *   func_021D4254 0x021D4254 thumb ov093
 *   func_021D8058 0x021D8058 thumb ov093
 *   func_021E8DF8 0x021E8DF8 thumb ov093
 *   func_021E88F8 0x021E88F8 thumb ov093
 *   func_021B7518 0x021B7518 thumb ov093
 *   func_021B7488 0x021B7488 thumb ov093
 *   func_021B8BEC  0x021B8BEC  thumb  ov093
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02007B44  0x02007B44  thumb
 *   func_02007B20  0x02007B20  thumb
 *   func_02007C20  0x02007C20  thumb
 *   func_021B997C  0x021B997C  thumb  ov093
 *   func_021BA710  0x021BA710  thumb  ov093
 *   func_021BA128  0x021BA128  thumb  ov093
 *   func_021B9E7C  0x021B9E7C  thumb  ov093
 *   func_021B9E38  0x021B9E38  thumb  ov093
 *   func_0201AA18  0x0201AA18  thumb
 *   func_021EE644 0x021EE644 thumb ov093
 *   func_021CD938 0x021CD938 thumb ov093
 *   func_021E8F20 0x021E8F20 thumb ov093
 *   func_021CD95C 0x021CD95C thumb ov093
 *   func_021B9460 0x021B9460 thumb ov093
 *   func_021BA9C8 0x021BA9C8 thumb ov093
 *   func_021CD6F0 0x021CD6F0 thumb ov093
 *   func_021CD978 0x021CD978 thumb ov093
 *   func_021BAA94 0x021BAA94 thumb ov093
 *   func_021BAB40 0x021BAB40 thumb ov093
 *   func_021B83F4 0x021B83F4 thumb ov093
 *   func_021E9034  0x021E9034  thumb  ov093
 *   func_021CD8E0  0x021CD8E0  thumb  ov093
 *   func_021B9674  0x021B9674  thumb  ov093
 *   func_021BAB5C  0x021BAB5C  thumb  ov093
 *   func_021B8B78 0x021B8B78 thumb ov093
 *   d_021EFD1C     0x021EFD1C  data  a4
 *   d_021EFD00     0x021EFD00  data  a4
 */
#include "../../matched/include/Obj01370.h"
#include "../../matched/include/Obj07741.h"
#include "../../matched/include/Obj03184.h"
#include "../../matched/include/Obj06216.h"
#include "../../matched/include/Obj13266.h"
#include "../../matched/include/Obj00661.h"
#include "../../matched/include/Obj13267.h"
#include "../../matched/include/Obj13268.h"
#include "../../matched/include/Obj01230.h"
#include "../../matched/include/Obj00965.h"
#include "../../matched/include/Obj00886.h"
#include "../../matched/include/Obj02772.h"
#include "../../matched/include/Obj00817.h"
#include "../../matched/include/Obj00887.h"

#define INIT(f) init(a, p, f)
struct S_021B6100;
struct S020315D4;
struct PerapVoice;
struct Sub02007AC8Entry;
struct Big;
struct A;
struct B;
struct Scene;
struct QA;
struct Copy24;
struct T_021B66D4;
struct QB;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

struct Lcg64
{
  u64 x;
  u64 mul;
  u64 add;
};

struct FlagByte
{
  u8 a0 : 1;
  u8 a1 : 1;
  u8 a2 : 1;
  u8 a3 : 1;
  u8 a4 : 1;
  u8 a5 : 1;
  u8 a6 : 1;
  u8 a7 : 1;
};

typedef int (*CallbackFn)(u32 *, void *);

typedef struct Callback
{
  CallbackFn first;
  CallbackFn second;
  void *object;
  u32 state;
} Callback;

struct Obj0203159C
{
  u32 pad00[5];
  void *buffer;
};

struct P_021B6100 {
    u8 pad00[0x88];
    int f88;
    u8 pad8c[0x35];
    u8 fc1_0 : 1;
    u8 fc1_1 : 1;
};

struct S_021B6100 {
    struct P_021B6100 *f00;
    u8 pad04[0x42c];
    int f430;
    int f434;
    int f438;
    u8 pad43c[0x14];
    Callback cb;
    u32 f460;
    int (*f464)(struct S_021B6100 *);
};

typedef struct { u8 pad[0x473]; u8 low:5; u8 flag5:1; u8 flag6:1; u8 flag7:1; } Flags;

typedef struct { u8 pad[0x460]; volatile int fade; } Fade;

struct P_021B66D4 {
    u8 pad00[0x44];
    u8 f44[4];
};

struct T_021B66D4 {
    u8 pad00[0x21];
    u8 f21;
    u8 pad22[0x36];
    u32 f58;
};

struct T_021B68D8 {
    u8 pad00[0x24];
    void *f24[4];
};

struct S_021B66D4 {
    u32 f00;
    u32 f04;
    u8 pad08[0x1a];
    u8 f22;
    u8 pad23;
    void *f24[4];
};

struct S_021B6C08 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10[4];
    u8 pad20[0xa8];
    u8 fc8[0xe8];
};

struct T_021B734C {
    u8 pad00[0x21];
    u8 f21;
};

struct S_021B734C {
    struct T_021B734C *f00;
    u8 pad04[0x424];
    u8 f428[6];
    u8 pad42e[0x32];
    u32 f460;
    u8 pad464[7];
    u8 f46b;
    u8 f46c;
    u8 f46d;
};

struct T_021B73C4 {
    u8 pad00[0x21];
    u8 f21;
    u8 f22;
};

struct S_021B73C4 {
    struct T_021B73C4 *f00;
    u8 pad04[0x424];
    u8 f428[6];
    u8 pad42e[0x32];
    u32 f460;
    u8 pad464[7];
    u8 f46b;
    u8 f46c;
    u8 f46d;
    u8 pad46e[3];
    u8 f471;
};

extern void func_0203064C(u32, u32, u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082A7C(u32, void *, u32);
extern void func_021E8DC4(unsigned short heap);
extern void func_021E88CC(void);
extern int func_020057C4(void);
extern void func_020057AC(void);
extern u32 func_02008374(int);
extern u32 func_020083AC(void *);
extern u32 func_020083C8(void *);
extern void *func_021EF958(u32);
extern void func_021B93E0(char *, u32, u32);
extern void func_021BA82C(char *);
extern void func_0203F258(struct Lcg64 *);
extern void func_021D7840(struct Lcg64 *, u32);
extern void func_021CD6EC(void);
extern u32 func_021D7F88(u8 *);
extern void func_021D8230(u8 *p);
extern void func_021D4150(void *, u16, u16);
extern void func_021D804C(u32);
extern int func_021D4270(void);
extern int func_021D4230(void);
extern void func_021EEA30(int v);
extern void func_021B9DB8(char *p);
extern void func_021BA094(struct S_021B6100 *p);
extern void func_021BA1B4(char **p, int i);
extern u8 func_021B9114(u8 **p);
extern int func_021BA54C(char *p);
extern void func_021BA6C0(char *p);
extern void func_021BA878(u8 *p);
extern void func_021BA2E4(char *p);
extern int func_021B8B9C(unsigned char *p, unsigned char k);
extern int func_021EE894(void *,u8);
extern void func_02005E30(u32);
extern int func_02005E50(void);
extern void func_02005D28(void);
extern int func_0207D55C(volatile u16 *);
extern void func_0207D534(volatile u16 *, int);
extern void func_021EF980(void *);
extern u32 func_020307B0(void *p);
extern void func_021D4D5C(void *);
extern void func_021D7894(void);
extern void func_021BA0CC(struct S_021B6100 *);
extern void func_021B9DE8(char *);
extern void func_021EEA54(void);
extern void func_021D4254(void);
extern void func_021D8058(void);
extern void func_021E8DF8(void);
extern void func_02005CA4(int, u32);
extern void func_02006740(void);
extern void func_02029F6C(void);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int);
extern void func_021E88F8(void);
extern int func_021B7518(u32 *, void *);
extern int func_021B7488(u32 *, void *);
extern u8 func_021B8BEC(u8 *s, u32 k, u8 n);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02007AC8Entry *func_02007B44(void *sys);
extern void *func_02007B20(u32 heap);
extern void func_02007C20(struct PerapVoice *dest, const struct PerapVoice *src);
extern int func_021B997C(u8 *p, unsigned int i);
extern u8 func_021BA710(int a, int b);
extern void func_021BA128(struct S_021B66D4 *p, int i, void *x);
extern void func_021B9E7C(struct A *p, struct B *src);
extern void func_021B9E38(char *p, int a, int b);
extern u32 func_0201AA18(void *p);
extern void func_021EE644(void *, int, int);
extern void func_021CD938(u8 *p, void *a);
extern struct Scene *func_021E8F20(void *,void *,u32,int,u16);
extern void func_021CD95C(struct QA *p, u32 v);
extern void func_021B9460(char *a, char *b, u8 c);
extern u8 *func_021BA9C8(void *a, struct Copy24 *b, void *c, int d, u16 heap);
extern u8 *func_021CD6F0(u8 *a, u8 *b, int c, int d, u16 idx, u16 kind, u8 e, int f, int g, struct Copy24 *h, u16 heap);
extern u32 func_021CD978(struct QB *p);
extern void func_021BAA94(char *p, int b, u8 c, u8 d);
extern void func_021BAB40(char *p);
extern int func_021B83F4(int a);
extern void func_021E9034(char *p);
extern void func_021CD8E0(u8 *p);
extern void func_021B9674(char *p);
extern void func_021BAB5C(int a);
extern unsigned int func_021B8B78(unsigned char *p, int k);
int func_021B6100(struct Obj0203159C *owner, u32 *state, u8 *q, u8 *p);
int func_021B6434(int a0, int a1, int a2, struct S_021B6100 *s);
int func_021B64CC(u8 *p);
int func_021B6500(int handle, u32 *state, int unused, u8 *p);
void func_021B66D4(Callback *a, u8 *p, u8 *q);
void func_021B6804(Callback *a, u8 *p, u8 *q);
unsigned int func_021B6818(unsigned int *p);
void func_021B6848(u8 *s, struct T_021B66D4 *t);
void func_021B68D8(u8 *s, struct T_021B68D8 *t);
void func_021B6954(int a, int b);
int func_021B6994(struct S_021B66D4 **pp, u32 b);
void func_021B69FC(int a, char *b);
void func_021B6A3C(unsigned char *p, unsigned char *q);
void func_021B6A70(unsigned char *p,unsigned char *q,int r);
int func_021B6AAC(u32 *unused, void *arg);
int func_021B6C08(u32 *a0, void *arg);
int func_021B6C5C(u32 *unused, void *arg);
int func_021B6DD0(u32 *unused, void *arg);
int func_021B7050(u32 *unused, void *arg);
int func_021B71D4(u32 *unused, void *arg);
int func_021B734C(u32 *pp, void *arg);
int func_021B73C4(u32 *pp, void *arg);




int func_021B6100(struct Obj0203159C *owner, u32 *state, u8 *q, u8 *p)
{
  u32 flag;
  u32 i;
  u32 ready;
  int done;
  struct S_021B6100 *s;
  Callback *cb;
  switch (*state)
  {
    case 0:
      func_0203064C(1, 0x12, 0x20000);
      func_0203064C(1, 0x14, 0x8000);
      func_0203064C(1, 0x13, 0xab100);
      p = func_0203159C(owner, 0x474, 0x12);
      func_02082A7C(0, p, 0x474);
      func_021E8DC4(0x13);
      func_021E88CC();
      if (!func_020057C4())
      {
        func_020057AC();
        p[0x473] |= 0x80;
      }
      *((u16 *) (p + 0x468)) = 0x12;
      *((u8 **) p) = q;
      q[0x90] = 6;
      *((u32 *) (p + 0xc0)) = *((u32 *) ((*((u8 **) p)) + 0x34));
      *((u16 *) (p + 0x440)) = *((u16 *) ((*((u8 **) p)) + 0x74));
      *((u16 *) (p + 0x442)) = *((u16 *) ((*((u8 **) p)) + 0x76));
      ((struct FlagByte *) (p + 0x473))->a3 = 0;
      ((struct FlagByte *) (p + 0x473))->a4 = 0;
      ((struct FlagByte *) (p + 0x473))->a0 = 0;
      ((struct FlagByte *) (p + 0x473))->a1 = 0;
      ((struct FlagByte *) (p + 0x473))->a5 = 0;
      ((struct FlagByte *) (p + 0x473))->a6 = 0;
      p[0x471] = 0;
      *((u32 *) (p + 0x464)) = 0;
      flag = 0;
      *((u32 *) (p + 4)) = 0;
      *((u32 *) (p + 0x444)) = 7;
      *((u32 *) (p + 0x43c)) = func_02008374(*((int *) ((*((u8 **) p)) + 0x5c)));
      if (func_020083AC(*((void **) (q + 0x5c))) == 0)
        flag = 1;
      ((struct FlagByte *) (p + 0x473))->a2 = (u8) flag;
      *((void **) (p + 0x2bc)) = func_021EF958(*((u16 *) (p + 0x468)));
      func_021B93E0(((char *) p) + 0xc8, (u32) p, 0);
      func_021B93E0(((char *) p) + 0x1b0, (u32) p, 1);
      func_021BA82C(*((char **) p));
      *((u32 *) (p + 0x2c0)) = 0;
      *((u32 *) (p + 0x2c4)) = 0;
      if ((*((u8 **) p))[0x23] == 0)
        func_0203F258((struct Lcg64 *) (p + 0x3f0));
      else
        *((struct Lcg64 *) (p + 0x3f0)) = *((struct Lcg64 *) (q + 0x9c));
      func_021D7840((struct Lcg64 *) (p + 0x3f0), *((u16 *) (p + 0x468)));
      func_021CD6EC();
      *((u32 *) (p + 0x430)) = func_021D7F88(q);
      *((u32 *) (p + 0x434)) = 0;
      *((u32 *) (p + 0x438)) = 0;
      if ((*((u8 **) p))[0x23] == 0)
      {
        for (i = 0; i < 4; i++)
          (*((u8 **) p))[0x44 + i] = 0;
      }
      func_021D8230(p + 0x448);
      ready = func_020083C8(*((void **) (q + 0x5c)));
      flag = 0;
      if (ready != 0)
        flag = 1;
      p[0x46f] = flag;
      func_021D4150(*((void **) (q + 0x1c)), *((u16 *) (q + 0x84)), 0x14);
      func_021D804C(0x12);
      (*state)++;
      break;

    case 1:
      if (((*((void **) ((*((u8 **) p)) + 0x1c))) != 0) && func_021D4270())
      {
        ((struct FlagByte *) (p + 0x473))->a0 = 1;
        ((struct FlagByte *) (p + 0x473))->a1 = 1;
        return 1;
      }
      if (func_021D4230())
      {
        func_021EEA30((*((u8 **) p))[0x20]);
        func_021B66D4((Callback *) (p + 0x450), p, *((u8 **) p));
        *((u32 *) (p + 0x460)) = 0;
        func_021B9DB8((char *)p);
        func_021BA094((struct S_021B6100 *)p);
        (*state)++;
      }
      break;

    case 2:
      s = (struct S_021B6100 *)p;
      if (s->cb.first != 0)
      {
        if (s->cb.first(&s->cb.state, s->cb.object))
        {
          s->cb.first = 0;
          s->cb.state = 0;
        }
        done = 0;
      }
      else if (s->cb.second != 0)
      {
        if (s->cb.second(&s->cb.state, s->cb.object))
        {
          s->cb.second = 0;
          done = 1;
        }
        else
          done = 0;
      }
      else
        done = 1;
      if (done != 0)
      {
        if (((struct FlagByte *) (p + 0x473))->a0 != 0)
        {
          ((struct FlagByte *) (p + 0x473))->a1 = 1;
          return 1;
        }
        if ((*((u32 *) (*((u8 **) p)))) != 4)
          func_021BA1B4((char **)p, 4);
        return 1;
      }
      break;
  }

  return 0;
}





int func_021B6434(int a0, int a1, int a2, struct S_021B6100 *s)
{
    u32 t;
    u32 r;

    if (s->f464 == 0) {
        return 1;
    }
    if (s->f464(s) != 0) {
        if (func_021B9114((u8 **)s) == 0) {
            t = func_021BA54C((char *)s);
            func_021BA6C0((char *)s);
            func_021BA878((u8 *)s);
            func_021BA2E4((char *)s);
            switch (t) {
            case 1:
                s->f00->f88 = s->f430 + s->f434;
                break;
            case 0:
            case 2:
                s->f00->f88 = -s->f438;
                break;
            }
        } else {
            r = func_021B64CC((u8 *)s);
            s->f00->fc1_1 = r;
        }
        return 1;
    }
    return 0;
}



int func_021B64CC(u8 *p) { unsigned int i; for(i=0;i<4;i++) { if(func_021B8B9C(p,i)) { if(!func_021EE894(p+0x2c8,i)) return 0; } } return 1; }


static inline int poll(struct S_021B6100 *s)
{
    if (s->cb.first) {
        if (s->cb.first(&s->cb.state, s->cb.object)) {
            s->cb.first = 0; s->cb.state = 0;
        }
        return 0;
    }
    if (s->cb.second) {
        if (s->cb.second(&s->cb.state, s->cb.object)) s->cb.second = 0;
        else return 0;
    }
    return 1;
}

/*
 * witness: ov093 leaf shards 021EF980, 021D4D5C, 021EEA54 and the 021D8058/021D805C unit resolve all four former wildcards.
 * lever: cache each re-read fade value for the comparison and setter; associate callback integer offsets before adding the base.
 * volatile: fade field re-read at 021B6584 and 021B659C across hardware-brightness calls.
 */
int func_021B6500(int handle, u32 *state, int unused, u8 *p)
{
    switch (*state) {
    case 0:
        if (!((Flags *)p)->flag5) func_02005E30(30);
        ((Fade *)p)->fade = 0;
        if (func_0207D55C((volatile u16 *)0x0400006c) != 0) {
            ((Fade *)p)->fade = -16;
            func_0207D534((volatile u16 *)0x0400006c, -16);
            func_0207D534((volatile u16 *)0x0400106c, -16);
            *state += 2;
        } else *state += 1;
        break;
    case 1: {
        int v;
        v = ((Fade *)p)->fade;
        if (v > -16) {
            ((Fade *)p)->fade = v - 1;
            if (func_0207D55C((volatile u16 *)0x0400006c) > (v = ((Fade *)p)->fade))
                func_0207D534((volatile u16 *)0x0400006c, v);
            if (func_0207D55C((volatile u16 *)0x0400106c) > (v = ((Fade *)p)->fade))
                func_0207D534((volatile u16 *)0x0400106c, v);
        } else *state += 1;
        break;
    }
    case 2:
        if (!((Flags *)p)->flag5) {
            if (func_02005E50() == 0) { func_02005D28(); *state += 1; }
        } else *state += 1;
        break;
    case 3:
        if (((struct Obj01370 *)p)->f2BC) { func_021EF980(((struct Obj01370 *)p)->f2BC); ((struct Obj01370 *)p)->f2BC = 0; }
        if (((struct Obj01370 *)p)->f2C0) { func_020307B0(((struct Obj01370 *)p)->f2C0); ((struct Obj01370 *)p)->f2C0 = 0; }
        if (((struct Obj01370 *)p)->f2C4) { func_021D4D5C(((struct Obj01370 *)p)->f2C4); ((struct Obj01370 *)p)->f2C4 = 0; }
        func_021D7894();
        func_021BA0CC((struct S_021B6100 *)p);
        func_021B9DE8((char *)p);
        func_021B6804((Callback *)(p + 0x450), p, *(u8 * *)&((struct Obj01370 *)p)->f0);
        *state += 1;
        break;
    case 4:
        if (poll((struct S_021B6100 *)p)) {
            func_021EEA54(); func_021D4254(); func_021D8058();
            *state += 1;
        }
        break;
    case 5:
        func_021E8DF8();
        func_02005CA4(1, 62);
        func_02006740();
        if (((Flags *)p)->flag7) { func_02029F6C(); ((Flags *)p)->flag7 = 0; }
        func_020315D4((struct S020315D4 *)handle);
        func_020306F0(19);
        func_020306F0(20);
        func_020306F0(18);
        func_021E88F8();
        return 1;
    }
    return 0;
}



static inline void init(Callback *a, u8 *p, CallbackFn f)
{
    a->first = f; a->second = 0; a->object = p; a->state = 0;
}



void func_021B66D4(Callback *a, u8 *p, u8 *q)
{
    u32 i;
    for (i = 0; i < 6; i++) p[0x428 + i] = 4;
    if (!q[0x20]) {
        switch (((struct Obj07741 *)q)->f4) {
        case 0: INIT(func_021B6AAC); return;
        case 1:
            if (!q[0x22]) { INIT(func_021B6C5C); return; }
            else { INIT(func_021B6DD0); return; }
        case 2: INIT(func_021B7050); return;
        case 3: INIT(func_021B71D4); return;
        default: INIT(func_021B6AAC); return;
        }
    } else {
        switch (((struct Obj07741 *)q)->f4) {
        case 0: INIT(func_021B734C); return;
        case 1: INIT(func_021B73C4); return;
        case 2: INIT(func_021B7518); return;
        case 3: INIT(func_021B7488); return;
        default: INIT(func_021B6AAC); return;
        }
    }
}



/*
 * size: 324
 * lever: initializer stores first, second, object, state; object-first reallocates all tails.
 */
void func_021B6804(Callback *a, u8 *p, u8 *q)
{
    INIT(func_021B6C08);
}




unsigned int func_021B6818(unsigned int *p) { switch (*p) { case 0: return 0; case 1: return 0; case 2: return 0; case 3: return 1; default: return 0; } }





void func_021B6848(u8 *s, struct T_021B66D4 *t)
{
    u32 i;
    u32 v;
    u8 tmp[4];
    u8 k = t->f21;

    i = 0;
    s[0x46c] = k;
    s[0x46d] = func_021B8BEC(s, k, 0);
    func_021B68D8(s, (struct T_021B68D8 *)t);
    if (func_021B9114((u8 **)s) == 0) {
        v = (u32)func_02007B44(func_02012EBC((void *)t->f58));
        ((struct Obj03184 *)s)->f3E0 = (u32)func_02007B20(((struct Obj03184 *)s)->f468);
        func_02007C20((struct PerapVoice *)(((struct Obj03184 *)s)->f3E0), (const struct PerapVoice *)v);
        (*(struct P_021B66D4 * *)&((struct Obj03184 *)s)->f0)->f44[0] = func_021B997C(s, i);
    } else {
        for (i = 0; i < 4; i++) {
            tmp[(int)func_021BA710(s[0x46c], (u8)i)] = (*(struct P_021B66D4 * *)&((struct Obj03184 *)s)->f0)->f44[i];
        }
        for (i = 0; i < 4; i++) {
            (*(struct P_021B66D4 * *)&((struct Obj03184 *)s)->f0)->f44[i] = tmp[i];
        }
    }
}




void func_021B68D8(u8 *s, struct T_021B68D8 *t)
{
    int a, b, c, d;

    a = func_021BA710(s[0x46c], 0);
    b = func_021BA710(s[0x46c], 1);
    func_021BA128((struct S_021B66D4 *)s, 0, t->f24[a]);
    func_021BA128((struct S_021B66D4 *)s, 1, t->f24[b]);
    c = func_021BA710(s[0x46c], 2);
    d = func_021BA710(s[0x46c], 3);
    if (t->f24[c] != 0) {
        func_021BA128((struct S_021B66D4 *)s, 2, t->f24[c]);
    }
    if (t->f24[d] != 0) {
        func_021BA128((struct S_021B66D4 *)s, 3, t->f24[d]);
    }
}




void func_021B6954(int a, int b)
{
    char *p = (char *)a;
    int base = ((struct Obj06216 *)p)->f0;
    int idx = func_021BA710(((struct Obj06216 *)p)->f46C, b);
    char *q = (char *)(a + 0x20) + b * 0x28;
    char *e = (char *)base + idx * 4;
    int *r = (int *)((struct Obj13266 *)e)->f48;
    if (*r != 0)
        func_021B9E7C((struct A *)((int)q), (struct B *)((int)r));
    else
        func_021B9E38((char *)((int)q), ((struct Obj06216 *)p)->f468, ((struct Obj13266 *)e)->f34);
}




int func_021B6994(struct S_021B66D4 **pp, u32 b)
{
    struct S_021B66D4 *p = *pp;
    void *q;

    switch (p->f04) {
    case 0:
        return 1;
    case 3:
        return 1;
    case 2:
        return 3;
    case 1:
        if (p->f22 == 0) {
            return 2;
        }
        if (p->f00 == 3) {
            return 1;
        }
        q = p->f24[(u8)((b + 2) & 3)];
        if (q != 0 && (int)func_0201AA18(q) > 0) {
            return 1;
        }
        return 2;
    }
    return 1;
}



void func_021B69FC(int a, char *b)
{
    if (((struct Obj00661 *)b)->f23 == 0) {
        func_021B9E38((char *)(a + 0x20), ((struct Obj06216 *)a)->f468, ((struct Obj06216 *)a)->fC0);
        func_021B9E7C((struct A *)(a + 0x48), (struct B *)(((struct Obj00661 *)b)->f4C));
    } else {
        func_021B6954(a, 0);
        func_021B6954(a, 1);
    }
}


void func_021B6A3C(unsigned char *p, unsigned char *q) { if(q[0x23]) { func_021EE644(p+0x2c8, ((struct Obj00661 *)q)->f94, ((struct Obj00661 *)q)->f98); func_021CD938(((struct Obj13267 *)p)->f10,p+0x2c8); func_021CD938(((struct Obj13267 *)p)->f14,p+0x2c8); } }


/*
 * extent: final two zero bytes are alignment padding before the next labelled function.
 */
void func_021B6A70(unsigned char *p,unsigned char *q,int r) { void *v; struct Scene *s; if(q[0x23]) v=*(void **)(p+0x10+q[0x21]*4); else v=((struct Obj13268 *)p)->f10; s=func_021E8F20(p,v,(u32)(p+0xc8),r,0x13); *(struct Scene * *)&((struct Obj13268 *)p)->f4=s; func_021CD95C(v,(u32)s); }


int func_021B6AAC(u32 *unused, void *arg)
{
    u8 *p = arg;
    u8 *q;
    int t;
    q = *(u8 * *)&((struct Obj01230 *)p)->f0;
    t = func_021B6818((unsigned int *)q);
    p[0x46b] = 2;
    p[0x428] = 0;
    p[0x429] = 1;
    func_021B6848(p, (struct T_021B66D4 *)q);
    func_021B93E0((char *)p + 0xc8, (u32)p, 0);
    func_021B9460((char *)(p + 0xc8), (char *)p, 0);
    func_021B9460((char *)(p + 0xc8), (char *)p, 1);
    func_021B93E0((char *)p + 0x1b0, (u32)p, 1);
    func_021B9460((char *)(p + 0x1b0), (char *)p, 0);
    func_021B9460((char *)(p + 0x1b0), (char *)p, 1);
    ((struct Obj01230 *)p)->f8 = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj01230 *)p)->f468);
    p[0x46e] = 1;
    func_021B69FC((int)p, (char *)q);
    ((struct Obj01230 *)p)->f10 = (int)func_021CD6F0(p, p + 0xc8, 0, ((struct Obj00661 *)q)->f1C, 0, 1, 0, t, q[0x23], (struct Copy24 *)(p + 0x3f0), ((struct Obj01230 *)p)->f468);
    ((struct Obj01230 *)p)->f14 = (int)func_021CD6F0(p, p + 0xc8, 0, ((struct Obj00661 *)q)->f1C, 1, 1, 1, t, q[0x23], (struct Copy24 *)(p + 0x3f0), ((struct Obj01230 *)p)->f468);
    func_021B6A3C(p, q);
    func_021B6A70(p, q, t);
    func_021BAA94((char *)(((struct Obj01230 *)p)->f8), func_021CD978((struct QB *)(((struct Obj01230 *)p)->f10)), 0, 1);
    func_021BAA94((char *)(((struct Obj01230 *)p)->f8), func_021CD978((struct QB *)(((struct Obj01230 *)p)->f14)), 1, 1);
    func_021BAB40((char *)(((struct Obj01230 *)p)->f8));
    ((struct Obj01230 *)p)->f464 = (u32)func_021B83F4;
    return 1;
}



int func_021B6C08(u32 *a0, void *arg)
{
    struct S_021B6C08 *s = arg;
    u32 i;

    if (s->f04 != 0) {
        func_021E9034((char *)s->f04);
        s->f04 = 0;
    }
    for (i = 0; i < 4; i++) {
        if (s->f10[i] != 0) {
            func_021CD8E0((u8 *)s->f10[i]);
        }
    }
    func_021B9674((char *)((u8 *)s + 0xc8));
    func_021B9674((char *)((u8 *)s + 0x1b0));
    if (s->f08 != 0) {
        func_021BAB5C(s->f08);
    }
    if (s->f0c != 0) {
        func_021BAB5C(s->f0c);
    }
    return 1;
}


int func_021B6C5C(u32 *unused, void *arg)
{
    u8 *p = arg;
    u8 *q;
    int t;
    q = *(u8 * *)&((struct Obj00965 *)p)->f0;
    t = func_021B6818((unsigned int *)q);
    p[0x46c] = 0;
    p[0x46b] = 2;
    p[0x428] = 0;
    p[0x429] = 1;
    p[0x42a] = 0;
    p[0x42b] = 1;
    func_021B6848(p, (struct T_021B66D4 *)q);
    func_021B93E0((char *)p + 0xc8, (u32)p, 0);
    func_021B9460((char *)(p + 0xc8), (char *)p, 0);
    func_021B9460((char *)(p + 0xc8), (char *)p, 1);
    func_021B93E0((char *)p + 0x1b0, (u32)p, 1);
    func_021B9460((char *)(p + 0x1b0), (char *)p, 0);
    func_021B9460((char *)(p + 0x1b0), (char *)p, 1);
    func_021B69FC((int)p, (char *)q);
    ((struct Obj00965 *)p)->f8 = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj00965 *)p)->f468);
    p[0x46e] = 1;
    ((struct Obj00965 *)p)->f10 = (int)func_021CD6F0(p, p + 0xc8, 0, ((struct Obj00661 *)q)->f1C, 0, 2, 0, t, q[0x23], (struct Copy24 *)(p + 0x3f0), ((struct Obj00965 *)p)->f468);
    ((struct Obj00965 *)p)->f14 = (int)func_021CD6F0(p, p + 0xc8, 0, ((struct Obj00661 *)q)->f1C, 1, 2, 1, t, q[0x23], (struct Copy24 *)(p + 0x3f0), ((struct Obj00965 *)p)->f468);
    func_021B6A3C(p, q);
    func_021B6A70(p, q, t);
    func_021BAA94((char *)(((struct Obj00965 *)p)->f8), func_021CD978((struct QB *)(((struct Obj00965 *)p)->f10)), 0, 2);
    func_021BAA94((char *)(((struct Obj00965 *)p)->f8), func_021CD978((struct QB *)(((struct Obj00965 *)p)->f14)), 1, 2);
    func_021BAB40((char *)(((struct Obj00965 *)p)->f8));
    ((struct Obj00965 *)p)->f464 = (u32)func_021B83F4;
    return 1;
}


/*
 * lever: the boolean passed narrow is an int local; t declared after desc puts t at sp+0x1c.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`desc = p;` before `desc = p + 0xc8;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
int func_021B6DD0(u32 *unused, void *arg)
{
    u8 *p = arg;
    u8 *q;
    int i;
    u8 k;
    int b;
    u8 *desc;
    u8 *table;
    int t;
    q = *(u8 * *)&((struct Obj00886 *)p)->f0;
    t = (int)func_021B6818((unsigned int *)q);
    p[0x46c] = 0;
    p[0x46b] = 2;
    p[0x428] = 0;
    p[0x42a] = 0;
    p[0x429] = 1;
    p[0x42b] = 1;
    switch (q[0x22]) {
    case 0: break;
    case 1: case 2: case 3:
        p[0x42a] = 2;
        p[0x42b] = 3;
        p[0x46b] = 4;
        break;
    case 4:
        p[0x42b] = 3;
        p[0x46b] = 3;
        break;
    }
    func_021B6848(p, (struct T_021B66D4 *)q);
    func_021B93E0((char *)p + 0xc8, (u32)p, 0);
    func_021B93E0((char *)p + 0x1b0, (u32)p, 1);
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(p, i)) {
            func_021B9460((char *)(p + 0xc8), (char *)p, i);
            func_021B9460((char *)(p + 0x1b0), (char *)p, i);
        }
    }
    if (!q[0x23]) {
        func_021B9E38((char *)((int)(p + 0x20)), ((struct Obj00886 *)p)->f468, ((struct Obj00886 *)p)->fC0);
        func_021B9E7C((struct A *)((int)(p + 0x48)), (struct B *)(((struct Obj02772 *)q)->f4C));
        if (func_021B8B9C(p, 2)) func_021B9E7C((struct A *)((int)(p + 0x70)), (struct B *)(((struct Obj02772 *)q)->f50));
        if (func_021B8B9C(p, 3)) func_021B9E7C((struct A *)((int)(p + 0x98)), (struct B *)(((struct Obj02772 *)q)->f54));
    } else {
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(p, i)) func_021B6954((int)p, (u8)i);
        }
    }
    ((struct Obj00886 *)p)->f8 = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj00886 *)p)->f468);
    p[0x46e] = 1;
    table = p + 0x3f0;
    desc = p + 0xc8;
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(p, i)) {
            k = func_021B8B78(p, (unsigned char)i);
            b = 0;
            if (i != 0) b = 1;
            *(int *)(p + i * 4 + 0x10) = (int)func_021CD6F0(p, desc, 0, ((struct Obj02772 *)q)->f1C, i, (u8)k, b, t, (u8)q[0x23], (struct Copy24 *)table, ((struct Obj00886 *)p)->f468);
        }
    }
    if (q[0x23]) {
        func_021EE644(p + 0x2c8, ((struct Obj02772 *)q)->f94, ((struct Obj02772 *)q)->f98);
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(p, i)) func_021CD938((u8 *)(*(int *)(p + i * 4 + 0x10)), p + 0x2c8);
        }
    }
    func_021B6A70(p, q, t);
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(p, i)) {
            k = func_021B8B78(p, (unsigned char)i);
            func_021BAA94((char *)(((struct Obj00886 *)p)->f8), func_021CD978((struct QB *)(*(int *)(p + i * 4 + 0x10))), i, k);
        }
    }
    func_021BAB40((char *)(((struct Obj00886 *)p)->f8));
    ((struct Obj00886 *)p)->f464 = (u32)func_021B83F4;
    return 1;
}


int func_021B7050(u32 *unused, void *arg)
{
    u8 *p = arg;
    u8 *q;
    int t;
    q = *(u8 * *)&((struct Obj00817 *)p)->f0;
    t = func_021B6818((unsigned int *)q);
    p[0x46b] = 2;
    p[0x46e] = 1;
    p[0x428] = 0;
    p[0x429] = 1;
    p[0x42a] = 0;
    p[0x42b] = 1;
    p[0x42c] = 0;
    p[0x42d] = 1;
    func_021B6848(p, (struct T_021B66D4 *)q);
    func_021B93E0((char *)p + 0xc8, (u32)p, 0);
    func_021B9460((char *)(p + 0xc8), (char *)p, 0);
    func_021B9460((char *)(p + 0xc8), (char *)p, 1);
    func_021B93E0((char *)p + 0x1b0, (u32)p, 1);
    func_021B9460((char *)(p + 0x1b0), (char *)p, 0);
    func_021B9460((char *)(p + 0x1b0), (char *)p, 1);
    func_021B69FC((int)p, (char *)q);
    ((struct Obj00817 *)p)->f8 = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj00817 *)p)->f468);
    p[0x46e] = 1;
    ((struct Obj00817 *)p)->f10 = (int)func_021CD6F0(p, p + 0xc8, 0, ((struct Obj00661 *)q)->f1C, 0, 3, 0, t, q[0x23], (struct Copy24 *)(p + 0x3f0), ((struct Obj00817 *)p)->f468);
    ((struct Obj00817 *)p)->f14 = (int)func_021CD6F0(p, p + 0xc8, 0, ((struct Obj00661 *)q)->f1C, 1, 3, 1, t, q[0x23], (struct Copy24 *)(p + 0x3f0), ((struct Obj00817 *)p)->f468);
    func_021B6A3C(p, q);
    func_021B6A70(p, q, t);
    func_021BAA94((char *)(((struct Obj00817 *)p)->f8), func_021CD978((struct QB *)(((struct Obj00817 *)p)->f10)), 0, 3);
    func_021BAA94((char *)(((struct Obj00817 *)p)->f8), func_021CD978((struct QB *)(((struct Obj00817 *)p)->f14)), 1, 3);
    func_021BAB40((char *)(((struct Obj00817 *)p)->f8));
    ((struct Obj00817 *)p)->f464 = (u32)func_021B83F4;
    return 1;
}


int func_021B71D4(u32 *unused, void *arg)
{
    u8 *p = arg;
    u8 *q;
    int t;
    q = *(u8 * *)&((struct Obj00887 *)p)->f0;
    t = func_021B6818((unsigned int *)q);
    p[0x46b] = 2;
    p[0x428] = 0;
    p[0x429] = 1;
    p[0x42a] = 0;
    p[0x42b] = 1;
    p[0x42c] = 0;
    p[0x42d] = 1;
    func_021B6848(p, (struct T_021B66D4 *)q);
    func_021B93E0((char *)p + 0xc8, (u32)p, 0);
    func_021B9460((char *)(p + 0xc8), (char *)p, 0);
    func_021B9460((char *)(p + 0xc8), (char *)p, 1);
    func_021B93E0((char *)p + 0x1b0, (u32)p, 1);
    func_021B9460((char *)(p + 0x1b0), (char *)p, 0);
    func_021B9460((char *)(p + 0x1b0), (char *)p, 1);
    ((struct Obj00887 *)p)->f8 = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj00887 *)p)->f468);
    p[0x46e] = 1;
    func_021B69FC((int)p, (char *)q);
    ((struct Obj00887 *)p)->f10 = (int)func_021CD6F0(p, p + 0xc8, 0, ((struct Obj00661 *)q)->f1C, 0, 1, 0, t, q[0x23], (struct Copy24 *)(p + 0x3f0), ((struct Obj00887 *)p)->f468);
    ((struct Obj00887 *)p)->f14 = (int)func_021CD6F0(p, p + 0xc8, 0, ((struct Obj00661 *)q)->f1C, 1, 1, 1, t, q[0x23], (struct Copy24 *)(p + 0x3f0), ((struct Obj00887 *)p)->f468);
    func_021B6A3C(p, q);
    func_021B6A70(p, q, t);
    func_021BAA94((char *)(((struct Obj00887 *)p)->f8), func_021CD978((struct QB *)(((struct Obj00887 *)p)->f10)), 0, 1);
    func_021BAA94((char *)(((struct Obj00887 *)p)->f8), func_021CD978((struct QB *)(((struct Obj00887 *)p)->f14)), 1, 1);
    func_021BAB40((char *)(((struct Obj00887 *)p)->f8));
    ((struct Obj00887 *)p)->f464 = (u32)func_021B83F4;
    return 1;
}


extern int (*d_021EFD1C[7])(struct S_021B734C *, u32 *);



int func_021B734C(u32 *pp, void *arg)
{
    struct S_021B734C *s = arg;
    if (*pp == 0) {
        s->f46b = 2;
        s->f428[0] = 0;
        s->f428[1] = 1;
        s->f46c = s->f00->f21;
        s->f46d = func_021B8BEC((u8 *)s, s->f46c, 0);
        *pp = *pp + 1;
        return 0;
    }
    if (*pp < 7) {
        if (d_021EFD1C[*pp](s, &s->f460) != 0) {
            s->f460 = 0;
            *pp = *pp + 1;
        }
        return 0;
    }
    return 1;
}


extern int (*d_021EFD00[7])(struct S_021B73C4 *, u32 *);



int func_021B73C4(u32 *pp, void *arg)
{
    struct S_021B73C4 *s = arg;
    if (*pp == 0) {
        switch (s->f00->f22) {
        case 0:
        default:
            s->f46b = 2;
            s->f428[0] = 0;
            s->f428[1] = 1;
            s->f428[2] = 0;
            s->f428[3] = 1;
            break;
        case 2:
            s->f471 = 2;
        case 1:
            s->f46b = 4;
            s->f428[0] = 0;
            s->f428[1] = 1;
            s->f428[2] = 2;
            s->f428[3] = 3;
            break;
        }
        s->f46c = s->f00->f21;
        s->f46d = func_021B8BEC((u8 *)s, s->f46c, 0);
        *pp = *pp + 1;
        return 0;
    }
    if (*pp < 7) {
        if (d_021EFD00[*pp](s, &s->f460) != 0) {
            s->f460 = 0;
            *pp = *pp + 1;
        }
        return 0;
    }
    return 1;
}
