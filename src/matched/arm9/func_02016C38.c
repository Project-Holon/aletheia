/*
 * unit:     no
 * function: MCSS_DeletePaletteTask
 * address:  0x02016C38
 * packet:   pkt_02016C38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TCBL_GetTaskUserData  0x02030EE8  arm
 */
#include "../include/Obj11258.h"

int MCSS_DeletePaletteTask(int a0){ int t0 = TCBL_GetTaskUserData(a0); int t1 = func_020307B0((int)*(int *)(((char *)(((struct Obj11258 *)((char *)((t0 + 0))))->f4) + 12))); int t2 = func_020307B0((int)((struct Obj11258 *)((char *)((t0 + 0))))->f4); int t3 = func_020307B0((int)((t0 + 0) + 0)); int t4 = func_02030EAC((int)((a0 + 0) + 0)); return t4; }
