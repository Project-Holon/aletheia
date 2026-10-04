/*
 * function: func_021FB3C8
 * address:  0x021FB3C8
 * packet:   pkt_ov094_021FB3C8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: passes one argument to func_021F8010.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F8010 0x021F8010 thumb ov094
 */
#include "../include/Obj21662.h"
extern int func_0201134C(void *);
extern void func_021F8010(int);

int func_021FB3C8(void *a, char *s)
{
    func_021F8010(func_0201134C(a));
    return ((struct Obj21662 *)s)->f23C;
}
