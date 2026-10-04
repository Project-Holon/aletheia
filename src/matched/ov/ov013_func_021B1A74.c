/*
 * function: func_021B1A74
 * address:  0x021B1A74
 * packet:   pkt_021B1A74
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021B2FE4  0x021B2FE4  arm  ov013
 *   func_021B1944  0x021B1944  arm  ov013
 */
#include "../include/Obj07348.h"

extern void func_021B2FE4(void *p);
typedef unsigned int   u32;
struct Node;
extern struct Node *func_021B1944(u32 t);

void func_021B1A74(char *p, int a1)
{
    if (((struct Obj07348 *)p)->f3C)
        func_021B2FE4(((struct Obj07348 *)p)->f3C);
    *(int *)&((struct Obj07348 *)p)->f3C = a1;
    func_021B1944((u32)(((struct Obj07348 *)p)->f34));
}
