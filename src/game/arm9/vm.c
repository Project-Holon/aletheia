/*
 * file:     vm.c
 * unit:     yes
 * function: VM_Exit, GPOWER_Init, GPOWER_CountDownTimers, GPOWER_ClearAll, GPOWER_Activate, GPOWER_GetActiveIdOfSameType, GPOWER_GetActiveIdByType, GPOWER_GetMinutesLeftByType, GPOWER_GetSelectedMinutesLeft, GPOWER_GetExpiringPowerId, GPOWER_ClearByPowerId, GPOWER_ClearType, GPOWER_LoadPowerTable, GPOWER_FreePowerTable, GPOWER_GetPowerType, GPOWER_GetPowerCost, GPOWER_NotifyTimerUpdate, GPOWER_ApplyEncountRate, GPOWER_ApplyHatchRate, GPOWER_ApplyFriendshipBonus, GPOWER_ApplyShopPrice, GPOWER_UseHpRestore, GPOWER_UsePpRestore, GPOWER_ApplyExpRate, GPOWER_ApplyPrizeMoney, GPOWER_ApplyCaptureRate, GPOWER_GetSpecialPowerId, VM_Reset, VM_Create, VM_Delete, VM_Init, VM_Start, VM_End, VM_Control, VM_GetContext, VM_SetHook, VM_ReadU16, VM_GetU32, VM_PushStack, VM_PopStack, VM_Jump, VM_Call, VM_Return, VM_SetWait, TIMEZONE_GetNowTimeZone, TIMEZONE_GetTimeZoneOfHour, VM_GetTimeZoneLight, TIMEZONE_IsNight
 * address:  0x02010D98
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from ica_anime.c, btl_setup.c by tools/splitfile.py.
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
 *   _VmFileName 0x020A7268  data
 *   GF_STANDARD_SetField00  0x0203F4CC  arm
 *   _TimeZoneTable  0x0209DF24  data  a1
 *   _TimeZoneLightTable  0x0209DF10  data  a1
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   PROCSYS_FreeProcWork     0x020315D4  arm
 *   PROCSYS_Delete  0x0203133C  arm
 */
#include "script_vm_types.h"
#include "vm_shared_types.h"

struct Pokemon;

typedef enum { GPOWER_TYPE_FIRST = 0, GPOWER_TYPE_MAX = 13 } GPowerType;

/* RTC time as GF_STANDARD_SetField00 fills it. */
struct RtcTime {
    u32 hour;
    u32 minute;
    u32 second;
};

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

typedef signed long long s64;

/* Game initialisation parameters (0x14 bytes, GAMESYSTEM_SetupInitWork). */
/*
 * Work of the save-screen proc of net_err_proc.c (0x1A8 bytes at heap 0x5B,
 * GFL_NET_SAVE_CreateScreenWork); only the fields VM_Exit and that constructor touch.
 */
struct SaveScreenWork {
    u32 initParam;
    u32 reserved;
    struct ProcSys *procSys;
};

extern void PROCSYS_Delete(struct ProcSys *procSys);

extern void PROCSYS_FreeProcWork(struct Proc *proc);

extern void *ARC_TOOL_LoadMember(u32 arcId, u32 dataId, u32 heapId);

extern u32 GFL_HEAP_Free(void *memory);

extern void POKE_TOOL_HealParty(void *party);

extern u32 POKEPARTY_FindFirstBattleReady(void *party);

extern void *POKEPARTY_GetMember(void *party, u32 slot);

extern u32 POKE_TOOL_DecodePartyParam(struct Pokemon *pokemon);

extern u32 POKE_TOOL_GetPartyValue(void *pokemon, u32 param, u32 arg);

extern void POKE_TOOL_SetPartyValue(void *pokemon, u32 param, u32 value);

extern u32 POKE_TOOL_EncodePartyParam(struct Pokemon *pokemon, u32 fastMode);

extern u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUp);

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

extern void GF_STANDARD_SetField00(struct RtcTime *time);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void GFL_HEAP_DeleteChecked(unsigned int heapId);

int VM_Exit(struct Proc *proc, u32 *seq, void *param, struct SaveScreenWork *work);

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

