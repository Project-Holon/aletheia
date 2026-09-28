/*
 * function: func_021F8FB0
 * address:  0x021F8FB0
 * packet:   pkt_ov185_021F8FB0
 * region:   ov185
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

void func_021F8FB0(char *p, char *a1)
{
    if (*(int *)(p + 4) != 0) {
        func_021FD15C(*(int *)(p + 4), *(int *)(a1 + 0xc));
        *(int *)(p + 4) = 0;
    }
}
