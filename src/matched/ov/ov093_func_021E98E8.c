/*
 * function: BTLV_CORE_PollTargetMenu
 * address:  0x021E98E8
 * packet:   pkt_ov093_021E98E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_CORE_RunStep  0x021E9738  thumb  ov093
 *   func_021E9910  0x021E9910  thumb  ov093
 */
#include "../include/Obj21555.h"
struct S;
extern int BTLV_CORE_RunStep(struct S *s);
extern int func_021E9910(void *p);

int BTLV_CORE_PollTargetMenu(char *p)
{
    if (BTLV_CORE_RunStep((struct S *)p) != 0) {
        if (func_021E9910(((struct Obj21555 *)p)->f180) != 0) {
            return 1;
        }
        return 2;
    }
    return 0;
}
