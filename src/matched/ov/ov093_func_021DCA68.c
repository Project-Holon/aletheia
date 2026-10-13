/*
 * unit: yes
 * function: BTL_ABILITY_SapSipperAbsorbGrass,BTL_ABILITY_GetSapSipperHandlers
 * address: 0x021DCA68
 * packet: pkt_ov093_021DCA68
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gSapSipperHandlers 0x021F05C8 data a4
 *   BTL_ABILITY_AbsorbCheckMoveType 0x021DA8A8 thumb ov093
 *   BTL_ABILITY_AbsorbRaiseStat 0x021DA96C thumb ov093
 */
extern unsigned char gSapSipperHandlers[];
extern int BTL_ABILITY_AbsorbCheckMoveType(int,int,int);
extern void BTL_ABILITY_AbsorbRaiseStat(void *,int,unsigned int,int);
void BTL_ABILITY_SapSipperAbsorbGrass(int a, void *b, int c) { if (BTL_ABILITY_AbsorbCheckMoveType((int)b,c,11)) BTL_ABILITY_AbsorbRaiseStat(b,c,1,1); }
void *BTL_ABILITY_GetSapSipperHandlers(int *p) { *p = 1; return gSapSipperHandlers; }
