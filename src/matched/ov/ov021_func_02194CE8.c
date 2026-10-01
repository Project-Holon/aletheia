/*
 * function: func_02194CE8
 * address:  0x02194CE8
 * packet:   pkt_ov021_02194CE8
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The callee 0x02194D1C is src/matched/ov/ov021_func_02194D1C.c. EXACT* only
 * because that callee is the unlabelled follower.
 *
 * symbols:
 *   func_02194D1C  0x02194D1C  thumb  ov021
 */

typedef unsigned short u16;

extern void func_02194D1C(int a, void *b, int c);

void func_02194CE8(int a, u16 *b)
{
    switch (*b) {
    case 0:
    case 1:
    case 2:
    case 5:
    case 6:
        break;
    case 3:
        func_02194D1C(a, b, 0);
        break;
    case 4:
        func_02194D1C(a, b, 1);
        break;
    }
}
