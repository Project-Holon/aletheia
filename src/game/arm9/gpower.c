/*
 * file:     gpower.c
 * unit:     yes
 * function: GPOWER_Init, GPOWER_CountDownTimers, GPOWER_ClearAll, GPOWER_Activate, GPOWER_GetActiveIdOfSameType, GPOWER_GetActiveIdByType, GPOWER_GetMinutesLeftByType, GPOWER_GetSelectedMinutesLeft, GPOWER_GetExpiringPowerId, GPOWER_ClearByPowerId, GPOWER_ClearType, GPOWER_LoadPowerTable, GPOWER_FreePowerTable, GPOWER_GetPowerType, GPOWER_GetPowerCost, GPOWER_NotifyTimerUpdate, GPOWER_ApplyEncountRate, GPOWER_ApplyHatchRate, GPOWER_ApplyFriendshipBonus, GPOWER_ApplyShopPrice, GPOWER_UseHpRestore, GPOWER_UsePpRestore, GPOWER_ApplyExpRate, GPOWER_ApplyPrizeMoney, GPOWER_ApplyCaptureRate, GPOWER_GetSpecialPowerId
 * address:  0x02010DB4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from vm.c by tools/splitfile.py.
 *
 * symbols:
 *   _GPowerState  0x021461E8  data
 *   _u32_div_f   0x0209C2B0  arm
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   POKE_TOOL_HealParty  0x0201BA34  thumb
 *   POKEPARTY_FindFirstBattleReady  0x0201AB08  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 *   WAZA_TOOL_GetMaxPP  0x0201C158  thumb
 *   MI_CpuFill8        0x02082BCC  arm
 *   _ll_sdiv                     0x0209BE5C  arm
 */
#include "../version.h"
#include "script_vm_types.h"
#include "vm_shared_types.h"

struct Pokemon;

typedef enum { GPOWER_TYPE_FIRST = 0, GPOWER_TYPE_MAX = 13 } GPowerType;

/* One record of the pass power table (archive 0x26 member 0, 12 bytes). */
typedef struct GPowerData {
    u16 nameId;
    u16 cost;
    u8  reserved[4];
    u16 value;
    u8  type;
    u8  durationHours;
} GPowerData;

/* Active pass powers, one slot per power type (0x60 bytes at 0x021461E8). */
typedef struct GPowerState {
    u32 secondsLeft[GPOWER_TYPE_MAX];
    u8  activeId[GPOWER_TYPE_MAX];
    u8  pad41;
    u16 value[GPOWER_TYPE_MAX];
    u8  selectedType;
    u8  pad5D[3];
} GPowerState;

#define GPOWER_ID_NONE   0x30

#define GPOWER_TYPE_NONE 0xD

#include "../types.h"

extern void *ARC_TOOL_LoadMember(u32 arcId, u32 dataId, u32 heapId);

extern u32 GFL_HEAP_Free(void *memory);
struct Party;

extern void POKE_TOOL_HealParty(struct Party *party);

extern u32 POKEPARTY_FindFirstBattleReady(struct Party *party);
struct PokemonParam;

extern struct PokemonParam *POKEPARTY_GetMember(struct Party *party, u32 pos);

extern u32 POKE_TOOL_DecodePartyParam(struct PokemonParam *pp);

extern u32 POKE_TOOL_GetPartyValue(struct PokemonParam *pp, u32 paramId, u32 arg);

extern void POKE_TOOL_SetPartyValue(struct PokemonParam *pp, u32 paramId, u32 value);

extern u32 POKE_TOOL_EncodePartyParam(struct PokemonParam *pp, u32 didDecode);

extern u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUp);

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

void GPOWER_Init(void);

void GPOWER_CountDownTimers(void);

void GPOWER_ClearAll(void);

void GPOWER_Activate(int powerId, const GPowerData *table, int select);

u8 GPOWER_GetActiveIdOfSameType(int powerId, const GPowerData *table);

u8 GPOWER_GetActiveIdByType(int type);

u32 GPOWER_GetMinutesLeftByType(u32 type);

int GPOWER_GetSelectedMinutesLeft(void);

u8 GPOWER_GetExpiringPowerId(void);

void GPOWER_ClearByPowerId(int powerId, const GPowerData *table);

void GPOWER_ClearType(int type);

