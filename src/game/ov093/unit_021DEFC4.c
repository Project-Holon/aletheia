/*
 * file:     unit_021DEFC4.c
 * unit:     yes
 * function: func_021DEFC4, func_021DF0C4, func_021DF144, func_021DF150, func_021DF1B0, func_021DF288, func_021DF2A4, func_021DF2B0, func_021DF2BC, func_021DF2C8, func_021DF2D4, func_021DF2E0, func_021DF2EC, func_021DF2F8, func_021DF304, func_021DF310, func_021DF31C, func_021DF328, func_021DF334, func_021DF340, func_021DF34C, func_021DF358, func_021DF364
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
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C83D4 0x021C83D4 thumb ov093
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021E8D24 0x021E8D24 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021DCFF8 0x021DCFF8 thumb ov093
 *   func_021D7B74 0x021D7B74 thumb ov093
 *   func_021C8010 0x021C8010 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021D70A8 0x021D70A8 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F154C 0x021F154C data a4
 *   func_021E899C  0x021E899C  thumb  ov093
 *   d_021F16FC 0x021F16FC data
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   d_021F138C 0x021F138C data a4
 *   d_021F1434 0x021F1434 data a4
 *   d_021F15A4 0x021F15A4 data a4
 *   d_021F1554 0x021F1554 data a4
 *   d_021F15B4 0x021F15B4 data a4
 *   d_021F15C4 0x021F15C4 data a4
 *   func_021D7704   0x021D7704  thumb ov093

 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

typedef struct Word { u32 v; } Word;

extern int func_021D775C(int key);
extern int func_021C83D4(void *flow);
extern u16 func_021D57FC(void *pokeParam);
extern int func_021E8D24(int typePair, int typeId);
extern void *func_021C7CF4(void *flow, int pokeId);
extern void *func_021C88A4(void *flow, int cmdKind, int pokeId);
extern int func_021DCFF8(struct BtlEventFactor *factor, int index);
extern int func_021D7B74(void *pokeParam, u32 divisor);
extern int func_021C8010(void *flow, unsigned int pokeId);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern u16 func_021D70A8(struct BtlEventFactor *factor);
extern void func_021C88C8(void *flow, void *cmd);
extern Word func_021E899C(int pokeId);
extern u16 func_021D5B40(void *pokeParam);
extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 flagBit);
extern void func_021D7704(int key, int multiplier);

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
void func_021DEFC4(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *holder;
    HandExRecoverHp *heal;
    HandExLoseHp *hurt;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && func_021C83D4(flow) == 0) {
        holder = func_021C7CF4(flow, pokeId);
        if (func_021E8D24(func_021D57FC(holder), BTL_POISON_TYPE)) {
            heal = (HandExRecoverHp *)func_021C88A4(flow, HANDEX_KIND_RECOVER_HP, pokeId);
            heal->pokeId = pokeId;
            heal->amount = func_021D7B74(holder, func_021DCFF8(factor, 2));
            func_021C8838(&heal->str, HANDEX_STR_SET, 0x392);
            func_021C8860(&heal->str, pokeId);
            func_021C8860(&heal->str, func_021D70A8(factor));
            func_021C88C8(flow, heal);
        } else {
            hurt = (HandExLoseHp *)func_021C88A4(flow, 7, pokeId);
            hurt->pokeId = pokeId;
            hurt->amount = func_021D7B74(holder, 8);
            hurt->flags |= 2;
            hurt->effectId = 0x25f;
            hurt->effectParam = func_021C8010(flow, pokeId);
            hurt->effectKind = 6;
            func_021C8838(&hurt->str, HANDEX_STR_SET, 0x40e);
            func_021C8860(&hurt->str, pokeId);
            func_021C8860(&hurt->str, func_021D70A8(factor));
            func_021C88C8(flow, hurt);
        }
    }
}

void *func_021DF0B8(int *count)
{
    *count = 1;
    return d_021F154C;
}

/*
 * 2026-10-03 (wave B3 lane 10): EXACT*. func_021E899C returns a one-word struct (Word), as in the other matched callers; its return temporary is the second frame word (see docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md).
 */
/* Destiny Knot: when the holder is infatuated by an attacker, the attacker is infatuated too. */
void func_021DF0C4(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    u8 attackerId;
    HandExAddSickFull *cmd;

    if (pokeId != func_021D775C(BTL_EVAR_DEFENDER_ID))
        return;
    if (func_021D775C(BTL_EVAR_SICK_ID) != BTL_SICK_INFATUATION)
        return;
    attackerId = (u8)func_021D775C(BTL_EVAR_ATTACKER_ID);
    if (attackerId == BTL_NO_POKE_ID)
        return;
    cmd = (HandExAddSickFull *)func_021C88A4(flow, HANDEX_KIND_ADD_SICK, pokeId);
    cmd->pokeId = attackerId;
    cmd->sickKind = BTL_SICK_INFATUATION;
    *(Word *)&cmd->sickCont = func_021E899C(pokeId);
    cmd->flagD = 1;
    func_021C8838(&cmd->str, HANDEX_STR_SET, 0x14a);
    func_021C8860(&cmd->str, attackerId);
    func_021C8860(&cmd->str, func_021D70A8(factor));
    func_021C88C8(flow, cmd);
}

