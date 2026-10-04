/*
 * function: func_021F015C
 * address:  0x021F015C
 * packet:   pkt_021F015C
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F015C 0x021F015C thumb
 *   func_02027FD8 0x02027FD8 thumb
 */
#include "../include/Obj20481.h"

struct TaskMenuState;
extern void func_02027FD8(struct TaskMenuState *s);

void func_021F015C(char *p)
{
    func_02027FD8((struct TaskMenuState *)(((struct Obj20481 *)p)->f40));
}