void VM_Reset(ScriptVm *vm);

ScriptVm *VM_Create(u32 heapId, const ScriptVmParams *params);

void VM_Delete(ScriptVm *vm);

void VM_Init(ScriptVm *vm, void *user);

void VM_Start(ScriptVm *vm, u8 *pc);

ScriptVm *VM_End(ScriptVm *vm);

int VM_Control(ScriptVm *vm);

void *VM_GetContext(ScriptVm *vm);

void VM_SetHook(ScriptVm *vm, ScriptHookFn hook, void *arg);

u16 VM_ReadU16(ScriptVm *vm);

u32 VM_GetU32(ScriptVm *vm);

void VM_PushStack(ScriptVm *vm, u32 value);

u32 VM_PopStack(ScriptVm *vm);

void VM_Jump(ScriptVm *vm, u8 *pc);

void VM_Call(ScriptVm *vm, u8 *pc);

u8 *VM_Return(ScriptVm *vm);

void VM_SetWait(ScriptVm *vm, ScriptWaitFn wait);

u32 TIMEZONE_GetNowTimeZone(u32 season);

int TIMEZONE_GetTimeZoneOfHour(int season, int hour);

u8 VM_GetTimeZoneLight(int season, int timeZone);

u32 TIMEZONE_IsNight(u32 season);

extern GPowerState _GPowerState;

extern const char _VmFileName[];

extern const u8 _TimeZoneTable[][0x18];

extern const u8 _TimeZoneLightTable[][5];

int VM_Exit(struct Proc *proc, u32 *seq, void *param, struct SaveScreenWork *work)
{
    PROCSYS_Delete(work->procSys);
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_DeleteChecked(0x5b);
    return 1;
}

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
 * entry-order residue of docs/notes/pkt_0201104C.sub_020110CC.c.txt.
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
 *   python tools/match.py one --src src/matched/sub_020111E8.c \
 *       --func GPOWER_GetSpecialPowerId --addr 0x020111E8 --cc 1.1p1
 */
u32 GPOWER_GetSpecialPowerId(void)
{
    return 0x15;
}

/*
 * The bottom two functions of the game's script virtual machine ("vm.c", the
 * __FILE__ string this unit's allocation site passes, at 0x020A7268, fixed by
 * the terminator of "net_save.c" at 0x020A725C).
 *
 * VM_Create is the constructor: it takes a heap id and a 12-byte
 * descriptor { u16 stackCap; u16 ringCap; const ScriptCmdFn *cmds;
 * u32 cmdCount; }, allocates the 0x30-byte context plus both arrays behind
 * it in one block, copies the descriptor into the head of the context (12
 * bytes, so the copy is an inlined ldm/stm triple,
 * docs/idioms/aggregate-assignment-is-ldm-stm.md), and points +0x1c at the
 * first array and +0x18 one ringCap past it.  Both capacities are read back
 * out of the caller's descriptor, not out of the context that was just
 * written, which is why the second ldrh addresses r5 and not r7.
 *
 * VM_Reset is the reset: program counter, both stack depths, the state
 * byte, the wait callback and the pre-dispatch hook all cleared, and both
 * arrays filled with zero at their declared capacities.  It is the shared
 * prologue of the two entry points in the next unit (VM_Init and
 * VM_Start, 0x0201126C and 0x0201127C).
 *
 * The 0x30-byte context is:
 *   +0x00 u16 stackCap      (0x100 for the field script system)
 *   +0x02 u16 ringCap       (0x40)
 *   +0x04 const ScriptCmdFn *cmds
 *   +0x08 u32 cmdCount
 *   +0x0c u8  stack depth
 *   +0x0d u8  state (0 stopped, 1 running, 2 waiting on the callback)
 *   +0x0e u8  ring depth
 *   +0x10 wait callback
 *   +0x14 u8 *pc
 *   +0x18 u32 *stack
 *   +0x1c u32 *ring
 *   +0x20 user object
 *   +0x24 pre-dispatch hook, +0x28 its argument
 *   +0x2c owner-defined word (the loaded script file, for the field system)
 *
 * The unit stops one word short of the Thumb-to-ARM veneer at 0x02011264
 * (`ldr r3,[pc,#0]; bx r3; .word 0x020307B0`), which no tu range may span
 * (docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020111EC.c \
 *       --addr 0x020111EC --thumb --cc 1.1p1
 */
