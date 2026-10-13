/*
 * function: BTL_MAIN_UpdateCommPlayerSupport
 * address:  0x021BA080
 * packet:   pkt_021BA080
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   COMM_PLAYER_SUPPORT_GetCurrent  0x0202E7DC  thumb
 *
 * blocker: target 0x0202E7DC has no `func_`/`sub_` label and no outside
 * branch, so the pool relocation cannot be witnessed.  All bytes correct.
 */
#include "../include/Obj20998.h"

char *COMM_PLAYER_SUPPORT_GetCurrent(char *p);

void BTL_MAIN_UpdateCommPlayerSupport(char **p)
{
    COMM_PLAYER_SUPPORT_GetCurrent((char *)(((struct Obj20998 *)(*p))->f70));
}
