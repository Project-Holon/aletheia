/*
 * unit: yes
 * function: COMM_BTL_DEMO_GRAPHIC_VBlankClact, COMM_BTL_DEMO_GRAPHIC_GetClactBank
 * address: 0x021BADBC
 * packet: pkt_ov213_021BADBC
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
extern void CLACT_VBlankSystem(void);
void COMM_BTL_DEMO_GRAPHIC_VBlankClact(void *a0){CLACT_VBlankSystem();}
void *COMM_BTL_DEMO_GRAPHIC_GetClactBank(void **p){return *p;}
