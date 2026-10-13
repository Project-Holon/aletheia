/*
 * file:     unit_021D93D8.c
 * unit:     yes
 * function: func_021D93D8, func_021D93EC, func_021D93FC, func_021D940C, func_021D9418, func_021D9460, func_021D9478, func_021D9484, func_021D9498, func_021D94A8, func_021D94B8, func_021D94C4, func_021D94D8, func_021D94E8, func_021D94F8, func_021D9504, func_021D9518, func_021D9528, func_021D9538, func_021D9544, func_021D9558, func_021D956C, func_021D957C, func_021D958C, func_021D9598, func_021D95AC, func_021D95BC, func_021D95CC, func_021D963C, func_021D9648, func_021D9670, func_021D96CC, func_021D96DC, func_021D96FC, func_021D9744, func_021D9754, func_021D9760, func_021D9770, func_021D977C, func_021D978C, func_021D9798, func_021D97A8, func_021D97B4, func_021D97EC, func_021D9830, func_021D983C, func_021D9848, func_021D9858, func_021D9864, func_021D9874, func_021D9880, func_021D98DC, func_021D9934, func_021D9978, func_021D99A4, func_021D99C8, func_021D99E0, func_021D99F8, func_021D9A24, func_021D9A44, func_021D9A5C, func_021D9A68, func_021D9AD0
 * address:  0x021D93D8
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
 *   func_021D76BC   0x021D76BC  thumb
 *   func_021D775C   0x021D775C  thumb
 *   d_021F0BFC     0x021F0BFC  data   ov093  a4
 *   d_021F0D3C     0x021F0D3C  data   ov093  a4
 *   d_021F0C4C     0x021F0C4C  data   ov093  a4
 *   d_021F0C74     0x021F0C74  data   ov093  a4
 *   d_021F0BB4     0x021F0BB4  data   ov093  a4
 *   d_021F0C9C     0x021F0C9C  data   ov093  a4
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F0CC4     0x021F0CC4  data   ov093  a4
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D62C4   0x021D62C4  thumb ov093
 *   d_021F08D0     0x021F08D0  data   ov093  a4
 *   d_021F08E0     0x021F08E0  data   ov093  a4
 *   d_021F08F0     0x021F08F0  data   ov093  a4
 *   d_021F0900     0x021F0900  data   ov093  a4
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F0930     0x021F0930  data   ov093  a4
 *   d_021F0CEC 0x021F0CEC data a4
 *   func_021E85F8 0x021E85F8 thumb ov093
 *   d_021F0910     0x021F0910  data   ov093  a4
 *   d_021F05C0     0x021F05C0  data   ov093  a4
 *   d_021F0670     0x021F0670  data   ov093  a4
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   d_021F05A8     0x021F05A8  data   a4
 *   d_021F0A88     0x021F0A88  data   ov093  a4
 */
#include "unit_021D93D8_types.h"
#include "btl_pokeparam_types.h"

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 value);
extern void func_021D7704(int key, s32 multiplier);
extern void func_021C88B4(void *flow, int cmdKind, int pokeId);
extern void *func_021C88A4(void *flow, int cmdKind, int pokeId);
extern void func_021C8838(void *strParam, int strType, int strId);
extern void func_021C8860(void *strParam, u32 arg);
extern void func_021C88C8(void *flow, void *cmd);
extern struct BtlPokeParam *func_021C7CF4(void *flow, int pokeId);
extern int func_021D62C4(struct BtlPokeParam *bpp, int sickIndex);
extern int func_021D62A8(struct BtlPokeParam *bpp);
extern int func_021D7B74(struct BtlPokeParam *bpp, u32 divisor);
extern int func_021C8288(void *flow);
extern int WAZA_TOOL_GetDamageType(int moveId);
extern int func_021E85F8(int pokeId);

