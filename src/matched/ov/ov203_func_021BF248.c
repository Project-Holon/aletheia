/*
 * function: DEMO3D_DATA_TaskSetLightSlot
 * address: 0x021BF248
 * packet: pkt_ov203_021BF248
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   DEMO3D_GRAPHIC_SetLightSlot 0x021BDF74 thumb ov203
 */
extern void DEMO3D_GRAPHIC_SetLightSlot(char *p, unsigned i, unsigned short val);
void DEMO3D_DATA_TaskSetLightSlot(unsigned unused,char **q,unsigned *v){DEMO3D_GRAPHIC_SetLightSlot(*q,(unsigned char)v[0],v[1]|(v[2]<<5)|(v[3]<<10));}
