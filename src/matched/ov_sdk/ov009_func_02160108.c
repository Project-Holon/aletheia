/*
 * function: CPS_SetRootCa
 * address:  0x02160108
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Hands a and b to the +0xc child of the object at +0xa4 as its +0x814 and
 * +0x818 words.
 *
 * symbols:
 *   gMslRefToken  0x02150FEC  data

 */

extern char gMslRefToken[];

void CPS_SetRootCa(int a, int b)
{
    char *p = *(char **)(*(char **)(gMslRefToken + 4) + 0xa4);
    char *q;

    if (p != 0 && (q = *(char **)(p + 0xc)) != 0) {
        *(int *)(q + 0x814) = a;
        *(int *)(q + 0x818) = b;
    }
}


