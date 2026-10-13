/*
 * file:     plist_demo.c
 * unit:     yes
 * function: func_021BDABC, func_021BDBE0, func_021BDBF8, func_021BDC3C, func_021BDC5C, func_021BDCA0, func_021BDCC0, func_021BDD58, func_021BDD78, func_021BE2B4, func_021BE874, func_021BE914, func_021BE948, func_021BE9BC
 * address:  0x021BDABC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_020307B0 0x020307B0 arm
 *   POKE_TOOL_GetStatusCondition  0x02017F90  thumb
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *   func_02020F34 0x02020F34 thumb
 *   func_02021014 0x02021014 thumb
 *   func_02017988 0x02017988 thumb
 *   func_0205121C 0x0205121C arm
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   func_02050C04 0x02050C04 arm
 *   func_02051230 0x02051230 arm
 *   PARTICLE_StartEffect 0x020515B4 arm
 *   d_021BED58 0x021BED58 data ov091 a4
 *   func_02050DB8 0x02050DB8 arm
 *   GFL_NET_FreeAligned 0x0203D7FC arm
 *   func_0200CDE0 0x0200CDE0 thumb
 *   func_02011400  0x02011400  thumb
 *   func_0203F4CC  0x0203F4CC  arm
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb
 *   POKE_TOOL_IsPPRestorable 0x0201B920 thumb
 *   func_02018584 0x02018584 thumb
 *   func_020185C4 0x020185C4 thumb
 *   POKE_TOOL_RestorePP 0x0201B970 thumb
 *   func_021BEA48 0x021BEA48 thumb ov091
 *   func_021BB3D4  0x021BB3D4  thumb
 */
struct Rec;
struct RtcTime;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short s16;
typedef signed int     s32;

#include "plist_battle_types.h"
#include "plist_demo_types.h"

extern u32 func_02017E1C(void *,u32,u32);
extern void func_02017E40(void *,u32,u32);
extern u32 func_020307B0(void *p);
extern u32 POKE_TOOL_GetStatusCondition(void *p);
void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern void *func_02020F34(u32 item, u32 which, u32 heap);
extern u32 func_02021014(struct Rec *p, u32 sel);
extern u32 func_02017988(void *,u32);
extern int func_0205121C(u32,u32,u32);
extern void *GFL_NET_AllocAligned(u32,u32,const char *,u16);
extern void *func_02050C04(void *memory, int size, int a, int heap);
extern u32 func_020056BC(void);
extern void func_02051230(void *system, u32 handle, u32 a, u32 b);
extern int PARTICLE_StartEffect(void *p, int b, int c);
extern void func_02050DB8(void *system);
extern void GFL_NET_FreeAligned(void *);
extern void func_0200CDE0(void *zukanSave, void *mon);
extern u8 func_02011400(int row, int col);
extern void func_0203F4CC(struct RtcTime *time);
extern u8 WAZA_TOOL_GetMaxPP(u16, u32);
extern u8 POKE_TOOL_IsPPRestorable(void *, u32);
extern u32 func_02018584(u16, u16, u16);
extern void func_020185C4(void *);
extern u32 POKE_TOOL_RestorePP(void *, u32, u32);
extern int func_021BEA48(int, int, int, int, u16, int);
void func_021BB3D4(PlistWork *work, u8 *plate, PlistPos *out);
void func_021BDABC(PlistWork *work);
void func_021BDBE0(PlistWork *work);
int func_021BDBF8(PlistWork *work, void *unused);
void func_021BDC3C(PlistWork *work, void *mon);
int func_021BDC5C(PlistWork *work, void *unused);
void func_021BDCA0(PlistWork *work, void *mon);
int func_021BDCC0(PlistWork *work, u32 unused);
void func_021BDD58(PlistWork *work, void *mon);
int func_021BDD78(void *mon, u32 itemId, int moveSlot, u32 heapId);
int func_021BE2B4(void *mon, u16 item, u16 moveSlot, u16 arg, int heap);
int func_021BE874(void *mon, int moveSlot, int ups);
void func_021BE914(void *mon, u32 hp, u32 maxHp, u32 amount);
int func_021BE948(int ev, int otherEvTotal, int delta, int ignoreCap);
int func_021BE9BC(void *mon, void *itemRec);
extern u8 d_021BED58[];

