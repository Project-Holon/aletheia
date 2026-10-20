/*
 * file:     plist_demo.c
 * unit:     yes
 * function: PLIST_DEMO_CreateParticles, PLIST_DEMO_DeleteParticles, PLIST_DEMO_CheckGiratinaToOrigin, PLIST_DEMO_ApplyGiratinaOriginForm, PLIST_DEMO_CheckGiratinaToAltered, PLIST_DEMO_ApplyGiratinaAlteredForm, PLIST_DEMO_CanUseGracidea, PLIST_DEMO_ApplyShayminSkyForm, PLIST_DEMO_CheckItemUsable, PLIST_DEMO_UseItemOnMon, PLIST_DEMO_RaiseMovePpUps, PLIST_DEMO_RestoreHp, PLIST_DEMO_AddEv, PLIST_DEMO_FriendshipItemApplies, PLIST_DEMO_ApplyFriendshipItem
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
 * The sixth parameter is passed as the callee's narrow fourth parameter, so
 * mwcc truncates it at the call site; see
 * docs/idioms/a-narrow-callee-parameter-truncates-at-the-call-site.md.
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   POKE_TOOL_GetStatusCondition  0x02017F90  thumb
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *   FILE_UTIL_LoadItemRecord 0x02020F34 thumb
 *   FILE_UTIL_GetItemRecordParam 0x02021014 thumb
 *   POKE_TOOL_ChangeForm 0x02017988 thumb
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   PARTICLE_SetupSystem 0x02051230 arm
 *   PARTICLE_StartEffect 0x020515B4 arm
 *   d_021BED58 0x021BED58 data ov091 a4
 *   PARTICLE_DeleteSystem 0x02050DB8 arm
 *   GFL_NET_FreeAligned 0x0203D7FC arm
 *   ZUKAN_SAVE_RegisterCaught 0x0200CDE0 thumb
 *   TIMEZONE_GetLight  0x02011400  thumb
 *   GF_STANDARD_GetCachedTime  0x0203F4CC  arm
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb
 *   POKE_TOOL_IsPPRestorable 0x0201B920 thumb
 *   POKE_TOOL_GetExpForLevel 0x02018584 thumb
 *   POKE_TOOL_RecalcParam 0x020185C4 thumb
 *   POKE_TOOL_RestorePP 0x0201B970 thumb
 *   PLIST_PLATE_GetCenterPos  0x021BB3D4  thumb
 *   NATSUKI_CalcUseItem  0x0201B7B4  thumb
 *   GFL_USE_GetMainTaskList  0x020056BC  thumb  arm9
 *   _fadd                        0x0209C95C  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _fsub                        0x0209CB8C  arm
 */
#include "../types.h"

#include "pokelist_types.h"
#include "plist_battle_types.h"
#include "plist_demo_types.h"

struct Rec;
struct RtcTime;
struct PokemonParam;
#include "../arm9/poke_tool.h"
#include "../arm9/gfl_heap_wrap.h"
struct TaskMenuWin;
#include "../arm9/app_taskmenu.h"
#include "../arm9/file_util.h"
struct ItemRecord;
#include "../arm9/particle.h"
#include "../arm9/net.h"
struct ParticleSys;
struct TcbList;
#include "../arm9/gfl_use.h"
struct ParticleSys;
struct ParticleSys;
struct ParticleSys;
struct ZukanSave;
#include "../arm9/zukan_save.h"
#include "../arm9/timezone.h"
#include "../arm9/gf_standard.h"
#include "../arm9/waza_tool.h"
#include "../arm9/poke_tool_ext.h"
struct PlistPlatePos;
struct PlistPlate;
#include "plist_plate.h"
#include "../arm9/natsuki.h"
void PLIST_DEMO_CreateParticles(PokelistWork *work);
void PLIST_DEMO_DeleteParticles(PokelistWork *work);
int PLIST_DEMO_CheckGiratinaToOrigin(PokelistWork *work, void *unused);
void PLIST_DEMO_ApplyGiratinaOriginForm(PokelistWork *work, void *mon);
int PLIST_DEMO_CheckGiratinaToAltered(PokelistWork *work, void *unused);
void PLIST_DEMO_ApplyGiratinaAlteredForm(PokelistWork *work, void *mon);
int PLIST_DEMO_CanUseGracidea(PokelistWork *work, u32 unused);
void PLIST_DEMO_ApplyShayminSkyForm(PokelistWork *work, void *mon);
int PLIST_DEMO_CheckItemUsable(void *mon, u32 itemId, int moveSlot, u32 heapId);
int PLIST_DEMO_UseItemOnMon(void *mon, u16 item, u16 moveSlot, u16 arg, int heap);
int PLIST_DEMO_RaiseMovePpUps(void *mon, int moveSlot, int ups);
void PLIST_DEMO_RestoreHp(void *mon, u32 hp, u32 maxHp, u32 amount);
int PLIST_DEMO_AddEv(int ev, int otherEvTotal, int delta, int ignoreCap);
int PLIST_DEMO_FriendshipItemApplies(void *mon, void *itemRec);
int PLIST_DEMO_ApplyFriendshipItem(struct PokemonParam *mon, int friendship, int delta, int item, u16 zoneId, int heapId);
extern u8 d_021BED58[];

