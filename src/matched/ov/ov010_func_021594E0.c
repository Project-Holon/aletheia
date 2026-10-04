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

typedef unsigned short u16;
struct Ring;
struct Stream;
extern u32 func_02011398(struct Ring *r);
extern u16 func_02011330(struct Stream *s);
extern void func_0201137C(struct Ring *r, u32 v);

int func_021594E0(int p)
{
    u32 a = func_02011398((struct Ring *)p);
    u32 b = func_02011398((struct Ring *)p);
    int r;
    switch (func_02011330((struct Stream *)p)) {
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
    func_0201137C((struct Ring *)p, r);
    return 0;
}
