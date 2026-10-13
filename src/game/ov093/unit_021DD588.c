/*
 * file:     unit_021DD588.c
 * unit:     yes
 * function: func_021DD588, func_021DD608, func_021DD614, func_021DD624, func_021DD63C, func_021DD648, func_021DD658, func_021DD670, func_021DD67C, func_021DD68C, func_021DD6A4, func_021DD6B0, func_021DD6C0, func_021DD6D8, func_021DD6E4, func_021DD6F4, func_021DD70C, func_021DD744, func_021DD77C, func_021DD7B8, func_021DD870
 * address:  0x021DD588
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
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *   func_021DCFF8   0x021DCFF8  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   func_021D70A8   0x021D70A8  thumb ov093
 *   func_0209C2B0   0x0209C2B0  arm
 *   d_021F1C2C 0x021F1C2C data a4
 *   d_021F1C54 0x021F1C54 data a4
 *   d_021F1C7C 0x021F1C7C data a4
 *   d_021F1CA4 0x021F1CA4 data a4
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021DDE30 0x021DDE30 thumb ov093
 *   func_021DDEA4 0x021DDEA4 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   POKE_TOOL_GetNatureStatMod  0x020189D0  thumb
 *   func_021D7DC0  0x021D7DC0  thumb  ov093
 *   d_021F1C04     0x021F1C04  data   ov093  a4
 *   d_021F1CCC     0x021F1CCC  data   ov093  a4
 */
#include "unit_021DD588_types.h"

extern int func_021D775C(int varId);
extern struct BtlPokeParam *func_021C7CF4(void *server, int pokeId);
extern int func_021D59B4(struct BtlPokeParam *pokeParam, int valueId);
extern int func_021DCFF8(struct BtlEventFactor *factor, int index);
extern void *func_021C88A4(void *server, int cmdKind, int pokeId);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern void func_021C88C8(void *server, void *cmd);
extern u16 func_021D70A8(struct BtlEventFactor *factor);
extern int func_0209C2B0(int dividend, int divisor);
extern int func_021D62C4(struct BtlPokeParam *pokeParam, int sickKind);
extern void func_021DDE30(struct BtlEventFactor *factor, void *server, int pokeId, int divisor, int checkMoveDamage);
extern int func_021DDEA4(void *server, int pokeId, unsigned int divisor);
extern void func_021DD044(struct BtlEventFactor *factor, void *server, int pokeId);
extern int func_021D7B74(struct BtlPokeParam *pokeParam, u32 divisor);
extern void *func_021D5844(struct BtlPokeParam *pokeParam);
extern int POKE_TOOL_GetNatureStatMod(void *mon, int statIndex);
extern void func_021D7DC0(int sickKind, struct BtlPokeParam *pokeParam, union SickCont *out);

extern int d_021F1C04[];
extern int d_021F1C2C[];
extern int d_021F1C54[];
extern int d_021F1C7C[];
extern int d_021F1CA4[];
extern int d_021F1CCC[];

