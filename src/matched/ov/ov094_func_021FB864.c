/*
 * function: BTLV_EFFVM_CmdSetClactAnim
 * address:  0x021FB864
 * packet:   pkt_ov094_021FB864
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command: passes slot arg of the table at 0xcc and a value to BTLV_CLACT_SetActorAnimSeq.
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   BTLV_EFFECT_GetClact 0x021F86F0 thumb ov094
 *   BTLV_CLACT_SetActorAnimSeq 0x02201DA0 thumb ov094
 */
#include "../include/Obj13589.h"
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
extern int BTLV_EFFECT_GetClact(void);
typedef unsigned int   u32;
extern u32 BTLV_CLACT_SetActorAnimSeq(char *p, int i, int v);

int BTLV_EFFVM_CmdSetClactAnim(void *a, char *s)
{
    int i = VM_GetU32(a);
    int x = VM_GetU32(a);

    BTLV_CLACT_SetActorAnimSeq((char *)BTLV_EFFECT_GetClact(), ((int *)(s + 0xcc))[i], x);
    return ((struct Obj13589 *)s)->f23C;
}