void *func_021DF144(int *count)
{
    *count = 2;
    return d_021F16FC;
}

/* Sticky Barb: a contact hit on the holder (not into a substitute) moves the barb to an item-less attacker. */
void func_021DF150(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    u8 attackerId;
    HandExStealItem *cmd;

    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID) && func_021D775C(BTL_EVAR_HIT_SUBSTITUTE) == 0) {
        if (WAZA_TOOL_GetFlag(func_021D775C(BTL_EVAR_MOVE_ID), BTL_MOVE_FLAG_CONTACT) != 0) {
            attackerId = func_021D775C(BTL_EVAR_ATTACKER_ID);
            if (func_021D5B40(func_021C7CF4(flow, attackerId)) == 0) {
                cmd = (HandExStealItem *)func_021C88A4(flow, 0x24, pokeId);
                cmd->pokeId = attackerId;
                func_021C88C8(flow, cmd);
            }
        }
    }
}

/* Sticky Barb: the holder loses an eighth of its maximum HP at the end of the turn. */
void func_021DF1B0(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *holder;
    HandExLoseHp *cmd;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        holder = func_021C7CF4(flow, pokeId);
        cmd = (HandExLoseHp *)func_021C88A4(flow, 7, pokeId);
        cmd->pokeId = pokeId;
        cmd->amount = func_021D7B74(holder, func_021DCFF8(factor, 2));
        cmd->flags |= 2;
        cmd->effectId = 0x25f;
        cmd->effectParam = func_021C8010(flow, pokeId);
        cmd->effectKind = 6;
        func_021C8838(&cmd->str, HANDEX_STR_SET, 0x40e);
        func_021C8860(&cmd->str, pokeId);
        func_021C8860(&cmd->str, func_021D70A8(factor));
        func_021C88C8(flow, cmd);
    }
}

void *func_021DF240(int *count)
{
    *count = 1;
    return d_021F138C;
}

void *func_021DF24C(int *count)
{
    *count = 1;
    return d_021F1434;
}

void *func_021DF258(int *count)
{
    *count = 1;
    return d_021F15A4;
}

void *func_021DF264(int *count)
{
    *count = 1;
    return d_021F1554;
}

void *func_021DF270(int *count)
{
    *count = 1;
    return d_021F15B4;
}

void *func_021DF27C(int *count)
{
    *count = 1;
    return d_021F15C4;
}

/* Power Weight, Bracer, Belt, Lens, Band and Anklet: the holder's speed is halved. */
void func_021DF288(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID))
        func_021D7704(BTL_EVAR_POWER_RATIO, 2 << 10);
}


extern int d_021F15CC[];
int *func_021DF2A4(int *count);

int *func_021DF2A4(int *count)
{
    *count = 1;
    return d_021F15CC;
}


extern int d_021F147C[];
int *func_021DF2B0(int *count);

int *func_021DF2B0(int *count)
{
    *count = 1;
    return d_021F147C;
}


extern int d_021F136C[];
int *func_021DF2BC(int *count);

int *func_021DF2BC(int *count)
{
    *count = 1;
    return d_021F136C;
}


extern int d_021F15D4[];
int *func_021DF2C8(int *count);

int *func_021DF2C8(int *count)
{
    *count = 1;
    return d_021F15D4;
}


extern int d_021F13CC[];
int *func_021DF2D4(int *count);

int *func_021DF2D4(int *count)
{
    *count = 1;
    return d_021F13CC;
}


extern int d_021F1494[];
int *func_021DF2E0(int *count);

int *func_021DF2E0(int *count)
{
    *count = 1;
    return d_021F1494;
}


extern int d_021F149C[];
int *func_021DF2EC(int *count);

int *func_021DF2EC(int *count)
{
    *count = 1;
    return d_021F149C;
}


extern int d_021F14E4[];
int *func_021DF2F8(int *count);

int *func_021DF2F8(int *count)
{
    *count = 1;
    return d_021F14E4;
}


extern int d_021F1594[];
int *func_021DF304(int *count);

int *func_021DF304(int *count)
{
    *count = 1;
    return d_021F1594;
}


extern int d_021F13F4[];
int *func_021DF310(int *count);

int *func_021DF310(int *count)
{
    *count = 1;
    return d_021F13F4;
}


extern int d_021F14A4[];
int *func_021DF31C(int *count);

int *func_021DF31C(int *count)
{
    *count = 1;
    return d_021F14A4;
}


extern int d_021F1574[];
int *func_021DF328(int *count);

int *func_021DF328(int *count)
{
    *count = 1;
    return d_021F1574;
}


extern int d_021F1374[];
int *func_021DF334(int *count);

int *func_021DF334(int *count)
{
    *count = 1;
    return d_021F1374;
}


extern int d_021F14D4[];
int *func_021DF340(int *count);

int *func_021DF340(int *count)
{
    *count = 1;
    return d_021F14D4;
}


extern int d_021F14EC[];
int *func_021DF34C(int *count);

int *func_021DF34C(int *count)
{
    *count = 1;
    return d_021F14EC;
}


extern int d_021F1424[];
int *func_021DF358(int *count);

int *func_021DF358(int *count)
{
    *count = 1;
    return d_021F1424;
}


extern int d_021F153C[];
int *func_021DF364(int *count);

int *func_021DF364(int *count)
{
    *count = 1;
    return d_021F153C;
}
