/*
 * file:     hand_waza_021e69e8.c
 * unit:     yes
 * function: HAND_WAZA_FocusPunchTense, HAND_WAZA_AddMetronome, HAND_WAZA_MetronomePickMove
 * address:  0x021E69E8
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
 *   func_0689CA8C  0x0689CA8C  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_IsSemiInvulnerable  0x021D5C30  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_CALC_PickRandomMoveExcluding  0x021D7E44  thumb  ov093
 *   BTL_SERVER_FLOW_DecideMoveTarget  0x021C8030  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gMetronomeWazaHandlers     0x021F28F8  data    a4
 */
#include "hand_waza_021e62f4_types.h"

struct BtlPokeParam;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *flow, void *record);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *flow, int pokeId);
extern int BTL_POKEPARAM_IsSemiInvulnerable(struct BtlPokeParam *bpp);
extern int BTL_SERVER_FLOW_GetPokeViewPos(u8 *flow, unsigned int pokeId);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *message, int type, int messageId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct HandWazaMessage *message, u32 arg);
extern int func_0689CA8C(u32 *out);
extern u16 BTL_CALC_PickRandomMoveExcluding(int a, int b);
extern int BTL_SERVER_FLOW_DecideMoveTarget(int flow, int pokeId, int moveId);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int gMetronomeWazaHandlers[];

#define BTL_VISIBILITY_FOCUS 5
#define BTL_ANIM_FOCUS_PUNCH_TENSE 0x272
#define BTL_ANIM_MODE_PLAY 6

/* Focus Punch: at the start of the turn, show the tensing animation and message. */
void HAND_WAZA_FocusPunchTense(int factor, void *flow, int pokeId)
{
    struct HandWazaStateRecord *state;
    struct HandWazaAnimRecord *anim;
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        state = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_VISIBILITY, pokeId);
        state->pokeId = pokeId;
        state->state = BTL_VISIBILITY_FOCUS;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, state);
        if (BTL_POKEPARAM_IsSemiInvulnerable(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) == 0) {
            anim = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_ANIMATION, pokeId);
            anim->animId = BTL_ANIM_FOCUS_PUNCH_TENSE;
            anim->target = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
            anim->mode = BTL_ANIM_MODE_PLAY;
            anim->flag = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, anim);
        }
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x268);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    }
}

/* Metronome: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddMetronome(int *handlerCount)
{
    *handlerCount = 2;
    return gMetronomeWazaHandlers;
}

/* Metronome: pick a random move other than the previous one and use it. */
void HAND_WAZA_MetronomePickMove(int factor, int flow, int pokeId)
{
    u32 previousMove;
    int moveId;
    int slot;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        moveId = BTL_CALC_PickRandomMoveExcluding(func_0689CA8C(&previousMove), (u16)previousMove);
        slot = BTL_SERVER_FLOW_DecideMoveTarget(flow, pokeId, moveId);
        BTL_EVENT_OverwriteVar(WAZAVAR_MOVE_ID, moveId);
        BTL_EVENT_OverwriteVar(WAZAVAR_MOVE_SLOT, slot);
    }
}
