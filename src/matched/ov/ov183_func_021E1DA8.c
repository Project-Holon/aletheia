/*
 * function: func_021E1DA8
 * address: 0x021E1DA8
 * packet: pkt_ov183_021E1DA8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021E1E3C 0x021E1E3C thumb ov183
 */
#include "../include/Obj14441.h"
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *p);
extern void func_021FD73C(int *p, int v);
extern void func_021E1E3C(int task, int *state, char *p);
void func_021E1DA8(int a,int *state,char *p)
{
    switch (*state) {
    case 0: func_021FE784(**(int * *)&((struct Obj14441 *)p)->f18,2,3,0); *state=1; break;
    case 1: if (func_021FE7B0((int *)(**(int * *)&((struct Obj14441 *)p)->f18))) *state=2; break;
    case 2: func_021FD73C((int *)a,(int)func_021E1E3C); break;
    }
}
