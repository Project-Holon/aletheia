/*
 * file:     field_gimmick.c
 * unit:     yes
 * function: FIELD_GIMMICK_Setup, FIELD_GIMMICK_Exit, FIELD_GIMMICK_RunMapCallback, FIELD_GIMMICK_IsGimmickId
 * address:  0x021BE1DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from entrance_camera.c and fld_exp_obj.c at 0x021BE1DC (lane FXC, CL117c and CL124: the field gimmick overlay load and unload and the gimmick dispatch helpers; no __FILE__ anchor).
 * Split from field_place_name.c at 0x021BDC94 (lane SP3, __FILE__ anchors, certain cut).
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetId  0x0200B3AC  thumb
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   gFieldGimmickOverlayIds     0x021D9D98  data  a4
 *   gFieldGimmickInitFuncs     0x021D9CBC  data  a4
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   gFieldGimmickExitFuncs     0x021D9BE0  data  ov021  a4
 *   gFieldGimmickCallbackTbl  0x021D9E74  data
 */

#include "../types.h"

struct FieldMap;
struct GameSystem;
struct GameData;
struct GimmickWork;

#include "fieldmap.h"
#include "../arm9/gamesystem.h"
#include "../arm9/game_data.h"
#include "../arm9/gimmick.h"
#include "../arm9/gf_overlay.h"

void FIELD_GIMMICK_Setup(FieldMap *fieldMap);
void FIELD_GIMMICK_Exit(FieldMap *fieldMap);
void FIELD_GIMMICK_RunMapCallback(struct FieldMap *fieldMap);
int FIELD_GIMMICK_IsGimmickId(struct FieldMap *fieldMap, int gimmickId);

/* Overlay id of each gimmick (0 = none), and the per gimmick init, exit and run callbacks. */
extern void *gFieldGimmickOverlayIds[];
extern void (*gFieldGimmickCallbackTbl[])(struct FieldMap *fieldMap);
extern void (*gFieldGimmickInitFuncs[])(FieldMap *);

/* Field gimmick setup: loads the gimmick overlay of the save and calls its init. */
void FIELD_GIMMICK_Setup(FieldMap *fieldMap)
{
    int gimmickId;

    gimmickId = GIMMICK_WORK_GetId((struct GimmickWork *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))));
    if (gimmickId != -1) {
        if (gFieldGimmickOverlayIds[gimmickId] != 0) {
            GF_OVERLAY_Load((sptr)gFieldGimmickOverlayIds[gimmickId]);
        }
        gFieldGimmickInitFuncs[gimmickId](fieldMap);
    }
}

extern void (*gFieldGimmickExitFuncs[])(FieldMap *);

/* Field gimmick exit: calls the gimmick exit and unloads its overlay. */
void FIELD_GIMMICK_Exit(FieldMap *fieldMap)
{
    int gimmickId;

    gimmickId = GIMMICK_WORK_GetId((struct GimmickWork *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))));
    if (gimmickId != -1) {
        if (gFieldGimmickExitFuncs[gimmickId] != 0) {
            gFieldGimmickExitFuncs[gimmickId](fieldMap);
        }
        if (gFieldGimmickOverlayIds[gimmickId] != 0) {
            GF_OVERLAY_Unload((sptr)gFieldGimmickOverlayIds[gimmickId]);
        }
    }
}

/*
 * Runs the callback of the field gimmick that is active on the map.
 */
void FIELD_GIMMICK_RunMapCallback(struct FieldMap *fieldMap)
{
    int gimmickId;

    gimmickId = GIMMICK_WORK_GetId((struct GimmickWork *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))));
    if (gimmickId != -1 && gFieldGimmickCallbackTbl[gimmickId] != 0)
        gFieldGimmickCallbackTbl[gimmickId](fieldMap);
}

int FIELD_GIMMICK_IsGimmickId(struct FieldMap *fieldMap, int gimmickId)
{
    if (gimmickId == GIMMICK_WORK_GetId((struct GimmickWork *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))))) {
        return 1;
    }
    return 0;
}
