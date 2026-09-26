/*
 * function: func_021F6898
 * address:  0x021F6898
 * packet:   pkt_021F6898
 * region:   ov094
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  register allocation only; all 12 relocations resolve (label and
 * sdk/arm).  The original keeps `a` in r0 and computes the inner element as
 * [r6(base), r0(index)] with a duplicated 4*i; mwcc here emits [r0, r6] and
 * picks a different register for the second loop's element pointer, so the
 * function is byte-different throughout despite identical logic.  No missing
 * witness; a matching C shape would be EXACT.
 *
 * symbols:
 *   func_0204762C  0x0204762C  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02047738  0x02047738  arm
 *   func_02047504  0x02047504  arm
 */

extern void func_0204762C(void *);
extern void func_02046EFC(void *);
extern void func_020307B0(void *);
extern void func_02047738(void *);
extern void func_02047504(void *);

void func_021F6898(char *s)
{
    int i, j;

    if (*(int *)(s + 4) != 0) {
        for (i = 0; i < *(int *)(s + 4); i++) {
            for (j = 0; j < 2; j++)
                func_0204762C(*(void **)(*(int *)(s + 0x14 + 4 * j) + 4 * i));
            func_02046EFC(*(void **)(*(int *)(s + 0x10) + 4 * i));
        }
        for (i = 0; i < 2; i++) {
            func_020307B0(*(void **)(s + 0x14 + 4 * i));
            func_020307B0(*(void **)(s + 8 + 4 * i));
        }
        func_020307B0(*(void **)(s + 0x10));
    }
    for (i = 0; i < 2; i++) {
        func_02047738(*(void **)(s + 0x24 + 4 * i));
        func_02047504(*(void **)(s + 0x1c + 4 * i));
    }
    func_02046EFC(*(void **)s);
    func_020307B0(*(void **)(*(int *)(s + 0xa8)));
    func_020307B0(*(void **)(s + 0xa8));
    func_020307B0(*(void **)(s + 0xa4));
    func_020307B0(s);
}
