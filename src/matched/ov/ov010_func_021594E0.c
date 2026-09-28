/*
 * function: func_021594E0
 * address:  0x021594E0
 * packet:   pkt_ov010_021594E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02011398  0x02011398  thumb
 *   func_02011330  0x02011330  thumb
 *   func_0201137C  0x0201137C  thumb
 */

typedef unsigned int u32;

extern u32 func_02011398(int);
extern int func_02011330(int);
extern void func_0201137C(int, int);

int func_021594E0(int p)
{
    u32 a = func_02011398(p);
    u32 b = func_02011398(p);
    int r;
    switch (func_02011330(p)) {
    case 0: r = (b < a) ? 1 : 0; break;
    case 1: r = (b == a) ? 1 : 0; break;
    case 2: r = (b > a) ? 1 : 0; break;
    case 3: r = (b <= a) ? 1 : 0; break;
    case 4: r = (b >= a) ? 1 : 0; break;
    case 5: r = (b != a) ? 1 : 0; break;
    case 6: r = (b == 1 || a == 1) ? 1 : 0; break;
    case 7: r = (b == 1 && a == 1) ? 1 : 0; break;
    default: r = 0; break;
    }
    func_0201137C(p, r);
    return 0;
}
