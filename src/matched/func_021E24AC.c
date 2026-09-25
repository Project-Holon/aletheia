/*
 * function: func_021E24AC
 * address:  0x021E24AC
 * packet:   pkt_021E24AC
 * region:   ov183
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FD15C  0x021FD15C  thumb  ov186
 */

extern void func_021FD15C(int, int);

void func_021E24AC(char *p, char *a1)
{
    if (*(int *)(p + 4) != 0) {
        func_021FD15C(*(int *)(p + 4), *(int *)(a1 + 0xc));
        *(int *)(p + 4) = 0;
    }
}