/*
 * lever: two-halfword coordinate struct keeps its address sp-relative; int alias added 4 B.
 */
void func_021BDABC(PlistWork *work)
{
    u8 count;
    int member;
    int handle;
    PlistPos pos;
    int vec[3];
    u8 i;
    count = 0;
    member = 0x1c;
    if (work->evolveCheckKind - 1 <= 1) {
        member = 0x1b;
        count = 3;
        work->effectLength = 0x41;
    } else if (work->evolveCheckKind == 3) {
        count = 2;
        work->effectLength = 0x26;
    }
    handle = func_0205121C(0x4c, member, work->heapId);
    work->particleMemory = GFL_NET_AllocAligned(work->heapId, 0x5000, (const char *)d_021BED58, 0xea);
    work->particleSystem = func_02050C04(work->particleMemory, 0x5000, 0, work->heapId);
    func_02051230(work->particleSystem, handle, 0, func_020056BC());
    func_021BB3D4(work, (u8 *)work->plates[work->selectedSlot], &pos);
    pos.x -= 0x28;
    pos.y += 4;
    if (pos.x > 0) vec[0] = (int)(0.5f + (float)(pos.x << 12)) / 0x26;
    else vec[0] = (int)((float)(pos.x << 12) - 0.5f) / 0x26;
    if (pos.y > 0) vec[1] = (int)(0.5f + (float)(pos.y << 12)) / 0x26;
    else vec[1] = (int)((float)(pos.y << 12) - 0.5f) / 0x26;
    vec[2] = 0x40000;
    for (i = 0; i < count; i++) PARTICLE_StartEffect(work->particleSystem, i, (int)vec);
}

void func_021BDBE0(PlistWork *work)
{
    func_02050DB8(work->particleSystem);
    GFL_NET_FreeAligned(work->particleMemory);
}

int func_021BDBF8(PlistWork *work, void *unused)
{
    int result = 0;
    if (func_02017E1C((void *)work->selectedMon, PLIST_MON_SPECIES, 0) != PLIST_SPECIES_GIRATINA)
        return 0;
    if (func_02017E1C((void *)work->selectedMon, PLIST_MON_HELD_ITEM, result) != PLIST_ITEM_GRISEOUS_ORB)
        return 0;
    if (func_02017E1C((void *)work->selectedMon, PLIST_MON_FORM, result) == 0)
        result = 1;
    return result;
}

/*
 * Extent tail: two bytes of alignment padding at 0x021BDC5A.
 */
void func_021BDC3C(PlistWork *work, void *mon)
{
    func_02017988(mon, 1);
    func_0200CDE0(work->arg->zukanSave, mon);
}

int func_021BDC5C(PlistWork *work, void *unused)
{
    int result = 0;
    if (func_02017E1C((void *)work->selectedMon, PLIST_MON_HELD_ITEM, 0) == PLIST_ITEM_GRISEOUS_ORB)
        return 0;
    if (func_02017E1C((void *)work->selectedMon, PLIST_MON_SPECIES, result) != PLIST_SPECIES_GIRATINA)
        return 0;
    if (func_02017E1C((void *)work->selectedMon, PLIST_MON_FORM, result) == 1)
        result = 1;
    return result;
}

/*
 * Extent tail: two bytes of alignment padding at 0x021BDCBE.
 */
void func_021BDCA0(PlistWork *work, void *mon)
{
    func_02017988(mon, 0);
    func_0200CDE0(work->arg->zukanSave, mon);
}

