/*
 * function: UNION_COMM_Exit
 * address: 0x02172CAC
 * packet: pkt_ov012_02172CAC
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CEAC 0x0203CEAC arm
 *   UNION_COMM_ExitCallback 0x02172D14 thumb ov012
 */
#include "../include/Obj09356.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_0203CEAC(int a0);
extern void UNION_COMM_ExitCallback(u8 *p);
int UNION_COMM_Exit(void *a, void *b, u8 *p) { ((struct Obj09356 *)p)->f356C = 1; if (p[0x3560] < 3) return 0; p[0x3560] = 4; if (func_0203CEAC((int)UNION_COMM_ExitCallback) == 0) UNION_COMM_ExitCallback(p); return 1; }
