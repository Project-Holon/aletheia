/*
 * function: CROWD_RemovePerson
 * address: 0x021F3DBC
 * packet: pkt_ov055_021F3DBC
 * region: ov055
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_SetStatusBitVanish 0x0216DAC8 thumb ov010
 */
#include "../include/Obj00204.h"
extern void FLDMMDL_SetStatusBitVanish(unsigned int *p, unsigned int v);
void CROWD_RemovePerson(unsigned char *p) { p[0]=0; p[2]=0; p[3]=0; p[1]=0; FLDMMDL_SetStatusBitVanish((unsigned int *)(*(int *)&((struct Obj00204 *)p)->fC),1); }
