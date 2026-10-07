/*
 * file:     btl_server_p112.c
 * unit:     yes
 * function: func_021CB1D4, func_021CB214, func_021CB274, func_021CB2D4, func_021CB55C, func_021CB5F0, func_021CB730
 * address:  0x021CB1D4
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
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021D7EB4 0x021D7EB4 thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_02082BCC 0x02082BCC arm
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021D6E04 0x021D6E04 thumb ov093
 *   func_021D6E0C 0x021D6E0C thumb ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021B871C 0x021B871C thumb ov093
 *   func_021D5844 0x021D5844 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_02018480 0x02018480 thumb arm9
 *   func_02017E1C 0x02017E1C thumb arm9
 *   func_02008564 0x02008564 thumb arm9
 *   func_021D7B10 0x021D7B10 thumb ov093
 *   func_02011168 0x02011168 thumb arm9
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   _u32_div_f 0x0209C2B0 arm
 *   _ffltu         0x0209BE04  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_0207C7B4  0x0207C7B4  arm
 *   func_021D6B6C  0x021D6B6C  thumb  ov093
 *   g_021EFDC0      0x021EFDC0  data  ov093
 *   func_021D5444   0x021D5444  thumb ov093
 *   func_021D805C   0x021D805C  thumb ov093
 *   func_02019C90   0x02019C90  thumb arm9
 *   func_02017D30   0x02017D30  thumb arm9
 *   func_02017D70   0x02017D70  thumb arm9
 *   func_02017E40   0x02017E40  thumb arm9
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B99B8 0x021B99B8 thumb ov093
 *   func_021CBA30 0x021CBA30 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021CBA40 0x021CBA40 thumb ov093
 *   func_021B9090 0x021B9090 thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C8338 0x021C8338 thumb ov093
 *   func_021CD4FC 0x021CD4FC thumb ov093
 *   func_021CD568 0x021CD568 thumb ov093
 *   func_021BA250 0x021BA250 thumb ov093
 *   data_021EFDE4 0x021EFDE4 data a4
 */
#include "../../matched/include/Obj13345.h"
#include "../../matched/include/Obj13346.h"

struct Q1;
struct QI;
struct S2;
struct Sub0200852CObj;
struct QF;
struct Sav;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct
{
  u32 value;
  u8 flag;
  u8 pad[7];
} Rec;

struct T6 { u8 f0; u8 f1; u16 f2; u16 f4; };

typedef enum
{
  COND_ZERO,
  COND_ONE,
  COND_TWO
} Condition;

typedef int (*Callback)(u8 *, u8 *, u16, u32, u32);

typedef struct
{
  u16 id;
  u8 mode;
  u8 exact;
  Callback call;
} Entry;

