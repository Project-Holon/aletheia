/*
 * function: BTL_MAIN_CheckAllClientsReady
 * address: 0x021B8564
 * packet: pkt_ov093_021B8564
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
int BTL_MAIN_CheckAllClientsReady(unsigned char *p) { unsigned int i; for (i=0;i<4;i++) { if (*(void **)(p+0x10+i*4) != 0 && p[0xc4+i] == 0) return 0; } return 1; }
