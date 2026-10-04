/*
 * function: func_021FBE60
 * address:  0x021FBE60
 * packet:   pkt_ov094_021FBE60
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: stores one argument at 4 of the state.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 */
#include "../include/Obj13594.h"
extern int func_0201134C(void *);

int func_021FBE60(void *a, char *s)
{
    ((struct Obj13594 *)s)->f4 = func_0201134C(a);
    return ((struct Obj13594 *)s)->f23C;
}
