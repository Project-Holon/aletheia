/*
 * function: BTL_SERVER_FLOW_CalcPartyExpShares
 * address: 0x021CB2D4
 * packet: pkt_ov093_021CB2D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: final push 2026-10-05 G1R6: closed. The loop count n is a u16 local and
 *   BTL_SLOT_GetCount is declared u8 (its matched definition returns u8). A narrow bound with
 *   narrow counters gives unsigned compares and keeps the loop-3 counter store before the
 *   bound reload. Earlier drafts kept n u32 (4 B off) or u8 (signed compares, 35 B off).
 *   Same shape as ov021 FIELD_MSGBG_DrawFrameBmp (u16 bound, u16 counter). A separate u16 counter i3
 *   for loop 3 gives the spill slots of the counter and of id.
 * symbols:
 *   BTL_CALC_CalcDefeatExp 0x021D7EB4 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SLOT_GetCount 0x021B9B94 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   MI_CpuFill8 0x02082BCC arm
 *   BTL_SLOT_GetPokeParam 0x021B9C00 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   BTL_POKEPARAM_GetFoughtCount 0x021D6E04 thumb ov093
 *   BTL_POKEPARAM_GetFoughtPokeId 0x021D6E0C thumb ov093
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_MAIN_GetPlayerStatus 0x021B871C thumb ov093
 *   BTL_POKEPARAM_GetMon 0x021D5844 thumb ov093
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 *   BTL_SERVER_FLOW_CalcLevelScaledExp 0x021CB55C thumb ov093
 *   POKE_TOOL_IsOwnedByPlayer 0x02018480 thumb arm9
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb arm9
 *   func_02008564 0x02008564 thumb arm9
 *   BTL_CALC_MulRatio 0x021D7B10 thumb ov093
 *   GPOWER_ApplyExpRate 0x02011168 thumb arm9
 *   BTL_SLOT_GetPoke 0x021B9BF0 thumb ov093
 *   BTL_SERVER_FLOW_AddDefeatEffortValues 0x021CB5F0 thumb ov093
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
struct Q1;
struct QI;
struct S2;
struct Sub0200852CObj;
extern u32 BTL_CALC_CalcDefeatExp(void *a);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern void *BTL_MAIN_GetCompetitor(void ***p);
extern void MI_CpuFill8(void *, int, u32);
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_IsFainted(void *);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern unsigned char BTL_POKEPARAM_GetFoughtCount(unsigned char *p);
extern u8 BTL_POKEPARAM_GetFoughtPokeId(u8 *p, u32 i);
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_MAIN_GetPlayerStatus(char *p);
extern void *BTL_POKEPARAM_GetMon(void *);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern u32 BTL_SERVER_FLOW_CalcLevelScaledExp(void *, u32, u16, u16);
extern int POKE_TOOL_IsOwnedByPlayer(void *p, int q);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern u8 func_02008564(const struct Sub0200852CObj *obj);
extern u32 BTL_CALC_MulRatio(u32, u32);
extern u32 GPOWER_ApplyExpRate(u32);
extern u32 BTL_SLOT_GetPoke(struct S2 *p, u32 i);
extern void BTL_SERVER_FLOW_AddDefeatEffortValues(u32 *a0, u8 *a1, u8 *a2);
void BTL_SERVER_FLOW_CalcPartyExpShares(u8 *p, u8 *a, u32 b, Rec *rec)
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

  scale = BTL_CALC_CalcDefeatExp((void *)b);
  n = BTL_SLOT_GetCount((struct Q1 *)a);
  cnt = 0;
  if (BTL_MAIN_GetCompetitor(*(void **) (p + 4)) == (void *) 1)
    scale = scale * 15 / 10;
  for (i = 0, j = 0; i < 6; i++)
    MI_CpuFill8(rec + i, j, 12);
  for (j = 0; j < n; j++)
  {
    t = BTL_SLOT_GetPokeParam((struct S2 *)a, (u8) j);
    if (BTL_POKEPARAM_IsFainted(t) == 0 && (u32)BTL_POKEPARAM_GetItem((struct QI *)t) == 0xd8)
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
      t = BTL_SLOT_GetPokeParam((struct S2 *)a, (u8) j);
      if (BTL_POKEPARAM_IsFainted(t) == 0 && (u32)BTL_POKEPARAM_GetItem((struct QI *)t) == 0xd8)
        rec[j].value = avg;
    }
  }
  n2 = (int)BTL_POKEPARAM_GetFoughtCount((unsigned char *)b);
  cnt2 = 0;
  for (j = 0; j < n2; j++)
  {
    if (BTL_POKEPARAM_IsFainted(BTL_SIDE_GetPokeByIdThunk(*(void **) (p + 8), (u32)BTL_POKEPARAM_GetFoughtPokeId((u8 *)b, (u8) j))) == 0)
      cnt2++;
  }
  share = scale / cnt2;
  if (share == 0)
    share = 1;
  for (i3 = 0; i3 < n; i3++)
  {
    t = BTL_SLOT_GetPokeParam((struct S2 *)a, (u8) i3);
    if (BTL_POKEPARAM_IsFainted(t) == 0)
    {
      id = BTL_POKEPARAM_GetPokeId(t);
      n3 = n2;
      for (q = 0; q < n3; q++)
      {
        if (id == (u32)BTL_POKEPARAM_GetFoughtPokeId((u8 *)b, q))
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

      v24 = (u32)BTL_MAIN_GetPlayerStatus(*(void **) (p + 4));
      t = BTL_SLOT_GetPokeParam((struct S2 *)a, (u8) j);
      v28 = BTL_POKEPARAM_GetMon(t);
      lvl = BTL_POKEPARAM_GetValue(t, 15);
      lvl2 = BTL_POKEPARAM_GetValue((void *) b, 15);
      rec[j].value = BTL_SERVER_FLOW_CalcLevelScaledExp(t, rec[j].value, lvl, lvl2);
      if (POKE_TOOL_IsOwnedByPlayer(v28, (u32)v24) == 0)
      {
        save = (void *) POKE_TOOL_GetPartyValue(v28, 12, 0);
        if ((u32) save != func_02008564((const struct Sub0200852CObj *)v24))
          k = 0x1b33;
        else
          k = 0x1800;
        rec[j].value = BTL_CALC_MulRatio(rec[j].value, k);
        rec[j].flag = 1;
      }
      if ((u32)BTL_POKEPARAM_GetItem((struct QI *)t) == 0xe7)
      {
        rec[j].value = BTL_CALC_MulRatio(rec[j].value, 0x1800);
        rec[j].flag = 1;
      }
      rec[j].value = GPOWER_ApplyExpRate(rec[j].value);
    }
  }
  for (m = 0; m < n; m++)
  {
    if (rec[m].value != 0)
      BTL_SERVER_FLOW_AddDefeatEffortValues((u32 *)BTL_SLOT_GetPoke((struct S2 *)a, (u8) m), (u8 *)b, (u8 *)(rec + m));
  }
}
