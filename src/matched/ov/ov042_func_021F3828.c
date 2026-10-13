/*
 * function: GIMMICK42_Update
 * address:  0x021F3828
 * packet:   pkt_021F3828
 * region:   ov042
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GIMMICK42_Update 0x021F3828 thumb
 *   FIELDMAP_GetExpObj 0x02188D2C thumb  ov021
 *   FLD_EXP_OBJ_UpdateAnimes 0x021BE580 thumb ov021
*/

extern int FIELDMAP_GetExpObj(int *p);
extern void FLD_EXP_OBJ_UpdateAnimes(void *p);

void GIMMICK42_Update(void *p)
{
    FLD_EXP_OBJ_UpdateAnimes((void *)FIELDMAP_GetExpObj(p));
}
