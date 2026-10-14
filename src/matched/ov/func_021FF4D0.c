/*
 * function: WORLDTRADE_SEARCH_CompareRecords
 * address:  0x021FF4D0
 * packet:   pkt_021FF4D0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * True when two {s16, s8, s8, s8} records are equal field by field and
 * the two trailing arguments are equal.
 */

typedef signed char s8;
typedef signed short s16;

typedef struct {
    s16 a;
    s8 b;
    s8 c;
    s8 d;
} Rec;

int WORLDTRADE_SEARCH_CompareRecords(Rec *x, Rec *y, int m, int n)
{
    if (x->a == y->a && x->b == y->b && x->c == y->c && x->d == y->d && m == n) {
        return 1;
    }
    return 0;
}
