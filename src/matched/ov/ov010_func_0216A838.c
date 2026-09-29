/*
 * function: func_0216A838
 * address:  0x0216A838
 * packet:   pkt_ov010_0216A838
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _s32_div_f     0x0209C0A4  arm
 *   func_0216D89C  0x0216D89C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int c;
} Vec3;

typedef struct {
    int f0;
    u16 f4;
    u16 f6;
    int f8;
    Vec3 v;
} S;

extern void func_0216D89C();

int func_0216A838(int a0, int a1, S *p)
{
    Vec3 loc;

    p->f6 = p->f6 + 1;
    loc = p->v;
    loc.b += (p->f0 * p->f6) / p->f4;
    func_0216D89C(p->f8, &loc);
    if (p->f6 >= p->f4) {
        return 1;
    }
    return 0;
}
