/*
 * file:     unit_021F8480_p04.c
 * unit:     yes
 * function: func_021F8950, func_021F8A0C, func_021F8AA8, func_021F8B5C
 * address:  0x021F8950
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
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021F86A4 0x021F86A4 thumb ov185
 *   func_021F8EE8 0x021F8EE8 thumb ov185
 *   func_021F8D5C 0x021F8D5C thumb ov185
 *   func_021F8E60 0x021F8E60 thumb ov185
 *   func_021F8EFC 0x021F8EFC thumb ov185
 *   func_021F8FB0 0x021F8FB0 thumb ov185
 *   func_021FFE34 0x021FFE34 thumb ov186
 *   func_021F8790 0x021F8790 thumb ov185
 *   func_021F8F58 0x021F8F58 thumb ov185
 *   func_021F8F88 0x021F8F88 thumb ov185
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021F8D18 0x021F8D18 thumb ov185
 *   func_021F8E90 0x021F8E90 thumb ov185
 *   func_021F86E4 0x021F86E4 thumb ov185
 */
#include "../../matched/include/Obj00278.h"
#include "../../matched/include/Obj04582.h"
#include "../../matched/include/Obj01568.h"

extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *);
extern int *func_021FD73C(int *p, int v);
extern void func_021F86A4(int,int,char *);
extern void func_021F8EE8(char *,int *);
extern void func_021F8D5C(char *p, char *q);
extern void func_021F8E60(char *p, char *q);
extern void func_021F8EFC(char *,int *);
extern void func_021F8FB0(char *p, char *a1);
extern unsigned func_021FFE34(char *p);
extern void func_021F8790(int *task, unsigned *state, char *p);
extern void func_021F8F58(char *p, char *q);
extern void func_021F8F88(char *,int *);
extern void func_021FD860(void *,int,int *);
extern void func_021F8D18(char *,int *);
extern void func_021F8E90(char *,int *);
extern void func_021F86E4(int,int,char *);
void func_021F8950(int *sys,int *state,char *p);
void func_021F8A0C(int *sys,int *state,char *p);
void func_021F8AA8(int *sys,int *state,char *p);
void func_021F8B5C(int *task,int *state,char *p);

void func_021F8950(int *sys,int *state,char *p)
{
    switch(*state) {
    case 0:
        if(((struct Obj00278 *)p)->f20) func_021FE784(**(int * *)&((struct Obj00278 *)p)->f34,4,3,1);
        else func_021FE784(**(int * *)&((struct Obj00278 *)p)->f34,2,3,1);
        *state=1; break;
    case 1: if(func_021FE7B0(*(int **)*(int * *)&((struct Obj00278 *)p)->f34)) *state=2; break;
    case 2:
        func_021F8EE8(p,*(int * *)&((struct Obj00278 *)p)->f34);
        func_021F8D5C(p,(char *)(*(int * *)&((struct Obj00278 *)p)->f34));
        func_021F8E60(p,(char *)(*(int * *)&((struct Obj00278 *)p)->f34));
        func_021F8EFC(p,*(int * *)&((struct Obj00278 *)p)->f34);
        *state=3; break;
    case 3:
        if(((struct Obj00278 *)p)->f20) func_021FE784(**(int * *)&((struct Obj00278 *)p)->f34,4,3,0);
        else func_021FE784(**(int * *)&((struct Obj00278 *)p)->f34,2,3,0);
        *state=4; break;
    case 4: if(func_021FE7B0(*(int **)*(int * *)&((struct Obj00278 *)p)->f34)) *state=5; break;
    case 5: func_021FD73C(sys,(int)func_021F86A4); break;
    }
}

void func_021F8A0C(int *sys,int *state,char *p)
{
    switch(*state) {
    case 0: func_021FE784(**(int * *)&((struct Obj00278 *)p)->f34,2,3,1); *state=1; break;
    case 1: if(func_021FE7B0(*(int **)*(int * *)&((struct Obj00278 *)p)->f34)) *state=2; break;
    case 2: func_021F8FB0(p,(char *)(*(int * *)&((struct Obj00278 *)p)->f34)); func_021F8EFC(p,*(int * *)&((struct Obj00278 *)p)->f34); *state=3; break;
    case 3: if(func_021FFE34((char *)(*(int *)&((struct Obj00278 *)p)->f0))) {func_021FE784(**(int * *)&((struct Obj00278 *)p)->f34,2,3,0); *state=4;} break;
    case 4: if(func_021FE7B0(*(int **)*(int * *)&((struct Obj00278 *)p)->f34)) *state=5; break;
    case 5: func_021FD73C(sys,(int)func_021F86A4); break;
    }
}

void func_021F8AA8(int *sys,int *state,char *p)
{
    int pair[2];
    switch(*state) {
    case 0: func_021FE784(**(int * *)&((struct Obj04582 *)p)->f34,2,3,1); *state=1; break;
    case 1: if(func_021FE7B0(*(int **)*(int * *)&((struct Obj04582 *)p)->f34)) *state=2; break;
    case 2:
        func_021F8F58(p,(char *)(*(int * *)&((struct Obj04582 *)p)->f34));
        func_021F8F88(p,*(int * *)&((struct Obj04582 *)p)->f34);
        pair[0]=0x80;pair[1]=0x60;
        func_021FD860(((struct Obj04582 *)p)->f38,4,pair); *state=3; break;
    case 3: func_021FE784(**(int * *)&((struct Obj04582 *)p)->f34,2,3,0); *state=4; break;
    case 4: if(func_021FE7B0(*(int **)*(int * *)&((struct Obj04582 *)p)->f34)) *state=5; break;
    case 5: func_021FD73C(sys,(int)func_021F8790); break;
    }
}

/*
 * abi: 021F8BBC/021F8BD6 load r1 for func_021F8EE8, retained despite unused callee input.
 */
void func_021F8B5C(int *task,int *state,char *p)
{
    switch (*state) {
    case 0:
        if (((struct Obj01568 *)p)->f20) func_021FE784(**(int * *)&((struct Obj01568 *)p)->f34,1,1,1);
        else func_021FE784(**(int * *)&((struct Obj01568 *)p)->f34,2,1,1);
        *state=1;break;
    case 1: if (func_021FE7B0(*(int **)*(int * *)&((struct Obj01568 *)p)->f34)) *state=2;break;
    case 2:
        if (((struct Obj01568 *)p)->f20) {
            func_021F8EE8(p,*(int * *)&((struct Obj01568 *)p)->f34);
            func_021F8D5C(p,(char *)(*(int * *)&((struct Obj01568 *)p)->f34));
            func_021F8D18(p,*(int * *)&((struct Obj01568 *)p)->f34);
        } else {
            func_021F8EE8(p,*(int * *)&((struct Obj01568 *)p)->f34);
            func_021F8D5C(p,(char *)(*(int * *)&((struct Obj01568 *)p)->f34));
            func_021F8E90(p,*(int * *)&((struct Obj01568 *)p)->f34);
        }
        *state=3;break;
    case 3:
        if (((struct Obj01568 *)p)->f20) func_021FE784(**(int * *)&((struct Obj01568 *)p)->f34,1,1,0);
        else func_021FE784(**(int * *)&((struct Obj01568 *)p)->f34,2,1,0);
        *state=4;break;
    case 4: if (func_021FE7B0(*(int **)*(int * *)&((struct Obj01568 *)p)->f34)) *state=5;break;
    case 5: func_021FD73C(task,(int)func_021F86E4);break;
    }
}
