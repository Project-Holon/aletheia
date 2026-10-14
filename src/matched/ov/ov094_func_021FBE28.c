/*
 * function: BTLV_EFFVM_CmdJumpIfPokeLoaded
 * address:  0x021FBE28
 * packet:   pkt_ov094_021FBE28
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: relative jump when BTLV_EFFECT_IsPokeSpriteLoaded(x) equals y.
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   BTLV_EFFECT_IsPokeSpriteLoaded 0x021F7F1C thumb ov094
 *   VM_Jump 0x020113B0 thumb
 */
#include "../include/Obj00005.h"
#include "../include/Obj21679.h"
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
extern int BTLV_EFFECT_IsPokeSpriteLoaded(int);
typedef unsigned int   u32;
struct Cur;
extern void VM_Jump(struct Cur *c, u32 v);

int BTLV_EFFVM_CmdJumpIfPokeLoaded(struct Cursor *a, char *s)
{
    int x = VM_GetU32(a);
    int y = VM_GetU32(a);
    int off = VM_GetU32(a);

    if (y == BTLV_EFFECT_IsPokeSpriteLoaded(x))
        VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + off);
    return ((struct Obj21679 *)s)->f23C;
}
