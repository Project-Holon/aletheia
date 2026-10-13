/*
 * file:     unit_021AF75C.c
 * unit:     yes
 * function: func_021AF75C, func_021AF794, func_021AF7C4, func_021AF7D4, func_021AF7E4, func_021AF844, func_021AF878, func_021AF8A8, func_021AF8D8, func_021AF908, func_021AF918, func_021AF928, func_021AF958, func_021AF9A4, func_021AF9F0, func_021AFA38, func_021AFA80, func_021AFAC8, func_021AFAFC, func_021AFB2C, func_021AFB5C, func_021AFB90, func_021AFBC4, func_021AFBEC, func_021AFC18, func_021AFC28, func_021AFC38, func_021AFC88, func_021AFCD8, func_021AFD44, func_021AFDAC, func_021AFE64, func_021AFECC, func_021AFEFC, func_021AFF7C, func_021B0000
 * address:  0x021AF75C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from scrcmd_screeneffects.c at 0x021AF75C (lane L135, script argument and event data command handlers; original unknown).
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_0201EF40  0x0201EF40  thumb
 *   func_0201EF4C  0x0201EF4C  thumb
 *   func_0201EF5C  0x0201EF5C  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0201EEC4  0x0201EEC4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201EE84  0x0201EE84  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_02188D50  0x02188D50  thumb  ov021
 *   func_021C34F8  0x021C34F8  thumb  ov021
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F0F8  0x0201F0F8  thumb
 *   func_0201F124  0x0201F124  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C1DC  0x0200C1DC  thumb
 *   func_0200C1C4  0x0200C1C4  thumb
 *   func_02012104  0x02012104  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02184D38  0x02184D38  thumb  ov020
 *   func_02185534  0x02185534  thumb  ov020
 *   func_02012844  0x02012844  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0216282C  0x0216282C  thumb  ov010
 *   func_02162A6C  0x02162A6C  thumb  ov010
 *   func_02184E40  0x02184E40  thumb  ov020
 *   func_021BB578  0x021BB578  thumb  ov021
 *   func_02185050  0x02185050  thumb  ov020
 *   func_021850A8  0x021850A8  thumb
 *   func_021854B0  0x021854B0  thumb  ov020
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB3E8  0x021BB3E8  thumb  ov021
 *   func_02184D90  0x02184D90  thumb  ov020
 *   func_02184DE8  0x02184DE8  thumb  ov020
 */
#include "../arm9/script_vm_types.h"
#include "fldmmdl_rail_types.h"

typedef signed int s32;

struct ScrcmdWork;
struct WordSet;
struct GameSystem;
struct GameData;
struct FieldMap;
struct EventRec;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

typedef void (*WordSetRegisterFn)(struct WordSet *wordSet, u32 slot, u32 value);

