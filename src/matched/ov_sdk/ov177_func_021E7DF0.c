/*
 * function: WIFIBATTLEMATCH_VIEW_DeleteActorArray
 * address:  0x021E7DF0
 * packet:   pkt_021E7DF0
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   func_020307B0  0x020307B0  arm
 */

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void WIFIBATTLEMATCH_VIEW_DeleteActorArray(int *p)
{
    CLACT_DeleteActor((struct Obj *)(*(int *)((char *)p + 4)));
    CLACT_DeleteActor((struct Obj *)(*(int *)p));
    func_020307B0(p);
}
