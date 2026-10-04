/*
 * function: func_021FB500
 * address:  0x021FB500
 * packet:   pkt_ov094_021FB500
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: no-op that skips 4 arguments.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 */
#include "../include/Obj21664.h"
extern int func_0201134C(void *);

int func_021FB500(void *a, char *s)
{
    func_0201134C(a);
    func_0201134C(a);
    func_0201134C(a);
    func_0201134C(a);
    return ((struct Obj21664 *)s)->f23C;
}