extern void *func_021A3074(void *fieldPlayer);
extern void *func_020120F4(struct GameSystem *gameSystem);
extern void *func_0201296C(void *gameData);
extern void *func_0215A5F4(struct ScrcmdWork *cmdWork);
extern int func_02158F58(void *scriptWork);
extern u16 func_02159B10(ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern void *func_0215A5DC(struct ScrcmdWork *cmdWork);
extern void *func_02158F54(void *scriptWork);
extern void *func_0215A5E4(struct ScrcmdWork *cmdWork);
extern void *func_0201210C(struct GameSystem *gameSystem);
extern u16 func_02011330(ScriptVm *vm);
extern struct WordSet *func_02158F74(void *scriptWork);
extern void *func_02012944(void *gameData);
extern void func_0201F02C(struct WordSet *wordSet, u32 slot, void *myStatus);
extern void func_0201EF40(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201EF4C(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201EF5C(struct WordSet *wordSet, u32 slot, u32 value);
extern u32 func_020212B0(u32 a);
extern void func_0201EF34(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201F020(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201EE60(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201EEC4(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201F14C(struct WordSet *wordSet, u32 slot, u32 value);
extern void *func_02012934(void *gameData);
extern void *func_0201AB28(void *party, u32 index);
extern void func_0201EE84(struct WordSet *wordSet, u32 slot, void *mon);
extern void func_0201EEF4(struct WordSet *wordSet, u32 slot, void *mon);
extern void *func_02188D50(struct FieldMap *fieldMap);
extern void *func_021C34F8(void *sodateya, u32 index);
extern void func_0201EFA4(struct WordSet *wordSet, u32 slot, u32 number, u32 topDigitIndex, u32 padMode, u32 isHalfWidth);
extern u32 func_02013E4C(u32 a);
extern void func_0201F158(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201EFC8(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201F048(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201F198(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201F1B0(struct WordSet *wordSet, u32 slot, u8 value);
extern void func_0201F184(struct WordSet *wordSet, u32 slot, s32 value);
extern void func_0201F0F8(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201F124(struct WordSet *wordSet, u32 slot, u32 value);
extern void *func_02012EBC(struct GameData *gameData);
extern void *func_0200C0F0(void *saveControl);
extern u32 func_0200C1DC(void *block);
extern u32 func_0200C1C4(void *block);
extern void *func_02012104(struct GameSystem *gameSystem);
extern void func_02012374(void *parentEvent, void *childEvent);
extern void *func_02184D38(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int zoneId, const VecFx32 *pos, u16 dir, int seasonFadeAllowed);
extern void *func_02185534(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int zoneId, const VecFx32 *pos, u16 dir);
extern u32 func_02012844(void *gameData);
extern void *func_02188CB4(struct FieldMap *fieldMap);
extern void *func_02188CD0(struct FieldMap *fieldMap);
extern void func_021A3038(void *fieldPlayer, VecFx32 *outPos);
extern struct EventRec *func_0216282C(void *eventData, void *eventWork, VecFx32 *pos, int mode);
extern void func_02162A6C(const struct EventRec *event, VecFx32 *outPos);
extern void *func_02184E40(struct GameSystem *gameSystem, struct FieldMap *fieldMap, const VecFx32 *targetPos, u16 zoneId, const VecFx32 *pos);
extern void func_021BB578(void *fieldEffectCtrl, void *mmdl, int type, int sePlay);
extern void *func_02185050(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int zoneId, const VecFx32 *pos, u16 dir);
extern void *func_021850A8(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern void *func_021854B0(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 zoneId, const VecFx32 *pos, u16 dir);
extern void *func_02188C5C(struct FieldMap *fieldMap);
extern void func_021BB3E8(void *nogridMapper, u32 zoneId, u16 railIndex, u16 lineGrid, u16 widthPos, RailLocation *outLocation, u16 heapId);
extern void *func_02184D90(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int zoneId, const RailLocation *rail, u16 dir, int seasonFadeAllowed);
extern void *func_02184DE8(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int zoneId, const RailLocation *rail, u16 dir, int seasonFadeAllowed);

int func_021AF75C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF794(ScriptVm *vm, struct ScrcmdWork *cmdWork, WordSetRegisterFn registerFn);
int func_021AF7C4(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF7D4(ScriptVm *vm, struct ScrcmdWork *cmdWork);
void func_021AF7E4(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF844(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF878(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF8A8(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF8D8(ScriptVm *vm, struct ScrcmdWork *cmdWork, WordSetRegisterFn registerFn);
int func_021AF908(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF918(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF928(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF958(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF9A4(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AF9F0(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFA38(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFA80(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFAC8(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFAFC(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFB2C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFB5C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFB90(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFBC4(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFBEC(ScriptVm *vm, struct ScrcmdWork *cmdWork, WordSetRegisterFn registerFn);
int func_021AFC18(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFC28(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFC38(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFC88(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFCD8(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFD44(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFDAC(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFE64(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFECC(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFEFC(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021AFF7C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B0000(ScriptVm *vm, struct ScrcmdWork *cmdWork);

static inline u8 ScriptVm_ReadU8(ScriptVm *vm)
{
    u8 value = *vm->pc;

    vm->pc++;
    return value;
}

/* Script command: put the player name into a word set slot (slot byte). */
int func_021AF75C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    void *myStatus;
    struct WordSet *wordSet;

    func_02158F58(scriptWork);
    myStatus = func_02012944(func_0215A5E4(cmdWork));
    wordSet = func_02158F74(scriptWork);
    func_0201F02C(wordSet, ScriptVm_ReadU8(vm), myStatus);
    return 0;
}

/*
 * Shared body of the word set commands that take a slot byte and one script
 * value: reads the slot and the value and registers the value with registerFn.
 */
int func_021AF794(ScriptVm *vm, struct ScrcmdWork *cmdWork, WordSetRegisterFn registerFn)
{
    struct WordSet *wordSet = func_02158F74(func_0215A5F4(cmdWork));
    u32 slot = ScriptVm_ReadU8(vm);

    registerFn(wordSet, slot, func_02159B10(vm, cmdWork));
    return 0;
}

int func_021AF7C4(ScriptVm *vm, struct ScrcmdWork *cmdWork) { return func_021AF794(vm, cmdWork, func_0201EF40); }
int func_021AF7D4(ScriptVm *vm, struct ScrcmdWork *cmdWork) { return func_021AF794(vm, cmdWork, func_0201EF4C); }

/*
 * Script command: register an entry (slot byte, entry value, count value,
 * flag byte). A count above 1 selects the plural entry list; otherwise the
 * flag selects between the two singular lists.
 */
void func_021AF7E4(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = func_02158F74(func_0215A5F4(cmdWork));
    u32 slot = ScriptVm_ReadU8(vm);
    u32 entry;
    u32 count;
    u32 flag;

    entry = func_02159B10(vm, cmdWork);
    count = func_02159B10(vm, cmdWork);
    flag = ScriptVm_ReadU8(vm);
    if (count > 1) {
        func_0201EF5C(wordSet, slot, entry);
    } else if (flag != 0) {
        func_0201EF4C(wordSet, slot, entry);
    } else {
        func_0201EF40(wordSet, slot, entry);
    }
}

/* Script command: register the item name with the converted item value (slot byte, value). */
int func_021AF844(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = func_02158F74(func_0215A5F4(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    func_0201EF34(wordSet, slot, func_020212B0(func_02159B10(vm, cmdWork)));
    return 0;
}

int func_021AF878(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = func_02158F74(func_0215A5F4(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    func_0201EF34(wordSet, slot, func_02159B10(vm, cmdWork));
    return 0;
}

int func_021AF8A8(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = func_02158F74(func_0215A5F4(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    func_0201F020(wordSet, slot, func_02159B10(vm, cmdWork));
    return 0;
}

/* Shared body of the species name commands: slot byte, then one script value. */
int func_021AF8D8(ScriptVm *vm, struct ScrcmdWork *cmdWork, WordSetRegisterFn registerFn)
{
    struct WordSet *wordSet = func_02158F74(func_0215A5F4(cmdWork));
    u32 slot = ScriptVm_ReadU8(vm);

    registerFn(wordSet, slot, func_02159B10(vm, cmdWork));
    return 0;
}

int func_021AF908(ScriptVm *vm, struct ScrcmdWork *cmdWork) { return func_021AF8D8(vm, cmdWork, func_0201EE60); }
int func_021AF918(ScriptVm *vm, struct ScrcmdWork *cmdWork) { return func_021AF8D8(vm, cmdWork, func_0201EEC4); }

int func_021AF928(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = func_02158F74(func_0215A5F4(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    func_0201F14C(wordSet, slot, func_02159B10(vm, cmdWork));
    return 0;
}

/* Script command: register the species name of a party member (slot byte, party index value). */
int func_021AF958(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    void *gameData = func_0215A5E4(cmdWork);
    struct WordSet *wordSet = func_02158F74(scriptWork);
    u32 slot = ScriptVm_ReadU8(vm);
    u32 partyIndex;

    partyIndex = func_02159B10(vm, cmdWork);
    func_0201EE84(wordSet, slot, func_0201AB28(func_02012934(gameData), partyIndex));
    return 0;
}

/* Script command: register the nickname of a party member (slot byte, party index value). */
int func_021AF9A4(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    void *gameData = func_0215A5E4(cmdWork);
    struct WordSet *wordSet = func_02158F74(scriptWork);
    u32 slot = ScriptVm_ReadU8(vm);
    u32 partyIndex;

    partyIndex = func_02159B10(vm, cmdWork);
    func_0201EEF4(wordSet, slot, func_0201AB28(func_02012934(gameData), partyIndex));
    return 0;
}

/* Script command: register the species name of a daycare Pokemon (slot byte, daycare index value). */
int func_021AF9F0(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = func_02158F74(func_0215A5F4(cmdWork));
    u32 slot = ScriptVm_ReadU8(vm);
    u32 daycareIndex;

    daycareIndex = func_02159B10(vm, cmdWork);
    func_0201EE84(wordSet, slot, func_021C34F8(func_02188D50(func_0201210C(func_0215A5DC(cmdWork))), daycareIndex));
    return 0;
}

/* Script command: register the nickname of a daycare Pokemon (slot byte, daycare index value). */
int func_021AFA38(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = func_02158F74(func_0215A5F4(cmdWork));
    u32 slot = ScriptVm_ReadU8(vm);
    u32 daycareIndex;

    daycareIndex = func_02159B10(vm, cmdWork);
    func_0201EEF4(wordSet, slot, func_021C34F8(func_02188D50(func_0201210C(func_0215A5DC(cmdWork))), daycareIndex));
    return 0;
}

/* Script command: register a number (slot byte, number value, digit count value). */
int func_021AFA80(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = func_02158F74(func_0215A5F4(cmdWork));
    u32 slot = ScriptVm_ReadU8(vm);
    u32 number;
    u32 digitCount;

    number = func_02159B10(vm, cmdWork);
    digitCount = func_02159B10(vm, cmdWork);
    func_0201EFA4(wordSet, slot, number, digitCount, 0, 1);
    return 0;
}

/* Script command: register the place name of a zone (slot byte, zone value). */
int func_021AFAC8(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = func_02158F74(func_0215A5F4(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    func_0201F158(wordSet, slot, func_02013E4C(func_02159B10(vm, cmdWork)));
    return 0;
}

int func_021AFAFC(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = func_02158F74(func_0215A5F4(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    func_0201EFC8(wordSet, slot, func_02159B10(vm, cmdWork));
    return 0;
}

int func_021AFB2C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = func_02158F74(func_0215A5F4(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    func_0201F048(wordSet, slot, func_02159B10(vm, cmdWork));
    return 0;
}

int func_021AFB5C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = func_02158F74(func_0215A5F4(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    func_0201F198(wordSet, slot, (u8)func_02159B10(vm, cmdWork));
    return 0;
}

int func_021AFB90(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct WordSet *wordSet = func_02158F74(func_0215A5F4(cmdWork));
    u8 slot = ScriptVm_ReadU8(vm);

    func_0201F1B0(wordSet, slot, func_02159B10(vm, cmdWork));
    return 0;
}

/* The slot byte comes first, then the value; the word set is looked up last. */
int func_021AFBC4(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u8 slot = ScriptVm_ReadU8(vm);
    u32 value = func_02159B10(vm, cmdWork);

    func_0201F184(func_02158F74(func_0215A5F4(cmdWork)), slot, value);
    return 0;
}

/* Shared body of the byte-valued word set commands (slot byte, one script value truncated to a byte). */
int func_021AFBEC(ScriptVm *vm, struct ScrcmdWork *cmdWork, WordSetRegisterFn registerFn)
{
    int slot = ScriptVm_ReadU8(vm);
    int value;

    value = (int)func_02159B10(vm, cmdWork);
    registerFn(func_02158F74(func_0215A5F4(cmdWork)), slot, (u8)value);
    return 0;
}

int func_021AFC18(ScriptVm *vm, struct ScrcmdWork *cmdWork) { return func_021AFBEC(vm, cmdWork, func_0201F0F8); }
int func_021AFC28(ScriptVm *vm, struct ScrcmdWork *cmdWork) { return func_021AFBEC(vm, cmdWork, func_0201F124); }

/* Script command: register a counter of the save data as a 9-digit number (slot byte). */
int func_021AFC38(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    void *counters;
    struct WordSet *wordSet;
    int slot;

    counters = func_0200C0F0(func_02012EBC(func_0215A5E4(cmdWork)));
    wordSet = func_02158F74(scriptWork);
    slot = ScriptVm_ReadU8(vm);
    func_0201EFA4(wordSet, slot, func_0200C1DC(counters), 9, 1, 1);
    return 0;
}

/* Same as func_021AFC38 with the second counter. */
int func_021AFC88(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    void *counters;
    struct WordSet *wordSet;
    int slot;

    counters = func_0200C0F0(func_02012EBC(func_0215A5E4(cmdWork)));
    wordSet = func_02158F74(scriptWork);
    slot = ScriptVm_ReadU8(vm);
    func_0201EFA4(wordSet, slot, func_0200C1C4(counters), 9, 1, 1);
    return 0;
}

/*
 * Script command: warp to a map position (zone, x, z, direction values; the
 * height is 0). Positions are in 16.16 fixed point.
 */
int func_021AFCD8(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u16 zoneId;
    u16 x;
    u16 z;
    u16 dir;
    VecFx32 pos;
    void *event;

    gameSystem = func_02158F54(func_0215A5F4(cmdWork));
    fieldMap = func_0201210C(gameSystem);
    zoneId = func_02011330(vm);
    x = func_02011330(vm);
    z = func_02011330(vm);
    dir = func_02011330(vm);
    pos.x = x << 16;
    pos.y = 0;
    pos.z = z << 16;
    event = func_02012104(gameSystem);
    func_02012374(event, func_02184D38(gameSystem, fieldMap, zoneId, &pos, dir, 0));
    return 1;
}

/* Same arguments as func_021AFCD8, plain warp event. */
int func_021AFD44(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u16 zoneId;
    u16 x;
    u16 z;
    u16 dir;
    VecFx32 pos;
    void *event;

    gameSystem = func_02158F54(func_0215A5F4(cmdWork));
    fieldMap = func_0201210C(gameSystem);
    zoneId = func_02011330(vm);
    x = func_02011330(vm);
    z = func_02011330(vm);
    dir = func_02011330(vm);
    pos.x = x << 16;
    pos.y = 0;
    pos.z = z << 16;
    event = func_02012104(gameSystem);
    func_02012374(event, func_02185534(gameSystem, fieldMap, zoneId, &pos, dir));
    return 1;
}

/*
 * Script command: warp to a zone, arriving at the player's position event
 * (zone, x, z values). The position event is found from the player's
 * position; the player model is then handed to the effect controller.
 */
int func_021AFDAC(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u16 zoneId;
    u16 x;
    u16 z;
    void *gameData;
    void *eventData;
    void *eventWork;
    void *event;
    void *mmdl;
    struct EventRec *posEvent;
    VecFx32 targetPos;
    VecFx32 pos;
    VecFx32 playerPos;

    gameSystem = func_02158F54(func_0215A5F4(cmdWork));
    fieldMap = func_0201210C(gameSystem);
    zoneId = func_02011330(vm);
    x = func_02011330(vm);
    z = func_02011330(vm);
    gameData = func_020120F4(gameSystem);
    eventData = (void *)func_02012844(gameData);
    eventWork = func_0201296C(gameData);
    func_021A3038(func_02188CB4(fieldMap), &playerPos);
    posEvent = func_0216282C(eventData, eventWork, &playerPos, 9);
    if (posEvent != 0)
        func_02162A6C(posEvent, &targetPos);
    pos.x = x << 16;
    pos.y = 0;
    pos.z = z << 16;
    event = func_02012104(gameSystem);
    func_02012374(event, func_02184E40(gameSystem, fieldMap, &targetPos, zoneId, &pos));
    mmdl = func_021A3074(func_02188CB4(fieldMap));
    func_021BB578(func_02188CD0(fieldMap), mmdl, 0, 1);
    return 1;
}

/* Same arguments as func_021AFCD8, fixed exit type warp event. */
int func_021AFE64(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u16 zoneId;
    u16 x;
    u16 z;
    u16 dir;
    VecFx32 pos;
    void *event;

    gameSystem = func_02158F54(func_0215A5F4(cmdWork));
    fieldMap = func_0201210C(gameSystem);
    zoneId = func_02011330(vm);
    x = func_02011330(vm);
    z = func_02011330(vm);
    dir = func_02011330(vm);
    pos.x = x << 16;
    pos.y = 0;
    pos.z = z << 16;
    event = func_02012104(gameSystem);
    func_02012374(event, func_02185050(gameSystem, fieldMap, zoneId, &pos, dir));
    return 1;
}

/* Script command: start the fixed zone warp event (no script arguments). */
int func_021AFECC(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = func_02158F54(func_0215A5F4(cmdWork));
    struct FieldMap *fieldMap = func_0201210C(gameSystem);
    void *event = func_02012104(gameSystem);

    func_02012374(event, func_021850A8(gameSystem, fieldMap));
    return 1;
}

/*
 * Script command: warp to a map position with the default transition (zone,
 * x, y, z, direction values, all positions in 16.16 fixed point).
 */
int func_021AFEFC(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u16 zoneId;
    u16 x;
    u16 y;
    u16 z;
    u16 dir;
    VecFx32 pos;
    void *event;

    gameSystem = func_02158F54(func_0215A5F4(cmdWork));
    fieldMap = func_0201210C(gameSystem);
    zoneId = func_02011330(vm);
    x = func_02011330(vm);
    y = func_02011330(vm);
    z = func_02011330(vm);
    dir = func_02011330(vm);
    func_021A3074(func_02188CB4(fieldMap));
    pos.x = x << 16;
    pos.y = y << 16;
    pos.z = z << 16;
    event = func_02012104(gameSystem);
    func_02012374(event, func_021854B0(gameSystem, fieldMap, zoneId, &pos, dir));
    return 1;
}

/*
 * Script command: warp to a rail location (zone, rail index, line grid,
 * width grid, direction values). The zone's rail location is looked up
 * through the no-grid mapper first.
 */
int func_021AFF7C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u16 zoneId;
    u16 railIndex;
    u16 lineGrid;
    u16 widthGrid;
    u16 dir;
    void *event;
    RailLocation rail;

    gameSystem = func_02158F54(func_0215A5F4(cmdWork));
    fieldMap = func_0201210C(gameSystem);
    zoneId = func_02011330(vm);
    railIndex = func_02011330(vm);
    lineGrid = func_02011330(vm);
    widthGrid = func_02011330(vm);
    dir = func_02011330(vm);
    event = func_02012104(gameSystem);
    func_021BB3E8(func_02188C5C(fieldMap), zoneId, railIndex, lineGrid, widthGrid, &rail, 0x15);
    func_02012374(event, func_02184D90(gameSystem, fieldMap, zoneId, &rail, dir, 0));
    return 1;
}

/* Same arguments as func_021AFF7C, rail warp event with the transition. */
int func_021B0000(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u16 zoneId;
    u16 railIndex;
    u16 lineGrid;
    u16 widthGrid;
    u16 dir;
    void *event;
    RailLocation rail;

    gameSystem = func_02158F54(func_0215A5F4(cmdWork));
    fieldMap = func_0201210C(gameSystem);
    zoneId = func_02011330(vm);
    railIndex = func_02011330(vm);
    lineGrid = func_02011330(vm);
    widthGrid = func_02011330(vm);
    dir = func_02011330(vm);
    event = func_02012104(gameSystem);
    func_021BB3E8(func_02188C5C(fieldMap), zoneId, railIndex, lineGrid, widthGrid, &rail, 0x15);
    func_02012374(event, func_02184DE8(gameSystem, fieldMap, zoneId, &rail, dir, 0));
    return 1;
}
