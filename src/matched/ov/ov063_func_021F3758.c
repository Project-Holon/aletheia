/*
 * function: RAIL_SLIPDOWN_Delete
 * address:  0x021F3758
 * packet:   pkt_021F3758
 * region:   ov063
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj20594.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Node;
extern void func_02030EAC(struct Node *n);
extern u32 func_020307B0(void *p);

void RAIL_SLIPDOWN_Delete(u8 *p)
{
    func_02030EAC((struct Node *)(((struct Obj20594 *)p)->f80));
    func_020307B0((void *)((u32)p));
}
