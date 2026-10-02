/*
 * function: func_021F8C78
 * address:  0x021F8C78
 * packet:   pkt_ov094_021F8C78
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the current task's mask bits from the low byte at 0x1ec of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_02030EE8 0x02030EE8 arm
 *   func_021F935C 0x021F935C thumb ov094
 */
typedef struct {
    char pad[0x1ec];
    unsigned m : 8;
    unsigned lo : 10;
    unsigned v : 8;
    unsigned b26 : 1;
} Work;

extern Work *d_0220AF20;
extern int *func_02030EE8(void *h);
extern int func_021F935C(int);

void func_021F8C78(void *h)
{
    int m = func_021F935C(*func_02030EE8(h));
    d_0220AF20->m &= m ^ 0xffffffff;
}
