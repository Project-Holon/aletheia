/*
 * function: func_0217ED38
 * address:  0x0217ED38
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The word the call fills in, or -1.
 *
 * symbols:
 *   SOC_InetAtoN  0x0215FAD0  arm  ov009
 */

extern int SOC_InetAtoN(char *cp, unsigned long *inp);

int func_0217ED38(int a)
{
    int v;

    if (SOC_InetAtoN((char *)a, (long unsigned int *)(&v)) == 0) {
        return -1;
    }

    return v;
}

