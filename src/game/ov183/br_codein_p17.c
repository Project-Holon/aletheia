/*
 * file:     br_codein_p17.c
 * unit:     yes
 * function: func_021DF0DC, func_021DF18C
 * address:  0x021DF0DC
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DEE7C 0x021DEE7C thumb ov183
 *   func_021DEB4C 0x021DEB4C thumb ov183
 */
#include "../../matched/include/Obj01962.h"
#include "../../matched/include/Obj24611.h"
#include "../../matched/include/Obj24613.h"
#include "../../matched/include/Obj24614.h"
#include "../../matched/include/Obj24615.h"
#include "../../matched/include/Obj24616.h"
#include "../../matched/include/Obj14432.h"
#include "../../matched/include/Obj24617.h"
#include "../../matched/include/Obj24618.h"

typedef unsigned short u16;

typedef unsigned int   u32;

extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern void func_021FD860(int, int, int *);
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *);
extern int *func_021FD73C(int *p, int v);
extern void func_021DEE7C(int *task, u32 *state, char *p);
extern void func_021DEB4C(int *task, int *state, char *p);
void func_021DF0DC(int *p, int *state, char *q);
void func_021DF18C(int *p, int *state, char *q);

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