int func_021BDCC0(PlistWork *work, u32 unused)
{
    u32 now[3];
    u32 dayStart, dayEnd;
    int result = 0;
    if (func_02017E1C((void *)work->selectedMon, PLIST_MON_SPECIES, 0) != PLIST_SPECIES_SHAYMIN)
        return result;
    if (func_02017E1C((void *)work->selectedMon, PLIST_MON_FORM, result) != 0)
        return result;
    if (func_02017E1C((void *)work->selectedMon, PLIST_MON_SPECIAL_FLAG, result) != 1)
        return result;
    if (POKE_TOOL_GetStatusCondition((void *)work->selectedMon) & 0x20)
        return result;
    dayStart = func_02011400(work->arg->season, result);
    dayEnd = func_02011400(work->arg->season, 3);
    func_0203F4CC((struct RtcTime *)now);
    if (now[0] < dayStart || now[0] >= dayEnd)
        return 0;
    return 1;
}

void func_021BDD58(PlistWork *work, void *mon)
{
    func_02017988(mon, 1);
    func_0200CDE0(work->arg->zukanSave, mon);
}

int func_021BDD78(void *mon, u32 itemId, int moveSlot, u32 heapId)
{
  void *itemRec;
  u32 result;
  u32 status;
  u32 hp;
  int i;
  long evAtk;
  long evDef;
  long evSpeed;
  long evSpAtk;
  long evSpDef;
  long evHp;
  int ignoreCap;
  int amount;
  int positive;
  itemRec = func_02020F34(itemId, 0, (u16)heapId);
  result = 0;
  if (func_02021014(itemRec, PLIST_ITEM_USABLE_ON_PARTY) != 1)
  {
    func_020307B0(itemRec);
    return result;
  }
  status = POKE_TOOL_GetStatusCondition(mon);
  if ((func_02021014(itemRec, PLIST_ITEM_CURES_SLEEP) != 0) && (status == 2))
  {
    func_020307B0(itemRec);
    return 1;
  }
  if ((func_02021014(itemRec, PLIST_ITEM_CURES_POISON) != 0) && (status == 5))
  {
    func_020307B0(itemRec);
    return 1;
  }
  if ((func_02021014(itemRec, PLIST_ITEM_CURES_BURN) != 0) && (status == 4))
  {
    func_020307B0(itemRec);
    return 1;
  }
  if ((func_02021014(itemRec, PLIST_ITEM_CURES_FREEZE) != 0) && (status == 3))
  {
    func_020307B0(itemRec);
    return 1;
  }
  if ((func_02021014(itemRec, PLIST_ITEM_CURES_PARALYSIS) != 0) && (status == 1))
  {
    func_020307B0(itemRec);
    return 1;
  }
  hp = func_02017E1C(mon, PLIST_MON_HP, 0);
  if (((func_02021014(itemRec, PLIST_ITEM_REVIVES) != 0) || (func_02021014(itemRec, PLIST_ITEM_REVIVES_FULL) != 0)) && (func_02021014(itemRec, PLIST_ITEM_RAISES_LEVEL) == 0))
  {
    if (hp == 0)
    {
      func_020307B0(itemRec);
      return 1;
    }
  }
  else
    if (((func_02021014(itemRec, PLIST_ITEM_RESTORES_HP) != 0) && (hp != 0)) && (hp < func_02017E1C(mon, PLIST_MON_MAX_HP, 0)))
  {
    func_020307B0(itemRec);
    return 1;
  }
  if ((func_02021014(itemRec, PLIST_ITEM_RAISES_LEVEL) != 0) && (func_02017E1C(mon, PLIST_MON_LEVEL, 0) < 100))
  {
    func_020307B0(itemRec);
    return 1;
  }
  if ((func_02021014(itemRec, PLIST_ITEM_RAISES_PP_UPS) != 0) || (func_02021014(itemRec, PLIST_ITEM_MAXES_PP_UPS) != 0))
  {
    result = 0;
    if ((func_02017E1C(mon, moveSlot + PLIST_MON_MOVE_PP_UPS, 0) < 3) && (WAZA_TOOL_GetMaxPP((u16) func_02017E1C(mon, moveSlot + PLIST_MON_MOVE_ID, 0), result) >= 5))
    {
      func_020307B0(itemRec);
      return 1;
    }
  }
  if ((func_02021014(itemRec, PLIST_ITEM_RESTORES_PP_ONE) != 0) && (POKE_TOOL_IsPPRestorable(mon, moveSlot) == 1))
  {
    func_020307B0(itemRec);
    return 1;
  }
  if (func_02021014(itemRec, PLIST_ITEM_RESTORES_PP_ALL) != 0)
  {
    for (i = 0; i < 4; i++)
    {
      if (POKE_TOOL_IsPPRestorable(mon, i) == 1)
      {
        func_020307B0(itemRec);
        return 1;
      }
    }

  }
  evHp = func_02017E1C(mon, PLIST_MON_EV_HP, 0);
  evAtk = func_02017E1C(mon, PLIST_MON_EV_ATK, 0);
  evDef = func_02017E1C(mon, PLIST_MON_EV_DEF, 0);
  evSpeed = func_02017E1C(mon, PLIST_MON_EV_SPEED, 0);
  evSpAtk = func_02017E1C(mon, PLIST_MON_EV_SPATK, 0);
  evSpDef = func_02017E1C(mon, PLIST_MON_EV_SPDEF, 0);
  ignoreCap = func_02021014(itemRec, PLIST_ITEM_EV_IGNORES_CAP);
  if (func_02017E1C(mon, PLIST_MON_SPECIES, 0) != PLIST_SPECIES_SHEDINJA)
    if (func_02021014(itemRec, PLIST_ITEM_CHANGES_EV_HP) != 0)
  {
    amount = func_02021014(itemRec, PLIST_ITEM_EV_HP_AMOUNT);
    if (amount > 0)
    {
      if ((((evHp < 100) || (ignoreCap != 0)) && (evHp < 255)) && ((((((evHp + evAtk) + evDef) + evSpeed) + evSpAtk) + evSpDef) < 510))
      {
        func_020307B0(itemRec);
        return 1;
      }
    }
    else
      if (amount < 0)
    {
      if (evHp > 0)
      {
        func_020307B0(itemRec);
        return 1;
      }
      if (func_021BE9BC(mon, itemRec) == 1)
      {
        func_020307B0(itemRec);
        return 1;
      }
    }
  }
  if (func_02021014(itemRec, PLIST_ITEM_CHANGES_EV_ATK) != 0)
  {
    amount = func_02021014(itemRec, PLIST_ITEM_EV_ATK_AMOUNT);
    if (amount > 0)
    {
      if ((((evAtk < 100) || (ignoreCap != 0)) && (evAtk < 255)) && ((((((evHp + evAtk) + evDef) + evSpeed) + evSpAtk) + evSpDef) < 510))
      {
        func_020307B0(itemRec);
        return 1;
      }
    }
    else
      if (amount < 0)
    {
      if (evAtk > 0)
      {
        func_020307B0(itemRec);
        return 1;
      }
      if (func_021BE9BC(mon, itemRec) == 1)
      {
        func_020307B0(itemRec);
        return 1;
      }
    }
  }
  if (func_02021014(itemRec, PLIST_ITEM_CHANGES_EV_DEF) != 0)
  {
    amount = func_02021014(itemRec, PLIST_ITEM_EV_DEF_AMOUNT);
    if (amount > 0)
    {
      if ((((evDef < 100) || (ignoreCap != 0)) && (evDef < 255)) && ((((((evHp + evAtk) + evDef) + evSpeed) + evSpAtk) + evSpDef) < 510))
      {
        func_020307B0(itemRec);
        return 1;
      }
    }
    else
      if (amount < 0)
    {
      if (evDef > 0)
      {
        func_020307B0(itemRec);
        return 1;
      }
      if (func_021BE9BC(mon, itemRec) == 1)
      {
        func_020307B0(itemRec);
        return 1;
      }
    }
  }
  if (func_02021014(itemRec, PLIST_ITEM_CHANGES_EV_SPEED) != 0)
  {
    amount = func_02021014(itemRec, PLIST_ITEM_EV_SPEED_AMOUNT);
    if (amount > 0)
    {
      if ((((evSpeed < 100) || (ignoreCap != 0)) && (evSpeed < 255)) && ((((((evHp + evAtk) + evDef) + evSpeed) + evSpAtk) + evSpDef) < 510))
      {
        func_020307B0(itemRec);
        return 1;
      }
    }
    else
      if (amount < 0)
    {
      if (evSpeed > 0)
      {
        func_020307B0(itemRec);
        return 1;
      }
      if (func_021BE9BC(mon, itemRec) == 1)
      {
        func_020307B0(itemRec);
        return 1;
      }
    }
  }
  if (func_02021014(itemRec, PLIST_ITEM_CHANGES_EV_SPATK) != 0)
  {
    amount = func_02021014(itemRec, PLIST_ITEM_EV_SPATK_AMOUNT);
    if (amount > 0)
    {
      if ((((evSpAtk < 100) || (ignoreCap != 0)) && (evSpAtk < 255)) && ((((((evHp + evAtk) + evDef) + evSpeed) + evSpAtk) + evSpDef) < 510))
      {
        func_020307B0(itemRec);
        return 1;
      }
    }
    else
      if (amount < 0)
    {
      if (evSpAtk > 0)
      {
        func_020307B0(itemRec);
        return 1;
      }
      if (func_021BE9BC(mon, itemRec) == 1)
      {
        func_020307B0(itemRec);
        return 1;
      }
    }
  }
  if (func_02021014(itemRec, PLIST_ITEM_CHANGES_EV_SPDEF) != 0)
  {
    amount = func_02021014(itemRec, PLIST_ITEM_EV_SPDEF_AMOUNT);
    positive = amount > 0;
    if (positive)
    {
      if ((((evSpDef < 100) || (ignoreCap != 0)) && (evSpDef < 255)) && ((((((evHp + evAtk) + evDef) + evSpeed) + evSpAtk) + evSpDef) < 510))
      {
        func_020307B0(itemRec);
        return 1;
      }
    }
    else
      if (amount < 0)
    {
      if (evSpDef > 0)
      {
        func_020307B0(itemRec);
        return 1;
      }
      if (func_021BE9BC(mon, itemRec) == 1)
      {
        func_020307B0(itemRec);
        return 1;
      }
    }
  }
  {
    func_020307B0(itemRec);
    return 0;
  }
}

