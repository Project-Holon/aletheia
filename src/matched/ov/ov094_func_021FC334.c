/*
 * function: BTLV_EFFVM_CmdJumpScript
 * address:  0x021FC334
 * packet:   pkt_ov094_021FC334
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command: jumps the reader by a relative offset.
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   VM_Jump 0x020113B0 thumb
 */
#include "../include/Obj00005.h"
#include "../include/Obj21682.h"
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
typedef unsigned int   u32;
struct Cur;
extern void VM_Jump(struct Cur *c, u32 v);

int BTLV_EFFVM_CmdJumpScript(struct Cursor *a, char *s)
{
    int off = VM_GetU32(a);
    VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + off);
    return ((struct Obj21682 *)s)->f23C;
}
