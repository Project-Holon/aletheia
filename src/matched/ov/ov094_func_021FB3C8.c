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
 *   VM_GetU32 0x0201134C thumb
 *   func_021F8010 0x021F8010 thumb ov094
 */
#include "../include/Obj21662.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void func_021F8010(int);

int func_021FB3C8(void *a, char *s)
{
    func_021F8010(VM_GetU32(a));
    return ((struct Obj21662 *)s)->f23C;
}
