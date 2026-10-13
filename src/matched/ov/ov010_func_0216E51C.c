/*
 * function: FLDMMDL_HasMovedPos
 * address: 0x0216E51C
 * packet: pkt_ov010_0216E51C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FLDMMDL_GetMovedPosSlot 0x0216E4EC thumb ov010
 *   FLDMMDL_GetMmdlSys 0x0216D67C thumb ov010
 *   FLDMMDL_IsMovedPosSet 0x0216E490 thumb ov010
 */
#include "../include/Obj19138.h"

extern int FLDMMDL_GetMovedPosSlot(int a0, int a1);
extern void *FLDMMDL_GetMmdlSys(void *);
extern int FLDMMDL_IsMovedPosSet(int a0);
int FLDMMDL_HasMovedPos(void *a, int a1) { int i; unsigned int base; i=FLDMMDL_GetMovedPosSlot((int)a, a1); if(i!=30) { base=((struct Obj19138 *)((char *)FLDMMDL_GetMmdlSys(a)))->f2C; return FLDMMDL_IsMovedPosSet((int)((void *)(base+i*12))); } return 0; }
