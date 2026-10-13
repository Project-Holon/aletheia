/*
 * unit: yes
 * function: HAND_TOKUSEI_SapSipperAbsorbGrass,HAND_TOKUSEI_GetSapSipperHandlers
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
 *   HAND_TOKUSEI_AbsorbCheckMoveType 0x021DA8A8 thumb ov093
 *   HAND_TOKUSEI_AbsorbRaiseStat 0x021DA96C thumb ov093
 */
extern unsigned char gSapSipperHandlers[];
extern int HAND_TOKUSEI_AbsorbCheckMoveType(int,int,int);
extern void HAND_TOKUSEI_AbsorbRaiseStat(void *,int,unsigned int,int);
void HAND_TOKUSEI_SapSipperAbsorbGrass(int a, void *b, int c) { if (HAND_TOKUSEI_AbsorbCheckMoveType((int)b,c,11)) HAND_TOKUSEI_AbsorbRaiseStat(b,c,1,1); }
void *HAND_TOKUSEI_GetSapSipperHandlers(int *p) { *p = 1; return gSapSipperHandlers; }
