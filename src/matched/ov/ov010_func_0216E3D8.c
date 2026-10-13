/*
 * function: FLDMMDL_GetEventWorkObjCode
 * address: 0x0216E3D8
 * packet: pkt_ov010_0216E3D8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZONEDATA_GetEventWorkAddress 0x020143CC thumb
 */

typedef unsigned short u16;
extern unsigned int ZONEDATA_GetEventWorkAddress(unsigned int, unsigned int);
unsigned int FLDMMDL_GetEventWorkObjCode(unsigned int a, unsigned int id) { if (id>=162 && id<=177) { if(a==0) id=10; else id=*(u16 *)ZONEDATA_GetEventWorkAddress(a,(u16)(id+0x3f7e)); } return id; }
