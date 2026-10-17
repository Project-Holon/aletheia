/*
 * file:     field_gimmick_bridge.c
 * unit:     yes
 * function: FIELD_GIMMICK_BRIDGE_Init, FIELD_GIMMICK_BRIDGE_Exit, FIELD_GIMMICK_BRIDGE_Update, FIELD_GIMMICK_BRIDGE_ResetSave, FIELD_GIMMICK_BRIDGE_IsOnSwayTile
 * address:  0x021F36C0
 * region:   ov047
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
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetWork  0x0200B3A4  thumb
 *   FLDMMDL_SetDrawOffsetOutside 0x0216D8E0 thumb ov010
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   FIELD_GIMMICK_BRIDGE_IsOnSwayTile  0x021F381C  thumb  ov047
 *   GFL_USE_GetRandomBelow  0x02005728  thumb
 *   GF_STANDARD_Get_F684  0x0203F684  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _ll_mul        0x0209C054  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   gBridgeSwayAmplitudes     0x021F3840  data  ov047  a1
 *   MI_CpuFill8 0x02082BCC arm
 *   FIELD_PLAYER_GetNowAttribute  0x021A30C8  thumb  ov021
 *   MAP_ATTR_IsPresent  0x021AB100  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_IsNoDash  0x021AB44C  thumb  ov021
 */
#include "field_gimmick_bridge_types.h"

extern u8 gBridgeSwayAmplitudes[];

/* Sway amplitudes (in tiles) picked at random at the start of each cycle. */
#define BRIDGE_SWAY_AMPLITUDE_COUNT 4
/* Degrees added to the sway phase per frame. */
#define BRIDGE_SWAY_ANGLE_STEP 8

#define FX32_FROM_INT(x) ((fx32)(((x) > 0) ? ((x) * (1 << 12) + .5f) : ((x) * (1 << 12) - .5f)))

/* Gimmick start: allocates the sway work and stores the player and its model in it. */
void FIELD_GIMMICK_BRIDGE_Init(FieldMap *fieldMap)
{
    BridgeSwayWork *work;

    GIMMICK_WORK_GetWork(GAME_DATA_GetFieldSave(ICA_ANIME_GetField1C(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_ID_BRIDGE_SWAY);
    FIELDMAP_AllocCommonWork(fieldMap, BRIDGE_SWAY_WORK_ID, FIELDMAP_GetHeapId(fieldMap), sizeof(BridgeSwayWork));
    work = FIELDMAP_GetCommonWork(fieldMap, BRIDGE_SWAY_WORK_ID);
    work->player = FIELDMAP_GetFieldPlayer(fieldMap);
    work->playerMmdl = FIELD_PLAYER_GetMmdl(work->player);
    work->drawOffset.x = 0;
    work->drawOffset.y = 0;
    work->drawOffset.z = 0;
}

/* Gimmick end: applies the last draw offset to the player model and frees the sway work. */
void FIELD_GIMMICK_BRIDGE_Exit(FieldMap *fieldMap)
{
    BridgeSwayWork *work;

    GIMMICK_WORK_GetWork(GAME_DATA_GetFieldSave(ICA_ANIME_GetField1C(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_ID_BRIDGE_SWAY);
    work = FIELDMAP_GetCommonWork(fieldMap, BRIDGE_SWAY_WORK_ID);
    FLDMMDL_SetDrawOffsetOutside(work->playerMmdl, &work->drawOffset);
    FIELDMAP_FreeCommonWork(fieldMap, BRIDGE_SWAY_WORK_ID);
}

/* Per frame: while the player stands on a no-dash tile, bob the player model on a sine of the sway phase. */
void FIELD_GIMMICK_BRIDGE_Update(FieldMap *fieldMap)
{
    BridgeSwaySave *save;
    BridgeSwayWork *work;
    fx32 height;
    int amplitude;
    fx32 sine;

    save = GIMMICK_WORK_GetWork(GAME_DATA_GetFieldSave(ICA_ANIME_GetField1C(FIELDMAP_GetGameSystem(fieldMap))), FIELD_GIMMICK_ID_BRIDGE_SWAY);
    work = FIELDMAP_GetCommonWork(fieldMap, BRIDGE_SWAY_WORK_ID);
    if (FIELD_GIMMICK_BRIDGE_IsOnSwayTile(work) == 0) {
        work->drawOffset.y = 0;
        save->angle = 0;
        FLDMMDL_SetDrawOffsetOutside(work->playerMmdl, &work->drawOffset);
        return;
    }
    if (save->angle == 0) {
        save->amplitude = gBridgeSwayAmplitudes[GFL_USE_GetRandomBelow(BRIDGE_SWAY_AMPLITUDE_COUNT)];
    }
    amplitude = save->amplitude;
    height = FX32_FROM_INT(amplitude);
    sine = GF_STANDARD_Get_F684((u16)save->angle);
    work->drawOffset.y = (fx32)(((s64)sine * height + 0x800) >> 12);
    FLDMMDL_SetDrawOffsetOutside(work->playerMmdl, &work->drawOffset);
    save->angle = (save->angle + BRIDGE_SWAY_ANGLE_STEP) % 360;
}

/* Gimmick save reset: clears the sway state. */
void FIELD_GIMMICK_BRIDGE_ResetSave(struct GameSystem *gameSystem)
{
    MI_CpuFill8(GIMMICK_WORK_GetWork(GAME_DATA_GetFieldSave(ICA_ANIME_GetField1C(gameSystem)), FIELD_GIMMICK_ID_BRIDGE_SWAY), 0, sizeof(BridgeSwaySave));
}

/* The player stands on a tile whose terrain is the no-dash terrain (checked through the attribute predicates). */
int FIELD_GIMMICK_BRIDGE_IsOnSwayTile(BridgeSwayWork *work)
{
    u32 attr = FIELD_PLAYER_GetNowAttribute(work->player);

    if (MAP_ATTR_IsPresent(attr) == 0) {
        return 0;
    }
    return MAP_ATTR_IsNoDash(MAP_ATTR_GetTerrainId(attr));
}
