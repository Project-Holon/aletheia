/*
 * function: func_021C4160
 * address:  0x021C4160
 * packet:   pkt_ov021_021C4160
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201ADD0  0x0201ADD0  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021C42F4  0x021C42F4  thumb  ov021
 *   d_021DA8F8     0x021DA8F8  data  ov021  a4
 *
 * Twin of func_021C4084 (same goto-rotated learnset walk). The call
 * result must be a named local (v == mv gives cmp r0, r5), and end = 0
 * goes after the entry copies, as in the twin.
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct { u16 x, y; } P;
typedef struct { u32 v[4]; } T4;

extern void func_0201ADD0(u16 a, u16 b, P *buf);
extern u32 func_02017E1C(u32 a, u32 b, u32 c);
extern void func_021C42F4(u32 *p, u32 v);
extern const T4 d_021DA8F8;

void func_021C4160(u32 *p, u32 *q)
{
    P buf[26];
    T4 t = d_021DA8F8;
    P d, b, a;
    int i;
    int fa;
    int fb;
    int end;
    int k;
    u32 mv;
    u32 v;

    func_0201ADD0(q[0], q[1], buf);
    i = 0;
    goto test;
body:
    d = a;
    mv = d.x;
    fa = 0;
    fb = 0;
    for (k = 0; k < 4; k++) {
        v = func_02017E1C(p[0], t.v[k], 0);
        if (v == mv) {
            fa = 1;
            break;
        }
    }
    for (k = 0; k < 4; k++) {
        v = func_02017E1C(p[1], t.v[k], 0);
        if (v == mv) {
            fb = 1;
            break;
        }
    }
    if (fa && fb)
        func_021C42F4(q, mv);
    i++;
test:
    a = buf[i];
    b = a;
    end = 0;
    if (b.x == 0xffff && b.y == 0xffff)
        end = 1;
    if (!end)
        goto body;
}
