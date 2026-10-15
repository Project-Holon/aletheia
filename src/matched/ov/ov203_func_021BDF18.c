/*
 * function: DEMO3D_GRAPHIC_UpdateLookAt
 * address: 0x021BDF18
 * packet: pkt_ov203_021BDF18
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DEMO3D_GRAPHIC_ApplyLookAt 0x021BE13C thumb ov203
 */
extern void DEMO3D_GRAPHIC_ApplyLookAt(void *);
void DEMO3D_GRAPHIC_UpdateLookAt(char *p){DEMO3D_GRAPHIC_ApplyLookAt(p+8);}
