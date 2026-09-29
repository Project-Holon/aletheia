/*
 * function: func_021B1AC0
 * address:  0x021B1AC0
 * packet:   pkt_ov013_021B1AC0
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * RFC 3550 update_seq shape: MAX_DROPOUT 3000, MAX_MISORDER 100.
 *
 * symbols:
 *   func_021B1AA0  0x021B1AA0  arm  ov013
 */

extern void func_021B1AA0(char *p, unsigned short v);

int func_021B1AC0(char *p, char *pkt, unsigned short seq)
{
    unsigned short last = *(unsigned short *)(p + 0x68);
    unsigned short delta = seq - last;

    if (delta < 3000) {
        if (seq < last)
            *(unsigned int *)(p + 0x60) += 0x10000;
        *(unsigned short *)(p + 0x68) = seq;
    } else if (delta <= 0x10000 - 100) {
        if (seq == *(unsigned int *)(p + 0x64)) {
            func_021B1AA0(p, seq);
            *(unsigned int *)(p + 0x54) = (unsigned short)(seq - 1);
        } else {
            *(unsigned int *)(p + 0x64) = (unsigned short)(seq + 1);
            return 0;
        }
    } else if (seq + *(unsigned int *)(p + 0x60) > *(unsigned int *)(p + 0x54) + 0x10000 - 100) {
        *(unsigned int *)(pkt + 0x18) = seq + *(unsigned int *)(p + 0x60) - 0x10000;
        return 1;
    }
    *(unsigned int *)(pkt + 0x18) = seq + *(unsigned int *)(p + 0x60);
    return 1;
}
