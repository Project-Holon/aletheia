/*
 * unit: yes
 * function: func_021DB61C, func_021DB690
 * address: 0x021DB61C
 * packet: pkt_ov183_021DB61C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE794 0x021FE794 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FEE9C 0x021FEE9C thumb ov186
 *   func_021FEE4C 0x021FEE4C thumb ov186
 *   func_021F9BF4 0x021F9BF4 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DB690 0x021DB690 thumb ov183
 *   func_021FD744 0x021FD744 thumb ov186
 */
#include "../include/Obj06597.h"
#include "../include/Obj24535.h"
#include "../include/Obj24536.h"
#include "../include/Obj24537.h"
#include "../include/Obj24538.h"
#include "../include/Obj24539.h"
typedef unsigned int   u32;
extern void func_021FE794(char *p, u32 index, u32 a, u32 b, u32 c);
extern int func_021FE7B0(int *);
extern void func_021FEE9C(char *p);
extern void func_021FEE4C(char *p);
extern void func_021F9BF4(unsigned *ctx, unsigned index);
extern void func_021FD73C(int *p, int v);
extern void func_021DB690(int *);
extern int func_021FD744(int a);
void func_021DB61C(int *task, int *state, char *p)
{
    switch(*state) {
    case 0:
        func_021FE794((char *)(((struct Obj24535 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f8),2,3,1,1);
        *state=1;
        break;
    case 1:
        if(func_021FE7B0(*(int * *)&((struct Obj24536 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f8)) *state=2;
        break;
    case 2:
        func_021FEE9C((char *)(((struct Obj24537 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f14));
        func_021FEE4C((char *)(((struct Obj24538 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f14));
        func_021F9BF4((unsigned int *)(((struct Obj24539 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f10),1);
        func_021FD73C(task,(int)func_021DB690);
        break;
    }
}
void func_021DB690(int *task)
{
    func_021FD744((int)task);
}