extern u32 func_021CC8D8(void *lock, int line);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern u32 func_021D7EB4(void *a);
extern u8 func_021B9B94(struct Q1 *p);
extern void *func_021B86B8(void ***p);
extern void func_02082BCC(void *, int, u32);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *);
extern u16 func_021D5B40(struct QI *p);
extern unsigned char func_021D6E04(unsigned char *p);
extern u8 func_021D6E0C(u8 *p, u32 i);
extern u8 *func_021B9934(char *p, int i);
extern int func_021B871C(char *p);
extern void *func_021D5844(void *);
extern int func_021D59B4(u8 *p, int k);
extern int func_02018480(void *p, int q);
extern u32 func_02017E1C(void *, u32, u32);
extern u8 func_02008564(const struct Sub0200852CObj *obj);
extern u32 func_021D7B10(u32, u32);
extern u32 func_02011168(u32);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern int func_0207C7B4(int x);
extern u32 func_021D6B6C(u8 *p);
extern u16 func_021D5444(struct QF *p);
extern u32 func_021D805C(void *p, u32 n);
extern u32 func_02019C90(void *p, u32 a, u32 b);
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u8 func_021B8DDC(u32);
extern char *func_021B9AEC(char *, int);
extern int func_021B99B8(void *, u32);
extern u32 func_021CBA30(void *, u32);
extern u32 func_021B8588(void **p);
extern void func_021CD64C(void *, u8, ...);
extern int func_021CBA40(u8 *, void *, u16);
extern void func_021B9090(u8 *, u32, u32);
extern u8 func_021B8FF4(u8 *);
extern void func_021BA1B4(char **p, int i);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021C8338(u8 *, int);
extern u32 func_021CD4FC(void *, u32);
extern void func_021CD568(void *, u32, u32, ...);
extern void func_021BA250(char *, u8 *, int);
u8 func_021CB1D4(u8 *p, u8 *a, u8 *b, u32 d);
u8 func_021CB214(u8 *p, u8 *a, u8 *b);
u8 func_021CB274(u8 *p, u8 *a, u8 *b, u32 d);
void func_021CB2D4(u8 *p, u8 *a, u32 b, Rec *rec);
u32 func_021CB55C(void *p, u32 a, u16 b, u16 c);
void func_021CB5F0(u32 *a0, u8 *a1, u8 *a2);
int func_021CB730(u8 *p, u8 *a, u16 move, u8 arg, u8 slot);
extern struct T6 g_021EFDC0[];
extern const Entry data_021EFDE4[];


u8 func_021CB1D4(u8 *p, u8 *a, u8 *b, u32 d)
{
    u32 s = func_021CC8D8(p + 0x1D74, 611);
    u8 r = func_021CB274(p, a, b, d);
    func_021CC95C((u32 *)(p + 0x1D74), s, 613);
    return r;
}


u8 func_021CB214(u8 *p, u8 *a, u8 *b)
{
    u8 r;
    func_021D74F8(631);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x16, b[6]);
    func_021D75EC(0x12, ((struct Obj13345 *)b)->f0);
    func_021D7630(4, 0x1f);
    func_021D7630(0x50, 0);
    func_021D70F0(p, 0x29);
    r = func_021D775C(4);
    func_021D7540(639);
    return r;
}


u8 func_021CB274(u8 *p, u8 *a, u8 *b, u32 d)
{
    u8 r;
    func_021D74F8(656);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x16, b[6]);
    func_021D75EC(0x12, ((struct Obj13346 *)b)->f0);
    func_021D7630(4, d);
    func_021D70F0(p, 0x2a);
    r = func_021D775C(4);
    func_021D7540(663);
    if (r == d) r = 0x1f;
    return r;
}

/*
 * note: final push 2026-10-05 G1R6: closed. The loop count n is a u16 local and
 *   func_021B9B94 is declared u8 (its matched definition returns u8). A narrow bound with
 *   narrow counters gives unsigned compares and keeps the loop-3 counter store before the
 *   bound reload. Earlier drafts kept n u32 (4 B off) or u8 (signed compares, 35 B off).
 *   Same shape as ov021 func_021922A4 (u16 bound, u16 counter). A separate u16 counter i3
 *   for loop 3 gives the spill slots of the counter and of id.
 */