void VM_Reset(ScriptVm *vm)
{
    vm->pc = 0;
    vm->cmpFlag = 0;
    vm->state = 0;
    vm->wait = 0;
    vm->depth = 0;
    MI_CpuFill8(vm->stack, 0, vm->params.stackCap * 4);
    MI_CpuFill8(vm->ring, 0, vm->params.ringCap * 4);
    vm->hook = 0;
    vm->hookArg = 0;
}

ScriptVm *VM_Create(u32 heapId, const ScriptVmParams *params)
{
    u32 size;
    ScriptVm *vm;

    size = params->ringCap * 4 + sizeof(ScriptVm) + params->stackCap * 4;
    vm = (ScriptVm *)GFL_HEAP_Alloc(heapId, size, 0, _VmFileName, 96);
    MI_CpuFill8(vm, 0, size);
    vm->params = *params;
    vm->ring = (u32 *)(vm + 1);
    vm->stack = vm->ring + params->ringCap;
    return vm;
}

void VM_Delete(ScriptVm *vm)
{
    GFL_HEAP_Free(vm);
}

/*
 *           VM_GetContext, VM_SetHook
 *
 * The step function of the game's script virtual machine ("vm.c"), plus the
 * four small entry points around it.  The context layout and the
 * constructor are in src/matched/unit_020111EC.c.
 *
 * VM_Control is the interpreter core, called once per frame by the owner
 * of the context:
 *
 *   state 0  stopped, nothing to do
 *   state 1  running: fetch a u16 opcode with VM_ReadU16 (the cursor read
 *            that advances +0x14 by two), bounds-check it against +0x08, run
 *            the optional pre-dispatch hook at +0x24, then call
 *            cmds[opcode](vm, user).  A handler returning 1 yields for this
 *            frame; returning 0 continues straight into the next opcode, so
 *            the whole loop is one frame's worth of script.
 *   state 2  waiting: call the callback at +0x10 with (vm, user) every frame
 *            until it returns 1, then clear it and go back to running.  A
 *            null callback in this state is treated as "done waiting".
 *
 * Every abnormal exit (null pc, opcode past the table, hook veto) stops the
 * machine by writing 0 to +0x0d and returning 0, and every yield returns 1;
 * the default arm's `state = 0; return 1` and the handler's `return 1` share
 * one tail (docs/idioms/switch-arms-tail-merge.md).
 *
 * Two shapes in the switch are load-bearing and neither is optional.  The
 * arms are written in the order 0, 2, 1, default: state 2 falls through into
 * state 1 once its callback is gone, which is what puts the wait block
 * physically before the loop and lets the fall-through reach the loop head
 * with no branch.  And the interpreter loop leaves through `break` twice
 * over (out of the `for`, then out of the switch) rather than by returning
 * in place, so that the yield and the default arm's stop share one
 * `movs r0, #1; pop` tail; writing `return 1` at either site splits that
 * tail and costs four bytes
 * (docs/idioms/switch-arms-tail-merge.md,
 * docs/idioms/an-empty-switch-arm-breaks-to-the-last-epilogue-not-the-nearest.md).
 *
 * The wait callback has to be bound to a local: the original loads +0x10
 * once and both tests and calls that register, which a re-read of the field
 * across the call would not reproduce.
 *
 * VM_End, VM_GetContext and VM_SetHook carry no label in the
 * generated listing: none of the three saves `lr`, so disasm.py's prologue
 * sweep never fires and their bytes print as a `.word` run
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The field script system instantiates this VM in overlay 10 at
 * SCRIPT_SYS_CreateVm with a 609-entry command table at 0x0217062C; see the
 * "Script virtual machine" section of docs/ASSETS.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201126C.c \
 *       --addr 0x0201126C --thumb --cc 1.1p1
 */
void VM_Init(ScriptVm *vm, void *user)
{
    VM_Reset(vm);
    vm->user = user;
}

