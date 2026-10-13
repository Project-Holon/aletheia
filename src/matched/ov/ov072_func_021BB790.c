/*
 * function: TOWNMAP_GRH_GetResourceIds
 * address: 0x021BB790
 * packet: pkt_ov072_021BB790
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   TOWNMAP_GRH_GetSpriteResourceId 0x021BBB1C thumb ov072
 */
extern int TOWNMAP_GRH_GetSpriteResourceId(char *,int);
void TOWNMAP_GRH_GetResourceIds(char *p,int *a,int *b,int *c) { *a=TOWNMAP_GRH_GetSpriteResourceId(p+4,0); *b=TOWNMAP_GRH_GetSpriteResourceId(p+4,1); *c=TOWNMAP_GRH_GetSpriteResourceId(p+4,2); }
