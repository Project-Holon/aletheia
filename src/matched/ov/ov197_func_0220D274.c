/*
 * function: func_0220D274
 * address: 0x0220D274
 * packet: pkt_ov197_0220D274
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   func_0220D848 0x0220D848 thumb ov197
 */
#include "../include/Obj10838.h"
struct PrintSys;
extern unsigned PRINTSYS_QUE_IsFinished(const struct PrintSys *);
extern void func_0220D848(char *,int);
int func_0220D274(char *p){if(PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj10838 *)p)->f18)==1){func_0220D848(p,((struct Obj10838 *)p)->f532);return ((struct Obj10838 *)p)->f531;}return 10;}
