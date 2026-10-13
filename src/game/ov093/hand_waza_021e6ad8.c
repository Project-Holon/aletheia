/*
 * file:     hand_waza_021e6ad8.c
 * unit:     yes
 * function: HAND_WAZA_MetronomeSetFailMessage, HAND_WAZA_AddNaturePower, HAND_WAZA_NaturePowerPickMove, HAND_WAZA_NaturePowerSetFailMessage, HAND_WAZA_AddAssist, HAND_WAZA_AssistPickMove, HAND_WAZA_AddSleepTalk, HAND_WAZA_SleepTalkPickMove
 * address:  0x021E6AD8
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
 *   func_0689CA3C  0x0689CA3C  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_GetFieldSituationType   0x021C8174  thumb
 *   BTL_SERVER_FLOW_DecideMoveTarget   0x021C8030  thumb
 *   gNaturePowerHandlers     0x021F2928  data   ov093  a4
 *   BTL_SERVER_FLOW_GetPartyOfPoke 0x021C7FCC thumb ov093
 *   BTL_SERVER_FLOW_GetScratchBuffer 0x021C8120 thumb ov093
 *   BTL_SLOT_GetCount 0x021B9B94 thumb ov093
 *   BTL_SLOT_GetPokeParam 0x021B9C00 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   gAssistHandlers     0x021F270C  data   ov093  a4
 *   func_0689CA1C  0x0689CA1C  thumb
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   gSleepTalkHandlers     0x021F2BB8  data   ov093  a4
 */
#include "hand_waza_021e62f4_types.h"

struct HandWazaMessage;
struct BtlPartyView;
struct BtlPokeParam;

extern int BTL_EVENT_GetVar(int key);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *message, int type, int messageId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct HandWazaMessage *message, u32 arg);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int BTL_SERVER_FLOW_GetFieldSituationType(int *flow);
extern int BTL_SERVER_FLOW_DecideMoveTarget(int flow, int pokeId, int moveId);
extern char *BTL_SERVER_FLOW_GetPartyOfPoke(u8 *flow, int pokeId);
extern u8 *BTL_SERVER_FLOW_GetScratchBuffer(u8 *flow, int size);
extern u8 BTL_SLOT_GetCount(struct BtlPartyView *party);
extern u8 *BTL_SLOT_GetPokeParam(struct BtlPartyView *party, u32 index);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *bpp);
extern u8 BTL_POKEPARAM_GetMoveCount(struct BtlPokeParam *bpp);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *bpp, int slot);
extern int func_0689CA3C(u16 moveId);
extern u32 BTL_CALC_Random(u32 range);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *flow, int pokeId);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *bpp, int sickId);
extern int func_0689CA1C(int moveId);
extern int WAZA_TOOL_GetFlag(int moveId, int flag);
extern int gNaturePowerHandlers[];
extern int gAssistHandlers[];
extern int gSleepTalkHandlers[];

/* Metronome: print the message that the move cannot be called, and fail it. */
void HAND_WAZA_MetronomeSetFailMessage(int factor, int flow, int pokeId)
{
    void *message;
    u16 moveId;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        message = (void *)BTL_EVENT_GetVar(WAZAVAR_FAIL_MESSAGE);
        moveId = BTL_EVENT_GetVar(WAZAVAR_MOVE_ID);
        BTL_SERVER_FLOW_InitMsgRecord(message, 1, 0x78);
        BTL_SERVER_FLOW_AppendMsgRecordArg(message, moveId);
        BTL_EVENT_OverwriteVar(WAZAVAR_SKIP_FLAG, 1);
    }
}

/* Nature Power: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddNaturePower(int *handlerCount)
{
    *handlerCount = 2;
    return gNaturePowerHandlers;
}

/*
 * Nature Power: pick the move to call from the terrain of the battle field.
 *
 * 16-case jump table on BTL_SERVER_FLOW_GetFieldSituationType(flow), gated on pokeId == BTL_EVENT_GetVar(2);
 * every value 0..15 is covered by eight bodies sitting at 6B66, 6B6A, 6B6E,
 * 6B72, 6B76, 6B7A, 6B7E, 6B82 -- that is the order they are written in
 * below.  Each body picks a move id (0x192 and 0x1aa come out of the pool
 * because they do not fit a movs); the id goes to BTL_SERVER_FLOW_DecideMoveTarget and to
 * BTL_EVENT_OverwriteVar(0x12,...), and BTL_SERVER_FLOW_DecideMoveTarget's result to BTL_EVENT_OverwriteVar(0xd,...).
 *
 * The `default:` label belongs on the case 4/14 group, not on a block of its
 * own: the `bhi` out-of-range arm of the table jumps to 6B6A, which is that
 * group's body, and the out-of-range arm being a real body is also what puts
 * the switch's temporary in r5 and the parameter flow in r4 (mwcc allocates r4 to
 * the first web the dispatch block defines).  `default:` as a separate group
 * costs 40 bytes of diff; without it at all the `bhi` lands on the shared tail.
 */
