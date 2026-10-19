/*
 * file:     scrcmd_event_mon.c
 * unit:     yes
 * function: SCRCMD_EVENT_MON_CmdStartSpPokeGimmickTask, SCRCMD_EVENT_MON_CmdMoveSpPokeGimmick, SCRCMD_EVENT_MON_CmdStartSpPokeGimmickStepA, SCRCMD_EVENT_MON_CmdStartSpPokeGimmickStepB, SCRCMD_EVENT_MON_CmdFindEventMonInParty, SCRCMD_EVENT_MON_FindEventMonInParty, SCRCMD_EVENT_MON_CmdClearEventMonFlag
 * address:  0x0216BBD4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from unit_0216B24C.c by tools/splitfile.py.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   SP_POKE_GIMMICK_StartMove  0x021F39B8  thumb  ov059
 *   SP_POKE_GIMMICK_ShowAndPlay  0x021F3AA0  thumb  ov059
 *   SP_POKE_GIMMICK_StartWaitAnimeEnd 0x021F3B68 thumb ov059
 *   SP_POKE_GIMMICK_StartWaitAnimeProgress 0x021F3B40 thumb ov059
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   SAVE_EVENT_IsStageDone  0x0202F488  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   SAVE_EVENT_CommitStage  0x0202F630  thumb
 */
#include "field_intrude_event_shared_types.h"
#include "scrcmd_research_shared_types.h"

extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);

extern void *FIELDMAP_GetFieldPlayer(void *fieldMap);

extern void *SCRCMD_WORK_GetScriptWork(struct ScrCmdWork *work);

extern void *SCRCMD_WORK_GetGameData(struct ScrCmdWork *work);

extern u16 *SCRIPT_WORK_ReadWorkPointer(struct ScriptContext *ctx, struct ScrCmdWork *work);

extern unsigned int SCRIPT_WORK_ReadWorkValue(struct ScriptContext *ctx, struct ScrCmdWork *work);

extern void *SCRCMD_WORK_GetGameSystem(struct ScrCmdWork *work);

extern int SCRIPT_SYS_CallEvent(void *scriptSystem, void *event);

extern void FIELD_PLAYER_GetPos(void *player, FxVec3 *out);

extern void *SP_POKE_GIMMICK_StartMove(void *gameSystem, int fromPlayer, FxVec3 *from, FxVec3 *to, int height, int frames);

extern void SP_POKE_GIMMICK_ShowAndPlay(void *gameSystem, int mode, FxVec3 *position);

extern void *SP_POKE_GIMMICK_StartWaitAnimeEnd(void *gameSystem, u32 value);

extern void *SP_POKE_GIMMICK_StartWaitAnimeProgress(void *gameSystem, u32 value);

extern void *GAME_DATA_GetMyParty(const struct GameData *gameData);

extern u32 POKEPARTY_GetCount(void *party);

extern void *POKEPARTY_GetMember(void *party, u32 index);

extern int SAVE_EVENT_IsStageDone(void *mon, int kind);

extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 paramId, u32 arg);

extern void SAVE_EVENT_CommitStage(void *mon, u32 kind);

int SCRCMD_EVENT_MON_FindEventMonInParty(void *party, int species, int move, int kind, u16 *outIndex);

/* Script command: starts a special Pokemon gimmick task between the player and a grid position. */
int SCRCMD_EVENT_MON_CmdStartSpPokeGimmickTask(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *scriptSystem;
    void *gameSystem;
    void *fieldMap;
    int fromPlayer;
    int gridX;
    int height;
    int gridZ;
    int speed;
    int frames;
    FxVec3 playerPos;
    FxVec3 targetPos;
    FxVec3 *from;
    FxVec3 *to;
    void *gimmickTask;

    scriptSystem = SCRCMD_WORK_GetScriptWork(scrWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(scrWork);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    fromPlayer = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    gridX = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    height = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    gridZ = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    speed = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    frames = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos);
    targetPos.x = (gridX << 16) + 0x8000;
    targetPos.y = height << 15;
    targetPos.z = (gridZ << 16) + 0x8000;
    if (fromPlayer == 0) {
        from = &playerPos;
        to = &targetPos;
    } else {
        from = &targetPos;
        to = &playerPos;
    }
    gimmickTask = SP_POKE_GIMMICK_StartMove(gameSystem, fromPlayer, from, to, speed << 15, frames);
    if (gimmickTask == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptSystem, gimmickTask);
    return 1;
}

/* Script command: moves the special Pokemon gimmick to a grid position. */
int SCRCMD_EVENT_MON_CmdMoveSpPokeGimmick(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *gameSystem;
    int mode;
    int gridX;
    int height;
    int gridZ;
    FxVec3 position;

    gameSystem = SCRCMD_WORK_GetGameSystem(scrWork);
    mode = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    gridX = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    height = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    gridZ = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    position.x = (gridX << 16) + 0x8000;
    position.y = height << 15;
    position.z = (gridZ << 16) + 0x8000;
    SP_POKE_GIMMICK_ShowAndPlay(gameSystem, mode, &position);
    return 0;
}

