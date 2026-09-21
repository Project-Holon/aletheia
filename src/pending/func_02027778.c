/*
 * function: func_02027778
 * address:  0x02027778
 * packet:   pkt_02027778
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note:     DIFF, 6 concrete bytes of 212, size-exact, every relocation
 *           resolved.  Wave 4 (2026-09-21) took this from 31 bytes out to 6:
 *           the two template defaults at +0x32/+0x33 are NOT if-guarded
 *           stores but unconditional stores of a conditioned value.  The
 *           original always executes `strb r1,[r0]` at +0x38/+0x46; the
 *           `bne` only skips the `movs r1,#0xd` / `movs r1,#3` that
 *           substitute the default, so the shape is
 *             v = tmpl->unk12; if (v == 0) v = 13; m->tmpl.unk12 = v;
 *           (a ternary spells identically).  Writing it as a guarded store
 *           into the member costs 8 extra bytes of address setup.
 *
 *           The 6 residual bytes are one two-instruction scheduling window
 *           at +0x86..+0x8C: the original issues `strh r7,[r4,#2]` and
 *           `movs r0,#1; str r0,[r4,#0x14]` BEFORE `ldrb r1,[r5,#0x12]`,
 *           and the compiler hoists the guard load above both stores.
 *           Every permutation of the six preceding zero-stores was measured
 *           (source order as written is the best at 6; the five others give
 *           12, 12, 13, 15); splitting the guard's declaration from its
 *           initialisation, a ternary, and an if/else with both arms
 *           spelled out are all 6 or worse (the if/else overshoots to 216
 *           bytes).  permuter.py hill 800 and anneal 2500 with --types both
 *           walk AWAY from this point: its instruction-level score ranks a
 *           22-bytes-out variant above this 6-bytes-out one, so read the
 *           bytes-out column, not the best line, on this target.
 *
 * symbols:
 *   func_02030734     0x02030734  arm
 *   MIi_CpuCopy16     0x02082A60  arm
 *   func_02027a24     0x02027A24  thumb
 *   func_020355c4     0x020355C4  arm
 *   func_02027b30     0x02027B30  thumb
 *   sFile_020A74E0    0x020A74E0  data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct TaskMenuTmpl
{
  u32 heapId;
  u8 count;
  u8 pad05[3];
  const void *unk08;
  u32 unk0c;
  u8 pad10[2];
  u8 unk12;
  u8 unk13;
};
struct TaskMenu
{
  u8 unk00;
  u8 unk01;
  u16 unk02;
  u32 pad04;
  u32 unk08;
  u32 unk0c;
  u32 unk10;
  u32 unk14;
  void *buf1;
  void *buf2;
  struct TaskMenuTmpl tmpl;
  void *arg1;
};
extern void *func_02030734(u32 heapId, u32 size, u32 clear, const char *file, u32 line);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern void func_02027a24(struct TaskMenu *m, void *arg1);
extern u32 func_020355c4(void);
extern void func_02027b30(void *a0, void *arg1, u32 flag);
extern char sFile_020A74E0[];
struct TaskMenu *func_02027778(const struct TaskMenuTmpl *tmpl, void *arg1)
{
  struct TaskMenu *m;
  const u8 *p;
  m = func_02030734((u16) tmpl->heapId, 0x38, 0, sFile_020A74E0, 162);
  m->tmpl = *tmpl;
  m->arg1 = arg1;
  p = ((const u8 *) m) + 0x24;
  m->buf1 = func_02030734((u16) m->tmpl.heapId, (*p) * 4, 0, sFile_020A74E0, 168);
  m->buf2 = func_02030734((u16) m->tmpl.heapId, (*p) * 12, 0, sFile_020A74E0, 169);
  MIi_CpuCopy16(m->tmpl.unk08, m->buf2, (*p) * 12);
  m->unk0c = 0;
  m->unk10 = 0;
  m->unk00 = 0;
  m->unk01 = 0;
  m->unk02 = 0;
  m->unk14 = 1U;
  {
    u8 v12 = tmpl->unk12;
    u8 v13;
    if (v12 == 0)
    {
      v12 = 13;
    }
    m->tmpl.unk12 = v12;
    v13 = tmpl->unk13;
    if (v13 == 0)
    {
      v13 = 3;
    }
    m->tmpl.unk13 = v13;
  }
  func_02027a24(m, arg1);
  if (func_020355c4() == 0)
  {
    func_02027b30(((void **) m->buf1)[m->unk00], m->arg1, 1);
  }
  m->unk08 = 1;
  return m;
}