/*
 * lever: two-halfword coordinate struct keeps its address sp-relative; int alias added 4 B.
 */
void PLIST_DEMO_CreateParticles(PokelistWork *work)
{
    u8 count;
    int member;
    sptr handle;
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
    handle = (sptr)PARTICLE_LoadArchiveMember(0x4c, member, work->heapId);
    work->particleMemory = GFL_NET_AllocAligned(work->heapId, 0x5000, (const char *)d_021BED58, 0xea);
    work->particleSystem = PARTICLE_CreateSystemDefault((uptr)work->particleMemory, 0x5000, 0, work->heapId);
    PARTICLE_SetupSystem(work->particleSystem, (void *)handle, 0, (uptr)GFL_USE_GetMainTaskList());
    PLIST_PLATE_GetCenterPos(work, (struct PlistPlate *)work->plates[work->selectedSlot], (struct PlistPlatePos *)(&pos));
    pos.x -= 0x28;
    pos.y += 4;
    if (pos.x > 0) vec[0] = (int)(0.5f + (float)(pos.x << 12)) / 0x26;
    else vec[0] = (int)((float)(pos.x << 12) - 0.5f) / 0x26;
    if (pos.y > 0) vec[1] = (int)(0.5f + (float)(pos.y << 12)) / 0x26;
    else vec[1] = (int)((float)(pos.y << 12) - 0.5f) / 0x26;
    vec[2] = 0x40000;
    for (i = 0; i < count; i++) PARTICLE_StartEffect(work->particleSystem, i, (sptr)vec);
}

void PLIST_DEMO_DeleteParticles(PokelistWork *work)
{
    PARTICLE_DeleteSystem(work->particleSystem);
    GFL_NET_FreeAligned(work->particleMemory);
}

int PLIST_DEMO_CheckGiratinaToOrigin(PokelistWork *work, void *unused)
{
    int result = 0;
    if (POKE_TOOL_GetPartyValue((void *)work->selectedMon, PLIST_MON_SPECIES, 0) != PLIST_SPECIES_GIRATINA)
        return 0;
    if (POKE_TOOL_GetPartyValue((void *)work->selectedMon, PLIST_MON_HELD_ITEM, result) != PLIST_ITEM_GRISEOUS_ORB)
        return 0;
    if (POKE_TOOL_GetPartyValue((void *)work->selectedMon, PLIST_MON_FORM, result) == 0)
        result = 1;
    return result;
}

/*
 * Extent tail: two bytes of alignment padding at 0x021BDC5A.
 */
void PLIST_DEMO_ApplyGiratinaOriginForm(PokelistWork *work, void *mon)
{
    POKE_TOOL_ChangeForm(mon, 1);
    ZUKAN_SAVE_RegisterCaught(work->arg->zukanSave, mon);
}

int PLIST_DEMO_CheckGiratinaToAltered(PokelistWork *work, void *unused)
{
    int result = 0;
    if (POKE_TOOL_GetPartyValue((void *)work->selectedMon, PLIST_MON_HELD_ITEM, 0) == PLIST_ITEM_GRISEOUS_ORB)
        return 0;
    if (POKE_TOOL_GetPartyValue((void *)work->selectedMon, PLIST_MON_SPECIES, result) != PLIST_SPECIES_GIRATINA)
        return 0;
    if (POKE_TOOL_GetPartyValue((void *)work->selectedMon, PLIST_MON_FORM, result) == 1)
        result = 1;
    return result;
}

