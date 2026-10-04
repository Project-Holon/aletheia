/*
 * function: func_021FBE74
 * address:  0x021FBE74
 * packet:   pkt_ov094_021FBE74
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: stores func_021FDBB0(s, arg) at 4 of the state.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021FDBB0 0x021FDBB0 thumb ov094
 */
#include "../include/Obj13595.h"
extern int func_0201134C(void *);
extern int func_021FDBB0(char *, int);

int func_021FBE74(void *a, char *s)
{
    ((struct Obj13595 *)s)->f4 = func_021FDBB0(s, func_0201134C(a));
    return ((struct Obj13595 *)s)->f23C;
}