void func_021CB2D4(u8 *p, u8 *a, u32 b, Rec *rec)
{
  u32 scale;
  u16 n;
  u32 share;
  u16 lvl;
  u16 lvl2;
  u32 k;
  u16 i;
  u8 id;
  u16 i3;
  u32 half;
  u16 cnt;
  u32 avg;
  int n2;
  u32 n3;
  u8 cnt2;
  u16 j;
  u16 m;
  u8 q;
  u8 *t;

  scale = func_021D7EB4((void *)b);
  n = func_021B9B94((struct Q1 *)a);
  cnt = 0;
  if (func_021B86B8(*(void **) (p + 4)) == (void *) 1)
    scale = scale * 15 / 10;
  for (i = 0, j = 0; i < 6; i++)
    func_02082BCC(rec + i, j, 12);
  for (j = 0; j < n; j++)
  {
    t = func_021B9C00((struct S2 *)a, (u8) j);
    if (func_021D5B68(t) == 0 && (u32)func_021D5B40((struct QI *)t) == 0xd8)
      cnt++;
  }
  if (cnt)
  {
    half = scale >> 1;
    scale = scale - half;
    avg = half / cnt;
    if (avg == 0)
      avg = 1;
    for (j = 0; j < n; j++)
    {
      t = func_021B9C00((struct S2 *)a, (u8) j);
      if (func_021D5B68(t) == 0 && (u32)func_021D5B40((struct QI *)t) == 0xd8)
        rec[j].value = avg;
    }
  }
  n2 = (int)func_021D6E04((unsigned char *)b);
  cnt2 = 0;
  for (j = 0; j < n2; j++)
  {
    if (func_021D5B68(func_021B9934(*(void **) (p + 8), (u32)func_021D6E0C((u8 *)b, (u8) j))) == 0)
      cnt2++;
  }
  share = scale / cnt2;
  if (share == 0)
    share = 1;
  for (i3 = 0; i3 < n; i3++)
  {
    t = func_021B9C00((struct S2 *)a, (u8) i3);
    if (func_021D5B68(t) == 0)
    {
      id = func_021D5440(t);
      n3 = n2;
      for (q = 0; q < n3; q++)
      {
        if (id == (u32)func_021D6E0C((u8 *)b, q))
          rec[i3].value += share;
      }
    }
  }
  for (j = 0; j < n; j++)
  {
    if (rec[j].value != 0)
    {
      void *save;
      void *v28;
      u32 v24;

      v24 = (u32)func_021B871C(*(void **) (p + 4));
      t = func_021B9C00((struct S2 *)a, (u8) j);
      v28 = func_021D5844(t);
      lvl = func_021D59B4(t, 15);
      lvl2 = func_021D59B4((void *) b, 15);
      rec[j].value = func_021CB55C(t, rec[j].value, lvl, lvl2);
      if (func_02018480(v28, (u32)v24) == 0)
      {
        save = (void *) func_02017E1C(v28, 12, 0);
        if ((u32) save != func_02008564((const struct Sub0200852CObj *)v24))
          k = 0x1b33;
        else
          k = 0x1800;
        rec[j].value = func_021D7B10(rec[j].value, k);
        rec[j].flag = 1;
      }
      if ((u32)func_021D5B40((struct QI *)t) == 0xe7)
      {
        rec[j].value = func_021D7B10(rec[j].value, 0x1800);
        rec[j].flag = 1;
      }
      rec[j].value = func_02011168(rec[j].value);
    }
  }
  for (m = 0; m < n; m++)
  {
    if (rec[m].value != 0)
      func_021CB5F0((u32 *)func_021B9BF0((struct S2 *)a, (u8) m), (u8 *)b, (u8 *)(rec + m));
  }
}

/*
 * note: the second block squares y in place (y *= y) and then multiplies the
 *   root by y: the product lands in the root copy register as in the original.
 *   Found in final push 2026-10-05 G1R4 after the Product helper and every
 *   named-yy form kept the product in the squared register.
 */
u32 func_021CB55C(void *p, u32 a, u16 b, u16 c)
{
  int tmp;
  u32 tmp1;
  u32 r, lim;
  u32 x = (2 * c) + 10;
  u32 y = (c + b) + 10;
  u32 t1 = ((u32) (func_0207C7B4((int) ((x > 0) ? ((x * (1 << 12)) + 0.5f) : ((x * (1 << 12)) - 0.5f))) * (x * x))) >> 12;
  tmp = (int) ((y > 0) ? ((y * (1 << 12)) + 0.5f) : ((y * (1 << 12)) - 0.5f));
  tmp1 = func_0207C7B4(tmp);
  y *= y;
  r = ((a * t1) / ((y * tmp1) >> 12)) + 1;
  lim = func_021D6B6C(p);
  if (r > lim)
    r = lim;
  return r;
}


