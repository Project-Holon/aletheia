/*
 * function: func_021CB2D4
 * address: 0x021CB2D4
 * packet: pkt_ov093_021CB2D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note: 2026-10-05 wave P3 lane R2. First draft, 648 bytes, 10 bytes differ. Only residue:
 *   the spill slots of the loop-3 counter i and the u8 id are swapped (original i at
 *   [sp,#0x10] and id at [sp,#0xc]; compiled the reverse), plus the scheduling of one
 *   store/reload pair that follows from it. Tried: declaration order of i and id, id as
 *   u32 or u8 (with matching callee return type), id declared in the loop block, a
 *   separate counter for the last loop, and all six per-function pragmas (none helps; three
 *   make it much worse). Levers that closed the rest: u16 count local plus a separate u32
 *   average local, a named u16 local for each func_021CB55C level argument, an if/else
 *   assigning an int local before one func_021D7B10 call (not two calls), v24/v28/save as
 *   block locals of the final loop, a copy n3 of n2 (original compares n2 signed in the
 *   first loop and unsigned in the second).
 *   2026-10-05 wave P3 lane R2b: 10 B -> 4 B. A separate u16 counter i3 for loop 3 (i stays
 *   the loop-1 counter, declared after id) fixes both spill slots (i3 at [sp,#0x10], id at
 *   [sp,#0xc]). Residue now: the loop-3 increment store `str r1,[sp,#0x10]` comes before
 *   `ldr r0,[sp,#0x1c]` (n) in the original, after it in ours (+0188/+018A). Tried, no change
 *   (4 B): i3 declared before id or last, block-local i3 or id, i3 shared with m, i3 as u32
 *   with (u16)(i3+1), while loop with trailing i3++, n copied to a local, scheduling off,
 *   peephole off, opt_dead_assignments off. Worse: id as u32 (10 B, slots swap again), `n > i3`
 *   (11 B), n as u8 (35 B), opt_lifetimes/propagation/common_subs off. Idioms read:
 *   function-scope-versus-block-scope, constant-temp-reuses-first-assigned-slot,
 *   a-separate-index-local-per-loop-reorders-spill-slots (the winning lever),
 *   a-narrow-spilled-parameter-keeps-its-reload-below-a-store, a-byte-count-local-preserves-word-spills.
 *   2026-10-05 wave P3 lane R2c: still 4 B (+0188/+018A), 18 compiles, none moved it. Tried
 *   (all 4 B unless noted): for (i3 = 0; i3 < n; ) with i3++ as the last body statement; `continue`
 *   guard instead of the nested if; ++i3 and i3 = i3 + 1; loop-3 bound read from a copy n1 of n; n3 = n2
 *   hoisted above loop 3; block-local t, block-local q; do-while with an explicit if (n) guard, both
 *   with trailing i3++ and with while (++i3 < n) (5 B: guard becomes beq instead of bls); n as u16
 *   (613 B), n as int (14 B, signed branches), volatile n (267 B, diagnostic only), rec pointer
 *   local r3 = rec + i3 in the body (25 B). Idioms read in full:
 *   logical-result-store-order-hoists-a-spilled-reload (acquisition-order stores; no multi-store
 *   here, nothing to reorder), a-spilled-local-assigned-twice-occupies-two-stack-slots (i3 is
 *   assigned once per iteration and the slots already match). Hypothesis left for the integrator:
 *   the original orders the spill store before the bound reload, which is what a may-alias memory
 *   access gives (bound or counter living in a struct or array on the stack); no human-plausible
 *   source for that was found, so the draft stays DIFF.
 * symbols:
 *   func_021D7EB4 0x021D7EB4 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
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
 *   func_021CB55C 0x021CB55C thumb ov093
 *   func_02018480 0x02018480 thumb arm9
 *   func_02017E1C 0x02017E1C thumb arm9
 *   func_02008564 0x02008564 thumb arm9
 *   func_021D7B10 0x021D7B10 thumb ov093
 *   func_02011168 0x02011168 thumb arm9
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   func_021CB5F0 0x021CB5F0 thumb ov093
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct
{
  u32 value;
  u8 flag;
  u8 pad[7];
} Rec;
extern u32 func_021D7EB4(u32);
extern u8 func_021D5440(void *);
extern u32 func_021B9B94(void *);
extern void *func_021B86B8(void *);
extern void func_02082BCC(void *, int, u32);
extern u8 *func_021B9C00(void *, u32);
extern int func_021D5B68(void *);
extern u32 func_021D5B40(void *);
extern int func_021D6E04(u32);
extern u32 func_021D6E0C(u32, u32);
extern u8 *func_021B9934(void *, u32);
extern u32 func_021B871C(void *);
extern void *func_021D5844(void *);
extern int func_021D59B4(void *, int);
extern u32 func_021CB55C(void *, u32, u16, u16);
extern int func_02018480(void *, u32);
extern u32 func_02017E1C(void *, u32, u32);
extern u8 func_02008564(u32);
extern u32 func_021D7B10(u32, u32);
extern u32 func_02011168(u32);
extern u8 *func_021B9BF0(void *, u32);
extern void func_021CB5F0(void *, u32, Rec *);
void func_021CB2D4(u8 *p, u8 *a, u32 b, Rec *rec)
{
  u32 scale;
  u32 n;
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

  scale = func_021D7EB4(b);
  n = func_021B9B94(a);
  cnt = 0;
  if (func_021B86B8(*(void **) (p + 4)) == (void *) 1)
    scale = scale * 15 / 10;
  for (i = 0, j = 0; i < 6; i++)
    func_02082BCC(rec + i, j, 12);
  for (j = 0; j < n; j++)
  {
    t = func_021B9C00(a, (u8) j);
    if (func_021D5B68(t) == 0 && func_021D5B40(t) == 0xd8)
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
      t = func_021B9C00(a, (u8) j);
      if (func_021D5B68(t) == 0 && func_021D5B40(t) == 0xd8)
        rec[j].value = avg;
    }
  }
  n2 = func_021D6E04(b);
  cnt2 = 0;
  for (j = 0; j < n2; j++)
  {
    if (func_021D5B68(func_021B9934(*(void **) (p + 8), func_021D6E0C(b, (u8) j))) == 0)
      cnt2++;
  }
  share = scale / cnt2;
  if (share == 0)
    share = 1;
  for (i3 = 0; i3 < n; i3++)
  {
    t = func_021B9C00(a, (u8) i3);
    if (func_021D5B68(t) == 0)
    {
      id = func_021D5440(t);
      n3 = n2;
      for (q = 0; q < n3; q++)
      {
        if (id == func_021D6E0C(b, q))
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

      v24 = func_021B871C(*(void **) (p + 4));
      t = func_021B9C00(a, (u8) j);
      v28 = func_021D5844(t);
      lvl = func_021D59B4(t, 15);
      lvl2 = func_021D59B4((void *) b, 15);
      rec[j].value = func_021CB55C(t, rec[j].value, lvl, lvl2);
      if (func_02018480(v28, v24) == 0)
      {
        save = (void *) func_02017E1C(v28, 12, 0);
        if ((u32) save != func_02008564(v24))
          k = 0x1b33;
        else
          k = 0x1800;
        rec[j].value = func_021D7B10(rec[j].value, k);
        rec[j].flag = 1;
      }
      if (func_021D5B40(t) == 0xe7)
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
      func_021CB5F0(func_021B9BF0(a, (u8) m), b, rec + m);
  }
}
