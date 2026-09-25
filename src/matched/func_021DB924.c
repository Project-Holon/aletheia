/*
 * function: func_021DB924
 * address:  0x021DB924
 * packet:   pkt_021DB924
 * region:   ov183
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FC240  0x021FC240  thumb  ov186
 */

extern void func_021FC240(int, int, int);

void func_021DB924(int a0, char *p)
{
    int v = *(int *)(p + 0x10);
    char *q = *(char **)(p + 0xc);

    if (v == 0) {
        func_021FC240(*(int *)(q + 0x18), *(int *)(q + 0x10),
                      *(unsigned short *)(p + 0x14));
    }
    *(int *)(p + 0x10) = 1;
}