int func_021D9648(void *flow, int pokeId, int sickIndex);
void func_021D9670(void *flow, void *flowCmd, int pokeId, int *work, u16 strId);
void func_021D96DC(void *flow, int pokeId, int sickIndex);
void func_021D96FC(void *flow, int pokeId, int sickIndex);
void func_021D97B4(void *flow, int pokeId, int weather);
void func_021D9880(void *flow, int pokeId, int weather);

extern int d_021F0BFC[];
extern int d_021F0D3C[];
extern int d_021F0C4C[];
extern int d_021F0C74[];
extern int d_021F0BB4[];
extern int d_021F0C9C[];
extern int d_021F0CC4[];
extern int d_021F08D0[];
extern int d_021F08E0[];
extern int d_021F08F0[];
extern int d_021F0900[];
extern int d_021F0930[];
extern unsigned int d_021F0CEC;
extern int d_021F0910[];
extern int d_021F05C0[];
extern int d_021F0670[];
extern int d_021F05A8[];
extern int d_021F0A88[];

void func_021D93D8(void *factor, void *flow, int pokeId, int *work)
{
    *work = func_021D9648(flow, pokeId, TKS_SICK_PARALYSIS);
}

void func_021D93EC(void *factor, void *flow, int pokeId)
{
    func_021D96DC(flow, pokeId, TKS_SICK_PARALYSIS);
}

void func_021D93FC(void *factor, void *flow, int pokeId)
{
    func_021D96FC(flow, pokeId, TKS_SICK_PARALYSIS);
}

int *func_021D940C(int *count)
{
    *count = 5;
    return d_021F0BFC;
}

void func_021D9418(void *factor, void *flow, int pokeId, int *work)
{
    int blocked;

    blocked = func_021D9648(flow, pokeId, TKS_SICK_SLEEP);
    *work = blocked;
    if (blocked == 0)
        *work = func_021D9648(flow, pokeId, 0xe);
}

void func_021D9440(void *factor, void *flow, int pokeId)
{
    func_021D96DC(flow, pokeId, TKS_SICK_SLEEP);
}

void func_021D9450(void *factor, void *flow, int pokeId)
{
    func_021D96FC(flow, pokeId, TKS_SICK_SLEEP);
}

void func_021D9460(void *factor, void *flow, int pokeId)
{
    if (pokeId == func_021D775C(TKS_EVAR_POKE_ID))
        func_021D76BC(TKS_EVAR_FAIL_FLAG, 1);
}

int *func_021D9478(int *count)
{
    *count = 6;
    return d_021F0D3C;
}

void func_021D9484(void *factor, void *flow, int pokeId, int *work)
{
    *work = func_021D9648(flow, pokeId, TKS_SICK_FREEZE);
}

void func_021D9498(void *factor, void *flow, int pokeId)
{
    func_021D96DC(flow, pokeId, TKS_SICK_FREEZE);
}

void func_021D94A8(void *factor, void *flow, int pokeId)
{
    func_021D96FC(flow, pokeId, TKS_SICK_FREEZE);
}

int *func_021D94B8(int *count)
{
    *count = 5;
    return d_021F0C4C;
}

void func_021D94C4(void *factor, void *flow, int pokeId, int *work)
{
    *work = func_021D9648(flow, pokeId, TKS_SICK_POISON);
}

void func_021D94D8(void *factor, void *flow, int pokeId)
{
    func_021D96DC(flow, pokeId, TKS_SICK_POISON);
}

void func_021D94E8(void *factor, void *flow, int pokeId)
{
    func_021D96FC(flow, pokeId, TKS_SICK_POISON);
}

int *func_021D94F8(int *count)
{
    *count = 5;
    return d_021F0C74;
}

void func_021D9504(void *factor, void *flow, int pokeId, int *work)
{
    *work = func_021D9648(flow, pokeId, TKS_SICK_BURN);
}

void func_021D9518(void *factor, void *flow, int pokeId)
{
    func_021D96DC(flow, pokeId, TKS_SICK_BURN);
}

