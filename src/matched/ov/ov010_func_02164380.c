/*
 * function: func_02164380
 * address: 0x02164380
 * packet: pkt_ov010_02164380
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * contract: setter func_0216435C writes the four payload halfwords
 * at +4,+6,+8,+10 before publishing 0xEFEFEFEF at +0;
 * this reader loads those halfwords only after the sentinel comparison.
 * symbols:
 *   func_0216D69C 0x0216D69C thumb ov010
 */
#include "../include/Obj05897.h"

typedef unsigned short u16;
extern void *func_0216D69C(void *p);
int func_02164380(void *a, u16 *b) { u16 *p=func_0216D69C(a); if (((struct Obj05897 *)p)->f0==0xEFEFEFEF) { b[0]=p[2]; b[1]=p[3]; b[2]=p[4]; b[3]=p[5]; return 1; } return 0; }
