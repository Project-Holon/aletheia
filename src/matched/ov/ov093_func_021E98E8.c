/*
 * function: func_021E98E8
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
 *   func_021E9738  0x021E9738  thumb  ov093
 *   func_021E9910  0x021E9910  thumb  ov093
 */
#include "../include/Obj21555.h"
extern int func_021E9738(void *p);
extern int func_021E9910(void *p);

int func_021E98E8(char *p)
{
    if (func_021E9738(p) != 0) {
        if (func_021E9910(((struct Obj21555 *)p)->f180) != 0) {
            return 1;
        }
        return 2;
    }
    return 0;
}
