/*
 * function: BTLV_EFFVM_CmdWaitForTask
 * address:  0x021FC354
 * packet:   pkt_ov094_021FC354
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: sets flag bit 7, waits on BTLV_EFFVM_WaitTaskCallback, and suspends.
 *
 * symbols:
 *   VM_SetWait 0x020113D0 thumb
 *   BTLV_EFFVM_WaitTaskCallback 0x021FC9E4 thumb ov094
 */
#include "../include/Obj13597.h"
extern void VM_SetWait(char *p, int val);
extern int BTLV_EFFVM_WaitTaskCallback(void *, void *);

int BTLV_EFFVM_CmdWaitForTask(void *a, char *s)
{
    ((struct Obj13597 *)s)->f0 |= 0x80;
    VM_SetWait(a, (int)BTLV_EFFVM_WaitTaskCallback);
    ((struct Obj13597 *)s)->f23C = 1;
    return 1;
}
