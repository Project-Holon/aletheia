/*
 * function: func_021D6CA8
 * address:  0x021D6CA8
 * packet:   pkt_021D6CA8
 * region:   ov118
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */

extern void func_020307B0(void *);

void func_021D6CA8(void *p)
{
    void *q = *(void **)((char *)p + 0x85C);
    if (q != 0) {
        func_020307B0(q);
        *(void **)((char *)p + 0x85C) = 0;
    }
}
