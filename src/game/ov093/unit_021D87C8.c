/*
 * file:     unit_021D87C8.c
 * unit:     yes
 * function: func_021D87C8, func_021D87FC, func_021D8808, func_021D8838, func_021D8844, func_021D8874, func_021D88AC, func_021D88B8, func_021D88D0, func_021D88E8, func_021D890C, func_021D8940, func_021D8964, func_021D8974, func_021D89B8, func_021D8A30, func_021D8A3C, func_021D8A64, func_021D8A8C, func_021D8A9C, func_021D8AA8, func_021D8AD0, func_021D8AE0, func_021D8AEC, func_021D8B1C
 * address:  0x021D87C8
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F0668 0x021F0668 data ov093 a4
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 *   func_021D7B10  0x021D7B10  thumb  ov093
 *   d_021F0748     0x021F0748  data   ov093  a4
 *   func_021D84F0 0x021D84F0 thumb ov093
 *   d_021F05A0 0x021F05A0 data a4
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C804C   0x021C804C  thumb ov093
 *   d_021F09C0     0x021F09C0  data   ov093  a4
 *   d_021F0650 0x021F0650 data a4
 *   func_021C8288 0x021C8288 thumb ov093
 *   d_021F0D6C     0x021F0D6C  data   ov093  a4
 *   d_021F09E0     0x021F09E0  data   ov093  a4
 *   d_021F0738 0x021F0738 data a4
 *   func_021D7AD4 0x021D7AD4 thumb ov093
 *   d_021F09F0     0x021F09F0  data   ov093  a4
 */
#include "unit_021D8434_types.h"

/* Slow Start state kept in the factor work area. */
typedef struct {
    int started;
    int turnCount;
    int finished;
    int active;
} SlowStartWork;

#define SLOW_START_TURNS 5
#define BTL_STR_TYPE_STD 2
#define BTL_STR_SLOW_START_BEGIN 0x1F0
#define BTL_STR_SLOW_START_END 0x1F3

int func_021C804C(struct BtlSvFlow *flow, int pokeId, BtlActionWord *outAction);

void func_021D87C8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021D87FC(int *packedInfo);
void func_021D8808(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
u8 *func_021D8838(u32 *packedInfo);
void func_021D8844(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021D8874(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021D88AC(int *packedInfo);
void func_021D88B8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void *func_021D88D0(unsigned int *packedInfo);
void func_021D88E8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work);
void func_021D890C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work);
void func_021D8940(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work);
void func_021D8964(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work);
void func_021D8974(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work);
void func_021D89B8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work);
int *func_021D8A30(int *packedInfo);
void func_021D8A3C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void *func_021D8A58(int *packedInfo);
void func_021D8A64(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021D8A8C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *func_021D8A9C(int *packedInfo);
void func_021D8AA8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021D8AD0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *func_021D8AE0(int *packedInfo);
void func_021D8AEC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, unsigned char weather);
void func_021D8B1C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void *func_021D8B44(int *packedInfo);
extern u8 d_021F0668[];
extern int d_021F0748[];
extern unsigned char d_021F05A0[];
extern int d_021F09C0[];
extern unsigned char d_021F0650[];
extern int d_021F0D6C[];
extern int d_021F09E0[];
extern unsigned char d_021F0738[];
extern int d_021F09F0[];

/* Quick Feet: a poke with a status condition gets 1.5 times speed and ignores the paralysis penalty. */
void func_021D87C8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *bpp;
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        bpp = func_021C7CF4(flow, pokeId);
        if (func_021D62A8(bpp) != 0) {
            func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_1_5);
            func_021D76BC(BTL_EVAR_SPEED_PENALTY_FLAG, 0);
        }
    }
}

/* Quick Feet: handler table. */
int *func_021D87FC(int *packedInfo)
{
    *packedInfo = 1;
    return d_021F0748;
}

/* Tangled Feet: halves the accuracy of moves against a confused owner. */
void func_021D8808(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID)) {
        if (func_021D62C4(func_021C7CF4(flow, pokeId), BTL_SICK_CONFUSION))
            func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_0_5);
    }
}

/* Tangled Feet: handler table. */
u8 *func_021D8838(u32 *packedInfo)
{
    *packedInfo = 1;
    return d_021F0668;
}

/* Hustle: physical moves of the owner lose accuracy. */
void func_021D8844(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID) && WAZA_TOOL_GetDamageType((unsigned short)func_021D775C(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_PHYSICAL)
        func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_0_8);
}

/* Hustle: physical moves of the owner get 1.5 times power. */
void func_021D8874(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        if (WAZA_TOOL_GetDamageType((u16)func_021D775C(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_PHYSICAL) {
            func_021D76BC(BTL_EVAR_POWER, func_021D7B10(func_021D775C(BTL_EVAR_POWER), BTL_RATIO_1_5));
        }
    }
}

/* Hustle: handler table. */
int *func_021D88AC(int *packedInfo)
{
    *packedInfo = 2;
    return d_021F09C0;
}

/* Stall: the owner moves last in its priority bracket. */
void func_021D88B8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID))
        func_021D76BC(BTL_EVAR_ACTION_ORDER, 0);
}

