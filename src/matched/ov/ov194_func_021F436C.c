/*
 * function: func_021F436C
 * address: 0x021F436C
 * packet: pkt_ov194_021F436C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020257D0 0x020257D0 thumb
 */
#include "../include/Obj06641.h"
struct Obj;extern int func_0201C6C4(int,int);extern void func_020257D0(struct Obj *);
void func_021F436C(unsigned char *p){if(((struct Obj06641 *)p)->f34){if(func_0201C6C4(((struct Obj06641 *)p)->f38,((struct Obj06641 *)p)->f30)==0){func_020257D0(*(struct Obj * *)&((struct Obj06641 *)p)->f2C);((struct Obj06641 *)p)->f34=0;}}}
