/*
 * function: GIMMICK50_InitModelsB
 * address: 0x021F3714
 * packet: pkt_ov050_021F3714
 * region: ov050
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two-byte alignment padding at 0x021F3742 follows the return.
 * symbols:
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled 0x021BE700 thumb ov021
 *   FLD_EXP_OBJ_GetAnime 0x021BE674 thumb ov021
 *   FLD_EXP_OBJ_SetAnimeLoop 0x021BE6B8 thumb ov021
 */

extern int FIELDMAP_GetExpObj(int *);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *, int,int,int,int);
extern void *FLD_EXP_OBJ_GetAnime(char *, int,unsigned int,int);
extern void FLD_EXP_OBJ_SetAnimeLoop(unsigned char *,int);
void GIMMICK50_InitModelsB(int *p) { char *q=(char *)FIELDMAP_GetExpObj(p); FLD_EXP_OBJ_SetAnimeEnabled(q,0,0,0,1); FLD_EXP_OBJ_SetAnimeLoop(FLD_EXP_OBJ_GetAnime(q,0,0,0),0); }
