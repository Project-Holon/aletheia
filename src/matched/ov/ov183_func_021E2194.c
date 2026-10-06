/*
 * function: func_021E2194
 * address: 0x021E2194
 * packet: pkt_ov183_021E2194
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 */
#include "../include/Obj10760.h"
#include "../include/Obj24651.h"
#include "../include/Obj24652.h"
#include "../include/Obj24653.h"
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *);
extern int func_021FD744(int *a);
extern void func_021F9BA0(unsigned *ctx);
void func_021E2194(int *task,int *state,char *p)
{
    switch (*state) {
    case 0: func_021FE784(((struct Obj24651 *)(*(char * *)&((struct Obj10760 *)p)->f20))->f4,2,3,1); *state=1; break;
    case 1: if (func_021FE7B0(*(int * *)&((struct Obj24652 *)(*(char * *)&((struct Obj10760 *)p)->f20))->f4)) *state=2; break;
    case 2: func_021F9BA0((unsigned int *)(((struct Obj24653 *)(*(char * *)&((struct Obj10760 *)p)->f20))->f10)); func_021FD744(task); break;
    }
}
