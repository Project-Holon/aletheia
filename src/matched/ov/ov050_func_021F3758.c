/*
 * function: GIMMICK50_IsModel0AnimeDone
 * address: 0x021F3758
 * packet: pkt_ov050_021F3758
 * region: ov050
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: index declared before pointer restores r4/r5; fourth callee parameter is u16 for the observed call-site shift pair.
 * symbols:
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FLD_EXP_OBJ_GetAnime 0x021BE674 thumb ov021
 *   FLD_EXP_OBJ_IsAnimeStopped 0x021BE6BC thumb ov021
 */

extern int FIELDMAP_GetExpObj(int *);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *);
int GIMMICK50_IsModel0AnimeDone(int *p) { int i; char *q; q=(char *)FIELDMAP_GetExpObj(p); for(i=0;i<1;i++) { if(FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(q,0,0,(unsigned short)i))==0) return 0; } return 1; }
