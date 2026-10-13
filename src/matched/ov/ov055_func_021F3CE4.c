/*
 * function: CROWD_DeletePerson
 * address: 0x021F3CE4
 * packet: pkt_ov055_021F3CE4
 * region: ov055
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_DeleteMmdl 0x0216CF2C thumb ov010
 */
#include "../include/Obj13122.h"

extern int FLDMMDL_DeleteMmdl(int a0, int a1);
void CROWD_DeletePerson(char *p, int a1) { FLDMMDL_DeleteMmdl((int)(*(unsigned char * *)&((struct Obj13122 *)p)->fC), a1); ((struct Obj13122 *)p)->fC=0; }
