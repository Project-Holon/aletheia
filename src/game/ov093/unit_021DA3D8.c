/*
 * file:     unit_021DA3D8.c
 * unit:     yes
 * function: func_021DA3D8, func_021DA528, func_021DA5BC, func_021DA618
 * address:  0x021DA3D8
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
 *   d_021F09A0     0x021F09A0  data   ov093  a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7D54 0x021C7D54 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021C8120 0x021C8120 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021C88B4 0x021C88B4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 *   WAZA_TOOL_GetPower 0x0201C1D8 thumb
 *   WAZA_TOOL_GetCategory 0x0201C1BC thumb
 *   d_021F0980 0x021F0980 data a4
 *   func_021D57FC   0x021D57FC  thumb ov093
 *   WAZA_TOOL_GetCategory    0x0201C1BC  thumb
 *   WAZA_TOOL_IsDamaging   0x0201C314  thumb
 *   WAZA_TOOL_GetType    0x0201C1C8  thumb
 *   func_021D799C   0x021D799C  thumb ov093
 */
#include "unit_021D9ADC_types.h"

/* Move ids Forewarn rates as counter moves. */
#define MOVE_COUNTER 68
#define MOVE_MIRROR_COAT 243
#define MOVE_METAL_BURST 368
#define MOVE_CATEGORY_OHKO 9
/* Type affinity value of a hit that is neither resisted nor super effective. */
#define AFFINITY_NORMAL 3

/* One candidate move Forewarn may reveal: the foe that owns it and the move. */
typedef struct { u8 pokeId, pad; u16 moveId; } ForewarnCandidate;

extern int func_021D775C(int varId);
extern u8 func_021C7D54(struct BtlServerFlow *flow, int pokeId, u8 *outFoeIds);
extern struct BtlPokeParam *func_021C7CF4(struct BtlServerFlow *flow, int pokeId);
extern u8 *func_021C8120(struct BtlServerFlow *flow, int size);
extern u8 func_021D5448(struct BtlPokeParam *pokeParam);
extern u8 func_021D5440(struct BtlPokeParam *pokeParam);
extern u16 func_021D54C0(struct BtlPokeParam *pokeParam, int moveIndex);
extern int WAZA_TOOL_GetDamageType(int moveId);
extern u16 WAZA_TOOL_GetPower(u16 moveId);
extern u32 WAZA_TOOL_GetCategory(u16 moveId);
extern u32 func_021D78AC(u32 range);
extern void func_021C88B4(struct BtlServerFlow *flow, int kind, int pokeId);
extern void *func_021C88A4(struct BtlServerFlow *flow, int kind, int pokeId);
extern void func_021C8838(struct HandExMessage *message, int kind, int messageId);
extern void func_021C8860(struct HandExMessage *message, u32 arg);
extern void func_021C88C8(struct BtlServerFlow *flow, void *record);
extern u16 func_021D57FC(struct BtlPokeParam *pokeParam);
extern u32 WAZA_TOOL_IsDamaging(u16 moveId);
extern u8 WAZA_TOOL_GetType(u16 moveId);
extern int func_021D799C(int attackType, int defenderTypes);
void func_021DA3D8(int myHandle, struct BtlServerFlow *flow, int pokeId);
int *func_021DA51C(int *handlerCount);
void func_021DA528(int myHandle, struct BtlServerFlow *flow, int pokeId);
int func_021DA5BC(struct BtlPokeParam *myPoke, struct BtlPokeParam *foe);
extern int d_021F0980;

/* Forewarn's rating of a move: its power, or a fixed rating for variable-power moves. */
static inline u32 getMoveThreat(u16 moveId)
{
    u32 value;
    if (WAZA_TOOL_GetDamageType(moveId)) {
        value = (u8)WAZA_TOOL_GetPower(moveId);
        if (value == 1) {
            if (WAZA_TOOL_GetCategory(moveId) == MOVE_CATEGORY_OHKO) value = 150;
            else if (moveId == MOVE_COUNTER || moveId == MOVE_MIRROR_COAT || moveId == MOVE_METAL_BURST) value = 120;
            else value = 80;
        }
    } else {
        value = 1;
    }
    return value;
}

