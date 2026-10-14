/*
 * function: BTLV_EFFVM_StopScript
 * address:  0x021F97E4
 * packet:   pkt_ov094_021F97E4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Releases the owner's buffer at 0x1e8 after BTLV_EFFVM_ReleaseScriptResources.
 *
 * symbols:
 *   VM_GetUserData 0x02011324 thumb
 *   BTLV_EFFVM_ReleaseScriptResources 0x021FC448 thumb ov094
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10136.h"
struct ScriptVm;
extern void *VM_GetUserData(struct ScriptVm *vm);
extern void BTLV_EFFVM_ReleaseScriptResources(void *, char *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void BTLV_EFFVM_StopScript(void *a)
{
    char *s = VM_GetUserData(a);

    if (((struct Obj10136 *)s)->f1E8 != 0) {
        BTLV_EFFVM_ReleaseScriptResources(a, VM_GetUserData(a));
        func_020307B0(((struct Obj10136 *)s)->f1E8);
        ((struct Obj10136 *)s)->f1E8 = 0;
    }
}