/* Stall: handler table, one handler at priority 7. */
void *func_021D88D0(unsigned int *packedInfo)
{
    *packedInfo = func_021D84F0(7, 1);
    return d_021F05A0;
}

/* Slow Start: halves the speed while the effect is active. */
void func_021D88E8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && work->active != 0)
        func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_0_5);
}

/* Slow Start: halves the attack power of physical moves while the effect is active. */
void func_021D890C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID) && work->active != 0 && WAZA_TOOL_GetDamageType((unsigned short)func_021D775C(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_PHYSICAL)
        func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_0_5);
}

/* Slow Start: starts the effect when the owner enters. */
void func_021D8940(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID))
        func_021D8974(factor, flow, pokeId, work);
}

/* Slow Start: starts the effect once if it has not started. */
void func_021D8964(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work)
{
    if (work->started == 0)
        func_021D8974(factor, flow, pokeId, work);
}

/* Slow Start: resets the work area and shows the start message. */
void func_021D8974(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work)
{
    BtlMessageCmd *msg;

    work->started = 1;
    work->turnCount = 0;
    work->finished = 0;
    work->active = 1;
    msg = func_021C88A4(flow, 4, pokeId);
    msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
    func_021C8838(msg->strParam, BTL_STR_TYPE_STD, BTL_STR_SLOW_START_BEGIN);
    func_021C8860(msg->strParam, pokeId);
    func_021C88C8(flow, msg);
}

/*
 * Slow Start: counts the turns on which the owner took an action other than
 * a switch; after 5 it shows the end message and ends the effect.
 */
void func_021D89B8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work)
{
    BtlActionWord action;
    BtlMessageCmd *msg;

    if (pokeId != func_021D775C(BTL_EVAR_POKE_ID))
        return;
    if (work->finished != 0)
        return;
    if (work->turnCount < SLOW_START_TURNS) {
        if (func_021C804C(flow, pokeId, &action) == 0)
            return;
        if (action.kind == BTL_ACTION_CHANGE)
            return;
        work->turnCount += 1;
    }
    if (work->turnCount < SLOW_START_TURNS)
        return;
    msg = func_021C88A4(flow, 4, pokeId);
    func_021C8838(msg->strParam, BTL_STR_TYPE_STD, BTL_STR_SLOW_START_END);
    func_021C8860(msg->strParam, pokeId);
    func_021C88C8(flow, msg);
    work->active = 0;
    work->finished = 1;
}

/* Slow Start: handler table. */
int *func_021D8A30(int *packedInfo)
{
    *packedInfo = 6;
    return d_021F0D6C;
}

/* Compound Eyes: multiplies the accuracy of the owner's moves by 1.3. */
void func_021D8A3C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID))
        func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_1_3);
}

/* Compound Eyes: handler table. */
void *func_021D8A58(int *packedInfo)
{
    *packedInfo = 1;
    return d_021F0650;
}

/* Sand Veil: lowers the accuracy of moves against the owner in a sandstorm. */
void func_021D8A64(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID) && func_021C8288(flow) == BTL_WEATHER_SAND)
        func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_0_8);
}

/* Sand Veil: no damage from the sandstorm. */
void func_021D8A8C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    func_021D8AEC(factor, flow, pokeId, work, BTL_WEATHER_SAND);
}

/* Sand Veil: handler table. */
int *func_021D8A9C(int *packedInfo)
{
    *packedInfo = 2;
    return d_021F09E0;
}

/* Snow Cloak: lowers the accuracy of moves against the owner in hail. */
void func_021D8AA8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID) && func_021C8288(flow) == BTL_WEATHER_HAIL)
        func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_0_8);
}

/* Snow Cloak: no damage from hail. */
void func_021D8AD0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    func_021D8AEC(factor, flow, pokeId, work, BTL_WEATHER_HAIL);
}

/* Snow Cloak: handler table. */
int *func_021D8AE0(int *packedInfo)
{
    *packedInfo = 2;
    return d_021F09F0;
}

/* Prevents the weather damage of the given weather for the owner. */
void func_021D8AEC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, unsigned char weather)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && func_021D775C(BTL_EVAR_DAMAGE) > 0 && weather == func_021D775C(BTL_EVAR_WEATHER))
        func_021D76BC(BTL_EVAR_PREVENT_FLAG, 1);
}

/* Tinted Lens: doubles the damage of moves that are not very effective. */
void func_021D8B1C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID) && func_021D7AD4(func_021D775C(BTL_EVAR_TYPE_AFFINITY)) == BTL_AFFINITY_RESISTED)
        func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_2_0);
}

/* Tinted Lens: handler table. */
void *func_021D8B44(int *packedInfo)
{
    *packedInfo = 1;
    return d_021F0738;
}
