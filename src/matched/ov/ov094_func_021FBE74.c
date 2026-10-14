/*
 * function: BTLV_EFFVM_CmdEvalCondition
 * address:  0x021FBE74
 * packet:   pkt_ov094_021FBE74
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command: stores BTLV_EFFVM_EvalCondition(s, arg) at 4 of the state.
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   BTLV_EFFVM_EvalCondition 0x021FDBB0 thumb ov094
 */
#include "../include/Obj13595.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int BTLV_EFFVM_EvalCondition(char *, int);

int BTLV_EFFVM_CmdEvalCondition(void *a, char *s)
{
    ((struct Obj13595 *)s)->f4 = BTLV_EFFVM_EvalCondition(s, VM_GetU32(a));
    return ((struct Obj13595 *)s)->f23C;
}
