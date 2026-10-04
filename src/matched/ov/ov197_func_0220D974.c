/*
 * function: func_0220D974
 * address:  0x0220D974
 * packet:   pkt_0220D974
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220AFDC 0x0220AFDC thumb ov196
 */

extern void func_0220AFDC(char *p, void *v);

void func_0220D974(char *a, int b)
{
    *(int *)(a + 0x598) = b;
    func_0220AFDC((char *)(*(int *)(a + 0x148)), (void *)b);
}