/*
 * function: func_021F8EF8
 * address:  0x021F8EF8
 * packet:   pkt_ov094_021F8EF8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the current task's mask bits from bits 8..15 of the word at 0x1ec of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   TCBL_IsDeletePending 0x02030EE8 arm
 *   func_021F935C 0x021F935C thumb ov094
 */
typedef struct {
    char pad[0x1ec];
    unsigned m0 : 8;
    unsigned m1 : 8;
    unsigned m2 : 2;
} Work;

extern Work *d_0220AF20;
typedef unsigned int   u32;
struct S02030EE8;
extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);
extern int func_021F935C(int);

void func_021F8EF8(void *h)
{
    int m = func_021F935C(((int *)TCBL_IsDeletePending(h))[0]);
    d_0220AF20->m1 &= m ^ 0xffffffff;
}
