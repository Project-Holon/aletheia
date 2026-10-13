/*
 * function: GIMMICK40_EventPlayAnime
 * address:  0x021F381C
 * packet:   pkt_ov040_021F381C
 * region:   ov040
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 */
#include "../unit_021F36C0_types.h"

/* Gimmick event: play the animation of the model, then record that it was played. */
int GIMMICK40_EventPlayAnime(struct GameEvent *event, int *seq, void *work)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    Gimmick40Work *gimmickWork;
    Gimmick40Save *save;
    FldExpObjAnime *anime;
    u8 modelIndex;

    fieldMap = GAMESYSTEM_GetFieldMap(func_020124E4(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    gimmickWork = FIELDMAP_GetCommonWork(fieldMap, 1);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), 3);
    switch (*seq) {
    case 0:
        modelIndex = gimmickWork->modelIndex;
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, modelIndex, 0, 1);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, modelIndex, 0), 0);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, modelIndex, 0, 0);
        (*seq)++;
        break;
    case 1:
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, (u8)gimmickWork->modelIndex, 0);
        if (FLD_EXP_OBJ_IsAnimeStopped(anime) && FLD_EXP_OBJ_IsAnimeStopped(anime)) {
            save->animeDone[gimmickWork->modelIndex] = 1;
            return 1;
        }
        break;
    }
    return 0;
}
