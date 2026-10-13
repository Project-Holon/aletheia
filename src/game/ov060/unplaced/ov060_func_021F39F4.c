/*
 * function: GIMMICK60_UpdateEffect
 * address:  0x021F39F4
 * packet:   pkt_ov060_021F39F4
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     closes docs/notes/ov060_func_021F39F4.c.txt: the Thumb callee at
 *           0x021BE6BC is ov021's leaf, now matched (ov021 token); the
 *           function is 52 bytes, the rest of the handed 492 is data.
 *
 * symbols:
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 */

#include "../unit_021F36C0_types.h"

extern u8 *FLD_EXP_OBJ_GetAnime(void *expObj, int unit, int model, int animeIdx);
extern int FLD_EXP_OBJ_IsAnimeStopped(u8 *anime);
extern void FLD_EXP_OBJ_SetModelHidden(void *expObj, int unit, int model, int hidden);

/* Ends the effect once its first anime has stopped: hides the model and clears the flag. */
void GIMMICK60_UpdateEffect(Gimmick60Work *work, void *expObj)
{
    if (work->effectActive != 0) {
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, GIMMICK60_EFFECT_MODEL, 0)) != 0) {
            FLD_EXP_OBJ_SetModelHidden(expObj, 0, GIMMICK60_EFFECT_MODEL, 1);
            work->effectActive = 0;
        }
    }
}