/*
 * Extent tail: two bytes of alignment padding at 0x021BDCBE.
 */
void PLIST_DEMO_ApplyGiratinaAlteredForm(PokelistWork *work, void *mon)
{
    POKE_TOOL_ChangeForm(mon, 0);
    ZUKAN_SAVE_RegisterCaught(work->arg->zukanSave, mon);
}

int PLIST_DEMO_CanUseGracidea(PokelistWork *work, u32 unused)
{
    u32 now[3];
    u32 dayStart, dayEnd;
    int result = 0;
    if (POKE_TOOL_GetPartyValue((void *)work->selectedMon, PLIST_MON_SPECIES, 0) != PLIST_SPECIES_SHAYMIN)
        return result;
    if (POKE_TOOL_GetPartyValue((void *)work->selectedMon, PLIST_MON_FORM, result) != 0)
        return result;
    if (POKE_TOOL_GetPartyValue((void *)work->selectedMon, PLIST_MON_SPECIAL_FLAG, result) != 1)
        return result;
    if (POKE_TOOL_GetStatusCondition((void *)work->selectedMon) & 0x20)
        return result;
    dayStart = TIMEZONE_GetLight(work->arg->season, result);
    dayEnd = TIMEZONE_GetLight(work->arg->season, 3);
    GF_STANDARD_GetCachedTime((struct RtcTime *)now);
    if (now[0] < dayStart || now[0] >= dayEnd)
        return 0;
    return 1;
}

void PLIST_DEMO_ApplyShayminSkyForm(PokelistWork *work, void *mon)
{
    POKE_TOOL_ChangeForm(mon, 1);
    ZUKAN_SAVE_RegisterCaught(work->arg->zukanSave, mon);
}

