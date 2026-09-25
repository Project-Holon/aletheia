/*
 * function: func_021EF1D8
 * address:  0x021EF1D8
 * packet:   pkt_021EF1D8
 * region:   ov188
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 */

extern void func_02082D44(void *, void *, int);

int func_021EF1D8(char *p, char *a1)
{
    int v = *(int *)(a1 + 0x34);

    *(int *)(p + 0x98) = v;
    func_02082D44(a1 + 0x38, *(void **)(p + 0x94), v);
    return 1;
}
