/*
 * function: CROWD_MakePersonSolid
 * address: 0x021F3D90
 * packet: pkt_ov055_021F3D90
 * region: ov055
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FLDMMDL_GetEventId 0x0216D5B8 thumb ov010
 *   CROWD_InitSolidPerson 0x021F4124 thumb ov055
 */
#include "../include/Obj00204.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 FLDMMDL_GetEventId(void *p);
extern void CROWD_InitSolidPerson(unsigned char *);
void CROWD_MakePersonSolid(unsigned char *p) { if (p[0]==1 && p[2]==1 && FLDMMDL_GetEventId(((struct Obj00204 *)p)->fC)==2000) { p[2]=0; CROWD_InitSolidPerson(p); } }