GPowerData *GPOWER_LoadPowerTable(u32 heapId);

void GPOWER_FreePowerTable(GPowerData *table);

unsigned int GPOWER_GetPowerType(const GPowerData *table, int powerId);

unsigned int GPOWER_GetPowerCost(const GPowerData *table, int powerId);

void GPOWER_NotifyTimerUpdate(void);

u32 GPOWER_ApplyEncountRate(u32 rate);

u32 GPOWER_ApplyHatchRate(u32 steps);

int GPOWER_ApplyFriendshipBonus(int friendship);

u32 GPOWER_ApplyShopPrice(u32 price);

u32 GPOWER_UseHpRestore(void *party);

u32 GPOWER_UsePpRestore(void *party);

u32 GPOWER_ApplyExpRate(u32 exp);

u32 GPOWER_ApplyPrizeMoney(u32 money);

s32 GPOWER_ApplyCaptureRate(s32 rate);

u32 GPOWER_GetSpecialPowerId(void);

extern GPowerState _GPowerState;

/*
 * Zeroes the 0x60-byte array and reinitialises it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_Init.c \
 *       --func GPOWER_Init --addr 0x02010DB4 --thumb --cc 1.1p1
 */
void GPOWER_Init(void)
{
    MI_CpuFill8(&_GPowerState, 0, sizeof(GPowerState));
    GPOWER_ClearAll();
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_CountDownTimers.c \
 *       --func GPOWER_CountDownTimers --addr 0x02010DCC --cc 1.1p1 --thumb
 *
 * net_save.c: decrement every counter above 1, then tail-call the empty
 * placeholder GPOWER_NotifyTimerUpdate (pool word 0x02010FAD, `matched`).  The counter
 * is an enum, which keeps the unfolded pre-loop guard with a plain
 * increment; see GPOWER_ClearAll.c and docs/notes/pkt_02010DCC.c.txt.
 */
void GPOWER_CountDownTimers(void)
{
    GPowerType type;

    for (type = 0; type < GPOWER_TYPE_MAX; type++) {
        if (_GPowerState.secondsLeft[type] > 1) {
            _GPowerState.secondsLeft[type]--;
        }
    }
    GPOWER_NotifyTimerUpdate();
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_ClearAll.c \
 *       --func GPOWER_ClearAll --addr 0x02010DF4 --cc 1.1p1 --thumb
 *
 * net_save.c: clear all thirteen counter slots, then deselect (+0x1c = 0xd,
 * the "none" slot).  Wave 14 closed the residue of
 * docs/notes/pkt_02010DCC.c.txt (unfolded pre-loop guard plus a plain
 * increment, "no C type gives both"): the counter is an ENUM.  With
 * -enum int an enum counter keeps the `cmp r4, #0xd; bge` entry guard
 * (mwcc does not fold the first test for an enum-typed induction variable)
 * and increments without a truncation pair.  The slot count is an enum
 * constant; 13 is a content constant (docs/families/net_save.h).
 */
void GPOWER_ClearAll(void)
{
    GPowerType type;

    for (type = 0; type < GPOWER_TYPE_MAX; type++) {
        GPOWER_ClearType(type);
    }
    _GPowerState.selectedType = GPOWER_TYPE_MAX;
}

/*
 * Records one play-time entry.  `rec` is an array of 0xc-byte records; the
 * record's +0xa byte is the SLOT (0..0xc) and +0xb is a count of hours, which
 * is stored as SECONDS in _GPowerState.secondsLeft[type] (0xe10 = 3600).  The +8 halfword
 * goes into the parallel halfword table at _GPowerState.value, and the selected-slot
 * byte _GPowerState.selectedType is cleared to 0xd when it named this slot and set to
 * this slot when `select` is 1.
 *
 * The four-case switch is emitted as a comparison TREE, not a table, because
 * the cases (0, 1, 7, 8) are not dense; the pairs are each other's partner
 * (slot 0 clears slot 1 and vice versa, slot 7 clears slot 8 and vice versa).
 *
 * EXACT* : the listing's extent runs to 0x02010EC0 because the two leaf
 * accessors that follow at 0x02010EA0 and 0x02010EB4 save no lr and so carry
 * no label (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * Both should be seeded into layout/function_starts.txt.
 *
 * Addresses are Black-image addresses; 0x30 (the record-count bound) and 0xd
 * (the slot count) are content constants.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_Activate.c \
 *       --func GPOWER_Activate --addr 0x02010E14 --cc 1.1p1 --thumb
 */
void GPOWER_Activate(int powerId, const GPowerData *table, int select)
{
    int type;

    if (powerId >= GPOWER_ID_NONE) {
        return;
    }
    table = table + powerId;
    type = table->type;
    _GPowerState.activeId[type] = (u8)powerId;
    _GPowerState.secondsLeft[type] = table->durationHours * 3600;
    _GPowerState.value[type] = table->value;
    if (_GPowerState.selectedType == type) {
        _GPowerState.selectedType = GPOWER_TYPE_NONE;
    }
    if (select == 1) {
        _GPowerState.selectedType = (u8)type;
    }
    switch (type) {
    case 0:
        GPOWER_ClearType(1);
        break;
    case 1:
        GPOWER_ClearType(0);
        break;
    case 7:
        GPOWER_ClearType(8);
        break;
    case 8:
        GPOWER_ClearType(7);
        break;
    }
}

/*
 * The second unlabelled leaf after GPOWER_Activate (it saves no lr, so
 * disasm.py never labels it; see docs/idioms/unlabelled-leaf-functions-hide-
 * in-word-runs.md).  It reads the state byte for the record `rec[slot]`
 * names, using the same 0xc-byte record stride and +0xa slot field that
 * GPOWER_Activate writes with.
 *
 * The pointer must be ADVANCED into its own value first: writing the whole
 * thing as one subscript, `_GPowerState.activeId[rec[slot * 0xc + 0xa]]`, folds the
 * +0xa into the scaled index and gives `adds r2, #0xa; ldrb r1, [r1, r2]`
 * where the original has `adds r0, r1, r2; ldrb r1, [r0, #0xa]` - four bytes
 * in the same place, same size, and the only difference in the function.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_GetActiveIdOfSameType.c \
 *       --func GPOWER_GetActiveIdOfSameType --addr 0x02010EA0 --cc 1.1p1 --thumb
 */
u8 GPOWER_GetActiveIdOfSameType(int powerId, const GPowerData *table)
{
    table = table + powerId;
    return _GPowerState.activeId[table->type];
}

/*
 * One of the two leaf accessors that follow GPOWER_Activate and carry no label
 * because they save no lr (docs/idioms/unlabelled-leaf-functions-hide-in-
 * word-runs.md).  It reads the state byte of one slot straight out of the
 * thirteen-entry byte table; see docs/families/net_save.h section 4.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_GetActiveIdByType.c \
 *       --func GPOWER_GetActiveIdByType --addr 0x02010EB4 --cc 1.1p1 --thumb
 */
u8 GPOWER_GetActiveIdByType(int type)
{
    return _GPowerState.activeId[type];
}

/*
 * Returns 0 for a 0x30 entry, otherwise the counter divided by 0x3c (or 1).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_GetMinutesLeftByType.c \
 *       --func GPOWER_GetMinutesLeftByType --addr 0x02010EC0 --thumb --cc 1.1p1
 */
u32 GPOWER_GetMinutesLeftByType(u32 type)
{
    u32 minutes;

    if (_GPowerState.activeId[type] == GPOWER_ID_NONE) {
        return 0;
    }
    minutes = _GPowerState.secondsLeft[type] / 60;
    return minutes != 0 ? minutes : 1;
}

/*
 * Index _GPowerState.selectedType selects one of thirteen u32 counters in _GPowerState.secondsLeft;
 * 0xd means "none" and answers 0, otherwise the counter is divided by 60 and
 * a zero quotient is lifted to 1.  The divide is unsigned (`_u32_div_f`), so the
 * counter is read as u32.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_GetSelectedMinutesLeft.c \
 *       --func GPOWER_GetSelectedMinutesLeft --addr 0x02010EEC --cc 1.1p1 --thumb
 */
int GPOWER_GetSelectedMinutesLeft(void)
{
    u8 type = _GPowerState.selectedType;
    u32 minutes;

    if (type == GPOWER_TYPE_NONE) {
        return 0;
    }
    minutes = _GPowerState.secondsLeft[type] / 60;
    if (minutes == 0) {
        minutes = 1;
    }
    return minutes;
}

/*
 * Returns the byte-table entry _GPowerState.activeId of the first of the thirteen counter slots whose value is 1,
 * or 0x30 when none is. The loop index is the Slot enum (as in GPOWER_ClearAll): an int index lets
 * mwcc fold the constant entry guard away.
 *
 * Addresses are Black-image addresses.
 */
u8 GPOWER_GetExpiringPowerId(void)
{
    GPowerType type;

    for (type = 0; type < GPOWER_TYPE_MAX; type++) {
        if (_GPowerState.secondsLeft[type] == 1)
            return _GPowerState.activeId[type];
    }
    return GPOWER_ID_NONE;
}

/*
 * Clears the counter slot named by byte 0xA of entry idx in a 12-byte-entry table.
 *
 * Addresses are Black-image addresses.
 */
void GPOWER_ClearByPowerId(int powerId, const GPowerData *table)
{
    GPOWER_ClearType(table[powerId].type);
}

/*
 * Clears slot `idx` of the same thirteen-entry counter table and marks the byte
 * table _GPowerState.activeId; if the slot was the selected one (_GPowerState.selectedType) the
 * selection is reset to 0xd.  The bound test is SIGNED (`bge`, not `bhs`): the
 * index is an int.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_ClearType.c \
 *       --func GPOWER_ClearType --addr 0x02010F50 --cc 1.1p1 --thumb
 */
void GPOWER_ClearType(int type)
{
    if (type >= GPOWER_TYPE_NONE) {
        return;
    }
    _GPowerState.activeId[type] = GPOWER_ID_NONE;
    _GPowerState.secondsLeft[type] = 0;
    if (_GPowerState.selectedType == type) {
        _GPowerState.selectedType = GPOWER_TYPE_NONE;
    }
}

/*
 * Loads archive 0x26 member 0 on the given heap.
 *
 * Addresses are Black-image addresses.
 */
GPowerData *GPOWER_LoadPowerTable(u32 heapId)
{
    return ARC_TOOL_LoadMember(0x26, 0, heapId);
}

/*
 * Frees a buffer from GPOWER_LoadPowerTable.
 *
 * Addresses are Black-image addresses.
 */
void GPOWER_FreePowerTable(GPowerData *table)
{
    GFL_HEAP_Free(table);
}

/*
 * Unlabelled Thumb leaf: byte at +0xa of the 12-byte record idx.
 */
unsigned int GPOWER_GetPowerType(const GPowerData *table, int powerId)
{
    return table[powerId].type;
}

/*
 * Unlabelled Thumb leaf: halfword at +0x2 of the 12-byte record idx.
 */
unsigned int GPOWER_GetPowerCost(const GPowerData *table, int powerId)
{
    return table[powerId].cost;
}

/*
 * An empty function: a pool word in the image holds 0x02010FAD (Thumb), so
 * this two-byte `bx lr` is a real entry point, a placeholder callback that
 * disasm.py could not label because it saves nothing.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_NotifyTimerUpdate.c \
 *       --func GPOWER_NotifyTimerUpdate --addr 0x02010FAC --cc 1.1p1 --thumb
 */
void GPOWER_NotifyTimerUpdate(void)
{
}

/*
 * Two mode bytes (+0x14, +0x15) and two scales (+2, +4), each arm clamped to 100
 * (`if (v > 100) v = 100;`) after the unsigned scale divide.  The two arms end
 * at one shared `pop`, which is why the compiler tail-merged them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_ApplyEncountRate.c \
 *       --func GPOWER_ApplyEncountRate --addr 0x02010FB0 --cc 1.1p1 --thumb
 */
u32 GPOWER_ApplyEncountRate(u32 rate)
{
    if (_GPowerState.activeId[0] != GPOWER_ID_NONE) {
        rate = _GPowerState.value[0] * rate / 100;
        if (rate > 100) rate = 100;
        return rate;
    }
    if (_GPowerState.activeId[1] != GPOWER_ID_NONE) {
        rate = _GPowerState.value[1] * rate / 100;
        if (rate > 100) rate = 100;
    }
    return rate;
}

/*
 * Scale by _GPowerState.value[2] unless _GPowerState.activeId[2]
 * is 0x30.  The divide is unsigned (`_u32_div_f`, which the runtime
 * table at 0x0209C2B0 calls `_div_by_zero_check`: mwcc's own symbol name for
 * the site is the `_u32_div_f` one, see docs/notes/pkt_0202EC44.c.txt), and the
 * multiply is spelled table-value-first: `x * v`, not `v * x`, or the result
 * register comes out r1 and the function is four bytes too long.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_ApplyHatchRate.c \
 *       --func GPOWER_ApplyHatchRate --addr 0x02010FF4 --cc 1.1p1 --thumb
 */
u32 GPOWER_ApplyHatchRate(u32 steps)
{
    if (_GPowerState.activeId[2] != GPOWER_ID_NONE)
        steps = _GPowerState.value[2] * steps / 100;
    return steps;
}

int GPOWER_ApplyFriendshipBonus(int friendship)
{
    if (_GPowerState.activeId[3] != GPOWER_ID_NONE)
        friendship += _GPowerState.value[3];
    return friendship;
}

/*
 * Same shape as GPOWER_ApplyHatchRate, mode byte +0x18, scale +0xa.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_ApplyShopPrice.c \
 *       --func GPOWER_ApplyShopPrice --addr 0x0201102C --cc 1.1p1 --thumb
 */
u32 GPOWER_ApplyShopPrice(u32 price)
{
    if (_GPowerState.activeId[4] != GPOWER_ID_NONE)
        price = _GPowerState.value[4] * price / 100;
    return price;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_UseHpRestore.c  *       --func GPOWER_UseHpRestore --addr 0x0201104C --cc 1.1p1 --thumb
 *
 * net_save.c, gated on mode byte +0x19 (slot 5): unless the +0xc factor
 * is 999, pick the record POKEPARTY_FindFirstBattleReady(box) names inside the box
 * (POKEPARTY_GetMember: box + 8 + idx * 0xdc), and add the +0xc factor to its
 * field 0xa0 clamped to field 0xa1, inside the POKE_TOOL_DecodePartyParam /
 * POKE_TOOL_EncodePartyParam access bracket; then clear slot 5.  Returns the index, or
 * 0xff when the mode byte is '0'.
 *
 * Wave 14 closed the entry residue shared with GPOWER_UsePpRestore and
 * GPOWER_ApplyCaptureRate (pool word loaded into r1 before the parameter copy):
 * it was ARITY, not order.  POKE_TOOL_HealParty, POKEPARTY_FindFirstBattleReady (a tail-call
 * forwarder that passes r0 through) and POKE_TOOL_DecodePartyParam all take the box
 * or record pointer, so r0 stays live across the guards.  The record is
 * a separate local from the box parameter (reassigning the parameter
 * swaps r4/r5).
 */
u32 GPOWER_UseHpRestore(void *party)
{
    void *pokemon;
    u32 slot;
    u32 fastMode;
    int maxHp;
    int hp;

    if (_GPowerState.activeId[5] != GPOWER_ID_NONE) {
        if (_GPowerState.value[5] == 999) {
            POKE_TOOL_HealParty(party);
            slot = 0;
        } else {
            slot = POKEPARTY_FindFirstBattleReady(party);
            pokemon = POKEPARTY_GetMember(party, slot);
            fastMode = POKE_TOOL_DecodePartyParam(pokemon);
            maxHp = POKE_TOOL_GetPartyValue(pokemon, 0xa1, 0);
            hp = POKE_TOOL_GetPartyValue(pokemon, 0xa0, 0);
            hp = hp + _GPowerState.value[5];
            if (hp > maxHp) {
                hp = maxHp;
            }
            POKE_TOOL_SetPartyValue(pokemon, 0xa0, hp);
            POKE_TOOL_EncodePartyParam(pokemon, fastMode);
        }
        GPOWER_ClearType(5);
        return slot;
    }
    return 0xff;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_UsePpRestore.c  *       --func GPOWER_UsePpRestore --addr 0x020110CC --cc 1.1p1 --thumb
 *
 * net_save.c, gated on mode byte +0x1a (slot 6): for each of the record's
 * four slots whose field 0x36+i is set, add the +0xe factor to field
 * 0x3a+i, clamped to WAZA_TOOL_GetMaxPP(field 0x36+i, field 0x3e+i); inside the
 * POKE_TOOL_DecodePartyParam / POKE_TOOL_EncodePartyParam access bracket; then clear slot 6.  Same
 * declarations as GPOWER_UseHpRestore.c (the callees take the box / record
 * pointer, the record is its own local), which is what closed the
 * entry-order residue of docs/notes/pkt_0201104C.GPOWER_UsePpRestore.c.txt.
 */
u32 GPOWER_UsePpRestore(void *party)
{
    void *pokemon;
    u32 slot;
    u32 fastMode;
    u32 i;
    u32 move;
    u32 maxPp;
    u32 pp;

    if (_GPowerState.activeId[6] != GPOWER_ID_NONE) {
        slot = POKEPARTY_FindFirstBattleReady(party);
        pokemon = POKEPARTY_GetMember(party, slot);
        fastMode = POKE_TOOL_DecodePartyParam(pokemon);
        for (i = 0; i < 4; i++) {
            move = POKE_TOOL_GetPartyValue(pokemon, (int)(0x36 + i), (int)0);
            if (move != 0) {
                maxPp = (u32)WAZA_TOOL_GetMaxPP(move, (u8)POKE_TOOL_GetPartyValue(pokemon, (int)(0x3e + i), (int)0));
                pp = POKE_TOOL_GetPartyValue(pokemon, (int)(0x3a + i), (int)0);
                pp += _GPowerState.value[6];
                if (pp > maxPp) {
                    pp = maxPp;
                }
                POKE_TOOL_SetPartyValue(pokemon, (int)(0x3a + i), pp);
            }
        }
        POKE_TOOL_EncodePartyParam(pokemon, fastMode);
        GPOWER_ClearType(6);
        return slot;
    }
    return 0xff;
}

/*
 * Two mode bytes (+0x1b, +0x1c) and two scales (+0x10, +0x12) on the same two
 * tables; the first arm returns early, the second falls into the shared exit.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_ApplyExpRate.c \
 *       --func GPOWER_ApplyExpRate --addr 0x02011168 --cc 1.1p1 --thumb
 */
u32 GPOWER_ApplyExpRate(u32 exp)
{
    if (_GPowerState.activeId[7] != GPOWER_ID_NONE)
        return _GPowerState.value[7] * exp / 100;
    if (_GPowerState.activeId[8] != GPOWER_ID_NONE)
        exp = _GPowerState.value[8] * exp / 100;
    return exp;
}

/*
 * Same shape as GPOWER_ApplyHatchRate, mode byte +0x1d, scale +0x14.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_ApplyPrizeMoney.c \
 *       --func GPOWER_ApplyPrizeMoney --addr 0x0201119C --cc 1.1p1 --thumb
 */
u32 GPOWER_ApplyPrizeMoney(u32 money)
{
    if (_GPowerState.activeId[9] != GPOWER_ID_NONE)
        money = _GPowerState.value[9] * money / 100;
    return money;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_ApplyCaptureRate.c
 *       --func GPOWER_ApplyCaptureRate --addr 0x020111BC --cc 1.1p1
 *
 * Scales v by the rate at +0x16 of the second record (v * rate / 100 in
 * 64 bits) unless the mode byte at +0x1e of the first is 0x30.  The 0x30
 * path has no return statement: the original falls off the end and hands
 * back v, still in r0.  Any written `return v;` makes the compiler join
 * the two paths through a copy (48 bytes); an s64 return type keeps the
 * size but colours the mode load in r3 (r1 is the high half of the
 * result).  See docs/idioms/a-missing-return-hands-back-the-parameter.md.
 */
s32 GPOWER_ApplyCaptureRate(s32 rate)
{
    if (_GPowerState.activeId[10] != GPOWER_ID_NONE) {
        return (s64)_GPowerState.value[10] * rate / 100;
    }
}

/*
 * Four bytes, `movs r0, #0x15; bx lr`: a constant getter, isolated between
 * two large unmatched functions, the same situation documented for
 * src/matched/unit_02011F24.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_GetSpecialPowerId.c \
 *       --func GPOWER_GetSpecialPowerId --addr 0x020111E8 --cc 1.1p1
 */
u32 GPOWER_GetSpecialPowerId(void)
{
    return PM_VERSION_ID;
}