void func_021D9528(void *factor, void *flow, int pokeId)
{
    func_021D96FC(flow, pokeId, TKS_SICK_BURN);
}

int *func_021D9538(int *count)
{
    *count = 5;
    return d_021F0C9C;
}

void func_021D9544(void *factor, void *flow, int pokeId, int *work)
{
    *work = func_021D9648(flow, pokeId, TKS_SICK_CONFUSION);
}

void func_021D9558(void *factor, void *flow, int pokeId, int *work)
{
    func_021D9670(factor, flow, pokeId, work, 0x165);
}

void func_021D956C(void *factor, void *flow, int pokeId)
{
    func_021D96DC(flow, pokeId, TKS_SICK_CONFUSION);
}

void func_021D957C(void *factor, void *flow, int pokeId)
{
    func_021D96FC(flow, pokeId, TKS_SICK_CONFUSION);
}

int *func_021D958C(int *count)
{
    *count = 4;
    return d_021F0BB4;
}

void func_021D9598(void *factor, void *flow, int pokeId, int *work)
{
    *work = func_021D9648(flow, pokeId, TKS_SICK_INFATUATION);
}

void func_021D95AC(void *factor, void *flow, int pokeId)
{
    func_021D96DC(flow, pokeId, TKS_SICK_INFATUATION);
}

void func_021D95BC(void *factor, void *flow, int pokeId)
{
    func_021D96FC(flow, pokeId, TKS_SICK_INFATUATION);
}

void func_021D95CC(void *factor, void *flow, int pokeId)
{
    TokuseiMessageCmd *cmd;

    if (pokeId == func_021D775C(TKS_EVAR_DEFENDER_ID) && (u16)func_021D775C(TKS_EVAR_MOVE_ID) == 0x1bd) {
        if (func_021D76BC(0x40, 1) != 0) {
            func_021C88B4(flow, 2, pokeId);
            cmd = func_021C88A4(flow, 4, pokeId);
            func_021C8838(&cmd->strParam, 2, 0xd2);
            func_021C8860(&cmd->strParam, pokeId);
            func_021C88C8(flow, cmd);
            func_021C88B4(flow, 3, pokeId);
        }
    }
}

int *func_021D963C(int *count)
{
    *count = 5;
    return d_021F0CC4;
}

int func_021D9648(void *flow, int pokeId, int sickIndex)
{
    if (pokeId == func_021D775C(TKS_EVAR_DEFENDER_ID) && sickIndex == func_021D775C(TKS_EVAR_CONDITION))
        return func_021D76BC(TKS_EVAR_FAIL_FLAG, 1);
    return 0;
}

void func_021D9670(void *factor, void *flow, int pokeId, int *work, u16 strId)
{
    TokuseiMessageCmd *cmd;

    if (pokeId == func_021D775C(TKS_EVAR_DEFENDER_ID) && *work == 1) {
        func_021C88B4(flow, 2, pokeId);
        cmd = func_021C88A4(flow, 4, pokeId);
        func_021C8838(&cmd->strParam, 2, strId);
        func_021C8860(&cmd->strParam, pokeId);
        func_021C88C8(flow, cmd);
        func_021C88B4(flow, 3, pokeId);
        *work = 0;
    }
}

void func_021D96CC(void *factor, void *flow, int pokeId, int *work)
{
    func_021D9670(factor, flow, pokeId, work, 0xd2);
}

void func_021D96DC(void *flow, int pokeId, int sickIndex)
{
    if (pokeId == func_021D775C(TKS_EVAR_POKE_ID))
        func_021D96FC(flow, pokeId, sickIndex);
}

void func_021D96FC(void *flow, int pokeId, int sickIndex)
{
    if (func_021D62C4(func_021C7CF4(flow, pokeId), sickIndex) != 0) {
        TokuseiCureSickCmd *cmd;

        func_021C88B4(flow, 2, pokeId);
        cmd = func_021C88A4(flow, 0xb, pokeId);
        cmd->sickIndex = sickIndex;
        cmd->showMessage = 1;
        cmd->pokeId = pokeId;
        func_021C88C8(flow, cmd);
        func_021C88B4(flow, 3, pokeId);
    }
}

