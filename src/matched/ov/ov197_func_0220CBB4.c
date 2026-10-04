/*
 * function: func_0220CBB4
 * address: 0x0220CBB4
 * packet: pkt_ov197_0220CBB4
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0202208C 0x0202208C thumb
 */
#include "../include/Obj14547.h"
#include "../include/Obj25065.h"
struct PrintSys;
extern unsigned func_0201C6B4(const struct PrintSys *);
extern void func_0202208C(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
int func_0220CBB4(char *p){if(func_0201C6B4(*(struct PrintSys * *)&((struct Obj14547 *)p)->f18)==1){func_0202208C((void *)4,1,1,0,6,1,((struct Obj25065 *)(*(char * *)&((struct Obj14547 *)p)->f0))->fC);return 3;}return 2;}
