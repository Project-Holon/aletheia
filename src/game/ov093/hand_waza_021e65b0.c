/*
 * file:     hand_waza_021e65b0.c
 * unit:     yes
 * function: HAND_WAZA_PluckEatTargetBerry, HAND_WAZA_StruggleSetSkipFlag, HAND_WAZA_StruggleShowNoMovesMessage, HAND_WAZA_StruggleSetFlag4B, HAND_WAZA_AddDestinyBond, HAND_WAZA_DestinyBondOnUse, HAND_WAZA_RemoveOnUserAction, HAND_WAZA_DestinyBondOnFaint, HAND_WAZA_AddGrudge, HAND_WAZA_GrudgeOnUse, HAND_WAZA_GrudgeOnFaint, HAND_WAZA_AddMinimize, HAND_WAZA_MinimizeSetState, HAND_WAZA_AddDefenseCurl, HAND_WAZA_DefenseCurlSetState, HAND_WAZA_AddRoost
 * address:  0x021E65B0
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
 *   func_0689C8CC  0x0689C8CC  thumb  ov095
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   ITEM_IsBerry  0x020213C0  thumb
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   gStruggleHandlers     0x021F2B28  data   ov093  a4
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb
 *   BTL_EVENT_RemoveFactor   0x021D7040  thumb
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   BTL_EVENT_MarkFactorDead  0x021D7090  thumb  ov093
 *   gDestinyBondHandlers     0x021F2B40  data   ov093  a4
 *   BTL_POKEPARAM_FindMoveSlot 0x021D5778 thumb ov093
 *   BTL_POKEPARAM_GetMovePPChecked 0x021D5584 thumb ov093
 *   gGrudgeHandlers     0x021F2B58  data   ov093  a4
 *   gMinimizeHandlers     0x021F276C  data   ov093  a4
 *   gDefenseCurlHandlers     0x021F2754  data   ov093  a4
 *   gRoostHandlers     0x021F255C  data   ov093  a4
 */
#include "hand_waza_021e62f4_types.h"

struct BtlPokeParam;
struct BtlEventNode;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *flow, int pokeId);
extern u16 BTL_POKEPARAM_GetItem(struct BtlPokeParam *bpp);
extern int ITEM_IsBerry(u32 itemId);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *flow, void *record);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *message, int type, int messageId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct HandWazaMessage *message, u32 arg);
extern void BTL_EVENT_RemoveFactor(struct BtlEventNode *factor);
extern int BTL_POKEPARAM_IsFainted(void *bpp);
extern int func_0689C8CC();
extern int BTL_MAIN_IsPokeSamePair(u32 attackerId, u32 defenderId);
extern void BTL_EVENT_MarkFactorDead(u8 *factor);
extern u8 BTL_POKEPARAM_FindMoveSlot(struct BtlPokeParam *bpp, u16 moveId);
extern u8 BTL_POKEPARAM_GetMovePPChecked(struct BtlPokeParam *bpp, u32 slot);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int gStruggleHandlers[];
extern int gDestinyBondHandlers[];
extern int gGrudgeHandlers[];
extern int gMinimizeHandlers[];
extern int gDefenseCurlHandlers[];
extern int gRoostHandlers[];

#define BTL_MOVE_SLOT_NONE 4

/* Pluck and Bug Bite: eat the target berry and apply its effect to the user. */
void HAND_WAZA_PluckEatTargetBerry(int factor, void *flow, u32 pokeId)
{
    struct HandWazaConsumeItemRecord *consume;
    struct HandWazaItemEffectRecord *effect;
    u8 targetId;
    u16 itemId;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(WAZAVAR_ITEM_SLOT);
        itemId = (int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, targetId));
        if (ITEM_IsBerry(itemId) != 0) {
            consume = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_CONSUME_ITEM, pokeId);
            consume->pokeId = targetId;
            consume->flags = 0;
            BTL_SERVER_FLOW_InitMsgRecord(&consume->message, 2, 0x308);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&consume->message, pokeId);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&consume->message, itemId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, consume);
            effect = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_ITEM_EFFECT, pokeId);
            effect->header |= 2 << 23;
            effect->itemId = itemId;
            effect->pokeId = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, effect);
        }
    }
}

/* Struggle: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddStruggle(int *handlerCount)
{
    *handlerCount = 3;
    return gStruggleHandlers;
}

/* Struggle: set the skip flag (guess: the move never needs PP checking). */
void HAND_WAZA_StruggleSetSkipFlag(int factor, int flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(WAZAVAR_SKIP_FLAG, 1);
}

/* Struggle: print the message that the Pokemon has no moves left. */
void HAND_WAZA_StruggleShowNoMovesMessage(int factor, void *flow, int pokeId)
{
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x344);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    }
}

/* Struggle: set event flag 0x4b (guess: the move skips the usual accuracy or type checks). */
void HAND_WAZA_StruggleSetFlag4B(int factor, int flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(0x4b, 1);
}

