/*
 * function: func_021DF18C
 * address: 0x021DF18C
 * packet: pkt_ov183_021DF18C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DEB4C 0x021DEB4C thumb ov183
 */
#include "../include/Obj14432.h"
#include "../include/Obj24617.h"
#include "../include/Obj24618.h"
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *);
extern void func_021FD73C(int *, int);
extern void func_021DEB4C(int *task, int *state, char *p);
void func_021DF18C(int *p, int *state, char *q)
{
    switch (*state) {
    case 0:
        func_021FE784((int)(*(int * *)&((struct Obj24617 *)(*(char * *)&((struct Obj14432 *)q)->f108))->f8), 2, 3, 1);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0(*(int * *)&((struct Obj24618 *)(*(char * *)&((struct Obj14432 *)q)->f108))->f8) != 0) *state = 2;
        break;
    case 2:
        func_021FD73C(p, (int)func_021DEB4C);
        break;
    }
}
