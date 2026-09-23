/*
 * function: func_020314F4
 * address:  0x020314F4
 * packet:   pkt_020314F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02031538  0x02031538  arm
 *
 * procsys.c: queue a call for the process at obj, or start it now.  When
 * the +8 node already exists the three parameters are parked at +0x14..
 * +0x1C with the pending flag at +0xC; otherwise the node is built with
 * the object's own u16 head as the heap id.
 *
 * The earlier DIFF (72 against 68, docs/notes/pkt_020314F4.c.txt) was the
 * polarity, not a predication threshold: written `== 0` with the call
 * first and the stores in the else arm, the compiler predicates the else
 * arm (movne, four strne, popne) and places it ahead of the call.
 */

typedef unsigned int u32;
typedef unsigned short u16;

struct Obj020314F4 {
    u16 f00;
    u16 pad02;
    u32 pad04;
    void *buffer;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
};

extern void *func_02031538(u32 a0, u32 a1, u32 a2, u32 heap);

void func_020314F4(struct Obj020314F4 *obj, u32 a1, u32 a2, u32 a3)
{
    if (obj->buffer == 0) {
        obj->buffer = func_02031538(a1, a2, a3, obj->f00);
    } else {
        obj->f0c = 1;
        obj->f14 = a1;
        obj->f18 = a2;
        obj->f1c = a3;
    }
}
