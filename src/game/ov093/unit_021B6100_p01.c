/*
 * file:     unit_021B6100_p01.c
 * unit:     yes
 * function: func_021B6100, func_021B6434
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
 *   func_021B66D4 0x021B66D4 thumb ov093
 *   func_021B9DB8 0x021B9DB8 thumb ov093
 *   func_021BA094 0x021BA094 thumb ov093
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 *   func_021B9114  0x021B9114  thumb  ov093
 *   func_021BA54C  0x021BA54C  thumb  ov093
 *   func_021BA6C0  0x021BA6C0  thumb  ov093
 *   func_021BA878  0x021BA878  thumb  ov093
 *   func_021BA2E4  0x021BA2E4  thumb  ov093
 *   func_021B64CC  0x021B64CC  thumb  ov093
 */
struct S;
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

struct Callback
{
  void (*first)(void);
  u32 second;
  u8 *object;
  u32 state;
};

typedef int (*CallbackFn)(u32 *, u8 *);

struct Obj0203159C
{
  u32 pad00[5];
  void *buffer;
};

struct P {
    u8 pad00[0x88];
    int f88;
    u8 pad8c[0x35];
    u8 fc1_0 : 1;
    u8 fc1_1 : 1;
};

struct S {
    struct P *f00;
    u8 pad04[0x42c];
    int f430;
    int f434;
    int f438;
    u8 pad43c[0x28];
    int (*f464)(struct S *);
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
extern void func_021B66D4(struct Callback *, u8 *, u8 *);
extern void func_021B9DB8(char *p);
extern void func_021BA094(struct S *p);
extern void func_021BA1B4(char **p, int i);
extern u8 func_021B9114(u8 **p);
extern int func_021BA54C(char *p);
extern void func_021BA6C0(char *p);
extern void func_021BA878(u8 *p);
extern void func_021BA2E4(char *p);
extern int func_021B64CC(u8 *p);
int func_021B6100(struct Obj0203159C *owner, u32 *state, u8 *q, u8 *p);
int func_021B6434(int a0, int a1, int a2, struct S *s);

int func_021B6100(struct Obj0203159C *owner, u32 *state, u8 *q, u8 *p)
{
  u32 flag;
  u32 i;
  u32 ready;
  int done;
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
        func_021B66D4((struct Callback *) (p + 0x450), p, *((u8 **) p));
        *((u32 *) (p + 0x460)) = 0;
        func_021B9DB8((char *)p);
        func_021BA094((struct S *)p);
        (*state)++;
      }
      break;

    case 2:
      if (*(void **)(p + 0x450) != 0)
      {
        if (((CallbackFn) *(void **)(p + 0x450))((u32 *)(p + 0x45c), *(u8 **)(p + 0x458)))
        {
          *(u32 *)(p + 0x450) = 0;
          *(u32 *)(p + 0x45c) = 0;
        }
        done = 0;
      }
      else if (*(u32 *)(p + 0x454) != 0)
      {
        if (((CallbackFn) *(u32 *)(p + 0x454))((u32 *)(p + 0x45c), *(u8 **)(p + 0x458)))
        {
          *(u32 *)(p + 0x454) = 0;
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


int func_021B6434(int a0, int a1, int a2, struct S *s)
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
