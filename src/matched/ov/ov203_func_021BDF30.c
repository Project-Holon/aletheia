/*
 * function: DEMO3D_GRAPHIC_GetUnit
 * address: 0x021BDF30
 * packet: pkt_ov203_021BDF30
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DEMO3D_GRAPHIC_GetClactUnit 0x021BE0F0 thumb ov203
 */
extern int DEMO3D_GRAPHIC_GetClactUnit(void *);
int DEMO3D_GRAPHIC_GetUnit(char *p){return DEMO3D_GRAPHIC_GetClactUnit(p+4);}
