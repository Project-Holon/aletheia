/*
 * function: func_021F21F8
 * address: 0x021F21F8
 * packet: pkt_ov032_021F21F8
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020257D0 0x020257D0 thumb
 *   func_02031194 0x02031194 arm
 */
#include "../include/Obj07638.h"
#include "../include/Obj20455.h"
#include "../include/Obj20458.h"

typedef unsigned int u32;
struct Obj;
struct PrintSys;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_020257D0(struct Obj *o);
struct TcblNode;
extern void func_02031194(struct TcblNode *n);
void func_021F21F8(void *task, char *q)
{
    int *r;
    if (func_0201C6C4((struct PrintSys *)(((struct Obj20455 *)(*(char * *)&((struct Obj07638 *)q)->f8))->fB4), (void *)((*(u32 **)(q + 4))[1])) == 0) {
        func_020257D0((struct Obj *)(**(u32 * *)&((struct Obj07638 *)q)->f4));
        r = *(int * *)&((struct Obj07638 *)q)->fC;
        if (r != 0)
            (*r)--;
        ((struct Obj20458 *)(*(char * *)&((struct Obj07638 *)q)->f0))->f2C = 0;
        func_02031194(task);
    }
}
