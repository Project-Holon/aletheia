/*
 * function: BTL_SERVER_FLOW_ProcBagItemUse
 * address: 0x021CB730
 * packet: pkt_ov093_021CB730
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: the local holding the u8 result of BTL_MAIN_PokeIdToClientIdThunk is a u8 (not int);
 *   its spill reload then stays below the outgoing stack-argument stores
 *   (ov093 021CD64C call at +0xDA) and the stack parameter load moves ahead
 *   of the p copy at entry. Both residues closed by this one type change.
 *   See docs/idioms/a-narrow-spilled-parameter-keeps-its-reload-below-a-store.md.
 * note: 2026-10-05 wave P2 lane Q8. Dropped the (void)(&pos) no-op from the
 *   older draft (it changed nothing).
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_MAIN_PokeIdToClientIdThunk 0x021B8DDC thumb ov093
 *   BTL_SIDE_GetSlotOfClient 0x021B9AEC thumb ov093
 *   BTL_MAIN_GetPositionsPerClientThunk 0x021B99B8 thumb ov093
 *   BTL_SLOT_GetPoke 0x021B9BF0 thumb ov093
 *   func_021CBA30 0x021CBA30 thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 *   BTL_CALC_GetMonParamWithHeap 0x021D805C thumb ov093
 *   BTL_SERVER_FLOW_TryThrowBall 0x021CBA40 thumb ov093
 *   BTL_MAIN_RemoveItemFromBag 0x021B9090 thumb ov093
 *   BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *   BTL_MAIN_TrainerRecordAdd 0x021BA1B4 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_SERVER_FLOW_IsPokeSemiInvulnerable 0x021C8338 thumb ov093
 *   BTL_SERVER_CMD_Reserve 0x021CD4FC thumb ov093
 *   BTL_SERVER_CMD_FillReserved 0x021CD568 thumb ov093
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_MAIN_RemoveItemFromBag 0x021B9090 thumb ov093
 *   BTL_MAIN_UpdateFriendshipUseItem 0x021BA250 thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 *   gBagItemEffectTable 0x021EFDE4 data a4
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
extern const Entry gBagItemEffectTable[];
extern u8 BTL_POKEPARAM_GetPokeId(u8 *);
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32);
extern char *BTL_SIDE_GetSlotOfClient(char *, int);
extern int BTL_MAIN_GetPositionsPerClientThunk(void *, u32);
struct S2;
extern u32 BTL_SLOT_GetPoke(struct S2 *p, u32 i);
extern u32 func_021CBA30(void *, u32);
extern u32 BTL_MAIN_GetRule(void **p);
extern void BTL_SERVER_CMD_PushVariable(void *, u8, ...);
extern u32 BTL_CALC_GetMonParamWithHeap(void *p, u32 n);
extern int BTL_SERVER_FLOW_TryThrowBall(u8 *, void *, u16);
extern void BTL_MAIN_RemoveItemFromBag(u8 *, u32, u32);
extern u8 BTL_MAIN_GetOwnClientId(u8 *);
extern void BTL_MAIN_TrainerRecordAdd(char **p, int i);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern int BTL_SERVER_FLOW_IsPokeSemiInvulnerable(u8 *, int);
extern u32 BTL_SERVER_CMD_Reserve(void *, u32);
extern void BTL_SERVER_CMD_FillReserved(void *, u32, u32, ...);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern void BTL_MAIN_UpdateFriendshipUseItem(char *, u8 *, int);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
int BTL_SERVER_FLOW_ProcBagItemUse(u8 *p, u8 *a, u16 move, u8 arg, u8 slot)
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
  side = BTL_MAIN_PokeIdToClientIdThunk(BTL_POKEPARAM_GetPokeId(a));
  mon = 0;
  initial = 0;
  if (slot != 6)
  {
    party = BTL_SIDE_GetSlotOfClient(*((char **) (p + 8)), side);
    n = BTL_MAIN_GetPositionsPerClientThunk(*((void **) (p + 4)), side);
    mon = (u8 *)BTL_SLOT_GetPoke((struct S2 *)party, slot);
    monId = BTL_POKEPARAM_GetPokeId(mon);
    state = func_021CBA30(p + 0x1ab8, monId);
    if (slot >= n)
      initial = 2;
    condition = (u8) initial;
    if (((BTL_MAIN_GetRule(*((void **) (p + 4))) == 3) && (condition == 2)) && (slot < 3))
      condition = 1;
  }
  if ((*((u32 *) (p + 24))) != 1)
  {
    BTL_SERVER_CMD_PushVariable(*((void **) (p + 12)), 0x5a, 0x21, side, move, 0xffff0000);
    if (BTL_CALC_GetMonParamWithHeap((void *)move, 15) == 4)
    {
      if (BTL_SERVER_FLOW_TryThrowBall(p, a, move))
        BTL_MAIN_RemoveItemFromBag(*((u8 **) (p + 4)), side, move);
      return 0;
    }
    if (BTL_CALC_GetMonParamWithHeap((void *)move, 7) == 3)
    {
      BTL_MAIN_RemoveItemFromBag(*((u8 **) (p + 4)), side, move);
      return 1;
    }
  }
  else
  {
    BTL_SERVER_CMD_PushVariable(*((void **) (p + 12)), 0x5a, 0x24, side, monId, move, 0xffff0000);
    if (side == BTL_MAIN_GetOwnClientId(*((u8 **) (p + 4))))
      BTL_MAIN_TrainerRecordAdd(*((void **) (p + 4)), 0x6f);
  }
  allowed = ((condition == 0) && (state != 6)) ? (1) : (0);
  if (!allowed)
  {
    for (i = 0; i < 23; i++)
    {
      e = gBagItemEffectTable;
      e = e + i;
      if ((e->exact && (move == e->id)) || ((!e->exact) && BTL_CALC_GetMonParamWithHeap((void *)move, e->id)))
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
    BTL_SERVER_CMD_PushVariable(*((void **) (p + 12)), 0x5a, 0xc4, 0xffff0000);
    return 0;
  }
  if ((*((u32 *) (p + 24))) == 1)
  {
    if (state != 6)
      BTL_SERVER_CMD_Push(*((void **) (p + 12)), 0x4d, state, 0x282);
    for (i = 0; i < 23; i++)
    {
      if (gBagItemEffectTable[i].exact && (move == gBagItemEffectTable[i].id))
      {
        result = 0;
        if (!BTL_SERVER_FLOW_IsPokeSemiInvulnerable(p, monId))
        {
          pos = BTL_SERVER_CMD_Reserve(*((void **) (p + 12)), 0x4d);
          result = gBagItemEffectTable[i].call(p, mon, move, 0, arg);
          if (result == 1)
          {
            BTL_SERVER_CMD_FillReserved(*((void **) (p + 12)), pos, 0x4d, state, 0x25e);
            BTL_SERVER_CMD_Push(*((void **) (p + 12)), 0x4c, 0x236);
            return 0;
          }
        }
        if (result == 0)
          BTL_SERVER_CMD_PushVariable(*((void **) (p + 12)), 0x5a, 0x44, 0xffff0000);
        BTL_SERVER_CMD_Push(*((void **) (p + 12)), 0x4c, 0x236);
        return 0;
      }
    }

  }
  mark = 0;
  pos = BTL_SERVER_CMD_Reserve(*((void **) (p + 12)), 0x4d);
  lock = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 1217);
  for (i = 0; i < 23; i++)
  {
    e = gBagItemEffectTable + i;
    result = BTL_CALC_GetMonParamWithHeap((void *)move, e->id);
    if (result && e->call(p, mon, move, result, arg))
      mark = 1;
  }

  if (mark)
  {
    BTL_SERVER_CMD_FillReserved(*((void **) (p + 12)), pos, 0x4d, state, (u16) ((state != 6) ? (0x25e) : (0x292)));
    if ((*((u32 *) (p + 24))) != 1)
    {
      BTL_MAIN_RemoveItemFromBag(*((u8 **) (p + 4)), side, move);
      BTL_MAIN_UpdateFriendshipUseItem(*((char **) (p + 4)), mon, move);
    }
  }
  else
    BTL_SERVER_CMD_PushVariable(*((void **) (p + 12)), 0x5a, 0x44, 0xffff0000);
  BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), lock, 1246);
  BTL_SERVER_CMD_Push(*((void **) (p + 12)), 0x4c, 0x236);
  return 0;
}
