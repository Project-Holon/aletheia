/*
 * function: GIMMICK65_WaitEffectEventMain
 * address:  0x021F38D0
 * packet:   pkt_021F38D0
 * region:   ov065
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching the leaf at 0x021897BC in ov021 (region hint added
 * to the symbols line); the bl at +0x0E now resolves via `matched`.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb
 */

#include "../unit_021F36C0_types.h"

extern void *func_020124E4(void *event);
extern void *GAMESYSTEM_GetFieldMap(void *gameSystem);
extern Gimmick65Work *FIELDMAP_GetCommonWork(void *fieldMap, int id);

int GIMMICK65_WaitEffectEventMain(void *event)
{
    void *fieldMap;
    int isDone;
    fieldMap = GAMESYSTEM_GetFieldMap(func_020124E4(event));
    isDone = 1;
    if (FIELDMAP_GetCommonWork(fieldMap, 1)->isPlaying != 0)
        isDone = 0;
    return isDone;
}
