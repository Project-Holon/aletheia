/*
 * function: func_021C70C0
 * address:  0x021C70C0
 * packet:   pkt_ov136_021C70C0
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_IsActorAnimActive   0x0204B98C  arm
 *   func_021C66A0 0x021C66A0 thumb
 */
#include "../include/Obj08207.h"
#include "../include/Obj23630.h"
#include "../include/Obj23631.h"

typedef unsigned char u8;
typedef unsigned int u32;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void func_021C66A0(u8 *p, int i, u32 v);
int func_021C70C0(u8 *p)
{
    if (CLACT_IsActorAnimActive(((struct Obj23630 *)(*(u8 * *)&((struct Obj08207 *)p)->f8))->f1FC) == 0) {
        ((struct Obj23631 *)(*(u8 * *)&((struct Obj08207 *)p)->f4))->f4 = 0;
        func_021C66A0(*(u8 * *)&((struct Obj08207 *)p)->f8, 7, 0);
        return ((struct Obj08207 *)p)->f28;
    }
    return 0x18;
}