void func_021D9744(void *factor, void *flow, int pokeId)
{
    func_021D97B4(flow, pokeId, TKS_WEATHER_RAIN);
}

int *func_021D9754(int *count)
{
    *count = 2;
    return d_021F08D0;
}

void func_021D9760(void *factor, void *flow, int pokeId)
{
    func_021D97B4(flow, pokeId, TKS_WEATHER_SUN);
}

int *func_021D9770(int *count)
{
    *count = 2;
    return d_021F08E0;
}

void func_021D977C(void *factor, void *flow, int pokeId)
{
    func_021D97B4(flow, pokeId, TKS_WEATHER_SAND);
}

int *func_021D978C(int *count)
{
    *count = 2;
    return d_021F08F0;
}

void func_021D9798(void *factor, void *flow, int pokeId)
{
    func_021D97B4(flow, pokeId, TKS_WEATHER_HAIL);
}

int *func_021D97A8(int *count)
{
    *count = 2;
    return d_021F0900;
}

void func_021D97B4(void *flow, int pokeId, int weather)
{
    TokuseiWeatherCmd *cmd;
    int cmdFlagKind = 2;

    if (pokeId == func_021D775C(cmdFlagKind)) {
        cmd = func_021C88A4(flow, 0x1d, pokeId);
        cmd->flags |= cmdFlagKind << 22;
        cmd->weather = weather;
        cmd->turns = 0xff;
        func_021C88C8(flow, cmd);
    }
}

void func_021D97EC(void *factor, void *flow, int pokeId)
{
    if (pokeId == func_021D775C(TKS_EVAR_POKE_ID)) {
        TokuseiWeatherCmd *cmd = func_021C88A4(flow, 0x1d, pokeId);

        cmd->flags |= 2 << 22;
        cmd->weather = 0;
        cmd->announce = 1;
        func_021C8838(&cmd->strParam, 1, 0x5e);
        func_021C88C8(flow, cmd);
    }
}

void func_021D9830(void)
{
    func_021D76BC(TKS_EVAR_FAIL_FLAG, 1);
}

int *func_021D983C(int *count)
{
    *count = 2;
    return d_021F0910;
}

void func_021D9848(void *factor, void *flow, int pokeId)
{
    func_021D9880(flow, pokeId, TKS_WEATHER_HAIL);
}

int *func_021D9858(int *count)
{
    *count = 1;
    return d_021F05C0;
}

void func_021D9864(void *factor, void *flow, int pokeId)
{
    func_021D9880(flow, pokeId, TKS_WEATHER_RAIN);
}

int *func_021D9874(int *count)
{
    *count = 1;
    return d_021F0670;
}

void func_021D9880(void *flow, int pokeId, int weather)
{
    struct BtlPokeParam *bpp;
    TokuseiHpCmd *cmd;

    if (weather == func_021D775C(TKS_EVAR_WEATHER) && pokeId == func_021D775C(TKS_EVAR_POKE_ID)) {
        bpp = func_021C7CF4(flow, pokeId);
        cmd = func_021C88A4(flow, 5, pokeId);
        cmd->flags |= 0x800000;
        cmd->pokeId = pokeId;
        cmd->amount = func_021D7B74(bpp, 0x10);
        func_021C88C8(flow, cmd);
        func_021D76BC(TKS_EVAR_FAIL_FLAG, 1);
    }
}