/*
 * Builds the six per-party "battle handicap" bytes and writes them to the
 * output record.  Reads the record's u16 fields 0xc and 0x13, asks the
 * battle dispatcher func_02019C90 for a base value per entry of the six
 * entry table at 0x021EFDC0 (6-byte records: u8 at +0, u16 at +2, u16 at
 * +4), doubles them when the mode field 0x12 is 0xd7, then walks the table
 * again to add func_021D805C's value for the entry whose +4 field matches
 * and to fold each result into the savedata record 0x97 through the
 * func_02017E1C/func_02017E40 read/write pair, clamped at 0xff.  The final
 * switch on the loop index is the image's, not a source choice: the table
 * at 0x021CB6F4 is six four-byte arms, case i storing the byte at
 * a2[5 + i].  Ends by releasing the savedata record.
 */
void func_021CB5F0(u32 *a0, u8 *a1, u8 *a2)
{
    u8 buf[6];
    u8 i;
    u16 v6;
    u32 m;
    u32 t;
    void *rec;
    u32 sv;

    m = func_021D5444((struct QF *)a1);
    v6 = (u16)func_021D59B4(a1, 0x13);
    for (i = 0; i < 6; i++) {
        buf[i] = (u8)func_02019C90((void *)m, v6, g_021EFDC0[i].f0);
    }
    if (func_021D5B40((struct QI *)a0) == 0xd7) {
        for (i = 0; i < 6; i++) {
            buf[i] = buf[i] * 2;
        }
    }
    for (i = 0; i < 6; i++) {
        t = g_021EFDC0[i].f4;
        if (t == func_021D5B40((struct QI *)a0)) {
            buf[i] = (u8)(buf[i] + (u8)func_021D805C((void *)t, 2));
        }
    }
    rec = func_021D5844(a0);
    sv = func_02017D30(rec);
    if (func_02017E1C(rec, 0x97, 0) != 0) {
        for (i = 0; i < 6; i++) {
            buf[i] = buf[i] * 2;
        }
    }
    for (i = 0; i < 6; i++) {
        u8 v;
        u32 w;

        v = buf[i];
        if (v == 0) {
            continue;
        }
        t = g_021EFDC0[i].f2;
        w = func_02017E1C(rec, t, 0) + v;
        if (w > 0xff) {
            w = 0xff;
        }
        func_02017E40(rec, t, w);
        switch (i) {
        case 0: a2[5] = v; break;
        case 1: a2[6] = v; break;
        case 2: a2[7] = v; break;
        case 3: a2[8] = v; break;
        case 4: a2[9] = v; break;
        case 5: a2[0xa] = v; break;
        }
    }
    func_02017D70(rec, sv);
}

/*
 * lever: the local holding the u8 result of func_021B8DDC is a u8 (not int);
 *   its spill reload then stays below the outgoing stack-argument stores
 *   (ov093 021CD64C call at +0xDA) and the stack parameter load moves ahead
 *   of the p copy at entry. Both residues closed by this one type change.
 *   See docs/idioms/a-narrow-spilled-parameter-keeps-its-reload-below-a-store.md.
 * note: 2026-10-05 wave P2 lane Q8. Dropped the (void)(&pos) no-op from the
 *   older draft (it changed nothing).
 */
