/*
 * function: DEMO3D_DATA_TaskSetLightVector
 * address: 0x021BF26C
 * packet: pkt_ov203_021BF26C
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DEMO3D_GRAPHIC_SetLightVector 0x021BDF88 thumb ov203
 */
struct Triple{unsigned short x,y,z;};
extern void DEMO3D_GRAPHIC_SetLightVector(char *p, int a, int b);
void DEMO3D_DATA_TaskSetLightVector(unsigned unused,char **q,unsigned *v){struct Triple t;t.x=v[1];t.y=v[2];t.z=v[3];DEMO3D_GRAPHIC_SetLightVector(*q,(unsigned char)v[0],(int)&t);}
