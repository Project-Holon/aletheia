/*
 * function: GIMMICK44_SnapLiftToBottom
 * address:  0x021F3970
 * packet:   pkt_ov044_021F3970
 * region:   ov044
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
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

/* Puts the lift at its lower end without the ride: the model and the player
 * are set to the bottom height and the camera is detached. */
void GIMMICK44_SnapLiftToBottom(void *gameSystem)
{
    void *fieldMap;
    void *expObj;
    Gimmick44Work *work;
    u8 *camera;
    void *player;
    VecFx32 pos;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    camera = FIELDMAP_GetCamera(fieldMap);
    work->savedCameraTarget = FIELD_CAMERA_GetTraceTarget(camera);
    FIELD_CAMERA_StopTargetTrace(camera);
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, 0)->y = -0x50000;
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    FIELD_PLAYER_GetPos(player, &pos);
    pos.y = -0x50000;
    FIELD_PLAYER_SetPos(player, &pos);
}
