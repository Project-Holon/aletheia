/*
 * function: func_021FC634
 * address:  0x021FC634
 * packet:   pkt_021FC634
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STA_ACTING_StopBgm  0x021F96C4  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23270.h"

extern void STA_ACTING_StopBgm(char *p);

int func_021FC634(int a, char **pp)
{
    STA_ACTING_StopBgm(((struct Obj23270 *)(*pp))->f34);
    return 0;
}
