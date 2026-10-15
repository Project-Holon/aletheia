/*
 * function: EGG_DEMO_GRAPHIC_GetClactBank2
 * address: 0x021F64FC
 * packet: pkt_ov215_021F64FC
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EGG_DEMO_GRAPHIC_GetClactBank 0x021F662C thumb ov215
 */
extern int EGG_DEMO_GRAPHIC_GetClactBank(void *);
int EGG_DEMO_GRAPHIC_GetClactBank2(char *p){return EGG_DEMO_GRAPHIC_GetClactBank(p+4);}
