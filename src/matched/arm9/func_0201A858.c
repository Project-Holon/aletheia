/*
 * function: func_0201A858
 * address:  0x0201A858
 * packet:   pkt_0201A858
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A base-7 odometer with a distinctness test: six nested counters (a[0]
 * outermost) over 0..6, and the innermost body returns 1 as soon as all six
 * values differ.  The entry `a[5]++` is the source's own first statement, not
 * a loop increment.
 *
 * The fifteen `!=` tests are one conjunction: every `cmp` in the listing
 * branches to the same increment block (0x0201A8B8) on equality, which is the
 * "guard chain sharing one exit block" spelling, not a chain of ifs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A858.c \
 *       --func func_0201A858 --addr 0x0201A858 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;

int func_0201A858(u8 *a)
{
    a[5]++;
    while (a[0] <= 6) {
        while (a[1] <= 6) {
            while (a[2] <= 6) {
                while (a[3] <= 6) {
                    while (a[4] <= 6) {
                        while (a[5] <= 6) {
                            if (a[0] != a[1] && a[0] != a[2] &&
                                a[0] != a[3] && a[0] != a[4] &&
                                a[0] != a[5] && a[1] != a[2] &&
                                a[1] != a[3] && a[1] != a[4] &&
                                a[1] != a[5] && a[2] != a[3] &&
                                a[2] != a[4] && a[2] != a[5] &&
                                a[3] != a[4] && a[3] != a[5] &&
                                a[4] != a[5]) {
                                return 1;
                            }
                            a[5]++;
                        }
                        a[5] = 1;
                        a[4]++;
                    }
                    a[4] = 1;
                    a[3]++;
                }
                a[3] = 1;
                a[2]++;
            }
            a[2] = 1;
            a[1]++;
        }
        a[1] = 1;
        a[0]++;
    }
    return 0;
}
