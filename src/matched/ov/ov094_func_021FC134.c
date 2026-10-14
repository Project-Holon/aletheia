/*
 * function: BTLV_EFFVM_CmdSetTypeSource
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
 *   VM_GetU32 0x0201134C thumb
 */
#include "../include/Obj13596.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);

int BTLV_EFFVM_CmdSetTypeSource(void *a, char *s)
{
    ((struct Obj13596 *)s)->f25C = VM_GetU32(a);
    return ((struct Obj13596 *)s)->f23C;
}
