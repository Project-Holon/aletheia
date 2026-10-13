/*
 * function: func_021FBE74
 * address:  0x021FBE74
 * packet:   pkt_ov094_021FBE74
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command: stores func_021FDBB0(s, arg) at 4 of the state.
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   func_021FDBB0 0x021FDBB0 thumb ov094
 */
#include "../include/Obj13595.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int func_021FDBB0(char *, int);

int func_021FBE74(void *a, char *s)
{
    ((struct Obj13595 *)s)->f4 = func_021FDBB0(s, VM_GetU32(a));
    return ((struct Obj13595 *)s)->f23C;
}
