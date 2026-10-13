/*
 * unit:     no
 * function: NNS_SndHeapDestroy
 * address:  0x02074758
 * packet:   pkt_020746E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_SndHeapClear  0x02074770  arm
 */

struct Obj;
extern void NNS_SndHeapClear(struct Obj *o);
extern void func_02061118(void *heap);

void NNS_SndHeapDestroy(void **a0)
{
    NNS_SndHeapClear((struct Obj *)a0);
    func_02061118(*a0);
}
