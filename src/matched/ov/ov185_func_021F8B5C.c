/*
 * function: func_021F8B5C
 * address: 0x021F8B5C
 * packet: pkt_ov185_021F8B5C
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * abi: 021F8BBC/021F8BD6 load r1 for func_021F8EE8, retained despite unused callee input.
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021F8D18 0x021F8D18 thumb ov185
 *   func_021F8D5C 0x021F8D5C thumb ov185
 *   func_021F8E90 0x021F8E90 thumb ov185
 *   func_021F8EE8 0x021F8EE8 thumb ov185
 *   func_021F86E4 0x021F86E4 thumb ov185
 */
#include "../include/Obj01568.h"
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *);
extern void func_021FD73C(int *,int);
extern void func_021F8D18(char *,int *);
extern void func_021F8D5C(char *p, char *q);
extern void func_021F8E90(char *,int *);
extern void func_021F8EE8(char *,int *);
extern void func_021F86E4(int,int,char *);
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
