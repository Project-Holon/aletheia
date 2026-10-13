/*
 * function: GIMMICK64_IsArcAnimeStopped
 * address:  0x021F3BD8
 * packet:   pkt_ov064_021F3BD8
 * region:   ov064
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
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 */

#include "../unit_021F36C0_types.h"

extern void *func_020124E4(void *event);
extern void *GAMESYSTEM_GetFieldMap(void *gameSystem);
extern void *FIELDMAP_GetExpObj(void *fieldMap);
extern void *FLD_EXP_OBJ_GetAnime(void *expObj, int unit, unsigned int model, int animeIdx);
extern int FLD_EXP_OBJ_IsAnimeStopped(void *anime);

/* Event: ends once the first anime of the arc model has stopped. */
int GIMMICK64_IsArcAnimeStopped(void *event, int *unusedSeq)
{
    void *expObj;

    expObj = FIELDMAP_GetExpObj(GAMESYSTEM_GetFieldMap(func_020124E4(event)));
    if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, GIMMICK64_ARC_MODEL, 0)) != 0) {
        return 1;
    }
    return 0;
}
