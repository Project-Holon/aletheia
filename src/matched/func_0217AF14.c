/*
 * function: func_0217AF14
 * address:  0x0217AF14
 * packet:   pkt_0217AF14
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E5534  0x021E5534  thumb  ov177
 *   func_021E5980  0x021E5980  thumb  ov177
 */

extern void func_021E5534(int);
extern void func_021E5980(int);

void func_0217AF14(int *p)
{
    if (*(int *)((char *)p + 0x24)) {
        func_021E5534(*(int *)((char *)p + 0x24));
        func_021E5980(*(int *)((char *)p + 0x20));
    }
}
