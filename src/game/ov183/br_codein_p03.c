/*
 * file:     br_codein_p03.c
 * unit:     yes
 * function: func_021DBCA8, func_021DBCF4
 * address:  0x021DBCA8
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
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DBD7C 0x021DBD7C thumb ov183
 *   func_021DBD40 0x021DBD40 thumb ov183
 */
#include "../../matched/include/Obj14421.h"
#include "../../matched/include/Obj24545.h"
#include "../../matched/include/Obj24546.h"
#include "../../matched/include/Obj14422.h"
#include "../../matched/include/Obj24547.h"
#include "../../matched/include/Obj24548.h"

extern void func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *);
extern int *func_021FD73C(int *p, int v);
extern void func_021DBD7C(int *task, int *state, char *p);
extern void func_021DBD40(int *task, int b, char *p);
void func_021DBCA8(int *task, int *state, char *p);
void func_021DBCF4(int *task, int *state, char *p);

void func_021DBCA8(int *task, int *state, char *p)
{
    switch(*state) {
    case 0:
        func_021FE784(((struct Obj24545 *)(*(char * *)&((struct Obj14421 *)p)->fD0))->fC,2,3,0);
        *state=1;
        break;
    case 1:
        if(func_021FE7B0(*(int * *)&((struct Obj24546 *)(*(char * *)&((struct Obj14421 *)p)->fD0))->fC)) *state=2;
        break;
    case 2:
        func_021FD73C(task,(int)func_021DBD7C);
        break;
    }
}

void func_021DBCF4(int *task, int *state, char *p)
{
    switch(*state) {
    case 0:
        func_021FE784(((struct Obj24547 *)(*(char * *)&((struct Obj14422 *)p)->fD0))->fC,2,3,1);
        *state=1;
        break;
    case 1:
        if(func_021FE7B0(*(int * *)&((struct Obj24548 *)(*(char * *)&((struct Obj14422 *)p)->fD0))->fC)) *state=2;
        break;
    case 2:
        func_021FD73C(task,(int)func_021DBD40);
        break;
    }
}