int PLIST_DEMO_CheckItemUsable(void *mon, u32 itemId, int moveSlot, u32 heapId)
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
  itemRec = FILE_UTIL_LoadItemRecord(itemId, 0, (u16)heapId);
  result = 0;
  if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_USABLE_ON_PARTY) != 1)
  {
    GFL_HEAP_Free(itemRec);
    return result;
  }
  status = POKE_TOOL_GetStatusCondition(mon);
  if ((FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CURES_SLEEP) != 0) && (status == 2))
  {
    GFL_HEAP_Free(itemRec);
    return 1;
  }
  if ((FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CURES_POISON) != 0) && (status == 5))
  {
    GFL_HEAP_Free(itemRec);
    return 1;
  }
  if ((FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CURES_BURN) != 0) && (status == 4))
  {
    GFL_HEAP_Free(itemRec);
    return 1;
  }
  if ((FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CURES_FREEZE) != 0) && (status == 3))
  {
    GFL_HEAP_Free(itemRec);
    return 1;
  }
  if ((FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CURES_PARALYSIS) != 0) && (status == 1))
  {
    GFL_HEAP_Free(itemRec);
    return 1;
  }
  hp = POKE_TOOL_GetPartyValue(mon, PLIST_MON_HP, 0);
  if (((FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_REVIVES) != 0) || (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_REVIVES_FULL) != 0)) && (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_RAISES_LEVEL) == 0))
  {
    if (hp == 0)
    {
      GFL_HEAP_Free(itemRec);
      return 1;
    }
  }
  else
    if (((FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_RESTORES_HP) != 0) && (hp != 0)) && (hp < POKE_TOOL_GetPartyValue(mon, PLIST_MON_MAX_HP, 0)))
  {
    GFL_HEAP_Free(itemRec);
    return 1;
  }
  if ((FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_RAISES_LEVEL) != 0) && (POKE_TOOL_GetPartyValue(mon, PLIST_MON_LEVEL, 0) < 100))
  {
    GFL_HEAP_Free(itemRec);
    return 1;
  }
  if ((FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_RAISES_PP_UPS) != 0) || (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_MAXES_PP_UPS) != 0))
  {
    result = 0;
    if ((POKE_TOOL_GetPartyValue(mon, moveSlot + PLIST_MON_MOVE_PP_UPS, 0) < 3) && (WAZA_TOOL_GetMaxPP((u16) POKE_TOOL_GetPartyValue(mon, moveSlot + PLIST_MON_MOVE_ID, 0), result) >= 5))
    {
      GFL_HEAP_Free(itemRec);
      return 1;
    }
  }
  if ((FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_RESTORES_PP_ONE) != 0) && (POKE_TOOL_IsPPRestorable(mon, moveSlot) == 1))
  {
    GFL_HEAP_Free(itemRec);
    return 1;
  }
  if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_RESTORES_PP_ALL) != 0)
  {
    for (i = 0; i < 4; i++)
    {
      if (POKE_TOOL_IsPPRestorable(mon, i) == 1)
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
    }

  }
  evHp = POKE_TOOL_GetPartyValue(mon, PLIST_MON_EV_HP, 0);
  evAtk = POKE_TOOL_GetPartyValue(mon, PLIST_MON_EV_ATK, 0);
  evDef = POKE_TOOL_GetPartyValue(mon, PLIST_MON_EV_DEF, 0);
  evSpeed = POKE_TOOL_GetPartyValue(mon, PLIST_MON_EV_SPEED, 0);
  evSpAtk = POKE_TOOL_GetPartyValue(mon, PLIST_MON_EV_SPATK, 0);
  evSpDef = POKE_TOOL_GetPartyValue(mon, PLIST_MON_EV_SPDEF, 0);
  ignoreCap = FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_EV_IGNORES_CAP);
  if (POKE_TOOL_GetPartyValue(mon, PLIST_MON_SPECIES, 0) != PLIST_SPECIES_SHEDINJA)
    if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CHANGES_EV_HP) != 0)
  {
    amount = FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_EV_HP_AMOUNT);
    if (amount > 0)
    {
      if ((((evHp < 100) || (ignoreCap != 0)) && (evHp < 255)) && ((((((evHp + evAtk) + evDef) + evSpeed) + evSpAtk) + evSpDef) < 510))
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
    }
    else
      if (amount < 0)
    {
      if (evHp > 0)
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
      if (PLIST_DEMO_FriendshipItemApplies(mon, itemRec) == 1)
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
    }
  }
  if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CHANGES_EV_ATK) != 0)
  {
    amount = FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_EV_ATK_AMOUNT);
    if (amount > 0)
    {
      if ((((evAtk < 100) || (ignoreCap != 0)) && (evAtk < 255)) && ((((((evHp + evAtk) + evDef) + evSpeed) + evSpAtk) + evSpDef) < 510))
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
    }
    else
      if (amount < 0)
    {
      if (evAtk > 0)
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
      if (PLIST_DEMO_FriendshipItemApplies(mon, itemRec) == 1)
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
    }
  }
  if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CHANGES_EV_DEF) != 0)
  {
    amount = FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_EV_DEF_AMOUNT);
    if (amount > 0)
    {
      if ((((evDef < 100) || (ignoreCap != 0)) && (evDef < 255)) && ((((((evHp + evAtk) + evDef) + evSpeed) + evSpAtk) + evSpDef) < 510))
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
    }
    else
      if (amount < 0)
    {
      if (evDef > 0)
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
      if (PLIST_DEMO_FriendshipItemApplies(mon, itemRec) == 1)
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
    }
  }
  if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CHANGES_EV_SPEED) != 0)
  {
    amount = FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_EV_SPEED_AMOUNT);
    if (amount > 0)
    {
      if ((((evSpeed < 100) || (ignoreCap != 0)) && (evSpeed < 255)) && ((((((evHp + evAtk) + evDef) + evSpeed) + evSpAtk) + evSpDef) < 510))
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
    }
    else
      if (amount < 0)
    {
      if (evSpeed > 0)
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
      if (PLIST_DEMO_FriendshipItemApplies(mon, itemRec) == 1)
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
    }
  }
  if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CHANGES_EV_SPATK) != 0)
  {
    amount = FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_EV_SPATK_AMOUNT);
    if (amount > 0)
    {
      if ((((evSpAtk < 100) || (ignoreCap != 0)) && (evSpAtk < 255)) && ((((((evHp + evAtk) + evDef) + evSpeed) + evSpAtk) + evSpDef) < 510))
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
    }
    else
      if (amount < 0)
    {
      if (evSpAtk > 0)
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
      if (PLIST_DEMO_FriendshipItemApplies(mon, itemRec) == 1)
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
    }
  }
  if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CHANGES_EV_SPDEF) != 0)
  {
    amount = FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_EV_SPDEF_AMOUNT);
    positive = amount > 0;
    if (positive)
    {
      if ((((evSpDef < 100) || (ignoreCap != 0)) && (evSpDef < 255)) && ((((((evHp + evAtk) + evDef) + evSpeed) + evSpAtk) + evSpDef) < 510))
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
    }
    else
      if (amount < 0)
    {
      if (evSpDef > 0)
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
      if (PLIST_DEMO_FriendshipItemApplies(mon, itemRec) == 1)
      {
        GFL_HEAP_Free(itemRec);
        return 1;
      }
    }
  }
  {
    GFL_HEAP_Free(itemRec);
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
int PLIST_DEMO_UseItemOnMon(void *mon, u16 item, u16 moveSlot, u16 arg, int heap)
{
    void *itemRec;
    int changed = 0;
    int applicable;
    int originalStatus, status, evSpAtk, evSpDef, ignoreCap, amount;
    int evHp, hp, evAtk, maxHp, evDef, evSpeed, level, friendship, result, i;
    itemRec = FILE_UTIL_LoadItemRecord(item, 0, (u16)heap);
    if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_USABLE_ON_PARTY) != 1) { GFL_HEAP_Free(itemRec); return changed; }
    applicable = 0;
    originalStatus = POKE_TOOL_GetPartyValue(mon, PLIST_MON_STATUS, 0);
    status = originalStatus;
    if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CURES_SLEEP)) { status = 0; applicable = 1; }
    if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CURES_POISON)) { status = 0; applicable = 1; }
    if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CURES_BURN)) { status = 0; applicable = 1; }
    if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CURES_FREEZE)) { status = 0; applicable = 1; }
    if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CURES_PARALYSIS)) { status = 0; applicable = 1; }
    if (originalStatus != status) { POKE_TOOL_SetPartyValue(mon, PLIST_MON_STATUS, status); changed = 1; }
    hp = POKE_TOOL_GetPartyValue(mon, PLIST_MON_HP, 0);
    maxHp = POKE_TOOL_GetPartyValue(mon, PLIST_MON_MAX_HP, 0);
    if ((FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_REVIVES) || FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_REVIVES_FULL)) && !FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_RAISES_LEVEL)) {
        if (hp == 0) {
            PLIST_DEMO_RestoreHp(mon, hp, maxHp, FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_HP_AMOUNT));
            changed = 1;
        }
        applicable = 1;
    } else if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_RESTORES_HP)) {
        if (hp < maxHp) { PLIST_DEMO_RestoreHp(mon, hp, maxHp, FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_HP_AMOUNT)); changed = 1; }
        applicable = 1;
    }
    level = POKE_TOOL_GetPartyValue(mon, PLIST_MON_LEVEL, 0);
    if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_RAISES_LEVEL)) {
        if (level < 100) {
            i = POKE_TOOL_GetPartyValue(mon, PLIST_MON_SPECIES, 0);
            result = POKE_TOOL_GetPartyValue(mon, PLIST_MON_FORM, 0);
            POKE_TOOL_SetPartyValue(mon, PLIST_MON_EXP, POKE_TOOL_GetExpForLevel(i, result, level + 1));
            POKE_TOOL_RecalcParam(mon);
            if (hp == 0) {
                result = POKE_TOOL_GetPartyValue(mon, PLIST_MON_MAX_HP, 0);
                PLIST_DEMO_RestoreHp(mon, hp, result, result - maxHp);
            }
            changed = 1;
        }
        applicable = 1;
    }
    if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_EVOLVES)) applicable = 1;
    if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_RAISES_PP_UPS)) {
        applicable = 1;
        if (PLIST_DEMO_RaiseMovePpUps(mon, moveSlot, 1) == 1) changed = 1;
        applicable = 1;
    } else if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_MAXES_PP_UPS)) {
        if (PLIST_DEMO_RaiseMovePpUps(mon, moveSlot, 3) == 1) changed = 1;
        applicable = 1;
    }
    if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_RESTORES_PP_ONE)) {
        if (POKE_TOOL_RestorePP(mon, moveSlot, FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_PP_AMOUNT)) == 1) changed = 1;
        applicable = 1;
    } else if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_RESTORES_PP_ALL)) {
        for (i = 0; i < 4; i++) if (POKE_TOOL_RestorePP(mon, i, FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_PP_AMOUNT)) == 1) changed = 1;
        applicable = 1;
    }
    evHp = POKE_TOOL_GetPartyValue(mon, PLIST_MON_EV_HP, 0);
    evAtk = POKE_TOOL_GetPartyValue(mon, PLIST_MON_EV_ATK, 0);
    evDef = POKE_TOOL_GetPartyValue(mon, PLIST_MON_EV_DEF, 0);
    evSpeed = POKE_TOOL_GetPartyValue(mon, PLIST_MON_EV_SPEED, 0);
    evSpAtk = POKE_TOOL_GetPartyValue(mon, PLIST_MON_EV_SPATK, 0);
    evSpDef = POKE_TOOL_GetPartyValue(mon, PLIST_MON_EV_SPDEF, 0);
    ignoreCap = FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_EV_IGNORES_CAP);
    if (POKE_TOOL_GetPartyValue(mon, PLIST_MON_SPECIES, 0) != PLIST_SPECIES_SHEDINJA && FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CHANGES_EV_HP)) {
        amount = FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_EV_HP_AMOUNT);
        result = PLIST_DEMO_AddEv(evHp, evSpDef + (evSpAtk + (evSpeed + (evAtk + evDef))), amount, ignoreCap);
        if (result != -1) { evHp = result; POKE_TOOL_SetPartyValue(mon, PLIST_MON_EV_HP, result); POKE_TOOL_RecalcParam(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CHANGES_EV_ATK)) {
        amount = FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_EV_ATK_AMOUNT);
        result = PLIST_DEMO_AddEv(evAtk, evSpDef + (evSpAtk + (evSpeed + (evHp + evDef))), amount, ignoreCap);
        if (result != -1) { evAtk = result; POKE_TOOL_SetPartyValue(mon, PLIST_MON_EV_ATK, result); POKE_TOOL_RecalcParam(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CHANGES_EV_DEF)) {
        amount = FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_EV_DEF_AMOUNT);
        result = PLIST_DEMO_AddEv(evDef, evSpDef + (evSpAtk + (evSpeed + (evHp + evAtk))), amount, ignoreCap);
        if (result != -1) { evDef = result; POKE_TOOL_SetPartyValue(mon, PLIST_MON_EV_DEF, result); POKE_TOOL_RecalcParam(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CHANGES_EV_SPEED)) {
        amount = FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_EV_SPEED_AMOUNT);
        result = PLIST_DEMO_AddEv(evSpeed, evSpDef + (evSpAtk + (evDef + (evHp + evAtk))), amount, ignoreCap);
        if (result != -1) { evSpeed = result; POKE_TOOL_SetPartyValue(mon, PLIST_MON_EV_SPEED, result); POKE_TOOL_RecalcParam(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CHANGES_EV_SPATK)) {
        amount = FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_EV_SPATK_AMOUNT);
        result = PLIST_DEMO_AddEv(evSpAtk, evSpDef + (evSpeed + (evDef + (evHp + evAtk))), amount, ignoreCap);
        if (result != -1) { evSpAtk = result; POKE_TOOL_SetPartyValue(mon, PLIST_MON_EV_SPATK, result); POKE_TOOL_RecalcParam(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_CHANGES_EV_SPDEF)) {
        amount = FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_EV_SPDEF_AMOUNT);
        result = PLIST_DEMO_AddEv(evSpDef, evSpAtk + (evSpeed + (evDef + (evHp + evAtk))), amount, ignoreCap);
        if (result != -1) { POKE_TOOL_SetPartyValue(mon, PLIST_MON_EV_SPDEF, result); POKE_TOOL_RecalcParam(mon); changed = 1; }
        if (amount > 0) applicable = 1;
    }
    if (changed == 0 && applicable == 1) { GFL_HEAP_Free(itemRec); return 0; }
    friendship = POKE_TOOL_GetPartyValue(mon, PLIST_MON_FRIENDSHIP, 0);
    if (friendship < 100) {
        if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_FRIENDSHIP_LOW)) {
            PLIST_DEMO_ApplyFriendshipItem(mon, friendship, FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_FRIENDSHIP_LOW_AMOUNT), item, arg, heap);
            GFL_HEAP_Free(itemRec); return changed;
        }
    } else if (friendship >= 100 && friendship < 200) {
        if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_FRIENDSHIP_MID)) {
            PLIST_DEMO_ApplyFriendshipItem(mon, friendship, FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_FRIENDSHIP_MID_AMOUNT), item, arg, heap);
            GFL_HEAP_Free(itemRec); return changed;
        }
    } else if (friendship >= 200 && friendship <= 255) {
        if (FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_FRIENDSHIP_HIGH)) {
            PLIST_DEMO_ApplyFriendshipItem(mon, friendship, FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_FRIENDSHIP_HIGH_AMOUNT), item, arg, heap);
            GFL_HEAP_Free(itemRec); return changed;
        }
    }
    GFL_HEAP_Free(itemRec);
    return changed;
}

