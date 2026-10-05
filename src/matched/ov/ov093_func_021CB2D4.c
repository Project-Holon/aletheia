/*
 * function: func_021CB2D4
 * address: 0x021CB2D4
 * packet: pkt_ov093_021CB2D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: final push 2026-10-05 G1R6: closed. The loop count n is a u16 local and
 *   func_021B9B94 is declared u8 (its matched definition returns u8). A narrow bound with
 *   narrow counters gives unsigned compares and keeps the loop-3 counter store before the
 *   bound reload. Earlier drafts kept n u32 (4 B off) or u8 (signed compares, 35 B off).
 *   Same shape as ov021 func_021922A4 (u16 bound, u16 counter). A separate u16 counter i3
 *   for loop 3 gives the spill slots of the counter and of id.
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
extern u8 func_021B9B94(void *);
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
