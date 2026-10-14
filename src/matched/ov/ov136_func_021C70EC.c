/*
 * function: MB_SEQ_StateCloseButtonDone
 * address:  0x021C70EC
 * packet:   pkt_ov136_021C70EC
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_IsActorAnimActive   0x0204B98C  arm
 */
#include "../include/Obj10609.h"
#include "../include/Obj23632.h"
#include "../include/Obj23633.h"

typedef unsigned char u8;
typedef unsigned int u32;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
int MB_SEQ_StateCloseButtonDone(u8 *p)
{
    if (CLACT_IsActorAnimActive(((struct Obj23632 *)(*(u8 * *)&((struct Obj10609 *)p)->f8))->f20C) == 0) {
        ((struct Obj23633 *)(*(u8 * *)&((struct Obj10609 *)p)->f4))->f4 = 1;
        return ((struct Obj10609 *)p)->f28;
    }
    return 0x19;
}
