/*
 * function: func_021FBD34
 * address:  0x021FBD34
 * packet:   pkt_ov094_021FBD34
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: stores one argument at 0x23c of the state.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 */
#include "../include/Obj21675.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 func_0201134C(struct Cursor *p);

void func_021FBD34(void *a, char *s)
{
    ((struct Obj21675 *)s)->f23C = func_0201134C(a);
}
