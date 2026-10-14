/*
 * function: BTLV_EFFVM_ClearLastEffect
 * address:  0x021F9AA4
 * packet:   pkt_ov094_021F9AA4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the two words at 0x2a4 and 0x2a8 of the owner's work.
 *
 * symbols:
 *   VM_GetUserData 0x02011324 thumb
 */
#include "../include/Obj13584.h"
struct ScriptVm;
extern void *VM_GetUserData(struct ScriptVm *vm);

void BTLV_EFFVM_ClearLastEffect(void *a)
{
    char *s = VM_GetUserData(a);
    ((struct Obj13584 *)s)->f2A4 = 0;
    ((struct Obj13584 *)s)->f2A8 = 0;
}
