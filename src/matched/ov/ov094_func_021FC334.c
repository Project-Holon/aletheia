/*
 * function: func_021FC334
 * address:  0x021FC334
 * packet:   pkt_ov094_021FC334
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command: jumps the reader by a relative offset.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_020113B0 0x020113B0 thumb
 */
#include "../include/Obj00005.h"
#include "../include/Obj21682.h"
extern int func_0201134C(void *);
typedef unsigned int   u32;
struct Cur;
extern void func_020113B0(struct Cur *c, u32 v);

int func_021FC334(char *a, char *s)
{
    int off = func_0201134C(a);
    func_020113B0((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + off);
    return ((struct Obj21682 *)s)->f23C;
}
