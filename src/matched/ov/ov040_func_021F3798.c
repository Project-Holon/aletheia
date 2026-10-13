/*
 * function: FIELD_GIMMICK_FLAG_ANIME_Update
 * address:  0x021F3798
 * packet:   pkt_021F3798
 * region:   ov040
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_GIMMICK_FLAG_ANIME_Update 0x021F3798 thumb
 *   FIELDMAP_GetExpObj 0x02188D2C thumb  ov021
 *   FLD_EXP_OBJ_UpdateAnimes 0x021BE580 thumb ov021
*/

extern int FIELDMAP_GetExpObj(int *p);
extern void FLD_EXP_OBJ_UpdateAnimes(void *p);

void FIELD_GIMMICK_FLAG_ANIME_Update(int *p)
{
    FLD_EXP_OBJ_UpdateAnimes((void *)FIELDMAP_GetExpObj(p));
}
