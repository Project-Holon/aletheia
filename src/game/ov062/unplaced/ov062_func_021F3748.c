/*
 * function: GIMMICK62_Update
 * address:  0x021F3748
 * packet:   pkt_ov062_021F3748
 * region:   ov062
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two-call wrapper.
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 */

extern void *FIELDMAP_GetExpObj(void *fieldMap);
extern void FLD_EXP_OBJ_UpdateAnimes(void *expObj);

/* Per-frame update: advances the model animes. */
void GIMMICK62_Update(void *fieldMap)
{
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
}
