/*
 * function: BTLV_EFFVM_CmdCopyPokeSpriteState
 * address:  0x021FBFA0
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFVM_CmdCopyPokeSpriteState   0x021FBFA0  thumb
 *   BTLV_EFFECT_GetMcss 0x021F8694 thumb ov094
 *   BTLV_MCSS_CopySpriteResources 0x02200140 thumb ov094

 *
 * lane O10 candidate
 */
#include "../include/Obj09236.h"

extern int  BTLV_EFFECT_GetMcss(void);
extern void BTLV_MCSS_CopySpriteResources(int a, int b, int c);

int BTLV_EFFVM_CmdCopyPokeSpriteState(int a, char *b)
{
    BTLV_MCSS_CopySpriteResources(BTLV_EFFECT_GetMcss(), ((struct Obj09236 *)b)->fE0, ((struct Obj09236 *)b)->fDC);
    return ((struct Obj09236 *)b)->f23C;
}

