/*
 * file:     field_gimmick_62.c
 * unit:     yes
 * function: func_021F36C0, GIMMICK62_Exit, GIMMICK62_Update
 * address:  0x021F36C0
 * region:   ov062
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   d_021F3768     0x021F3768  data  a4
 *   d_021F3790     0x021F3790  data  a4
 *   FLD_EXP_OBJ_RemoveUnit  0x021BE418  thumb  ov021
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 */
#include "field_gimmick_62_types.h"

struct GameSystem;
struct GameData;
struct GimmickWork;

extern struct GameSystem *FIELDMAP_GetGameSystem(void *fieldMap);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct GimmickWork *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern s32 *GIMMICK_WORK_GetSaveArea(struct GimmickWork *gimmickWork, u32 slot);
extern void *FIELDMAP_GetExpObj(void *fieldMap);
extern void FLD_EXP_OBJ_AddUnitFromArchive(void *expObj, void *unitDesc, int b);
extern VecFx32 *FLD_EXP_OBJ_GetModelStatus(void *expObj, unsigned unit, int model);
extern void FLD_EXP_OBJ_SetModelCullDraw(void *expObj, int unit, int model, int visible);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *expObj, int unit, int model, int animeIdx, int enabled);
extern void FLD_EXP_OBJ_SetModelHidden(void *expObj, int unit, int model, int hidden);
extern void FLD_EXP_OBJ_RemoveUnit(void *expObj, unsigned short unit);
void func_021F36C0(void *fieldMap);
void GIMMICK62_Exit(void *fieldMap);
extern VecFx32 d_021F3768;
extern VecFx32 d_021F3790;
extern void FLD_EXP_OBJ_UpdateAnimes(void *expObj);

void func_021F36C0(void *fieldMap)
{
    s32 *hideFlag;
    void *expObj;

    hideFlag = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK62_WORK_SLOT);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, &d_021F3768, 0);
    *FLD_EXP_OBJ_GetModelStatus(expObj, 0, 0) = d_021F3790;
    FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, 0, 1);
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0, 0, 1);
    if (*hideFlag != 0)
        FLD_EXP_OBJ_SetModelHidden(expObj, 0, 0, 1);
}

void GIMMICK62_Exit(void *fieldMap)
{
    FLD_EXP_OBJ_RemoveUnit(FIELDMAP_GetExpObj(fieldMap), 0);
}

/* Per-frame update: advances the model animes. */
void GIMMICK62_Update(void *fieldMap)
{
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
}
