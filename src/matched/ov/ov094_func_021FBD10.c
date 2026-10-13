/*
 * function: func_021FBD10
 * address:  0x021FBD10
 * packet:   pkt_ov094_021FBD10
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: stores one argument at 0x1e4, waits on func_021FC9D0, and suspends.
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   VM_SetWait 0x020113D0 thumb
 *   func_021FC9D0 0x021FC9D0 thumb ov094
 */
#include "../include/Obj13593.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void VM_SetWait(char *p, int val);
extern int func_021FC9D0(void *a, char *s);

int func_021FBD10(void *a, char *s)
{
    ((struct Obj13593 *)s)->f1E4 = VM_GetU32(a);
    VM_SetWait(a, (int)func_021FC9D0);
    ((struct Obj13593 *)s)->f23C = 1;
    return 1;
}
