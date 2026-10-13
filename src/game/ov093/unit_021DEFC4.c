/*
 * file:     unit_021DEFC4.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_BlackSludge_HealOrDamage, BTL_HANDLER_ITEM_DestinyKnot_Infatuate, BTL_HANDLER_ITEM_GetStickyBarbHandlers, BTL_HANDLER_ITEM_StickyBarb_Transfer, BTL_HANDLER_ITEM_StickyBarb_TurnEndDamage, BTL_HANDLER_ITEM_PowerItem_HalveSpeed, BTL_HANDLER_ITEM_GetFlamePlateHandlers, BTL_HANDLER_ITEM_GetSplashPlateHandlers, BTL_HANDLER_ITEM_GetZapPlateHandlers, BTL_HANDLER_ITEM_GetMeadowPlateHandlers, BTL_HANDLER_ITEM_GetIciclePlateHandlers, BTL_HANDLER_ITEM_GetFistPlateHandlers, BTL_HANDLER_ITEM_GetToxicPlateHandlers, BTL_HANDLER_ITEM_GetEarthPlateHandlers, BTL_HANDLER_ITEM_GetSkyPlateHandlers, BTL_HANDLER_ITEM_GetMindPlateHandlers, BTL_HANDLER_ITEM_GetInsectPlateHandlers, BTL_HANDLER_ITEM_GetStonePlateHandlers, BTL_HANDLER_ITEM_GetSpookyPlateHandlers, BTL_HANDLER_ITEM_GetDracoPlateHandlers, BTL_HANDLER_ITEM_GetDreadPlateHandlers, BTL_HANDLER_ITEM_GetIronPlateHandlers, BTL_HANDLER_ITEM_GetBigRootHandlers
 * address:  0x021DEFC4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F15CC     0x021F15CC  data   ov093  a4
 *   d_021F147C     0x021F147C  data   ov093  a4
 *   d_021F136C     0x021F136C  data   ov093  a4
 *   d_021F15D4     0x021F15D4  data   ov093  a4
 *   d_021F13CC     0x021F13CC  data   ov093  a4
 *   d_021F1494     0x021F1494  data   ov093  a4
 *   d_021F149C     0x021F149C  data   ov093  a4
 *   d_021F14E4     0x021F14E4  data   ov093  a4
 *   d_021F1594     0x021F1594  data   ov093  a4
 *   d_021F13F4     0x021F13F4  data   ov093  a4
 *   d_021F14A4     0x021F14A4  data   ov093  a4
 *   d_021F1574     0x021F1574  data   ov093  a4
 *   d_021F1374     0x021F1374  data   ov093  a4
 *   d_021F14D4     0x021F14D4  data   ov093  a4
 *   d_021F14EC     0x021F14EC  data   ov093  a4
 *   d_021F1424     0x021F1424  data   ov093  a4
 *   d_021F153C     0x021F153C  data   ov093  a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C83D4 0x021C83D4 thumb ov093
 *   BTL_POKEPARAM_GetTypePair 0x021D57FC thumb ov093
 *   BTLV_CORE_HasByte 0x021E8D24 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   BTL_HANDLER_ITEM_GetParam 0x021DCFF8 thumb ov093
 *   BTL_CALC_DivideMaxHpMin1 0x021D7B74 thumb ov093
 *   func_021C8010 0x021C8010 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   BTL_EVENT_GetFactorKey 0x021D70A8 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F154C 0x021F154C data a4
 *   BTLV_CORE_MakeSlotKind3  0x021E899C  thumb  ov093
 *   d_021F16FC 0x021F16FC data
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   d_021F138C 0x021F138C data a4
 *   d_021F1434 0x021F1434 data a4
 *   d_021F15A4 0x021F15A4 data a4
 *   d_021F1554 0x021F1554 data a4
 *   d_021F15B4 0x021F15B4 data a4
 *   d_021F15C4 0x021F15C4 data a4
 *   BTL_EVENT_MultiplyVar   0x021D7704  thumb ov093

 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

typedef struct Word { u32 v; } Word;

extern int BTL_EVENT_GetVar(int key);
extern int func_021C83D4(void *flow);
extern u16 BTL_POKEPARAM_GetTypePair(void *pokeParam);
extern int BTLV_CORE_HasByte(int typePair, int typeId);
extern void *func_021C7CF4(void *flow, int pokeId);
extern void *func_021C88A4(void *flow, int cmdKind, int pokeId);
extern int BTL_HANDLER_ITEM_GetParam(struct BtlEventFactor *factor, int index);
extern int BTL_CALC_DivideMaxHpMin1(void *pokeParam, u32 divisor);
extern int func_021C8010(void *flow, unsigned int pokeId);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern void func_021C88C8(void *flow, void *cmd);
extern Word BTLV_CORE_MakeSlotKind3(int pokeId);
extern u16 BTL_POKEPARAM_GetItem(void *pokeParam);
extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 flagBit);
extern void BTL_EVENT_MultiplyVar(int key, int multiplier);

#define BTL_POISON_TYPE 3
#define BTL_NO_POKE_ID 0x1f
#define BTL_MOVE_FLAG_CONTACT 0

extern u8 d_021F154C[];
extern unsigned char d_021F16FC[];
extern u8 d_021F138C[], d_021F1434[], d_021F15A4[], d_021F1554[], d_021F15B4[], d_021F15C4[];

/*
 * Black Sludge: a Poison type holder recovers (item parameter) of its maximum
 * HP at the end of the turn; any other holder loses an eighth.
 */