void VM_Start(ScriptVm *vm, u8 *pc)
{
    VM_Reset(vm);
    vm->pc = pc;
    vm->state = 1;
}

ScriptVm *VM_End(ScriptVm *vm)
{
    vm->state = 0;
    vm->pc = 0;
    return vm;
}

/*
 * Alternate entry: sub_02011292() enters VM_End two bytes in, after the
 * `movs r1, #0`, so the caller's r1 is stored to vm->state and vm->pc.
 */
int VM_Control(ScriptVm *vm)
{
    u32 op;
    ScriptWaitFn wait;

    switch (vm->state) {
    case 0:
        return 0;
    case 2:
        wait = vm->wait;
        if (wait != 0) {
            if (wait(vm, vm->user) == 1) {
                vm->wait = 0;
                vm->state = 1;
            }
            return 1;
        }
        vm->state = 1;
        /* fall through */
    case 1:
        for (;;) {
            if (vm->pc == 0) {
                vm->state = 0;
                return 0;
            }
            op = VM_ReadU16(vm);
            if (op >= vm->params.cmdCount) {
                vm->state = 0;
                return 0;
            }
            if (vm->hook != 0) {
                if (vm->hook(vm, vm->user, vm->hookArg, op) == 0) {
                    vm->state = 0;
                    return 0;
                }
            }
            if (vm->params.cmds[op](vm, vm->user) == 1) {
                break;
            }
        }
        break;
    default:
        vm->state = 0;
        break;
    }

    return 1;
}

void *VM_GetContext(ScriptVm *vm)
{
    return vm->user;
}

void VM_SetHook(ScriptVm *vm, ScriptHookFn hook, void *arg)
{
    vm->hook = hook;
    vm->hookArg = arg;
}

/*
 *           VM_Jump, VM_Call, VM_Return
 *
 * Seven functions, no external calls at all, over two small structs read and
 * written by cursor.  Two of the seven carry no label in the generated
 * listing at all: VM_GetU32 and VM_Jump, both leaves whose
 * prologue (or total absence of one) saves no `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * VM_Jump is four bytes, `str r1, [r0, #0x14]; bx lr`: the plain
 * setter of the +0x14 field that VM_Call and VM_Return reach only
 * through a history ring.
 *
 * VM_ReadU16 and VM_GetU32 are a matched pair, a little-endian u16
 * and u32 read off a byte cursor at +0x14, advancing it by 2 and by 4.
 * VM_GetU32 carries no label in the generated listing: it opens with
 * `push {r4, r5}`, which saves no `lr`, so disasm.py's prologue sweep never
 * fires on it and its 48 bytes print as a `.word` run between VM_ReadU16
 * and VM_PushStack (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * Its four byte reads are built MSB-first through a Horner chain
 * (((0 + b3) << 8 + b2) << 8 + b1) << 8 + b0, which is what the register
 * allocator does with a `for` loop counting down; the two-byte version is
 * small enough that the same loop unrolls into the flat expression used
 * below.
 *
 * VM_PushStack and VM_PopStack are a fixed-capacity ring: a byte count at
 * +0xC bounded by a halfword capacity at +0x0, backed by a `u32` array
 * pointed to by +0x18.  VM_PushStack pushes if there is room and returns
 * whether it did; VM_PopStack pops the oldest entry, or 0 if the ring is
 * empty (and leaves the count at 0 rather than going negative).
 *
 * VM_Call and VM_Return are a different struct's accessors for a
 * plain u32 field at +0x14, the same offset VM_Jump sets directly:
 * VM_Call pushes the field's old value onto a VM_PushStack ring
 * before overwriting it with the new one, and VM_Return pops a
 * VM_PopStack ring back into the field.  Both take the ring struct
 * pointer as the same first argument as the field's owner, so the two
 * structs are declared distinctly here (Ring and Cur) even though nothing
 * in this file proves they are not the same struct in the original; only
 * the offsets that are read are declared.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011330.c \
 *       --addr 0x02011330 --thumb
 */
