/*
 * function: func_021DBCF4
 * address: 0x021DBCF4
 * packet: pkt_ov183_021DBCF4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DBD40 0x021DBD40 thumb ov183
 */
#include "../include/Obj14422.h"
#include "../include/Obj24547.h"
#include "../include/Obj24548.h"
extern void BR_FADE_Start(int,int,int,int);
extern int BR_FADE_GetResult(int *);
extern int *func_021FD73C(int *p, int v);
extern void func_021DBD40(int *task, int b, char *p);
void func_021DBCF4(int *task, int *state, char *p)
{
    switch(*state) {
    case 0:
        BR_FADE_Start(((struct Obj24547 *)(*(char * *)&((struct Obj14422 *)p)->fD0))->fC,2,3,1);
        *state=1;
        break;
    case 1:
        if(BR_FADE_GetResult(*(int * *)&((struct Obj24548 *)(*(char * *)&((struct Obj14422 *)p)->fD0))->fC)) *state=2;
        break;
    case 2:
        func_021FD73C(task,(int)func_021DBD40);
        break;
    }
}
