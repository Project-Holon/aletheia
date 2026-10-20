/*
 * file:     field_gimmick_62.c
 * unit:     yes
 * function: FIELD_GIMMICK_62_Init, FIELD_GIMMICK_62_Exit, FIELD_GIMMICK_62_Update
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
 *   GIMMICK_WORK_GetWork  0x0200B3A4  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   gFieldGimmick62UnitSetup     0x021F3768  data  a4
 *   gFieldGimmick62ModelPos     0x021F3790  data  a4
 *   FLD_EXP_OBJ_RemoveUnit  0x021BE418  thumb  ov021
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 */
#include "field_gimmick_62_types.h"

struct GameSystem;
struct GameData;
struct GimmickWork;
struct FieldMap;

#include "../ov021/fieldmap.h"
#include "../arm9/gamesystem.h"
#include "../arm9/game_data.h"
#include "../arm9/gimmick.h"
#include "../ov021/fld_exp_obj.h"
struct FldExpObjCnt;
void FIELD_GIMMICK_62_Init(void *fieldMap);
void FIELD_GIMMICK_62_Exit(void *fieldMap);
extern const struct G3dUtilSetup gFieldGimmick62UnitSetup;
extern VecFx32 gFieldGimmick62ModelPos;
struct FldExpObjCnt;

void FIELD_GIMMICK_62_Init(void *fieldMap)
{
    s32 *hideFlag;
    struct FldExpObjCnt *expObj;

    hideFlag = GIMMICK_WORK_GetWork((struct GimmickWork *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_62_WORK_SLOT);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, &gFieldGimmick62UnitSetup, 0);
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, 0)->trans = gFieldGimmick62ModelPos;
    FLD_EXP_OBJ_SetModelCullDraw(expObj, 0, 0, 1);
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, 0, 0, 1);
    if (*hideFlag != 0)
        FLD_EXP_OBJ_SetModelHidden(expObj, 0, 0, 1);
}

void FIELD_GIMMICK_62_Exit(void *fieldMap)
{
    FLD_EXP_OBJ_RemoveUnit(FIELDMAP_GetExpObj(fieldMap), 0);
}

/* Per-frame update: advances the model animes. */
void FIELD_GIMMICK_62_Update(void *fieldMap)
{
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
}
