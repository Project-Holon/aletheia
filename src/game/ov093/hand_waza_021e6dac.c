/*
 * file:     hand_waza_021e6dac.c
 * unit:     yes
 * function: HAND_WAZA_MirrorMovePickMove, HAND_WAZA_AddMeFirst, HAND_WAZA_MeFirstPickMove
 * address:  0x021E6DAC
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
 *   func_0689C8BC  0x0689C8BC  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke  0x021C7D00  thumb  ov093
 *   BTL_SERVER_FLOW_GetRule  0x021C815C  thumb  ov093
 *   BTL_MAIN_GetEnemyLanePos  0x021B8C20  thumb  ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds  0x021C7F68  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetLastUsedMoveId  0x021D67A8  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_POKEPARAM_TestTurnFlag 0x021D5BB0 thumb ov093
 *   BTL_SERVER_FLOW_GetActionWordByPokeId 0x021C804C thumb ov093
 *   BTL_SERVER_FLOW_IsPokeInPosTable 0x021C814C thumb ov093
 *   BTL_SERVER_FLOW_IsPokeAfflictedByStatus 0x021C8374 thumb ov093
 *   BTL_ACTION_GetFightMove 0x021D8340 thumb ov093
 *   WAZA_TOOL_IsDamaging 0x0201C314 thumb
 *   gMeFirstHandlers     0x021F2968  data    a4
 */
#include "hand_waza_021e62f4_types.h"

struct BtlPokeParam;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(u8 *flow, int pokeId);
extern int BTL_SERVER_FLOW_GetRule(int *flow);
extern u8 BTL_MAIN_GetEnemyLanePos(int mode, u32 flags, u32 value);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(int *flow, int slot, u8 *outPokeId);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *flow, int pokeId);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct BtlPokeParam *bpp);
extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 flag);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int BTL_POKEPARAM_TestTurnFlag(struct BtlPokeParam *bpp, u32 flag);
extern int BTL_SERVER_FLOW_GetActionWordByPokeId(void *flow, u8 pokeId, u32 *outAction);
extern int BTL_SERVER_FLOW_IsPokeInPosTable(u8 *flow, u8 pokeId);
extern int BTL_SERVER_FLOW_IsPokeAfflictedByStatus(u8 *flow, int pokeId);
extern u32 BTL_ACTION_GetFightMove(u32 *action);
extern u32 WAZA_TOOL_IsDamaging(void *moveId);
extern int func_0689C8BC(u32 moveId);
extern int gMeFirstHandlers[];

#define BTL_TARGET_SLOT_NONE 6
#define BTL_WAZA_FLAG_MIRRORABLE 6
#define BTL_TURN_FLAG_ACTED 3

/* Mirror Move: use the move that the target used last, if it can be mirrored. */
void HAND_WAZA_MirrorMovePickMove(int factor, int flow, int pokeId, u8 *targetPokeId)
{
    u8 targetSlot;
    u16 lastMove;
    u32 targetFlags;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        targetSlot = BTL_EVENT_GetVar(WAZAVAR_TARGET_SLOT);
        if (targetSlot == BTL_TARGET_SLOT_NONE) {
            targetFlags = BTL_SERVER_FLOW_GetFrontPosOfPoke((u8 *)flow, pokeId);
            targetSlot = BTL_MAIN_GetEnemyLanePos(BTL_SERVER_FLOW_GetRule((int *)flow), targetFlags, 0);
        }
        if (BTL_SERVER_FLOW_CollectAlivePokeIds((int *)flow, targetSlot, targetPokeId) != 0) {
            lastMove = BTL_POKEPARAM_GetLastUsedMoveId(BTL_SERVER_FLOW_GetPokeParam((int *)flow, *targetPokeId));
            if (lastMove == 0 || WAZA_TOOL_GetFlag(lastMove, BTL_WAZA_FLAG_MIRRORABLE) == 0) {
                BTL_EVENT_OverwriteVar(WAZAVAR_FAIL_FLAG, 1);
                return;
            }
            BTL_EVENT_OverwriteVar(WAZAVAR_MOVE_ID, lastMove);
            BTL_EVENT_OverwriteVar(WAZAVAR_MOVE_SLOT, targetSlot);
        }
    }
}

/* Me First: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddMeFirst(int *handlerCount)
{
    *handlerCount = 2;
    return gMeFirstHandlers;
}

/*
 * Me First: use the damaging move that the target chose for this turn, if
 * the target has not acted yet.
 *
 * extent: 202 bytes of code followed by 2-byte alignment nop at 021E6F02,
 * then the labelled Thumb veneer func_0689C8BC.
 */
void HAND_WAZA_MeFirstPickMove(void *factor, void *flow, int pokeId, u8 *targetPokeId)
{
    u8 targetSlot;
    u8 targetId;
    u32 targetFlags;
    u32 action;
    u32 moveId;
    int usable;
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        targetSlot = BTL_EVENT_GetVar(WAZAVAR_TARGET_SLOT);
        if (targetSlot == BTL_TARGET_SLOT_NONE) {
            targetFlags = BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, pokeId);
            targetSlot = BTL_MAIN_GetEnemyLanePos(BTL_SERVER_FLOW_GetRule(flow), targetFlags, 0);
        }
        if (BTL_SERVER_FLOW_CollectAlivePokeIds(flow, targetSlot, targetPokeId) != 0) {
            void *target;
            target = BTL_SERVER_FLOW_GetPokeParam(flow, *targetPokeId);
            targetId = *targetPokeId;
            usable = 0;
            if (BTL_POKEPARAM_TestTurnFlag(target, BTL_TURN_FLAG_ACTED) == 0) {
                if (BTL_SERVER_FLOW_GetActionWordByPokeId(flow, targetId, &action) != 0) {
                    if (BTL_SERVER_FLOW_IsPokeInPosTable(flow, targetId) != 0) {
                        if (BTL_SERVER_FLOW_IsPokeAfflictedByStatus(flow, targetId) == 0) {
                            moveId = BTL_ACTION_GetFightMove(&action);
                            if (moveId != 0 && WAZA_TOOL_IsDamaging((void *)moveId) != 0 && func_0689C8BC(moveId) == 0)
                                usable = 1;
                        }
                    }
                }
            }
            if (usable != 0) {
                BTL_EVENT_OverwriteVar(18, moveId);
                BTL_EVENT_OverwriteVar(13, targetSlot);
                return;
            }
        }
        BTL_EVENT_OverwriteVar(65, 1);
    }
}