int func_021CB730(u8 *p, u8 *a, u16 move, u8 arg, u8 slot)
{
  u32 n;
  char *party;
  u8 side;
  u32 monId;
  Condition initial;
  u8 condition;
  u8 *mon;
  unsigned long lock;
  u32 result;
  unsigned long state;
  u32 mark;
  u32 pos;
  u32 allowed;
  u32 i;
  const Entry *e;
  u8 *tmp;
  u8 *tmp1;
  side = func_021B8DDC(func_021D5440(a));
  mon = 0;
  initial = 0;
  if (slot != 6)
  {
    party = func_021B9AEC(*((char **) (p + 8)), side);
    n = func_021B99B8(*((void **) (p + 4)), side);
    mon = (u8 *)func_021B9BF0((struct S2 *)party, slot);
    monId = func_021D5440(mon);
    state = func_021CBA30(p + 0x1ab8, monId);
    if (slot >= n)
      initial = 2;
    condition = (u8) initial;
    if (((func_021B8588(*((void **) (p + 4))) == 3) && (condition == 2)) && (slot < 3))
      condition = 1;
  }
  if ((*((u32 *) (p + 24))) != 1)
  {
    func_021CD64C(*((void **) (p + 12)), 0x5a, 0x21, side, move, 0xffff0000);
    if (func_021D805C((void *)move, 15) == 4)
    {
      if (func_021CBA40(p, a, move))
        func_021B9090(*((u8 **) (p + 4)), side, move);
      return 0;
    }
    if (func_021D805C((void *)move, 7) == 3)
    {
      func_021B9090(*((u8 **) (p + 4)), side, move);
      return 1;
    }
  }
  else
  {
    func_021CD64C(*((void **) (p + 12)), 0x5a, 0x24, side, monId, move, 0xffff0000);
    if (side == func_021B8FF4(*((u8 **) (p + 4))))
      func_021BA1B4(*((void **) (p + 4)), 0x6f);
  }
  allowed = ((condition == 0) && (state != 6)) ? (1) : (0);
  if (!allowed)
  {
    for (i = 0; i < 23; i++)
    {
      e = data_021EFDE4;
      e = e + i;
      if ((e->exact && (move == e->id)) || ((!e->exact) && func_021D805C((void *)move, e->id)))
      {
        if (e->mode == 0)
        {
          allowed = 1;
          break;
        }
        if (((e->mode == 1) && (condition < 2)) && (state != 6))
        {
          allowed = 1;
          break;
        }
      }
    }

  }
  if (!allowed)
  {
    func_021CD64C(*((void **) (p + 12)), 0x5a, 0xc4, 0xffff0000);
    return 0;
  }
  if ((*((u32 *) (p + 24))) == 1)
  {
    if (state != 6)
      func_021CD4B0(*((void **) (p + 12)), 0x4d, state, 0x282);
    for (i = 0; i < 23; i++)
    {
      if (data_021EFDE4[i].exact && (move == data_021EFDE4[i].id))
      {
        result = 0;
        if (!func_021C8338(p, monId))
        {
          pos = func_021CD4FC(*((void **) (p + 12)), 0x4d);
          result = data_021EFDE4[i].call(p, mon, move, 0, arg);
          if (result == 1)
          {
            func_021CD568(*((void **) (p + 12)), pos, 0x4d, state, 0x25e);
            func_021CD4B0(*((void **) (p + 12)), 0x4c, 0x236);
            return 0;
          }
        }
        if (result == 0)
          func_021CD64C(*((void **) (p + 12)), 0x5a, 0x44, 0xffff0000);
        func_021CD4B0(*((void **) (p + 12)), 0x4c, 0x236);
        return 0;
      }
    }

  }
  mark = 0;
  pos = func_021CD4FC(*((void **) (p + 12)), 0x4d);
  lock = func_021CC8D8(p + 0x1d74, 1217);
  for (i = 0; i < 23; i++)
  {
    e = data_021EFDE4 + i;
    result = func_021D805C((void *)move, e->id);
    if (result && e->call(p, mon, move, result, arg))
      mark = 1;
  }

  if (mark)
  {
    func_021CD568(*((void **) (p + 12)), pos, 0x4d, state, (u16) ((state != 6) ? (0x25e) : (0x292)));
    if ((*((u32 *) (p + 24))) != 1)
    {
      func_021B9090(*((u8 **) (p + 4)), side, move);
      func_021BA250(*((char **) (p + 4)), mon, move);
    }
  }
  else
    func_021CD64C(*((void **) (p + 12)), 0x5a, 0x44, 0xffff0000);
  func_021CC95C((u32 *)(p + 0x1d74), lock, 1246);
  func_021CD4B0(*((void **) (p + 12)), 0x4c, 0x236);
  return 0;
}
