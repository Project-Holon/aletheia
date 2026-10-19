/*
 * function: PLIST_DEMO_CheckItemUsable
 * address: 0x021BDD78
 * packet: pkt_ov091_021BDD78
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * residual: MATCH 1340/1340,81/82 resolved; zero concrete byte differences.
 * blocker: ARM9 02020F34 lacks an outside witness; the integrator owns it. No leaf attempted.
 * renewed: wave75 R30 direct s2/s4 declaration swap fixes all 20 bytes; one and TU agree.
 * checks: 1 own ARM9 getter interfaces and BE9BC re-read; 2 no additional twin; 3 direct spill-slot declaration correction; 4 spill-order idiom; 5 fresh neighbours. TU suggest-split has no cut for 02020F34. Prior permuter remains spent.
 * permuter: temp(tmp=v > 0) only in final stat block; decl-order(s5<->s1); no type/signature change, all reads assigned before use.
 * ABI: heap is narrowed before 02020F34; its extern uses u16 to retain that caller truncation.
 * symbols:
 *   FILE_UTIL_LoadItemRecord 0x02020F34 thumb
 *   FILE_UTIL_GetItemRecordParam 0x02021014 thumb
 *   POKE_TOOL_GetStatusCondition 0x02017F90 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb
 *   POKE_TOOL_IsPPRestorable 0x0201B920 thumb
 *   func_020307B0 0x020307B0 arm
 *   PLIST_DEMO_FriendshipItemApplies 0x021BE9BC thumb ov091
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern void *FILE_UTIL_LoadItemRecord(u32 item, u32 which, u32 heap);
struct Rec;
extern u32 FILE_UTIL_GetItemRecordParam(struct Rec *p, u32 sel);
extern u32 POKE_TOOL_GetStatusCondition(void *);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern u8 WAZA_TOOL_GetMaxPP(u16, u32);
extern u8 POKE_TOOL_IsPPRestorable(void *, u32);
extern u32 func_020307B0(void *p);
extern int PLIST_DEMO_FriendshipItemApplies(void *, void *);
int PLIST_DEMO_CheckItemUsable(void *a, u32 id, int slot, u32 heap)
{
  void *p;
  u32 r;
  u32 sex;
  u32 hp;
  int i;
  long s1;
  long s2;
  long s3;
  long s4;
  long s5;
  long s0;
  int flag;
  int v;
  int tmp;
  p = FILE_UTIL_LoadItemRecord(id, 0, (u16)heap);
  r = 0;
  if (FILE_UTIL_GetItemRecordParam(p, 14) != 1)
  {
    func_020307B0(p);
    return r;
  }
  ;
  sex = POKE_TOOL_GetStatusCondition(a);
  if ((FILE_UTIL_GetItemRecordParam(p, 18) != 0) && (sex == 2))
  {
    func_020307B0(p);
    return 1;
  }
  ;
  if ((FILE_UTIL_GetItemRecordParam(p, 19) != 0) && (sex == 5))
  {
    func_020307B0(p);
    return 1;
  }
  ;
  if ((FILE_UTIL_GetItemRecordParam(p, 20) != 0) && (sex == 4))
  {
    func_020307B0(p);
    return 1;
  }
  ;
  if ((FILE_UTIL_GetItemRecordParam(p, 21) != 0) && (sex == 3))
  {
    func_020307B0(p);
    return 1;
  }
  ;
  if ((FILE_UTIL_GetItemRecordParam(p, 22) != 0) && (sex == 1))
  {
    func_020307B0(p);
    return 1;
  }
  ;
  hp = POKE_TOOL_GetPartyValue(a, 0xA0, 0);
  if (((FILE_UTIL_GetItemRecordParam(p, 26) != 0) || (FILE_UTIL_GetItemRecordParam(p, 27) != 0)) && (FILE_UTIL_GetItemRecordParam(p, 28) == 0))
  {
    if (hp == 0)
    {
      func_020307B0(p);
      return 1;
    }
    ;
  }
  else
    if (((FILE_UTIL_GetItemRecordParam(p, 41) != 0) && (hp != 0)) && (hp < POKE_TOOL_GetPartyValue(a, 0xA1, 0)))
  {
    func_020307B0(p);
    return 1;
  }
  ;
  if ((FILE_UTIL_GetItemRecordParam(p, 28) != 0) && (POKE_TOOL_GetPartyValue(a, 0x9E, 0) < 100))
  {
    func_020307B0(p);
    return 1;
  }
  ;
  if ((FILE_UTIL_GetItemRecordParam(p, 37) != 0) || (FILE_UTIL_GetItemRecordParam(p, 38) != 0))
  {
    r = 0;
    if ((POKE_TOOL_GetPartyValue(a, slot + 0x3E, 0) < 3) && (WAZA_TOOL_GetMaxPP((u16) POKE_TOOL_GetPartyValue(a, slot + 0x36, 0), r) >= 5))
    {
      func_020307B0(p);
      return 1;
    }
    ;
  }
  if ((FILE_UTIL_GetItemRecordParam(p, 39) != 0) && (POKE_TOOL_IsPPRestorable(a, slot) == 1))
  {
    func_020307B0(p);
    return 1;
  }
  ;
  if (FILE_UTIL_GetItemRecordParam(p, 40) != 0)
  {
    for (i = 0; i < 4; i++)
    {
      if (POKE_TOOL_IsPPRestorable(a, i) == 1)
      {
        func_020307B0(p);
        return 1;
      }
      ;
    }

  }
  s0 = POKE_TOOL_GetPartyValue(a, 13, 0);
  s1 = POKE_TOOL_GetPartyValue(a, 14, 0);
  s2 = POKE_TOOL_GetPartyValue(a, 15, 0);
  s3 = POKE_TOOL_GetPartyValue(a, 16, 0);
  s4 = POKE_TOOL_GetPartyValue(a, 17, 0);
  s5 = POKE_TOOL_GetPartyValue(a, 18, 0);
  flag = FILE_UTIL_GetItemRecordParam(p, 48);
  if (POKE_TOOL_GetPartyValue(a, 5, 0) != 0x124)
    if (FILE_UTIL_GetItemRecordParam(p, 42) != 0)
  {
    v = FILE_UTIL_GetItemRecordParam(p, 52);
    if (v > 0)
    {
      if ((((s0 < 100) || (flag != 0)) && (s0 < 255)) && ((((((s0 + s1) + s2) + s3) + s4) + s5) < 510))
      {
        func_020307B0(p);
        return 1;
      }
    }
    else
      if (v < 0)
    {
      if (s0 > 0)
      {
        func_020307B0(p);
        return 1;
      }
      if (PLIST_DEMO_FriendshipItemApplies(a, p) == 1)
      {
        func_020307B0(p);
        return 1;
      }
    }
  }
  ;
  if (FILE_UTIL_GetItemRecordParam(p, 43) != 0)
  {
    v = FILE_UTIL_GetItemRecordParam(p, 53);
    if (v > 0)
    {
      if ((((s1 < 100) || (flag != 0)) && (s1 < 255)) && ((((((s0 + s1) + s2) + s3) + s4) + s5) < 510))
      {
        func_020307B0(p);
        return 1;
      }
    }
    else
      if (v < 0)
    {
      if (s1 > 0)
      {
        func_020307B0(p);
        return 1;
      }
      if (PLIST_DEMO_FriendshipItemApplies(a, p) == 1)
      {
        func_020307B0(p);
        return 1;
      }
    }
  }
  ;
  if (FILE_UTIL_GetItemRecordParam(p, 44) != 0)
  {
    v = FILE_UTIL_GetItemRecordParam(p, 54);
    if (v > 0)
    {
      if ((((s2 < 100) || (flag != 0)) && (s2 < 255)) && ((((((s0 + s1) + s2) + s3) + s4) + s5) < 510))
      {
        func_020307B0(p);
        return 1;
      }
    }
    else
      if (v < 0)
    {
      if (s2 > 0)
      {
        func_020307B0(p);
        return 1;
      }
      if (PLIST_DEMO_FriendshipItemApplies(a, p) == 1)
      {
        func_020307B0(p);
        return 1;
      }
    }
  }
  ;
  if (FILE_UTIL_GetItemRecordParam(p, 45) != 0)
  {
    v = FILE_UTIL_GetItemRecordParam(p, 55);
    if (v > 0)
    {
      if ((((s3 < 100) || (flag != 0)) && (s3 < 255)) && ((((((s0 + s1) + s2) + s3) + s4) + s5) < 510))
      {
        func_020307B0(p);
        return 1;
      }
    }
    else
      if (v < 0)
    {
      if (s3 > 0)
      {
        func_020307B0(p);
        return 1;
      }
      if (PLIST_DEMO_FriendshipItemApplies(a, p) == 1)
      {
        func_020307B0(p);
        return 1;
      }
    }
  }
  ;
  if (FILE_UTIL_GetItemRecordParam(p, 46) != 0)
  {
    v = FILE_UTIL_GetItemRecordParam(p, 56);
    if (v > 0)
    {
      if ((((s4 < 100) || (flag != 0)) && (s4 < 255)) && ((((((s0 + s1) + s2) + s3) + s4) + s5) < 510))
      {
        func_020307B0(p);
        return 1;
      }
    }
    else
      if (v < 0)
    {
      if (s4 > 0)
      {
        func_020307B0(p);
        return 1;
      }
      if (PLIST_DEMO_FriendshipItemApplies(a, p) == 1)
      {
        func_020307B0(p);
        return 1;
      }
    }
  }
  ;
  if (FILE_UTIL_GetItemRecordParam(p, 47) != 0)
  {
    v = FILE_UTIL_GetItemRecordParam(p, 57);
    tmp = v > 0;
    if (tmp)
    {
      if ((((s5 < 100) || (flag != 0)) && (s5 < 255)) && ((((((s0 + s1) + s2) + s3) + s4) + s5) < 510))
      {
        func_020307B0(p);
        return 1;
      }
    }
    else
      if (v < 0)
    {
      if (s5 > 0)
      {
        func_020307B0(p);
        return 1;
      }
      if (PLIST_DEMO_FriendshipItemApplies(a, p) == 1)
      {
        func_020307B0(p);
        return 1;
      }
    }
  }
  ;
  {
    func_020307B0(p);
    return 0;
  }
  ;
}
