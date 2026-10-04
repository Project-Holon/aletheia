/*
 * function: func_021FC134
 * address:  0x021FC134
 * packet:   pkt_ov094_021FC134
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: stores one argument at 0x25c of the state.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 */
#include "../include/Obj13596.h"
extern int func_0201134C(void *);

int func_021FC134(void *a, char *s)
{
    ((struct Obj13596 *)s)->f25C = func_0201134C(a);
    return ((struct Obj13596 *)s)->f23C;
}
