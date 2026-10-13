/*
 * function: BTL_MAIN_CheckFrontPos
 * address: 0x021B86A0
 * packet: pkt_ov093_021B86A0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: final two zero bytes are alignment padding before the next labelled function.
 * symbols:
 *   BTL_MAIN_GetActivePosPerSide 0x021B8670 thumb ov093
 */
extern unsigned int BTL_MAIN_GetActivePosPerSide(unsigned int **);
int BTL_MAIN_CheckFrontPos(unsigned int **p, unsigned int i) { if (i < BTL_MAIN_GetActivePosPerSide(p)*2) return 1; return 0; }