void func_021D98DC(void *factor, void *flow, int pokeId)
{
    int damage;
    TokuseiHpCmd *cmd;

    if (pokeId == func_021D775C(TKS_EVAR_POKE_ID) && func_021D775C(TKS_EVAR_WEATHER) == TKS_WEATHER_SUN) {
        damage = func_021D7B74(func_021C7CF4(flow, pokeId), 8);
        func_021C88B4(flow, 2, pokeId);
        cmd = func_021C88A4(flow, 7, pokeId);
        cmd->pokeId = pokeId;
        cmd->amount = damage;
        func_021C88C8(flow, cmd);
        func_021C88B4(flow, 3, pokeId);
    }
}

void func_021D9934(void *factor, void *flow, int pokeId)
{
    if (pokeId == func_021D775C(TKS_EVAR_ATTACKER_ID) && func_021C8288(flow) == TKS_WEATHER_SUN) {
        if (WAZA_TOOL_GetDamageType((u16)func_021D775C(TKS_EVAR_MOVE_ID)) == 2)
            func_021D7704(TKS_EVAR_POWER_RATIO, 0x1800);
    }
}

int *func_021D996C(int *count)
{
    *count = 2;
    return d_021F0930;
}

void func_021D9978(void *factor, void *flow, int pokeId)
{
    if (pokeId == func_021D775C(TKS_EVAR_DEFENDER_ID) && pokeId != func_021D775C(TKS_EVAR_ATTACKER_ID) && func_021D775C(TKS_EVAR_CONDITION) != 8)
        func_021D76BC(TKS_EVAR_FAIL_FLAG, 1);
}

void func_021D99A4(void *factor, void *flow, int pokeId)
{
    if (pokeId == func_021D775C(TKS_EVAR_DEFENDER_ID) && pokeId != func_021D775C(TKS_EVAR_ATTACKER_ID))
        func_021D76BC(TKS_EVAR_FAIL_FLAG, 1);
}

void func_021D99C8(void *factor, void *flow, int pokeId)
{
    if (pokeId == func_021D775C(TKS_EVAR_DEFENDER_ID))
        func_021D76BC(TKS_EVAR_FAIL_FLAG, 1);
}

void func_021D99E0(void *factor, void *flow, int pokeId)
{
    if (pokeId == func_021D775C(TKS_EVAR_DEFENDER_ID))
        func_021D76BC(0x47, 1);
}

void func_021D99F8(void *factor, void *flow, int pokeId)
{
    if (func_021E85F8(pokeId) != 0 && func_021D775C(5) == 1)
        func_021D76BC(0x47, 1);
}

void *func_021D9A18(int *count)
{
    *count = 5;
    return &d_021F0CEC;
}

void func_021D9A24(void *factor, void *flow, int pokeId)
{
    unsigned short doubled;

    if (pokeId == func_021D775C(TKS_EVAR_ATTACKER_ID)) {
        doubled = func_021D775C(TKS_EVAR_CHANGE_AMOUNT) * 2;
        func_021D76BC(TKS_EVAR_CHANGE_AMOUNT, doubled);
    }
}

void func_021D9A44(void *factor, void *flow, int pokeId)
{
    if (pokeId == func_021D775C(TKS_EVAR_ATTACKER_ID))
        func_021D76BC(0x45, 1);
}

int *func_021D9A5C(int *count)
{
    *count = 3;
    return d_021F0A88;
}

void func_021D9A68(void *factor, void *flow, int pokeId)
{
    TokuseiCureSickCmd *cmd;

    if (pokeId == func_021D775C(TKS_EVAR_POKE_ID) && func_021C8288(flow) == TKS_WEATHER_RAIN) {
        if (func_021D62A8(func_021C7CF4(flow, pokeId))) {
            func_021C88B4(flow, 2, pokeId);
            cmd = func_021C88A4(flow, 0xb, pokeId);
            cmd->sickIndex = 0x24;
            cmd->pokeId = pokeId;
            cmd->showMessage = 1;
            cmd->flags |= 0x2000000;
            func_021C88C8(flow, cmd);
            func_021C88B4(flow, 3, pokeId);
        }
    }
}

int *func_021D9AD0(int *count)
{
    *count = 1;
    return d_021F05A8;
}