int PLIST_DEMO_RaiseMovePpUps(void *mon, int moveSlot, int ups)
{
    int result = 0;
    u16 moveId;
    u32 oldMaxPp;
    u32 pp;
    u32 upCount;
    int newUps;
    upCount = (u8)POKE_TOOL_GetPartyValue(mon, moveSlot + PLIST_MON_MOVE_PP_UPS, 0);
    if (upCount == 3)
        return result;
    moveId = (u16)POKE_TOOL_GetPartyValue(mon, moveSlot + PLIST_MON_MOVE_ID, result);
    if (WAZA_TOOL_GetMaxPP(moveId, result) < 5)
        return result;
    pp = (u8)POKE_TOOL_GetPartyValue(mon, moveSlot + PLIST_MON_MOVE_PP, result);
    oldMaxPp = WAZA_TOOL_GetMaxPP(moveId, upCount);
    newUps = upCount + ups;
    if ((u32)newUps > 3)
        upCount = 3;
    else
        upCount = (u8)newUps;
    pp = (u8)(pp + WAZA_TOOL_GetMaxPP(moveId, upCount) - oldMaxPp);
    POKE_TOOL_SetPartyValue(mon, moveSlot + PLIST_MON_MOVE_PP_UPS, upCount);
    POKE_TOOL_SetPartyValue(mon, moveSlot + PLIST_MON_MOVE_PP, pp);
    return 1;
}

