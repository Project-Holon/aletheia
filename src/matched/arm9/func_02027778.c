/*
 * function: func_02027778
 * address:  0x02027778
 * packet:   pkt_02027778
 * region:   arm9
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The TaskMenu constructor: allocate the 0x38-byte menu ("app_taskmenu.c",
 * lines 162/168/169), copy the 0x14-byte template in, allocate count*4 and
 * count*12 buffers and copy the template's item table into the second,
 * zero the cursor state, default the two template bytes at +0x12/+0x13 to
 * 13 and 3 when zero, then run func_02027A24 and, unless func_020355C4()
 * says otherwise, func_02027B30 on the current item.
 *
 * Promoted from src/pending (DIFF, 6 bytes out) in wave 12.  The last
 * residue was the scheduling of the +0x12 template load after the three
 * zero stores: the template parameter is NOT const.  With a const pointer
 * mwcc proves the stores into the menu cannot reach the template and
 * hoists the ldrb above them; without it the load stays in source order.
 * The two defaults are unconditional stores of a conditioned value
 * (v = tmpl->unk12; if (v == 0) v = 13; m->tmpl.unk12 = v), not guarded
 * member stores.
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
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
struct Cfg;
struct Obj;
extern void func_02027a24(struct Obj *o, struct Cfg *cfg);
extern u8 func_020355c4(void);
struct S;
extern void func_02027b30(u32 a0, struct S *s, int mode);
extern char sFile_020A74E0[];
struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1)
{
  struct TaskMenu *m;
  m = func_02030734((u16) tmpl->heapId, 0x38, 0, sFile_020A74E0, 162);
  m->tmpl = *tmpl;
  m->arg1 = arg1;
  m->buf1 = func_02030734((u16) m->tmpl.heapId, m->tmpl.count * 4, 0, sFile_020A74E0, 168);
  m->buf2 = func_02030734((u16) m->tmpl.heapId, m->tmpl.count * 12, 0, sFile_020A74E0, 169);
  MIi_CpuCopy16(m->tmpl.unk08, m->buf2, m->tmpl.count * 12);
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
  func_02027a24((struct Obj *)m, arg1);
  if (func_020355c4() == 0)
  {
    func_02027b30((u32)(((void **) m->buf1)[m->unk00]), m->arg1, 1);
  }
  m->unk08 = 1;
  return m;
}