/*
 * levers: wave 82 R12. Real callee prototypes (02020F34 heap u32, 021BEA48 first int)
 *   with the caller-side (u16)heap narrowing the listing shows before 02020F34; item and
 *   moveSlot are u16 parameters (callers pass ldrh values / constant 0). u16 item
 *   fixed 31 of 35 bytes (spill reloads of item), u16 or u8 moveSlot the last 4 (r2 spill
 *   order); u16 chosen with item/arg, no byte evidence between u16 and u8.
 */
int func_021BE2B4(void *mon, u16 item, u16 moveSlot, u16 arg, int heap)
{
    void *itemRec;
    int changed = 0;
    int applicable;
    int originalStatus, status, evSpAtk, evSpDef, ignoreCap, amount;
    int evHp, hp, evAtk, maxHp, evDef, evSpeed, level, friendship, result, i;
    itemRec = func_02020F34(item, 0, (u16)heap);
    if (func_02021014(itemRec, PLIST_ITEM_USABLE_ON_PARTY) != 1) { func_020307B0(itemRec); return changed; }
    applicable = 0;
    originalStatus = func_02017E1C(mon, PLIST_MON_STATUS, 0);
    status = originalStatus;
    if (func_02021014(itemRec, PLIST_ITEM_CURES_SLEEP)) { status = 0; applicable = 1; }
    if (func_02021014(itemRec, PLIST_ITEM_CURES_POISON)) { status = 0; applicable = 1; }
    if (func_02021014(itemRec, PLIST_ITEM_CURES_BURN)) { status = 0; applicable = 1; }
    if (func_02021014(itemRec, PLIST_ITEM_CURES_FREEZE)) { status = 0; applicable = 1; }
    if (func_02021014(itemRec, PLIST_ITEM_CURES_PARALYSIS)) { status = 0; applicable = 1; }
    if (originalStatus != status) { func_02017E40(mon, PLIST_MON_STATUS, status); changed = 1; }
    hp = func_02017E1C(mon, PLIST_MON_HP, 0);
    maxHp = func_02017E1C(mon, PLIST_MON_MAX_HP, 0);
    if ((func_02021014(itemRec, PLIST_ITEM_REVIVES) || func_02021014(itemRec, PLIST_ITEM_REVIVES_FULL)) && !func_02021014(itemRec, PLIST_ITEM_RAISES_LEVEL)) {
        if (hp == 0) {
            func_021BE914(mon, hp, maxHp, func_02021014(itemRec, PLIST_ITEM_HP_AMOUNT));
            changed = 1;
        }
        applicable = 1;
    } else if (func_02021014(itemRec, PLIST_ITEM_RESTORES_HP)) {
        if (hp < maxHp) { func_021BE914(mon, hp, maxHp, func_02021014(itemRec, PLIST_ITEM_HP_AMOUNT)); changed = 1; }
        applicable = 1;
    }
    level = func_02017E1C(mon, PLIST_MON_LEVEL, 0);
    if (func_02021014(itemRec, PLIST_ITEM_RAISES_LEVEL)) {
        if (level < 100) {
            i = func_02017E1C(mon, PLIST_MON_SPECIES, 0);
            result = func_02017E1C(mon, PLIST_MON_FORM, 0);
            func_02017E40(mon, PLIST_MON_EXP, func_02018584(i, result, level + 1));
            func_020185C4(mon);
            if (hp == 0) {
                result = func_02017E1C(mon, PLIST_MON_MAX_HP, 0);
                func_021BE914(mon, hp, result, result - maxHp);
            }
            changed = 1;
        }
        applicable = 1;
    }
    if (func_02021014(itemRec, PLIST_ITEM_EVOLVES)) applicable = 1;
    if (func_02021014(itemRec, PLIST_ITEM_RAISES_PP_UPS)) {
        applicable = 1;
        if (func_021BE874(mon, moveSlot, 1) == 1) changed = 1;
        applicable = 1;
    } else if (func_02021014(itemRec, PLIST_ITEM_MAXES_PP_UPS)) {
        if (func_021BE874(mon, moveSlot, 3) == 1) changed = 1;
        applicable = 1;
    }
    if (func_02021014(itemRec, PLIST_ITEM_RESTORES_PP_ONE)) {
        if (POKE_TOOL_RestorePP(mon, moveSlot, func_02021014(itemRec, PLIST_ITEM_PP_AMOUNT)) == 1) changed = 1;
        applicable = 1;
    } else if (func_02021014(itemRec, PLIST_ITEM_RESTORES_PP_ALL)) {
        for (i = 0; i < 4; i++) if (POKE_TOOL_RestorePP(mon, i, func_02021014(itemRec, PLIST_ITEM_PP_AMOUNT)) == 1) changed = 1;
        applicable = 1;
    }
    evHp = func_02017E1C(mon, PLIST_MON_EV_HP, 0);
    evAtk = func_02017E1C(mon, PLIST_MON_EV_ATK, 0);
    evDef = func_02017E1C(mon, PLIST_MON_EV_DEF, 0);
    evSpeed = func_02017E1C(mon, PLIST_MON_EV_SPEED, 0);
    evSpAtk = func_02017E1C(mon, PLIST_MON_EV_SPATK, 0);
    evSpDef = func_02017E1C(mon, PLIST_MON_EV_SPDEF, 0);
    ignoreCap = func_02021014(itemRec, PLIST_ITEM_EV_IGNORES_CAP);
    if (func_02017E1C(mon, PLIST_MON_SPECIES, 0) != PLIST_SPECIES_SHEDINJA && func_02021014(itemRec, PLIST_ITEM_CHANGES_EV_HP)) {
        amount = func_02021014(itemRec, PLIST_ITEM_EV_HP_AMOUNT);
        result = func_021BE948(evHp, evSpDef + (evSpAtk + (evSpeed + (evAtk + evDef))), amount, ignoreCap);
        if (result != -1) { evHp = result; func_02017E40(mon, PLIST_MON_EV_HP, result); func_020185C4(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (func_02021014(itemRec, PLIST_ITEM_CHANGES_EV_ATK)) {
        amount = func_02021014(itemRec, PLIST_ITEM_EV_ATK_AMOUNT);
        result = func_021BE948(evAtk, evSpDef + (evSpAtk + (evSpeed + (evHp + evDef))), amount, ignoreCap);
        if (result != -1) { evAtk = result; func_02017E40(mon, PLIST_MON_EV_ATK, result); func_020185C4(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (func_02021014(itemRec, PLIST_ITEM_CHANGES_EV_DEF)) {
        amount = func_02021014(itemRec, PLIST_ITEM_EV_DEF_AMOUNT);
        result = func_021BE948(evDef, evSpDef + (evSpAtk + (evSpeed + (evHp + evAtk))), amount, ignoreCap);
        if (result != -1) { evDef = result; func_02017E40(mon, PLIST_MON_EV_DEF, result); func_020185C4(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (func_02021014(itemRec, PLIST_ITEM_CHANGES_EV_SPEED)) {
        amount = func_02021014(itemRec, PLIST_ITEM_EV_SPEED_AMOUNT);
        result = func_021BE948(evSpeed, evSpDef + (evSpAtk + (evDef + (evHp + evAtk))), amount, ignoreCap);
        if (result != -1) { evSpeed = result; func_02017E40(mon, PLIST_MON_EV_SPEED, result); func_020185C4(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (func_02021014(itemRec, PLIST_ITEM_CHANGES_EV_SPATK)) {
        amount = func_02021014(itemRec, PLIST_ITEM_EV_SPATK_AMOUNT);
        result = func_021BE948(evSpAtk, evSpDef + (evSpeed + (evDef + (evHp + evAtk))), amount, ignoreCap);
        if (result != -1) { evSpAtk = result; func_02017E40(mon, PLIST_MON_EV_SPATK, result); func_020185C4(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (func_02021014(itemRec, PLIST_ITEM_CHANGES_EV_SPDEF)) {
        amount = func_02021014(itemRec, PLIST_ITEM_EV_SPDEF_AMOUNT);
        result = func_021BE948(evSpDef, evSpAtk + (evSpeed + (evDef + (evHp + evAtk))), amount, ignoreCap);
        if (result != -1) { func_02017E40(mon, PLIST_MON_EV_SPDEF, result); func_020185C4(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (changed == 0 && applicable == 1) { func_020307B0(itemRec); return 0; }
    friendship = func_02017E1C(mon, PLIST_MON_FRIENDSHIP, 0);
    if (friendship < 100) {
        if (func_02021014(itemRec, PLIST_ITEM_FRIENDSHIP_LOW)) {
            func_021BEA48((int)mon, friendship, func_02021014(itemRec, PLIST_ITEM_FRIENDSHIP_LOW_AMOUNT), item, arg, heap);
            func_020307B0(itemRec); return changed;
        }
    } else if (friendship >= 100 && friendship < 200) {
        if (func_02021014(itemRec, PLIST_ITEM_FRIENDSHIP_MID)) {
            func_021BEA48((int)mon, friendship, func_02021014(itemRec, PLIST_ITEM_FRIENDSHIP_MID_AMOUNT), item, arg, heap);
            func_020307B0(itemRec); return changed;
        }
    } else if (friendship >= 200 && friendship <= 255) {
        if (func_02021014(itemRec, PLIST_ITEM_FRIENDSHIP_HIGH)) {
            func_021BEA48((int)mon, friendship, func_02021014(itemRec, PLIST_ITEM_FRIENDSHIP_HIGH_AMOUNT), item, arg, heap);
            func_020307B0(itemRec); return changed;
        }
    }
    func_020307B0(itemRec);
    return changed;
}

int func_021BE874(void *mon, int moveSlot, int ups)
{
    int result = 0;
    u16 moveId;
    u32 oldMaxPp;
    u32 pp;
    u32 upCount;
    int newUps;
    upCount = (u8)func_02017E1C(mon, moveSlot + PLIST_MON_MOVE_PP_UPS, 0);
    if (upCount == 3)
        return result;
    moveId = (u16)func_02017E1C(mon, moveSlot + PLIST_MON_MOVE_ID, result);
    if (WAZA_TOOL_GetMaxPP(moveId, result) < 5)
        return result;
    pp = (u8)func_02017E1C(mon, moveSlot + PLIST_MON_MOVE_PP, result);
    oldMaxPp = WAZA_TOOL_GetMaxPP(moveId, upCount);
    newUps = upCount + ups;
    if ((u32)newUps > 3)
        upCount = 3;
    else
        upCount = (u8)newUps;
    pp = (u8)(pp + WAZA_TOOL_GetMaxPP(moveId, upCount) - oldMaxPp);
    func_02017E40(mon, moveSlot + PLIST_MON_MOVE_PP_UPS, upCount);
    func_02017E40(mon, moveSlot + PLIST_MON_MOVE_PP, pp);
    return 1;
}

void func_021BE914(void *mon, u32 hp, u32 maxHp, u32 amount)
{
    if (maxHp == 1) amount = 1;
    else if (amount == 0xff) amount = maxHp;
    else if (amount == 0xfe) amount = maxHp >> 1;
    else if (amount == 0xfd) amount = maxHp >> 2;
    hp += amount;
    if (hp > maxHp) hp = maxHp;
    func_02017E40(mon, PLIST_MON_HP, hp);
}

int func_021BE948(int ev, int otherEvTotal, int delta, int ignoreCap)
{
    if (ev == 0 && delta < 0)
        return -1;
    if (ev == 0xff && delta > 0)
        return -1;
    if (ev >= 100 && ignoreCap == 0 && delta > 0)
        return -1;
    if (ev + otherEvTotal >= 0x1FE && delta > 0)
        return -1;
    ev += delta;
    if (delta > 0 && ev > 100 && ignoreCap == 0)
        ev = 100;
    else if (ev < 0)
        ev = 0;
    if (ev + otherEvTotal > 0x1FE)
        ev = 0x1FE - otherEvTotal;
    return ev;
}

int func_021BE9BC(void *mon, void *itemRec)
{
    int result = 0;
    int friendship = func_02017E1C(mon, PLIST_MON_FRIENDSHIP, 0);
    if (friendship >= 0xFF)
        return result;
    if (friendship < 100) {
        if ((int)func_02021014(itemRec, PLIST_ITEM_FRIENDSHIP_LOW) != 0 && (int)func_02021014(itemRec, PLIST_ITEM_FRIENDSHIP_LOW_AMOUNT) > 0)
            return 1;
        return 0;
    }
    if (friendship >= 100 && friendship < 200) {
        if ((int)func_02021014(itemRec, PLIST_ITEM_FRIENDSHIP_MID) != 0 && (int)func_02021014(itemRec, PLIST_ITEM_FRIENDSHIP_MID_AMOUNT) > 0)
            return 1;
        return 0;
    }
    if (friendship >= 200 && friendship < 0xFF) {
        if ((int)func_02021014(itemRec, PLIST_ITEM_FRIENDSHIP_HIGH) != 0 && (int)func_02021014(itemRec, PLIST_ITEM_FRIENDSHIP_HIGH_AMOUNT) > 0)
            return 1;
        return 0;
    }
    return 0;
}
