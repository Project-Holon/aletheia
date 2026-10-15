/*
 * function: MANUAL_COMMON_DeleteDialog
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
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void MANUAL_COMMON_DeleteDialog(char *p)
{
    func_02030EAC((struct Node *)(((struct Obj26230 *)p)->f14));
    func_020307B0(p);
}