void func_021DD588(struct BtlEventFactor *factor, void *server, int pokeId);
int *func_021DD608(int *handlerCount);
void func_021DD614(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021DD624(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *func_021DD63C(int *handlerCount);
void func_021DD648(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021DD658(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *func_021DD670(int *handlerCount);
void func_021DD67C(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021DD68C(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *func_021DD6A4(int *handlerCount);
void func_021DD6B0(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021DD6C0(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *func_021DD6D8(int *handlerCount);
void func_021DD6E4(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021DD6F4(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021DD70C(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021DD744(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021DD77C(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021DD7B8(struct BtlEventFactor *factor, void *server, int pokeId, int *work, int statIndex);
int *func_021DD870(int *handlerCount);

void func_021DD588(struct BtlEventFactor *factor, void *server, int pokeId)
{
    HandExRecoverHp *cmd;
    int maxHp;
    u8 percent;

    if (pokeId != func_021D775C(BTL_EVAR_POKE_ID))
        return;
    maxHp = func_021D59B4(func_021C7CF4(server, pokeId), BTL_VALUE_MAX_HP);
    percent = (u8)func_021DCFF8(factor, 2);
    cmd = func_021C88A4(server, HANDEX_KIND_RECOVER_HP, pokeId);
    cmd->pokeId = pokeId;
    cmd->amount = func_0209C2B0(maxHp * percent, 100);
    func_021C8838(&cmd->str, HANDEX_STR_SET, 908);
    func_021C8860(&cmd->str, pokeId);
    func_021C8860(&cmd->str, func_021D70A8(factor));
    func_021C88C8(server, cmd);
}

int *func_021DD608(int *handlerCount)
{
    *handlerCount = 5;
    return d_021F1C04;
}

void func_021DD614(struct BtlEventFactor *factor, void *server, int pokeId, int *work) { func_021DD7B8(factor, server, pokeId, work, 0); }

void func_021DD624(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_FORCED_USE] != 0) func_021DD7B8(factor, server, pokeId, work, 0);
}

int *func_021DD63C(int *handlerCount) { *handlerCount = 5; return d_021F1C2C; }

void func_021DD648(struct BtlEventFactor *factor, void *server, int pokeId, int *work) { func_021DD7B8(factor, server, pokeId, work, 1); }

void func_021DD658(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_FORCED_USE] != 0) func_021DD7B8(factor, server, pokeId, work, 1);
}

int *func_021DD670(int *handlerCount) { *handlerCount = 5; return d_021F1C54; }

void func_021DD67C(struct BtlEventFactor *factor, void *server, int pokeId, int *work) { func_021DD7B8(factor, server, pokeId, work, 2); }

void func_021DD68C(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_FORCED_USE] != 0) func_021DD7B8(factor, server, pokeId, work, 2);
}

int *func_021DD6A4(int *handlerCount) { *handlerCount = 5; return d_021F1C7C; }

void func_021DD6B0(struct BtlEventFactor *factor, void *server, int pokeId, int *work) { func_021DD7B8(factor, server, pokeId, work, 3); }

void func_021DD6C0(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_FORCED_USE] != 0) func_021DD7B8(factor, server, pokeId, work, 3);
}

int *func_021DD6D8(int *handlerCount) { *handlerCount = 5; return d_021F1CA4; }

void func_021DD6E4(struct BtlEventFactor *factor, void *server, int pokeId, int *work) { func_021DD7B8(factor, server, pokeId, work, 4); }

void func_021DD6F4(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_FORCED_USE] != 0) func_021DD7B8(factor, server, pokeId, work, 4);
}

void func_021DD70C(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_USED] == 0 && func_021D62C4(func_021C7CF4(server, pokeId), BTL_SICK_ITEM_BLOCK) == 0) func_021DDE30(factor, server, pokeId, 2, 1);
}

void func_021DD744(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_USED] == 0 && func_021D62C4(func_021C7CF4(server, pokeId), BTL_SICK_ITEM_BLOCK) == 0) func_021DDE30(factor, server, pokeId, 2, 0);
}

void func_021DD77C(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (work[ITEM_WORK_USED] == 0 && func_021D62C4(func_021C7CF4(server, pokeId), BTL_SICK_ITEM_BLOCK) == 0 && func_021DDEA4(server, pokeId, 2) != 0) func_021DD044(factor, server, pokeId);
}

void func_021DD7B8(struct BtlEventFactor *factor, void *server, int pokeId, int *work, int statIndex)
{
    struct BtlPokeParam *pokeParam;
    HandExRecoverHp *healCmd;
    HandExAddSick *sickCmd;

    if (work[ITEM_WORK_USED] == 0 && pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        pokeParam = func_021C7CF4(server, pokeId);
        healCmd = func_021C88A4(server, HANDEX_KIND_RECOVER_HP, pokeId);
        healCmd->pokeId = pokeId;
        healCmd->amount = func_021D7B74(pokeParam, func_021DCFF8(factor, 2));
        func_021C8838(&healCmd->str, HANDEX_STR_SET, 908);
        func_021C8860(&healCmd->str, pokeId);
        func_021C8860(&healCmd->str, func_021D70A8(factor));
        func_021C88C8(server, healCmd);
        if (POKE_TOOL_GetNatureStatMod(func_021D5844(pokeParam), statIndex) == -1) {
            sickCmd = func_021C88A4(server, HANDEX_KIND_ADD_SICK, pokeId);
            sickCmd->pokeId = pokeId;
            sickCmd->sickKind = BTL_SICK_CONFUSION;
            func_021D7DC0(BTL_SICK_CONFUSION, pokeParam, &sickCmd->sickCont);
            func_021C88C8(server, sickCmd);
        }
        work[ITEM_WORK_USED] = 1;
    }
}

int *func_021DD870(int *handlerCount)
{
    *handlerCount = 5;
    return d_021F1CCC;
}
