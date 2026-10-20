/*
 * file:     scrcmd_bridge_gimmick.c
 * unit:     yes
 * function: SCRCMD_GIMMICK_BRIDGE_ResetSave
 * address:  0x02164778
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from field_skill_check.c, calender.c, game_beacon_search.c, game_beacon_accessor.c by tools/splitfile.py.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   FIELD_GIMMICK_BRIDGE_ResetSave 0x021F3800 thumb ov047
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   ov_id_47 0x0000002F data
 */
#include "field_skill_check_shared_types.h"
#include "scrcmd_bridge_gimmick_shared_types.h"

/* Overlay ids are linker symbols whose address is the id. */
#define OVERLAY_ID_47 ((sptr)ov_id_47)

#include "scrcmd_work.h"

#include "../arm9/gf_overlay.h"

#include "../ov047/field_gimmick_bridge.h"


extern u8 ov_id_47[];

int SCRCMD_GIMMICK_BRIDGE_ResetSave(struct ScriptVm *vm, struct ScrcmdWork *work);

/* Script command: loads overlay 47 and runs its entry on the game system. */
int SCRCMD_GIMMICK_BRIDGE_ResetSave(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(work);

    GF_OVERLAY_Load(OVERLAY_ID_47);
    FIELD_GIMMICK_BRIDGE_ResetSave(gameSystem);
    GF_OVERLAY_Unload(OVERLAY_ID_47);
    return 0;
}
