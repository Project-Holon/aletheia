/*
 * function: func_021BB308
 * address:  0x021BB308
 * packet:   pkt_021BB308
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26230.h"

struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_020307B0(void *);

void func_021BB308(char *p)
{
    func_02030EAC((struct Node *)(((struct Obj26230 *)p)->f14));
    func_020307B0(p);
}
