/*
 * function: BTLV_EFFVM_CmdSetPokeAnimIndex
 * address:  0x021FB390
 * packet:   pkt_ov094_021FB390
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command: when BTLV_MCSS_SetAnimIndexIfValid(x, y) reports 1, calls BTLV_MCSS_SetAnimPendingCallback(x).
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   BTLV_EFFECT_GetMcss 0x021F8694 thumb ov094
 *   BTLV_MCSS_SetAnimIndexIfValid 0x0220041C thumb ov094
 *   BTLV_MCSS_SetAnimPendingCallback 0x02200468 thumb ov094
 */
#include "../include/Obj21661.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int BTLV_EFFECT_GetMcss(void);
extern int BTLV_MCSS_SetAnimIndexIfValid(void *, int, int);
extern void BTLV_MCSS_SetAnimPendingCallback(void *, int);

int BTLV_EFFVM_CmdSetPokeAnimIndex(void *a, char *s)
{
    int x = VM_GetU32(a);
    int y = VM_GetU32(a);

    if (BTLV_MCSS_SetAnimIndexIfValid((void *)BTLV_EFFECT_GetMcss(), x, y) == 1)
        BTLV_MCSS_SetAnimPendingCallback((void *)BTLV_EFFECT_GetMcss(), x);
    return ((struct Obj21661 *)s)->f23C;
}