void PLIST_DEMO_RestoreHp(void *mon, u32 hp, u32 maxHp, u32 amount)
{
    if (maxHp == 1) amount = 1;
    else if (amount == 0xff) amount = maxHp;
    else if (amount == 0xfe) amount = maxHp >> 1;
    else if (amount == 0xfd) amount = maxHp >> 2;
    hp += amount;
    if (hp > maxHp) hp = maxHp;
    POKE_TOOL_SetPartyValue(mon, PLIST_MON_HP, hp);
}

int PLIST_DEMO_AddEv(int ev, int otherEvTotal, int delta, int ignoreCap)
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

int PLIST_DEMO_FriendshipItemApplies(void *mon, void *itemRec)
{
    int result = 0;
    int friendship = POKE_TOOL_GetPartyValue(mon, PLIST_MON_FRIENDSHIP, 0);
    if (friendship >= 0xFF)
        return result;
    if (friendship < 100) {
        if ((int)FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_FRIENDSHIP_LOW) != 0 && (int)FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_FRIENDSHIP_LOW_AMOUNT) > 0)
            return 1;
        return 0;
    }
    if (friendship >= 100 && friendship < 200) {
        if ((int)FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_FRIENDSHIP_MID) != 0 && (int)FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_FRIENDSHIP_MID_AMOUNT) > 0)
            return 1;
        return 0;
    }
    if (friendship >= 200 && friendship < 0xFF) {
        if ((int)FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_FRIENDSHIP_HIGH) != 0 && (int)FILE_UTIL_GetItemRecordParam(itemRec, PLIST_ITEM_FRIENDSHIP_HIGH_AMOUNT) > 0)
            return 1;
        return 0;
    }
    return 0;
}

/*
 * Friendship change of an item use: nothing happens when the friendship is
 * already at its limit in the direction of the change (255 and a rise, or 0
 * and a fall). The band delta comes from the item record.
 */
int PLIST_DEMO_ApplyFriendshipItem(struct PokemonParam *mon, int friendship, int delta, int item, u16 zoneId, int heapId)
{
    if (friendship == 0xff && delta > 0)
        return 0;
    if (friendship == 0 && delta < 0)
        return 0;
    NATSUKI_CalcUseItem(mon, item, zoneId, heapId);
    return 1;
}
