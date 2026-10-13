/*
 * function: FLDMMDL_GetMovedPos
 * address: 0x0216E544
 * packet: pkt_ov010_0216E544
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_GetMovedPosSlot 0x0216E4EC thumb ov010
 *   FLDMMDL_GetMmdlSys 0x0216D67C thumb ov010
 *   FLDMMDL_IsMovedPosSet 0x0216E490 thumb ov010
 */
#include "../include/Obj19139.h"

typedef struct { int x,y,z; } Vec;
extern int FLDMMDL_GetMovedPosSlot(int a0, int a1);
extern void *FLDMMDL_GetMmdlSys(void *);
extern int FLDMMDL_IsMovedPosSet(int a0);
int FLDMMDL_GetMovedPos(void *a, Vec *out) { int i; Vec *p; unsigned int base; i=FLDMMDL_GetMovedPosSlot((int)a, (int)out); if(i!=30) { base=((struct Obj19139 *)((char *)FLDMMDL_GetMmdlSys(a)))->f2C; p=(Vec *)(base+i*12); if(FLDMMDL_IsMovedPosSet((int)p)) { *out=*p; return 1; } } return 0; }