void BTL_HANDLER_ITEM_BlackSludge_HealOrDamage(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *holder;
    HandExRecoverHp *heal;
    HandExLoseHp *hurt;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && func_021C83D4(flow) == 0) {
        holder = func_021C7CF4(flow, pokeId);
        if (BTLV_CORE_HasByte(BTL_POKEPARAM_GetTypePair(holder), BTL_POISON_TYPE)) {
            heal = (HandExRecoverHp *)func_021C88A4(flow, HANDEX_KIND_RECOVER_HP, pokeId);
            heal->pokeId = pokeId;
            heal->amount = BTL_CALC_DivideMaxHpMin1(holder, BTL_HANDLER_ITEM_GetParam(factor, 2));
            func_021C8838(&heal->str, HANDEX_STR_SET, 0x392);
            func_021C8860(&heal->str, pokeId);
            func_021C8860(&heal->str, BTL_EVENT_GetFactorKey(factor));
            func_021C88C8(flow, heal);
        } else {
            hurt = (HandExLoseHp *)func_021C88A4(flow, 7, pokeId);
            hurt->pokeId = pokeId;
            hurt->amount = BTL_CALC_DivideMaxHpMin1(holder, 8);
            hurt->flags |= 2;
            hurt->effectId = 0x25f;
            hurt->effectParam = func_021C8010(flow, pokeId);
            hurt->effectKind = 6;
            func_021C8838(&hurt->str, HANDEX_STR_SET, 0x40e);
            func_021C8860(&hurt->str, pokeId);
            func_021C8860(&hurt->str, BTL_EVENT_GetFactorKey(factor));
            func_021C88C8(flow, hurt);
        }
    }
}

void *BTL_HANDLER_ITEM_GetDestinyKnotHandlers(int *count)
{
    *count = 1;
    return d_021F154C;
}

/*
 * 2026-10-03 (wave B3 lane 10): EXACT*. BTLV_CORE_MakeSlotKind3 returns a one-word struct (Word), as in the other matched callers; its return temporary is the second frame word (see docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md).
 */
