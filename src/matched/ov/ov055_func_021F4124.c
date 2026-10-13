/*
 * function: CROWD_InitSolidPerson
 * address: 0x021F4124
 * packet: pkt_ov055_021F4124
 * region: ov055
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_SetStatusBitHeightGetOff 0x0216DB4C thumb ov010
 *   FLDMMDL_SetStatusBitAttrGetOff 0x0216DC98 thumb ov010
 *   FLDMMDL_SetStatusBitFellowHit 0x0216DAE0 thumb ov010
 *   FLDMMDL_SetEventId 0x0216D5B4 thumb ov010
 */
#include "../include/Obj00204.h"
extern int FLDMMDL_SetStatusBitHeightGetOff(void *a0, int a1);
extern int FLDMMDL_SetStatusBitAttrGetOff(void *a0, int a1);
extern void FLDMMDL_SetStatusBitFellowHit(unsigned int *,unsigned int);
typedef unsigned short u16;
extern void FLDMMDL_SetEventId(void *p, u16 v);
void CROWD_InitSolidPerson(unsigned char *p) { FLDMMDL_SetStatusBitHeightGetOff(*(unsigned int * *)&((struct Obj00204 *)p)->fC,1); FLDMMDL_SetStatusBitAttrGetOff(*(unsigned int * *)&((struct Obj00204 *)p)->fC,1); FLDMMDL_SetStatusBitFellowHit(*(unsigned int * *)&((struct Obj00204 *)p)->fC,0); FLDMMDL_SetEventId((void *)(*(unsigned int *)&((struct Obj00204 *)p)->fC),2000); }
