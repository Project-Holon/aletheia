/*
 * function: func_021D893C
 * address:  0x021D893C
 * packet:   pkt_021D893C
 * region:   ov129
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02021D50  0x02021D50  thumb
 *   func_0204A648  0x0204A648  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23114.h"

struct S02021D50;
extern void func_02021D50(struct S02021D50 *p);
extern void func_0204A648(void);

void func_021D893C(int a, char *p)
{
    func_02021D50((struct S02021D50 *)(((struct Obj23114 *)p)->f290));
    func_0204A648();
}
