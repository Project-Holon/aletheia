/*
 * function: sub_0200BAF4
 * address:  0x0200BAF4
 * packet:   pkt_0200BAF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * packet line: 100 bytes, 7 of 7 relocations resolved by label
 *
 * Closed 2026-09-22 by tools/permuter.py (--mode anneal, 823 compiles).
 * The lever: the (a1 & 0x7fff) | 0x8000 mask is NOT a loop-invariant local
 * hoisted above the loop.  It is recomputed inside the loop body, after the
 * sub_02017E88 test result is bound to its own local.  Hoisting it (the
 * shape every earlier pass wrote) swaps r6 and r7 across the whole body:
 * five instructions, 5 concrete bytes out, which --explain reports as
 * r6->r7 x3 / r7->r6 x2.  Recomputing it inside gives the mask value the
 * later first-definition point the allocator needs to leave h in r6.
 *
 * `i` is u32, not int: the loop bound at +0x0058 is `blo`, not `blt`.
 * The failing test `break`s out of the loop (beq to the epilogue at
 * +0x005A), it does not `continue`.
 *
 * symbols:
 *   sub_0201747C   0x0201747C  thumb
 *   sub_02017E88   0x02017E88  thumb
 *   sub_0201A920   0x0201A920  thumb
 *   sub_0201A954   0x0201A954  thumb
 *   sub_0201A98C   0x0201A98C  thumb
 *   sub_0200BBEC   0x0200BBEC  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *sub_0201A920(int a);
extern void  sub_0201A954(void *h, int a);
extern void  sub_0201A98C(void *h, void *p);
extern int   sub_02017E88(void *p, int a, int b);
extern void *sub_0201747C(void *p, u32 v);
extern void *sub_0200BBEC(int a, int b, int c);
extern void  func_020307B0(void *p);

void *sub_0200BAF4(int a0, int a1)
{
    void *h;
    u32 i;

    h = sub_0201A920(a1);
    sub_0201A954(h, 6);
    for (i = 0; i < 6; i++) {
        void *p = sub_0200BBEC(a0, 0, i);
        int ok = sub_02017E88(p, 0xa9, 0);
        int v  = (a1 & 0x7fff) | 0x8000;

        if (ok == 0) {
            break;
        }
        p = sub_0201747C(p, (u16)v);
        sub_0201A98C(h, p);
        func_020307B0(p);
    }
    return h;
}