/* Destiny Bond: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddDestinyBond(int *handlerCount)
{
    *handlerCount = 3;
    return gDestinyBondHandlers;
}

/* Destiny Bond: when used, print the message and arm the effect in the work area. */
void HAND_WAZA_DestinyBondOnUse(int factor, void *flow, u32 pokeId, u32 *work)
{
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x272);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
        work[6] = 1;
    }
}

/* Destiny Bond and Grudge: the effect ends when the user acts again. */
void HAND_WAZA_RemoveOnUserAction(struct BtlEventNode *factor, int flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID))
        BTL_EVENT_RemoveFactor(factor);
}

/* Destiny Bond: when the user faints from an attack, the attacker faints too. */
void HAND_WAZA_DestinyBondOnFaint(int factor, void *flow, u32 pokeId)
{
    struct HandWazaKillRecord *kill;
    void *attacker;
    u8 attackerId;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_DEFENDER_ID)) {
        if (BTL_POKEPARAM_IsFainted(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) != 0) {
            if (func_0689C8CC((u16)BTL_EVENT_GetVar(WAZAVAR_MOVE_ID)) == 0) {
                attackerId = BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID);
                attacker = BTL_SERVER_FLOW_GetPokeParam(flow, attackerId);
                if (BTL_MAIN_IsPokeSamePair(pokeId, attackerId) == 0 && BTL_POKEPARAM_IsFainted(attacker) == 0) {
                    BTL_EVENT_MarkFactorDead((u8 *)factor);
                    kill = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_KILL, pokeId);
                    kill->pokeId = pokeId;
                    kill->flag = 1;
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, kill);
                    kill = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_KILL, pokeId);
                    kill->pokeId = BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID);
                    BTL_SERVER_FLOW_InitMsgRecord(&kill->message, 2, 0x275);
                    BTL_SERVER_FLOW_AppendMsgRecordArg(&kill->message, pokeId);
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, kill);
                }
            }
            BTL_EVENT_RemoveFactor((struct BtlEventNode *)factor);
        }
    }
}

/* Grudge: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddGrudge(int *handlerCount)
{
    *handlerCount = 3;
    return gGrudgeHandlers;
}

/* Grudge: when used, print the message and arm the effect in the work area. */
void HAND_WAZA_GrudgeOnUse(int factor, void *flow, u32 pokeId, u32 *work)
{
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x278);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
        work[6] = 1;
    }
}

/*
 * Grudge: when the user faints from an attack, the PP of the move that
 * finished it drops to zero.
 *
 * lever: Callback kind 10 is reused as the multiplier, then decreased by 11;
 * this retains the live constant and reproduces the spill frame and muls.
 */
void HAND_WAZA_GrudgeOnFaint(void *factor, void *flow, int pokeId)
{
    u8 attackerId;
    void *attacker;
    u16 moveId;
    int slot;
    struct HandWazaPpRecord *pp;
    int multiplier;
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_DEFENDER_ID)) {
        if (func_0689C8CC((u16)BTL_EVENT_GetVar(18)) == 0) {
            if (BTL_POKEPARAM_IsFainted(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) != 0) {
                attackerId = BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID);
                attacker = BTL_SERVER_FLOW_GetPokeParam(flow, attackerId);
                moveId = BTL_EVENT_GetVar(20);
                slot = BTL_POKEPARAM_FindMoveSlot(attacker, moveId);
                if (slot != BTL_MOVE_SLOT_NONE) {
                    multiplier = 10;
                    pp = BTL_SERVER_FLOW_AllocCmdRecord(flow, multiplier, pokeId);
                    pp->pokeId = attackerId;
                    pp->slot = slot;
                    multiplier -= 11;
                    pp->amount = BTL_POKEPARAM_GetMovePPChecked(attacker, (u8)slot) * multiplier;
                    pp->flags |= 2;
                    BTL_SERVER_FLOW_InitMsgRecord(&pp->message, 2, 0x27b);
                    BTL_SERVER_FLOW_AppendMsgRecordArg(&pp->message, attackerId);
                    BTL_SERVER_FLOW_AppendMsgRecordArg(&pp->message, moveId);
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, pp);
                }
                BTL_EVENT_RemoveFactor(factor);
            }
        }
    }
}

/* Minimize: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddMinimize(int *handlerCount)
{
    *handlerCount = 1;
    return gMinimizeHandlers;
}

/* Minimize: mark the user as minimized. */
void HAND_WAZA_MinimizeSetState(int factor, void *flow, int pokeId)
{
    struct HandWazaStateRecord *state;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        state = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_SET_STATE, pokeId);
        state->pokeId = pokeId;
        state->state = 8;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, state);
    }
}

/* Defense Curl: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddDefenseCurl(int *handlerCount)
{
    *handlerCount = 1;
    return gDefenseCurlHandlers;
}

/* Defense Curl: mark the user as curled up. */
void HAND_WAZA_DefenseCurlSetState(int factor, void *flow, int pokeId)
{
    struct HandWazaStateRecord *state;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        state = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_SET_STATE, pokeId);
        state->pokeId = pokeId;
        state->state = 7;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, state);
    }
}

/* Roost: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddRoost(int *handlerCount)
{
    *handlerCount = 1;
    return gRoostHandlers;
}
