/*
 * function: GIMMICK38_EventScripted
 * address:  0x021F44C0
 * packet:   pkt_ov038_021F44C0
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: The handed extent includes rodata after 0x021F45E8.
 *         0200B3A4 receives the visibly loaded second argument 6.
 *         Enum id plus u16 extern arguments preserves the observed #16
 *         truncations at 021F4594/459A and 021F45C4/45CA; u16 local alone
 *         folds them away. Matched callee's wide id receives the same bits.
 * symbols:
 *   func_020124E4 0x020124E4 thumb
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   FLD_EXP_OBJ_SetAnimeEnabled 0x021BE700 thumb ov021
 *   FLD_EXP_OBJ_GetAnime 0x021BE674 thumb ov021
 *   FLD_EXP_OBJ_SetAnimePaused 0x021BE6B0 thumb ov021
 *   FLD_EXP_OBJ_SetAnimeFrame 0x021BE6CC thumb ov021
 *   FLD_EXP_OBJ_GetModelStatus 0x021BE480 thumb ov021
 *   FLD_EXP_OBJ_IsAnimeStopped 0x021BE6BC thumb ov021
 *   SCRIPT_SYS_CallScriptEvent 0x02158780 thumb ov010
 *   SCRIPT_SYS_ChangeScriptEvent 0x021587B0 thumb ov010
 *   gGimmick38EffectPos 0x021F465C data a4
 */
#include "../unit_021F36C0_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
/* The enum type keeps the narrowing of the script event ids, see the note above. */
typedef enum { SCRIPT_EVENT_ID_ZERO } ScriptEventId;
struct GameSystem;
struct GameData;
struct GimmickWork;
struct GameEvent;
extern void *func_020124E4(struct GameEvent *event);
extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
extern int FIELDMAP_GetExpObj(int *fieldMap);
extern struct Gimmick38Runtime *FIELDMAP_GetCommonWork(char *fieldMap, int idx);
extern void *FIELDMAP_GetGameSystem(void *fieldMap);
extern void *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct GimmickWork *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern void *GIMMICK_WORK_GetSaveArea(struct GimmickWork *gimmickSave, u32 gimmickId);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *expObj, int unitIdx, int modelIdx, int animeIdx, int enable);
extern void *FLD_EXP_OBJ_GetAnime(char *expObj, int unitIdx, unsigned int modelIdx, u16 animeIdx);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *anime, int paused);
extern void FLD_EXP_OBJ_SetAnimeFrame(int expObj, int unitIdx, int modelIdx, u16 animeIdx, int frame);
extern VecFx32 *FLD_EXP_OBJ_GetModelStatus(void *expObj, int unitIdx, u16 modelIdx);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *anime);
extern int SCRIPT_SYS_CallScriptEvent(void *gameSystem, u16 scriptId, int arg1, int arg2, u16 flags);
extern int SCRIPT_SYS_ChangeScriptEvent(int gameSystem, int scriptId, int arg1, int flags);
extern const VecFx32 gGimmick38EffectPos[];

/*
 * Event: shows the effect model at the position of the variant, calls the
 * first script event, waits for the effect animation and calls the second.
 */
int GIMMICK38_EventScripted(void *event, int *state)
{
    void *fieldMap;
    void *expObj;
    Gimmick38Runtime *runtime;
    u8 *anime;
    int i;
    ScriptEventId scriptId;

    fieldMap = (void *)GAMESYSTEM_GetFieldMap(func_020124E4(event));
    expObj = (void *)FIELDMAP_GetExpObj(fieldMap);
    runtime = FIELDMAP_GetCommonWork(fieldMap, 1);
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave((struct GameData *)GAMESYSTEM_GetGameData((void *)FIELDMAP_GetGameSystem(fieldMap))), 6);
    switch (*state) {
    case 0:
        for (i = 0; i < 2; i++) {
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0x20, (u16)i, 1);
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, 0x20, i), 0);
            FLD_EXP_OBJ_SetAnimeFrame((int)expObj, 0, 0x20, i, 0);
        }
        *FLD_EXP_OBJ_GetModelStatus(expObj, 0, 0x20) = gGimmick38EffectPos[runtime->scriptVariant];
        *state = *state + 1;
        break;
    case 1:
        scriptId = 4;
        if (runtime->scriptVariant == 0)
            scriptId = 3;
        SCRIPT_SYS_CallScriptEvent(event, (u16)scriptId, 0, 0, 0x8015);
        *state = *state + 1;
        break;
    case 2:
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, 0x20, 0))) {
            scriptId = 6;
            if (runtime->scriptVariant == 0)
                scriptId = 5;
            SCRIPT_SYS_ChangeScriptEvent((int)event, (u16)scriptId, 0, 0x8015);
            *state = *state + 1;
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}
