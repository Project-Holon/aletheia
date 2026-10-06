/*
 * function: func_021DCF30
 * address:  0x021DCF30
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * lane O46
 */
#include "../include/Obj00000.h"


struct TaskMenuState;
struct U16Vec;
typedef unsigned int   u32;
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_02045808(struct U16Vec *vec);
void func_021DCF30(char *p)
{
    func_02027FD8((struct TaskMenuState *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x19C)));
    func_02045808((struct U16Vec *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x190)));
    func_02045808((struct U16Vec *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x184)));
}
