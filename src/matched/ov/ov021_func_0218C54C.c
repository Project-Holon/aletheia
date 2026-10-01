/*
 * function: func_0218C54C
 * address:  0x0218C54C
 * packet:   pkt_ov021_0218C54C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    int f0;
    int f4;
    short f8;
    short fA;
    int *fC;
} S;

void func_0218C54C(S *p, int save)
{
    if (save) {
        *p->fC = p->f4;
        p->f4 = -1;
        p->fA = 1;
    } else {
        p->f4 = *p->fC;
        *p->fC = -1;
        p->fA = 0;
    }
}
