/*
 * function: func_0202627C
 * address:  0x0202627C
 * packet:   pkt_0202627C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_0209FB5C     0x0209FB5C  data
 *   func_02026490  0x02026490  thumb
 *
 * game_comm.c: the per-frame request state machine.  The request kind
 * (+5) selects a 0x1C-byte record of callbacks in the table at 0x0209FB5C
 * (func_02026388 and func_020263B0 read its words at +0x14 and +0x18); the
 * state byte of the 8-byte sub-object at +0xC is the dense switch.
 *
 * Closed 2026-09-24 (wave 21, lane E) after the DIFF 10 recorded in
 * docs/notes/pkt_0202627C.c.txt.  The lever is the finish arm's zero typed
 * as an enum (`E z = Z0` assigned first, then cb, a, b read in that order):
 * with -enum int an enum value is not constant-propagated the way a u32
 * zero is, so the zero keeps its own web (r2, shared with the bics mask)
 * and the callback takes r5 as in the image.  A u32 zero in the same
 * position is 13 out; see
 * docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0202627C.c \
 *       --func func_0202627C --addr 0x0202627C --cc 1.1p1 --thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Sub
{
  u32 f00;
  u8 state;
  u8 changed;
  u8 f06;
  u8 f07;
};
struct Comm
{
  u32 f00;
  u8 b0 : 1;
  u8 b1 : 1;
  u8 b2 : 1;
  u8 b3 : 5;
  u8 kind;
  u8 f06;
  u8 f07;
  u32 f08;
  struct Sub sub;
  u32 f14;
  u32 f18;
  u32 f1c;
  void (*f20)(u32, u32);
};
struct Rec
{
  u32 (*start)(struct Sub *, u32);
  u32 (*wait)(struct Sub *, u32, u32);
  void (*run)(struct Sub *, u32, u32);
  u32 (*stop)(struct Sub *, u32, u32);
  u32 (*end)(struct Sub *, u32, u32);
  u32 f14;
  u32 f18;
};
/* the finish arm clears its fields through an enum-typed zero */
typedef enum { Z0 } E;
extern struct Rec g_0209FB5C[];
extern void func_02026490(void *obj, u32 value);
void func_0202627C(struct Comm *p)
{
  struct Sub *sub;
  struct Rec *rec;
  if ((p == 0) || (p->kind == 0))
    return;
  sub = &p->sub;
  rec = &g_0209FB5C[p->kind];
  if (sub->changed == 1)
  {
    sub->f00 = 0;
    sub->changed = 0;
  }
  switch (sub->state)
  {
    case 0:
      if (rec->start != 0)
      p->f18 = rec->start(sub, p->f14);
      p->f06 = p->kind;
      p->f08 = 0;
      func_02026490(sub, 1);
      break;

    case 1:
      if ((rec->wait == 0) || (rec->wait(sub, p->f14, p->f18) == 1))
      func_02026490(sub, 2);
      break;

    case 2:
      if (p->b0 == 1)
    {
      p->b0 = 0;
      func_02026490(&p->sub, 3);
      break;
    }
      rec->run(sub, p->f14, p->f18);
      break;

    case 3:
      if (rec->stop != 0)
    {
      if (rec->stop(sub, p->f14, p->f18) == 1)
        func_02026490(sub, 4);
    }
    else
    {
      func_02026490(sub, 4);
    }
      break;

    case 4:
      if ((rec->end != 0) && (rec->end(sub, p->f14, p->f18) != 1))
      break;
      func_02026490(sub, 5);

    case 5:
    {
      void (*cb)(u32, u32);
      u32 a;
      u32 b;
      E z;
      z = Z0;
      cb = p->f20;
      a = p->f1c;
      b = p->b1;
      p->f18 = z;
      p->kind = z;
      p->f20 = 0;
      p->f1c = z;
      p->b1 = 0;
      if (cb != 0)
        cb(a, b);
      break;
    }

  }

}
