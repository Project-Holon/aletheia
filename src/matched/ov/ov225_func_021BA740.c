/*
 * function: MANUAL_COMMON_DeleteListWork
 * address:  0x021BA740
 * packet:   pkt_021BA740
 * region:   ov225
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj26178.h"

typedef unsigned int   u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void BG_SYS_ResetSlot(u32 index, u32 a, u32 b);
extern u32 func_020307B0(void *p);

void MANUAL_COMMON_DeleteListWork(char *p)
{
    func_02030EAC(((struct Obj26178 *)p)->f80);
    BG_SYS_ResetSlot(5, 3, 0);
    func_020307B0(p);
}
