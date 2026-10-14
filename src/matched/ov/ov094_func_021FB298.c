/*
 * function: BTLV_EFFVM_CmdDeletePokeSprites
 * address:  0x021FB298
 * packet:   pkt_ov094_021FB298
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: runs BTLV_EFFECT_DeletePokeSprite on each id listed by BTLV_EFFVM_ResolveBattlerList.
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   BTLV_EFFVM_ResolveBattlerList 0x021FCA04 thumb ov094
 *   BTLV_EFFECT_DeletePokeSprite 0x021F7F04 thumb ov094
 */
#include "../include/Obj00177.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int BTLV_EFFVM_ResolveBattlerList(char *, int, int *);
extern void BTLV_EFFECT_DeletePokeSprite(int);

int BTLV_EFFVM_CmdDeletePokeSprites(void *a, char *s)
{
    int ids[8];
    int n;
    int i;

    n = BTLV_EFFVM_ResolveBattlerList(s, VM_GetU32(a), ids);
    if (n != 0) {
        for (i = 0; i < n; i++)
            BTLV_EFFECT_DeletePokeSprite(ids[i]);
    }
    return ((struct Obj00177 *)s)->f23C;
}
