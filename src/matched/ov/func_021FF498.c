/*
 * function: BTLV_MCSS_SetAnimSpeed
 * address:  0x021FF498
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MCSS_SetAnimeSpeed  0x020160C4  thumb
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 *
 * Byte-identical to the original; parked because the call to 0x020160C4
 * (an unlabelled ARM9 leaf, no traced label) has no witness outside the
 * compared range.  The call to 0x022019F4 is an ov094 Thumb function.
 */
#include "../include/Obj12220.h"


extern int  BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern void MCSS_SetAnimeSpeed(char *p, int v);

void BTLV_MCSS_SetAnimSpeed(char *p, int key, void *v)
{
    int i = BTLV_MCSS_FindSpriteIndex(p, key);
    char *e;

    if (i == -1)
        return;
    e = p + i * 0x5c;
    if (((struct Obj12220 *)e)->f8 == 0)
        return;
    MCSS_SetAnimeSpeed((char *)(((struct Obj12220 *)e)->f8), (int)v);
}

