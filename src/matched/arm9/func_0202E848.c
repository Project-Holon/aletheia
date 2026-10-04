/*
 * unit:     no
 * function: func_0202E848
 * address:  0x0202E848
 * packet:   pkt_0202E79C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj06926.h"
#include "../include/Obj08811.h"

int func_0202E848(int a0, int a1, int a2, int a3){ int t0, t1, t2, t3; t0 = func_02012B70((int)((a0 + 0) + 0)); if ((unsigned int)(t0) != (unsigned int)(0)) { t1 = func_02012984((int)((a0 + 0) + 0)); ((struct Obj06926 *)((char *)((a1 + 0))))->f0 = (unsigned short)t1; ((struct Obj08811 *)((char *)((a2 + 0))))->f0 = (unsigned short)((struct Obj06926 *)((char *)((a1 + 0))))->f0; return 0; } else { t2 = func_02012984((int)((a0 + 0) + 0)); ((struct Obj06926 *)((char *)((a1 + 0))))->f0 = (unsigned short)t2; t3 = func_0202E888((int)t2); ((struct Obj08811 *)((char *)((a2 + 0))))->f0 = (unsigned short)t3; if ((unsigned int)(((struct Obj06926 *)((char *)((a1 + 0))))->f0) != (unsigned int)(((struct Obj08811 *)((char *)((a2 + 0))))->f0)) { return 1; } else { return 0; } } }
