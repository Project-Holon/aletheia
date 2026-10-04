/*
 * function: func_02159670
 * address:  0x02159670
 * packet:   pkt_ov010_02159670
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_02011398  0x02011398  thumb
 *   func_020113B0  0x020113B0  thumb
 *   d_021705DC     0x021705DC  data  ov010
 */

typedef unsigned char u8;

struct P { int _0[3]; u8 _p[2]; u8 e; u8 _f[5]; u8 *cur; };

extern int func_0201134C(struct P *);
extern int func_02011398(struct P *);
typedef unsigned int   u32;
struct Cur;
extern void func_020113B0(struct Cur *c, u32 v);
extern u8 d_021705DC[][3];

int func_02159670(struct P *p)
{
    u8 *q = p->cur;
    u8 c = *q;
    int n;
    p->cur = q + 1;
    n = func_0201134C(p);
    if (c == 0xFF) {
        if (func_02011398(p) == 1)
            goto end;
    } else {
        if (d_021705DC[c][p->e] != 1)
            goto end;
    }
    func_020113B0((struct Cur *)p, (u32)(p->cur + n));
end:
    return 0;
}
