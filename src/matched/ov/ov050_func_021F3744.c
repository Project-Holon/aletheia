/*
 * function: GIMMICK50_StopModel0Anime
 * address: 0x021F3744
 * packet: pkt_ov050_021F3744
 * region: ov050
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled 0x021BE700 thumb ov021
 */

extern int FIELDMAP_GetExpObj(int *p);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *, int, int, int, int);
void GIMMICK50_StopModel0Anime(int *p) { FLD_EXP_OBJ_SetAnimeEnabled((void *)FIELDMAP_GetExpObj(p), 0, 0, 0, 0); }
