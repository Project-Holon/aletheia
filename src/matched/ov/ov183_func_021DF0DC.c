/*
 * function: func_021DF0DC
 * address: 0x021DF0DC
 * packet: pkt_ov183_021DF0DC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DEE7C 0x021DEE7C thumb ov183
 */
#include "../include/Obj01962.h"
#include "../include/Obj24611.h"
#include "../include/Obj24613.h"
#include "../include/Obj24614.h"
#include "../include/Obj24615.h"
#include "../include/Obj24616.h"
typedef unsigned short u16;
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern void func_021FD860(int, int, int *);
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *);
extern void func_021FD73C(int *, int);
extern void func_021DEE7C(void);
void func_021DF0DC(int *p, int *state, char *q)
{
    int args[2];
    switch (*state) {
    case 0:
        if (((struct Obj01962 *)q)->f24 == 0) {
            ((struct Obj01962 *)q)->f24 = (int)func_021FD12C(((struct Obj24611 *)(*(char * *)&((struct Obj01962 *)q)->f108))->f10, (void *)(((struct Obj01962 *)q)->f14), ((struct Obj01962 *)q)->f18);
        }
        if (**(int * *)&((struct Obj01962 *)q)->f108 == 3) {
            func_021FD170((char *)(((struct Obj01962 *)q)->f24), (char *)(((struct Obj24613 *)(*(char * *)&((struct Obj01962 *)q)->f108))->f10), (void *)0x14B);
        } else {
            func_021FD170((char *)(((struct Obj01962 *)q)->f24), (char *)(((struct Obj24614 *)(*(char * *)&((struct Obj01962 *)q)->f108))->f10), (void *)0x13E);
        }
        args[0] = 0x80;
        args[1] = 0x60;
        func_021FD860(((struct Obj01962 *)q)->f1C, 4, args);
        *state = 1;
        break;
    case 1:
        func_021FE784((int)(*(int * *)&((struct Obj24615 *)(*(char * *)&((struct Obj01962 *)q)->f108))->f8), 2, 3, 0);
        *state = 2;
        break;
    case 2:
        if (func_021FE7B0(*(int * *)&((struct Obj24616 *)(*(char * *)&((struct Obj01962 *)q)->f108))->f8) != 0) *state = 3;
        break;
    case 3:
        func_021FD73C(p, (int)func_021DEE7C);
        break;
    }
}
