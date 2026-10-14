/*
 * function: BTLV_EFFVM_CmdNop5
 * address:  0x021FB524
 * packet:   pkt_ov094_021FB524
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command: no-op that skips 5 arguments.
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 */
#include "../include/Obj21665.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);

int BTLV_EFFVM_CmdNop5(void *a, char *s)
{
    VM_GetU32(a);
    VM_GetU32(a);
    VM_GetU32(a);
    VM_GetU32(a);
    VM_GetU32(a);
    return ((struct Obj21665 *)s)->f23C;
}