/* Destiny Knot: when the holder is infatuated by an attacker, the attacker is infatuated too. */
void BTL_HANDLER_ITEM_DestinyKnot_Infatuate(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    u8 attackerId;
    HandExAddSickFull *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_SICK_ID) != BTL_SICK_INFATUATION)
        return;
    attackerId = (u8)BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    if (attackerId == BTL_NO_POKE_ID)
        return;
    cmd = (HandExAddSickFull *)func_021C88A4(flow, HANDEX_KIND_ADD_SICK, pokeId);
    cmd->pokeId = attackerId;
    cmd->sickKind = BTL_SICK_INFATUATION;
    *(Word *)&cmd->sickCont = BTLV_CORE_MakeSlotKind3(pokeId);
    cmd->flagD = 1;
    func_021C8838(&cmd->str, HANDEX_STR_SET, 0x14a);
    func_021C8860(&cmd->str, attackerId);
    func_021C8860(&cmd->str, BTL_EVENT_GetFactorKey(factor));
    func_021C88C8(flow, cmd);
}

void *BTL_HANDLER_ITEM_GetStickyBarbHandlers(int *count)
{
    *count = 2;
    return d_021F16FC;
}

/* Sticky Barb: a contact hit on the holder (not into a substitute) moves the barb to an item-less attacker. */
void BTL_HANDLER_ITEM_StickyBarb_Transfer(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    u8 attackerId;
    HandExStealItem *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE) == 0) {
        if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), BTL_MOVE_FLAG_CONTACT) != 0) {
            attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
            if (BTL_POKEPARAM_GetItem(func_021C7CF4(flow, attackerId)) == 0) {
                cmd = (HandExStealItem *)func_021C88A4(flow, 0x24, pokeId);
                cmd->pokeId = attackerId;
                func_021C88C8(flow, cmd);
            }
        }
    }
}

/* Sticky Barb: the holder loses an eighth of its maximum HP at the end of the turn. */
void BTL_HANDLER_ITEM_StickyBarb_TurnEndDamage(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *holder;
    HandExLoseHp *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        holder = func_021C7CF4(flow, pokeId);
        cmd = (HandExLoseHp *)func_021C88A4(flow, 7, pokeId);
        cmd->pokeId = pokeId;
        cmd->amount = BTL_CALC_DivideMaxHpMin1(holder, BTL_HANDLER_ITEM_GetParam(factor, 2));
        cmd->flags |= 2;
        cmd->effectId = 0x25f;
        cmd->effectParam = func_021C8010(flow, pokeId);
        cmd->effectKind = 6;
        func_021C8838(&cmd->str, HANDEX_STR_SET, 0x40e);
        func_021C8860(&cmd->str, pokeId);
        func_021C8860(&cmd->str, BTL_EVENT_GetFactorKey(factor));
        func_021C88C8(flow, cmd);
    }
}

void *BTL_HANDLER_ITEM_GetPowerWeightHandlers(int *count)
{
    *count = 1;
    return d_021F138C;
}

void *BTL_HANDLER_ITEM_GetPowerBracerHandlers(int *count)
{
    *count = 1;
    return d_021F1434;
}

void *BTL_HANDLER_ITEM_GetPowerBeltHandlers(int *count)
{
    *count = 1;
    return d_021F15A4;
}

void *BTL_HANDLER_ITEM_GetPowerLensHandlers(int *count)
{
    *count = 1;
    return d_021F1554;
}

void *BTL_HANDLER_ITEM_GetPowerBandHandlers(int *count)
{
    *count = 1;
    return d_021F15B4;
}

void *BTL_HANDLER_ITEM_GetPowerAnkletHandlers(int *count)
{
    *count = 1;
    return d_021F15C4;
}

/* Power Weight, Bracer, Belt, Lens, Band and Anklet: the holder's speed is halved. */
void BTL_HANDLER_ITEM_PowerItem_HalveSpeed(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, 2 << 10);
}


extern int d_021F15CC[];
int *BTL_HANDLER_ITEM_GetFlamePlateHandlers(int *count);

int *BTL_HANDLER_ITEM_GetFlamePlateHandlers(int *count)
{
    *count = 1;
    return d_021F15CC;
}


extern int d_021F147C[];
int *BTL_HANDLER_ITEM_GetSplashPlateHandlers(int *count);

int *BTL_HANDLER_ITEM_GetSplashPlateHandlers(int *count)
{
    *count = 1;
    return d_021F147C;
}


