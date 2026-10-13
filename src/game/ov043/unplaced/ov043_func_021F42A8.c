/*
 * function: GIMMICK43_SnapElevatorToTop
 * address:  0x021F42A8
 * packet:   pkt_021F42A8
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb
 */
#include "../unit_021F36C0_types.h"

extern void *GAMESYSTEM_GetFieldMap(void *gameSystem);
extern void *FIELDMAP_GetExpObj(void *fieldMap);
extern void *FIELDMAP_GetCommonWork(char *fieldMap, int id);
extern void *FIELDMAP_GetCamera(void *fieldMap);
extern u32 FIELD_CAMERA_GetTraceTarget(u8 *camera);
extern void FIELD_CAMERA_StopTargetTrace(u8 *camera);
extern VecFx32 *FLD_EXP_OBJ_GetModelStatus(void *expObj, unsigned unit, int model);
extern void *FIELDMAP_GetFieldPlayer(void *fieldMap);
extern void FIELD_PLAYER_GetPos(unsigned char *player, VecFx32 *out);
extern void FIELD_PLAYER_SetPos(u8 *player, VecFx32 *pos);

/* Puts the elevator at its upper end without the ride: the model and the
 * player are set to the top height and the camera is detached. */
void GIMMICK43_SnapElevatorToTop(void *gameSystem)
{
    void *fieldMap;
    void *expObj;
    Gimmick43Work *work;
    u8 *camera;
    void *player;
    VecFx32 pos;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    camera = FIELDMAP_GetCamera(fieldMap);
    work->savedCameraTarget = FIELD_CAMERA_GetTraceTarget(camera);
    FIELD_CAMERA_StopTargetTrace(camera);
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, 7)->y = 0x370000;
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    FIELD_PLAYER_GetPos(player, &pos);
    pos.y = 0x370000;
    FIELD_PLAYER_SetPos(player, &pos);
}
