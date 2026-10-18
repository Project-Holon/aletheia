/*
 * function: B_BAG_MAIN_StateMessageDone
 * address: 0x0220D328
 * packet: pkt_ov197_0220D328
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: larger follower filed as B_BAG_MAIN_StateWaitKey.c (parent cleared).
 * symbols:
 *   B_BAG_MAIN_CheckCancel 0x0220D884 thumb ov197
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 */
#include "../include/Obj25088.h"

typedef unsigned int u32;
extern int B_BAG_MAIN_CheckCancel(char **);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
int B_BAG_MAIN_StateMessageDone(char *p)
{
    if (B_BAG_MAIN_CheckCancel((char **)p) == 1) return 18;
    if ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg() == 1)
        return ((struct Obj25088 *)p)->f531;
    return 15;
}
