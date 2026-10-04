/*
 * function: func_021FBCEC
 * address:  0x021FBCEC
 * packet:   pkt_ov094_021FBCEC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: stores one argument at 0x240, waits on func_021FC744, and suspends.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_020113D0 0x020113D0 thumb
 *   func_021FC744 0x021FC744 thumb ov094
 */
#include "../include/Obj13592.h"
extern int func_0201134C(void *);
extern void func_020113D0(char *p, int val);
extern int func_021FC744(void *, void *);

int func_021FBCEC(void *a, char *s)
{
    ((struct Obj13592 *)s)->f240 = func_0201134C(a);
    func_020113D0(a, (int)func_021FC744);
    ((struct Obj13592 *)s)->f23C = 1;
    return 1;
}
