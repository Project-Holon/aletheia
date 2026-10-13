/*
 * function: FIELD_GIMMICK_MODELS_B_Update
 * address:  0x021F3708
 * packet:   pkt_ov050_021F3708
 * region:   ov050
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two-call wrapper.  Blocker: both callees are unlabelled leaves at
 * 0x02188D2C / 0x021BE580, so no label/sole-ref witness exists.  Address is
 * also resident in ov049; region-qualified packet id.
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 
 *
 * UNBLOCKED: FIELDMAP_GetExpObj is now an EXACT entry at 0x02188D2C in
 * layout/matched/ov021, and FLD_EXP_OBJ_UpdateAnimes resolves with the ov021
 * region hint; both call sites fine, verdict promoted to EXACT.
*/

void FIELD_GIMMICK_MODELS_B_Update(void *p)
{
    void *FIELDMAP_GetExpObj(void *p);
    void FLD_EXP_OBJ_UpdateAnimes(void *p);
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(p));
}
