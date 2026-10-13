/*
 * function: FIELD_FK_DEMO_StartBuildAnime
 * address: 0x021F3904
 * packet: pkt_ov056_021F3904
 * region: ov056
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FIELD_BUILDMODEL_PlayNodeSlot 0x0218C88C thumb ov021
 */
extern void FIELD_BUILDMODEL_PlayNodeSlot(unsigned char *,int,int);
void FIELD_FK_DEMO_StartBuildAnime(unsigned char **p) { if (*p) FIELD_BUILDMODEL_PlayNodeSlot(*p,0,0); }
