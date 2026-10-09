/*
 * file:     unit_020746C4_p02.c
 * unit:     no
 * function: func_02074758
 * address:  0x02074758
 * packet:   pkt_020746E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

struct Obj;
extern void func_02074770(struct Obj *o);
extern void func_02061118(void *heap);

void func_02074758(void **a0)
{
    func_02074770((struct Obj *)a0);
    func_02061118(*a0);
}
