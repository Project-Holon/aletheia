/*
 * function: GIMMICK50_HideModel1
 * address: 0x021F3788
 * packet: pkt_ov050_021F3788
 * region: ov050
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: index declared before pointer restores r4/r5; u16 fourth parameter reproduces the observed call-site truncation.
 * symbols:
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FLD_EXP_OBJ_SetModelHidden 0x021BE4B4 thumb ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled 0x021BE700 thumb ov021
 */

extern int FIELDMAP_GetExpObj(int *);
extern void FLD_EXP_OBJ_SetModelHidden(char *,int,int,int);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
void GIMMICK50_HideModel1(int *p) { int i; char *q; q=(char *)FIELDMAP_GetExpObj(p); FLD_EXP_OBJ_SetModelHidden(q,0,1,1); for(i=0;i<2;i++) FLD_EXP_OBJ_SetAnimeEnabled(q,0,1,(unsigned short)i,0); }