/* Script command: starts the first special Pokemon gimmick step task and waits on it. */
int SCRCMD_EVENT_MON_CmdStartSpPokeGimmickStepA(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *scriptSystem, *gameSystem, *task;
    scriptSystem = SCRCMD_WORK_GetScriptWork(scrWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(scrWork);
    task = SP_POKE_GIMMICK_StartWaitAnimeEnd(gameSystem, SCRIPT_WORK_ReadWorkValue(ctx, scrWork));
    if (task == 0) return 1;
    SCRIPT_SYS_CallEvent(scriptSystem, task);
    return 1;
}

/* Script command: starts the second special Pokemon gimmick step task and waits on it. */
int SCRCMD_EVENT_MON_CmdStartSpPokeGimmickStepB(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *scriptSystem, *gameSystem, *task;
    scriptSystem = SCRCMD_WORK_GetScriptWork(scrWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(scrWork);
    task = SP_POKE_GIMMICK_StartWaitAnimeProgress(gameSystem, SCRIPT_WORK_ReadWorkValue(ctx, scrWork));
    if (task == 0) return 1;
    SCRIPT_SYS_CallEvent(scriptSystem, task);
    return 1;
}

/*
 * Script command: reads a species, a signature-move flag and two result
 * variables, maps the event species (243-245, 251, 492, 647-649) to a flag
 * kind and, for 647/648, a signature move (548/547, dropped when the flag
 * is 0), and stores SCRCMD_EVENT_MON_FindEventMonInParty's answer in the second variable; any other
 * species stores 0.
 */
int SCRCMD_EVENT_MON_CmdFindEventMonInParty(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *party = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(scrWork));
    int species = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    unsigned int useSignatureMove = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    u16 *outIndex = SCRIPT_WORK_ReadWorkPointer(ctx, scrWork);
    u16 *outFound = SCRIPT_WORK_ReadWorkPointer(ctx, scrWork);
    int kind;
    int move;

    switch (species) {
    case 647:
        kind = 4;
        move = 548;
        break;
    case 648:
        kind = 5;
        move = 547;
        break;
    case 251:
        kind = 0;
        move = 0;
        break;
    case 243:
    case 244:
    case 245:
        kind = 2;
        move = 0;
        break;
    case 649:
        kind = 6;
        move = 0;
        break;
    case 492:
        kind = 7;
        move = 0;
        break;
    default:
        *outFound = 0;
        return 0;
    }
    if (useSignatureMove == 0) {
        move = 0;
    }
    *outFound = SCRCMD_EVENT_MON_FindEventMonInParty(party, species, move, kind, outIndex);
    return 0;
}

/* Finds the first party member of the species that has the event flag and does not know the move. */
int SCRCMD_EVENT_MON_FindEventMonInParty(void *party, int species, int move, int kind, u16 *outIndex)
{
    int found;
    int count;
    int i;
    void *mon;

    count = POKEPARTY_GetCount(party);
    found = 0;
    *outIndex = 0;
    for (i = 0; i < count; i++) {
        mon = POKEPARTY_GetMember(party, i);
        if (SAVE_EVENT_IsStageDone(mon, kind) == 0) {
            continue;
        }
        if (species != POKE_TOOL_GetPartyValue(mon, 5, 0)) {
            continue;
        }
        if (move != 0) {
            if (move == POKE_TOOL_GetPartyValue(mon, 0x36, 0)
                || move == POKE_TOOL_GetPartyValue(mon, 0x37, 0)
                || move == POKE_TOOL_GetPartyValue(mon, 0x38, 0)
                || move == POKE_TOOL_GetPartyValue(mon, 0x39, 0)) {
                continue;
            }
        }
        found = 1;
        *outIndex = i;
        break;
    }
    return found;
}

/* Script command: clears the event flag of the party member at an index when its species has one. */
int SCRCMD_EVENT_MON_CmdClearEventMonFlag(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *party;
    int species;
    int partyIndex;
    int kind;
    void *mon;

    party = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(scrWork));
    species = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    partyIndex = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    switch (species) {
    case 0xFB:
        kind = 0;
        break;
    case 0xF3:
    case 0xF4:
    case 0xF5:
        kind = 2;
        break;
    case 0xF6:
    case 0xF7:
    case 0xF8:
    case 0xF9:
    case 0xFA:
    default:
        return 0;
    }
    mon = POKEPARTY_GetMember(party, partyIndex);
    if (SAVE_EVENT_IsStageDone(mon, kind) == 0) {
        return 0;
    }
    SAVE_EVENT_CommitStage(mon, kind);
    return 0;
}
