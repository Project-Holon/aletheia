/*
 * function: GIMMICK44_Update
 * address:  0x021F3764
 * packet:   pkt_021F3764
 * region:   ov044
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GIMMICK44_Update 0x021F3764 thumb
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FLD_EXP_OBJ_UpdateAnimes 0x021BE580 thumb ov021
*/

extern int FIELDMAP_GetExpObj(int *p);
extern void FLD_EXP_OBJ_UpdateAnimes(void *p);

void GIMMICK44_Update(void *p)
{
    FLD_EXP_OBJ_UpdateAnimes((void *)FIELDMAP_GetExpObj(p));
}
