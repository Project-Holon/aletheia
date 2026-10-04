/*
 * function: func_02155B00
 * address:  0x02155B00
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Flag test on the three-argument call.
 *
 * symbols:
 *   func_02155A80  0x02155A80  thumb  ov009
 */

extern int func_02155A80(void *src, int len, int c);

int func_02155B00(int a, int b)
{
    if (func_02155A80((void *)a, b, 3) != 0) {
        return 1;
    }

    return 0;
}

