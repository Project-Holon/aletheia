/*
 * function: BTLV_EFFVM_CmdWaitFrames
 * address:  0x021FBCEC
 * packet:   pkt_ov094_021FBCEC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: stores one argument at 0x240, waits on BTLV_EFFVM_IsAllIdle, and suspends.
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   VM_SetWait 0x020113D0 thumb
 *   BTLV_EFFVM_IsAllIdle 0x021FC744 thumb ov094
 */
#include "../include/Obj13592.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void VM_SetWait(char *p, int val);
extern int BTLV_EFFVM_IsAllIdle(void *, void *);

int BTLV_EFFVM_CmdWaitFrames(void *a, char *s)
{
    ((struct Obj13592 *)s)->f240 = VM_GetU32(a);
    VM_SetWait(a, (int)BTLV_EFFVM_IsAllIdle);
    ((struct Obj13592 *)s)->f23C = 1;
    return 1;
}