/* Forewarn: on entering the field, reveal the strongest move among the foes
   (ties are chosen at random). */
void func_021DA3D8(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    u8 foeIds[4];
    struct BtlPokeParam *foe;
    ForewarnCandidate *candidates;
    u8 foeCount, moveCount, i;
    u16 moveId;
    u8 candidateCount, j, choice;
    u32 bestThreat, threat;
    struct HandExMessageRecord *record;
    if (pokeId != func_021D775C(HANDVAR_POKE_ID)) return;
    foeCount = func_021C7D54(flow, pokeId, foeIds);
    bestThreat = 0;
    candidateCount = 0;
    candidates = (ForewarnCandidate *)func_021C8120(flow, 12);
    for (i = 0; i < foeCount; i++) {
        foe = func_021C7CF4(flow, foeIds[i]);
        moveCount = func_021D5448(foe);
        for (j = 0; j < moveCount; j++) {
            moveId = func_021D54C0(foe, j);
            threat = getMoveThreat(moveId);
            if (threat >= bestThreat) {
                if (threat > bestThreat) { bestThreat = threat; candidateCount = 0; }
                candidates[candidateCount].pokeId = func_021D5440(foe);
                candidates[candidateCount].moveId = moveId;
                candidateCount++;
            }
        }
    }
    if (candidateCount == 0) return;
    choice = func_021D78AC(candidateCount);
    func_021C88B4(flow, HANDEX_ABILITY_WINDOW_IN, pokeId);
    record = func_021C88A4(flow, HANDEX_KIND_MESSAGE, pokeId);
    func_021C8838(&record->message, HANDEX_MESSAGE_SET, 0x1b1);
    func_021C8860(&record->message, candidates[choice].pokeId);
    func_021C8860(&record->message, candidates[choice].moveId);
    func_021C88C8(flow, record);
    func_021C88B4(flow, HANDEX_ABILITY_WINDOW_OUT, pokeId);
}

int *func_021DA51C(int *handlerCount) { *handlerCount = 2; return &d_021F0980; }


/* Anticipation: on entering the field, announce it if a foe has a move that is
   super effective against this Pokemon or is a one-hit KO. */
void func_021DA528(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    u8 foeIds[4];
    u8 foeCount;
    u8 i;
    struct BtlPokeParam *myPoke;
    struct HandExMessageRecord *record;

    if (pokeId != func_021D775C(HANDVAR_POKE_ID))
        return;
    foeCount = func_021C7D54(flow, pokeId, foeIds);
    myPoke = func_021C7CF4(flow, pokeId);
    for (i = 0; i < foeCount; i++) {
        if (func_021DA5BC(myPoke, func_021C7CF4(flow, foeIds[i])) != 0)
            break;
    }
    if (i == foeCount)
        return;
    func_021C88B4(flow, HANDEX_ABILITY_WINDOW_IN, pokeId);
    record = func_021C88A4(flow, HANDEX_KIND_MESSAGE, pokeId);
    func_021C8838(&record->message, HANDEX_MESSAGE_SET, 0x1b4);
    func_021C8860(&record->message, pokeId);
    func_021C88C8(flow, record);
    func_021C88B4(flow, HANDEX_ABILITY_WINDOW_OUT, pokeId);
}


/* Whether the foe has a one-hit KO move or a damaging move super effective against myPoke. */
int func_021DA5BC(struct BtlPokeParam *myPoke, struct BtlPokeParam *foe)
{
    u16 myTypes;
    u8 moveCount;
    u8 i;
    u16 moveId;

    myTypes = func_021D57FC(myPoke);
    moveCount = func_021D5448(foe);
    for (i = 0; i < moveCount; i++) {
        moveId = func_021D54C0(foe, i);
        if (WAZA_TOOL_GetCategory(moveId) == MOVE_CATEGORY_OHKO)
            return 1;
        if (WAZA_TOOL_IsDamaging(moveId) != 0) {
            if (func_021D799C(WAZA_TOOL_GetType(moveId), myTypes) > AFFINITY_NORMAL)
                return 1;
        }
    }
    return 0;
}


extern int d_021F09A0[];

int *func_021DA618(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F09A0;
}
