/*
 * function: BTLV_CORE_PollActionMenu
 * address:  0x021E97A4
 * packet:   pkt_ov093_021E97A4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_CORE_RunStep  0x021E9738  thumb  ov093
 */
#include "../include/Obj21552.h"
struct S;
extern int BTLV_CORE_RunStep(struct S *s);

int BTLV_CORE_PollActionMenu(char *p)
{
    if (BTLV_CORE_RunStep((struct S *)p) != 0) {
        return ((struct Obj21552 *)p)->fC4;
    }
    return 0;
}
