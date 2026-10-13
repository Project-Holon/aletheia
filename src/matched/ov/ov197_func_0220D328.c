/*
 * function: func_0220D328
 * address: 0x0220D328
 * packet: pkt_ov197_0220D328
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: larger follower filed as ov197_func_0220D358.c (parent cleared).
 * symbols:
 *   func_0220D884 0x0220D884 thumb ov197
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 */
#include "../include/Obj25088.h"

typedef unsigned int u32;
extern int func_0220D884(char **);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
int func_0220D328(char *p)
{
    if (func_0220D884((char **)p) == 1) return 18;
    if ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg() == 1)
        return ((struct Obj25088 *)p)->f531;
    return 15;
}
