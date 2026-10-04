/*
 * function: func_021F8950
 * address: 0x021F8950
 * packet: pkt_ov185_021F8950
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021F86A4 0x021F86A4 thumb ov185
 *   func_021F8EE8 0x021F8EE8 thumb ov185
 *   func_021F8D5C 0x021F8D5C thumb ov185
 *   func_021F8E60 0x021F8E60 thumb ov185
 *   func_021F8EFC 0x021F8EFC thumb ov185
 */
#include "../include/Obj00278.h"
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *);
extern void func_021FD73C(int *,int);
extern void func_021F86A4(int,int,char *);
extern void func_021F8EE8(char *,int *);
extern void func_021F8D5C(char *,int *);
extern void func_021F8E60(char *,int *);
extern void func_021F8EFC(char *,int *);
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
        func_021F8D5C(p,*(int * *)&((struct Obj00278 *)p)->f34);
        func_021F8E60(p,*(int * *)&((struct Obj00278 *)p)->f34);
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
