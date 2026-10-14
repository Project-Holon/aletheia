/*
 * function: BTLV_EFFVM_CmdSetPokeSpriteAnimMode
 * address:  0x021FC434
 * packet:   pkt_ov094_021FC434
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: passes one argument to BTLV_EFFECT_SetAllPokeSpriteAnim.
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   BTLV_EFFECT_SetAllPokeSpriteAnim 0x021F8934 thumb ov094
 */
#include "../include/Obj21684.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void BTLV_EFFECT_SetAllPokeSpriteAnim(int);

int BTLV_EFFVM_CmdSetPokeSpriteAnimMode(void *a, char *s)
{
    BTLV_EFFECT_SetAllPokeSpriteAnim(VM_GetU32(a));
    return ((struct Obj21684 *)s)->f23C;
}
