/*
 * function: BTL_MAIN_GetActivePosPerSide
 * address: 0x021B8670
 * packet: pkt_ov093_021B8670
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
unsigned int BTL_MAIN_GetActivePosPerSide(unsigned int **p) { switch ((*p)[1]) { case 0:return 1; case 1:return 2; case 2:return 3; case 3:return 1; default:return 1; } }
