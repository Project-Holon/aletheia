/*
 * function: TOWNMAP_GRH_UpdateTask
 * address: 0x021BB80C
 * packet: pkt_ov072_021BB80C
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   TOWNMAP_GRH_VBlankSprites 0x021BBB04 thumb ov072
 *   TOWNMAP_GRH_TransferBgData 0x021BB9B0 thumb ov072
 */
extern void TOWNMAP_GRH_VBlankSprites(void *);
extern void TOWNMAP_GRH_TransferBgData(void *);
void TOWNMAP_GRH_UpdateTask(int unused, char *p) { TOWNMAP_GRH_VBlankSprites(p+4); TOWNMAP_GRH_TransferBgData(p); }
