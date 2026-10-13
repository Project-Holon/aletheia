/*
 * function: func_021FC5A0
 * address:  0x021FC5A0
 * packet:   pkt_021FC5A0
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_021F9664  0x021F9664  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14122.h"
#include "../include/Obj23263.h"

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void func_021F9664(char *p, int a);

int func_021FC5A0(int a, char **pp)
{
    char *p = *pp;
    int x = VM_GetU32((struct Cursor *)(((struct Obj14122 *)pp)->f4));

    func_021F9664(((struct Obj23263 *)p)->f34, (unsigned short)x);
    return 0;
}
