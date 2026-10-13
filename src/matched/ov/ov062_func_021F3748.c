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

void GIMMICK62_Update(void *p)
{
    int FIELDMAP_GetExpObj(int *p);
    void FLD_EXP_OBJ_UpdateAnimes(void *p);
    FLD_EXP_OBJ_UpdateAnimes((void *)FIELDMAP_GetExpObj(p));
}