extern int d_021F136C[];
int *BTL_HANDLER_ITEM_GetZapPlateHandlers(int *count);

int *BTL_HANDLER_ITEM_GetZapPlateHandlers(int *count)
{
    *count = 1;
    return d_021F136C;
}


extern int d_021F15D4[];
int *BTL_HANDLER_ITEM_GetMeadowPlateHandlers(int *count);

int *BTL_HANDLER_ITEM_GetMeadowPlateHandlers(int *count)
{
    *count = 1;
    return d_021F15D4;
}


extern int d_021F13CC[];
int *BTL_HANDLER_ITEM_GetIciclePlateHandlers(int *count);

int *BTL_HANDLER_ITEM_GetIciclePlateHandlers(int *count)
{
    *count = 1;
    return d_021F13CC;
}


extern int d_021F1494[];
int *BTL_HANDLER_ITEM_GetFistPlateHandlers(int *count);

int *BTL_HANDLER_ITEM_GetFistPlateHandlers(int *count)
{
    *count = 1;
    return d_021F1494;
}


extern int d_021F149C[];
int *BTL_HANDLER_ITEM_GetToxicPlateHandlers(int *count);

int *BTL_HANDLER_ITEM_GetToxicPlateHandlers(int *count)
{
    *count = 1;
    return d_021F149C;
}


extern int d_021F14E4[];
int *BTL_HANDLER_ITEM_GetEarthPlateHandlers(int *count);

int *BTL_HANDLER_ITEM_GetEarthPlateHandlers(int *count)
{
    *count = 1;
    return d_021F14E4;
}


extern int d_021F1594[];
int *BTL_HANDLER_ITEM_GetSkyPlateHandlers(int *count);

int *BTL_HANDLER_ITEM_GetSkyPlateHandlers(int *count)
{
    *count = 1;
    return d_021F1594;
}


extern int d_021F13F4[];
int *BTL_HANDLER_ITEM_GetMindPlateHandlers(int *count);

int *BTL_HANDLER_ITEM_GetMindPlateHandlers(int *count)
{
    *count = 1;
    return d_021F13F4;
}


extern int d_021F14A4[];
int *BTL_HANDLER_ITEM_GetInsectPlateHandlers(int *count);

int *BTL_HANDLER_ITEM_GetInsectPlateHandlers(int *count)
{
    *count = 1;
    return d_021F14A4;
}


extern int d_021F1574[];
int *BTL_HANDLER_ITEM_GetStonePlateHandlers(int *count);

int *BTL_HANDLER_ITEM_GetStonePlateHandlers(int *count)
{
    *count = 1;
    return d_021F1574;
}


extern int d_021F1374[];
int *BTL_HANDLER_ITEM_GetSpookyPlateHandlers(int *count);

int *BTL_HANDLER_ITEM_GetSpookyPlateHandlers(int *count)
{
    *count = 1;
    return d_021F1374;
}


extern int d_021F14D4[];
int *BTL_HANDLER_ITEM_GetDracoPlateHandlers(int *count);

int *BTL_HANDLER_ITEM_GetDracoPlateHandlers(int *count)
{
    *count = 1;
    return d_021F14D4;
}


extern int d_021F14EC[];
int *BTL_HANDLER_ITEM_GetDreadPlateHandlers(int *count);

int *BTL_HANDLER_ITEM_GetDreadPlateHandlers(int *count)
{
    *count = 1;
    return d_021F14EC;
}


extern int d_021F1424[];
int *BTL_HANDLER_ITEM_GetIronPlateHandlers(int *count);

int *BTL_HANDLER_ITEM_GetIronPlateHandlers(int *count)
{
    *count = 1;
    return d_021F1424;
}


extern int d_021F153C[];
int *BTL_HANDLER_ITEM_GetBigRootHandlers(int *count);

int *BTL_HANDLER_ITEM_GetBigRootHandlers(int *count)
{
    *count = 1;
    return d_021F153C;
}
