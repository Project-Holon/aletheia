/*
 * function: func_021F8EE8
 * address:  0x021F8EE8
 * packet:   pkt_021F8EE8
 * region:   ov185
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FD640  0x021FD640  thumb  ov186
 */

extern void func_021FD640(int *p);

void func_021F8EE8(char *p)
{
    if (*(int *)(p + 0x10) != 0) {
        func_021FD640((int *)(*(int *)(p + 0x10)));
        *(int *)(p + 0x10) = 0;
    }
}
