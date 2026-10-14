/*
 * function: BTLV_EFFVM_CmdSetScriptVar
 * address:  0x021FBE60
 * packet:   pkt_ov094_021FBE60
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command: stores one argument at 4 of the state.
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 */
#include "../include/Obj13594.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);

int BTLV_EFFVM_CmdSetScriptVar(void *a, char *s)
{
    ((struct Obj13594 *)s)->f4 = VM_GetU32(a);
    return ((struct Obj13594 *)s)->f23C;
}
