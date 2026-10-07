/*
 * function: func_021F3858
 * address:  0x021F3858
 * packet:   pkt_021F3858
 * region:   ov057
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02047A60  0x02047A60  arm
 *   d_021F38C4     0x021F38C4  data
 */
#include "../../../matched/include/Obj09853.h"

struct Arg;
extern void func_02047A60(void *a0, struct Arg *a1);
extern int d_021F38C4;

void func_021F3858(int a, int b, char *c)
{
    func_02047A60(((struct Obj09853 *)c)->f38, (struct Arg *)(&d_021F38C4));
    func_02047A60(((struct Obj09853 *)c)->f3C, (struct Arg *)(&d_021F38C4));
    func_02047A60(((struct Obj09853 *)c)->f40, (struct Arg *)(&d_021F38C4));
}