u16 VM_ReadU16(ScriptVm *vm)
{
    u8  lo, hi;
    u16 high;

    lo = *vm->pc;
    vm->pc = vm->pc + 1;
    hi = *vm->pc;
    vm->pc = vm->pc + 1;
    high = (u16)(hi << 8);
    return lo + high;
}

u32 VM_GetU32(ScriptVm *vm)
{
    u8  b0, b1, b2, b3;
    u32 value;

    b0 = *vm->pc;
    vm->pc = vm->pc + 1;
    b1 = *vm->pc;
    vm->pc = vm->pc + 1;
    b2 = *vm->pc;
    vm->pc = vm->pc + 1;
    b3 = *vm->pc;
    vm->pc = vm->pc + 1;

    value = 0;
    value = value + b3;
    value = value << 8;
    value = value + b2;
    value = value << 8;
    value = value + b1;
    value = value << 8;
    value = value + b0;
    return value;
}

void VM_PushStack(ScriptVm *vm, u32 value)
{
    if (vm->depth + 1 < vm->params.stackCap) {
        vm->stack[vm->depth] = value;
        vm->depth = vm->depth + 1;
    }
}

u32 VM_PopStack(ScriptVm *vm)
{
    if (vm->depth == 0) {
        return 0;
    }
    vm->depth = vm->depth - 1;
    return vm->stack[vm->depth];
}

void VM_Jump(ScriptVm *vm, u8 *pc)
{
    vm->pc = pc;
}

void VM_Call(ScriptVm *vm, u8 *pc)
{
    u8 *ret = vm->pc;
    VM_PushStack(vm, (u32)ret);
    vm->pc = pc;
}

u8 *VM_Return(ScriptVm *vm)
{
    vm->pc = (u8 *)VM_PopStack(vm);
    return vm->pc;
}

void VM_SetWait(ScriptVm *vm, ScriptWaitFn wait)
{
    vm->state = 2;
    vm->wait = wait;
}

/*
 * Alternate entry: sub_020113D2() enters VM_SetWait two bytes in, after the
 * `movs r2, #2`, so the caller's r2 is stored at +0x0d.
 */



/*
 * Fills a 12-byte buffer through GF_STANDARD_SetField00 and tail-hands its own
 * argument and the buffer's first word to TIMEZONE_GetTimeZoneOfHour, a table lookup
 * that is a documented near miss (src/matched/sub_02011410.c's header has
 * the details) and so is declared here only, not defined.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020113D8.c \
 *       --func TIMEZONE_GetNowTimeZone --addr 0x020113D8 --cc 1.1p1 --lang c99 --thumb
 */
u32 TIMEZONE_GetNowTimeZone(u32 season)
{
    struct RtcTime time;

    GF_STANDARD_SetField00(&time);
    return TIMEZONE_GetTimeZoneOfHour(season, time.hour);
}

/*
 * vm.c, 0x020113F0..0x02011410: two byte lookups in constant 2D tables,
 * rows of 0x18 and 5 bytes.  Plain subscripts `tbl[row][col]` give the
 * image's `base + row * stride` then `ldrb [col, base]`; the old pending
 * park (byte-offset arithmetic, docs/notes/pkt_020113F0.c.txt) was capped on
 * the two single-pool rodata tables, which sole-ref/self now carries.
 */
int TIMEZONE_GetTimeZoneOfHour(int season, int hour)
{
    return _TimeZoneTable[season][hour];
}

u8 VM_GetTimeZoneLight(int season, int timeZone)
{
    return _TimeZoneLightTable[season][timeZone];
}

/*
 * ica_anime.c: is the animation in one of the two "finished" states.  Both
 * arms return the same 1, which is why the original reaches one epilogue
 * from both compares - it is a single disjunction, not two ifs.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011410.c \
 *       --addr 0x02011410 --thumb
 *   (tu, not one: the last two bytes of the extent are the linker's
 *    alignment padding up to the next function, which `one` reports as a
 *    size mismatch and would mark EXACT*.  The code itself is 54/22 bytes.)
 */
u32 TIMEZONE_IsNight(u32 season)
{
    switch (TIMEZONE_GetNowTimeZone(season)) {
    case 3:
    case 4:
        return 1;
    default:
        return 0;
    }
}
