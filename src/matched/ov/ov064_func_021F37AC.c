/*
 * function: GIMMICK64_Update
 * address:  0x021F37AC
 * packet:   pkt_021F37AC
 * region:   ov064
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

void GIMMICK64_Update(void *p)
{
    void *FIELDMAP_GetExpObj(void *p);
    void FLD_EXP_OBJ_UpdateAnimes(void *p);
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(p));
}