void HAND_WAZA_NaturePowerPickMove(int factor, int flow, int pokeId)
{
    int moveId;
    int slot;

    if (BTL_EVENT_GetVar(WAZAVAR_POKE_ID) != pokeId)
        return;
    switch (BTL_SERVER_FLOW_GetFieldSituationType((int *)flow)) {
    case 1: case 2: case 3: case 8: case 15:
        moveId = 0x59;
        break;
    case 4: case 14: default:
        moveId = 0xa1;
        break;
    case 10:
        moveId = 0x9d;
        break;
    case 0: case 5:
        moveId = 0x192;
        break;
    case 6: case 11: case 12:
        moveId = 0x38;
        break;
    case 9:
        moveId = 0x1aa;
        break;
    case 7:
        moveId = 0x3b;
        break;
    case 13:
        moveId = 0x3a;
        break;
    }
    slot = BTL_SERVER_FLOW_DecideMoveTarget(flow, pokeId, moveId);
    BTL_EVENT_OverwriteVar(WAZAVAR_MOVE_ID, moveId);
    BTL_EVENT_OverwriteVar(WAZAVAR_MOVE_SLOT, slot);
}

/* Nature Power: print the message that the move cannot be called, and fail it. */
void HAND_WAZA_NaturePowerSetFailMessage(int factor, int flow, int pokeId)
{
    void *message;
    u16 moveId;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        message = (void *)BTL_EVENT_GetVar(WAZAVAR_FAIL_MESSAGE);
        moveId = BTL_EVENT_GetVar(WAZAVAR_MOVE_ID);
        BTL_SERVER_FLOW_InitMsgRecord(message, 1, 0x79);
        BTL_SERVER_FLOW_AppendMsgRecordArg(message, moveId);
        BTL_EVENT_OverwriteVar(WAZAVAR_SKIP_FLAG, 1);
    }
}

/* Assist: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddAssist(int *handlerCount)
{
    *handlerCount = 1;
    return gAssistHandlers;
}

/*
 * Assist: collect the callable moves of the other party members and use one
 * of them at random.
 *
 * lever: Both loop bounds and their accessor returns are u8; u32 n loses
 * its pre-loop reload, and u32 count schedules its reload before i's spill.
 */
void HAND_WAZA_AssistPickMove(void *factor, void *flow, int pokeId)
{
    void *party;
    u16 *moves;
    u8 partyCount;
    u8 memberIndex;
    u8 moveCount;
    u8 candidateCount, slot;
    void *member;
    u16 moveId;
    u8 pick;
    int moveSlot;
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        party = BTL_SERVER_FLOW_GetPartyOfPoke(flow, pokeId);
        moves = (u16 *)BTL_SERVER_FLOW_GetScratchBuffer(flow, 48);
        candidateCount = 0;
        partyCount = BTL_SLOT_GetCount(party);
        for (memberIndex = 0; memberIndex < partyCount; memberIndex++) {
            member = BTL_SLOT_GetPokeParam(party, memberIndex);
            if (pokeId != BTL_POKEPARAM_GetPokeId(member)) {
                moveCount = BTL_POKEPARAM_GetMoveCount(member);
                for (slot = 0; slot < moveCount; slot++) {
                    moveId = BTL_POKEPARAM_GetMoveId(member, slot);
                    if (func_0689CA3C(moveId) == 0) {
                        moves[candidateCount++] = moveId;
                    }
                }
            }
        }
        if (candidateCount != 0) {
            pick = BTL_CALC_Random(candidateCount);
            moveSlot = BTL_SERVER_FLOW_DecideMoveTarget((int)flow, pokeId, moves[pick]);
            BTL_EVENT_OverwriteVar(18, moves[pick]);
            BTL_EVENT_OverwriteVar(13, moveSlot);
        }
    }
}

/* Sleep Talk: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddSleepTalk(int *handlerCount)
{
    *handlerCount = 3;
    return gSleepTalkHandlers;
}

/* Sleep Talk: while asleep, pick one of the user's other moves at random. */
void HAND_WAZA_SleepTalkPickMove(int factor, int flow, int pokeId, u32 *candidates)
{
    void *user;
    u8 moveCount;
    u8 candidateCount;
    u8 slot;
    int candidate;
    int sickSleep = 2;
    u16 moveId;
    int moveSlot;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        user = BTL_SERVER_FLOW_GetPokeParam((int *)flow, pokeId);
        if (BTL_POKEPARAM_HasSick(user, sickSleep) != 0) {
            moveCount = BTL_POKEPARAM_GetMoveCount(user);
            slot = 0;
            candidateCount = 0;
            for (; slot < moveCount; slot++) {
                candidate = BTL_POKEPARAM_GetMoveId(user, slot);
                if (func_0689CA1C(candidate) == 0 && WAZA_TOOL_GetFlag(candidate, 1) == 0) {
                    candidates[candidateCount++] = candidate;
                }
            }
            if (candidateCount != 0) {
                moveId = candidates[(u8)BTL_CALC_Random(candidateCount)];
                moveSlot = BTL_SERVER_FLOW_DecideMoveTarget((int)flow, pokeId, moveId);
                BTL_EVENT_OverwriteVar(0x12, moveId);
                BTL_EVENT_OverwriteVar(0xd, moveSlot);
            } else {
                BTL_EVENT_OverwriteVar(WAZAVAR_FAIL_FLAG, 1);
            }
        }
    }
}
