/*
 * function: func_021CB730
 * address: 0x021CB730
 * packet: pkt_ov093_021CB730
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: the local holding the u8 result of func_021B8DDC is a u8 (not int);
 *   its spill reload then stays below the outgoing stack-argument stores
 *   (ov093 021CD64C call at +0xDA) and the stack parameter load moves ahead
 *   of the p copy at entry. Both residues closed by this one type change.
 *   See docs/idioms/a-narrow-spilled-parameter-keeps-its-reload-below-a-store.md.
 * note: 2026-10-05 wave P2 lane Q8. Dropped the (void)(&pos) no-op from the
 *   older draft (it changed nothing).
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B99B8 0x021B99B8 thumb ov093
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   func_021CBA30 0x021CBA30 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021D805C 0x021D805C thumb ov093
 *   func_021CBA40 0x021CBA40 thumb ov093
 *   func_021B9090 0x021B9090 thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C8338 0x021C8338 thumb ov093
 *   func_021CD4FC 0x021CD4FC thumb ov093
 *   func_021CD568 0x021CD568 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021B9090 0x021B9090 thumb ov093
 *   func_021BA250 0x021BA250 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   data_021EFDE4 0x021EFDE4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
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
extern const Entry data_021EFDE4[];
extern u8 func_021D5440(u8 *);
extern u8 func_021B8DDC(u32);
extern char *func_021B9AEC(char *, int);
extern int func_021B99B8(void *, u32);
struct S2;
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern u32 func_021CBA30(void *, u32);
extern u32 func_021B8588(void **p);
extern void func_021CD64C(void *, u8, ...);
extern u32 func_021D805C(void *p, u32 n);
extern int func_021CBA40(u8 *, void *, u16);
extern void func_021B9090(u8 *, u32, u32);
extern u8 func_021B8FF4(u8 *);
extern void func_021BA1B4(char **p, int i);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021C8338(u8 *, int);
extern u32 func_021CD4FC(void *, u32);
extern void func_021CD568(void *, u32, u32, ...);
extern u32 func_021CC8D8(void *, int);
extern void func_021BA250(char *, u8 *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
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
