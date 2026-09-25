/*
 * function: func_021BA5D8
 * address:  0x021BA5D8
 * packet:   pkt_ov093_021BA5D8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CDDA0  0x021CDDA0  thumb  ov093
 */

extern int func_021CDDA0(int);

int func_021BA5D8(char *p)
{
    int *q = *(int **)p;
    if (*(unsigned char *)((char *)q + 0x23) == 0) {
        if (*(unsigned short *)(p + 0x440) != 0)
            return func_021CDDA0(*(int *)(p + (*(unsigned char *)(p + 0x46c) << 2) + 0x10));
        return 0;
    }
    return func_021CDDA0(*(int *)(p + (*(unsigned char *)(p + 0x46c) << 2) + 0x10));
}
