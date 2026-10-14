/*
 * function: BTLV_EFFVM_CmdStopSe
 * address:  0x021FBAD8
 * packet:   pkt_ov094_021FBAD8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the listing extent includes two bytes of trailing alignment padding.
 *
 * Script command: mode 5 calls GFL_USE_StopAllSe, any other mode is passed to
 * GFL_USE_StopSeSlot.
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   GFL_USE_StopSeSlot 0x020061F8 thumb
 */
#include "../include/Obj21673.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void GFL_USE_StopAllSe(void);
extern void GFL_USE_StopSeSlot(int i);

int BTLV_EFFVM_CmdStopSe(void *a, char *s)
{
    int r = VM_GetU32(a);

    if (r == 5)
        GFL_USE_StopAllSe();
    else
        GFL_USE_StopSeSlot(r);
    return ((struct Obj21673 *)s)->f23C;
}
