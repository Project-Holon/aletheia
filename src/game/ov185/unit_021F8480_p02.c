/*
 * file:     unit_021F8480_p02.c
 * unit:     yes
 * function: func_021F8658, func_021F86A4
 * address:  0x021F8658
 * region:   ov185
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021F8AA8   0x021F8AA8  thumb
 *   func_021FFC9C   0x021FFC9C  thumb
 *   func_021FFE90   0x021FFE90  thumb
 *   func_021FD73C   0x021FD73C  thumb
 */
#include "../../matched/include/Obj08320.h"
#include "../../matched/include/Obj24722.h"
#include "../../matched/include/Obj10771.h"

extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *p);
extern int func_021FD744(int *a);
extern void func_021F9BA0(unsigned *ctx);
extern void func_021F8AA8(int *sys, int *state, char *p);
extern void func_021FFC9C(int);
extern int func_021FFE90(int, unsigned short *);
extern void func_021FD73C(int, void *);
void func_021F8658(int a,int *state,char *p);
void func_021F86A4(int a, int b, char *p);

void func_021F8658(int a,int *state,char *p)
{
    switch (*state) {
    case 0: func_021FE784(**(int * *)&((struct Obj08320 *)p)->f34,2,3,1); *state=1; break;
    case 1: if (func_021FE7B0((int *)(**(int * *)&((struct Obj08320 *)p)->f34))) *state=2; break;
    case 2: func_021FD744((int *)(((struct Obj08320 *)p)->f24)); func_021F9BA0((unsigned int *)(((struct Obj24722 *)(*(char * *)&((struct Obj08320 *)p)->f34))->f10)); break;
    }
}


void func_021F86A4(int a, int b, char *p)
{
    unsigned short buf;
    int r;
    func_021FFC9C(((struct Obj10771 *)p)->f0);
    r = func_021FFE90(((struct Obj10771 *)p)->f0, &buf);
    if (r == 0)
        return;
    if (r == 2) {
        ((struct Obj10771 *)p)->f8 = buf;
        func_021FD73C(a, func_021F8AA8);
    } else {
        func_021FD73C(a, func_021F8658);
    }
}
