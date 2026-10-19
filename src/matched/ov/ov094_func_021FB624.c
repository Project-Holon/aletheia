/*
 * function: BTLV_EFFVM_CmdSetStageLayerHidden
 * address:  0x021FB624
 * packet:   pkt_ov094_021FB624
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command: passes two arguments to BTLV_EFFECT_SetStageLayerHidden.
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   BTLV_EFFECT_SetStageLayerHidden 0x021F839C thumb ov094
 */
#include "../include/Obj21667.h"
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
typedef unsigned int   u32;
extern void BTLV_EFFECT_SetStageLayerHidden(u32 a, u32 b);

int BTLV_EFFVM_CmdSetStageLayerHidden(void *a, char *s)
{
    int x = VM_GetU32(a);
    BTLV_EFFECT_SetStageLayerHidden(x, VM_GetU32(a));
    return ((struct Obj21667 *)s)->f23C;
}
