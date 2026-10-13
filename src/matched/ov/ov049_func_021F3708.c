/*
 * function: FIELD_GIMMICK_MODELS_A_Update
 * address:  0x021F3708
 * packet:   pkt_021F3708
 * region:   ov049
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     archived here under this lane's recursive MATCH-unblock pass;
 *           the annotated header contract for this file has no `packet:`
 *           field (four callers under src/pending resurrected it), so it is
 *           not spliced and no shard is emitted for it.  The 02188D2C
 *           call site resolves via the ov021 `matched` witness.
 *
 * Two-call wrapper.
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
*/

void FIELD_GIMMICK_MODELS_A_Update(void *p)
{
    void *FIELDMAP_GetExpObj(void *p);
    void FLD_EXP_OBJ_UpdateAnimes(void *p);
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(p));
}
