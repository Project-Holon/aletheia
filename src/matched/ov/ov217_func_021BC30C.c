/*
 * function: func_021BC30C
 * address: 0x021BC30C
 * packet: pkt_ov217_021BC30C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   func_021BC41C 0x021BC41C thumb ov217
 */
struct S { char pad[0x34]; int f34; int f38; };

typedef unsigned int   u32;
extern u32 func_021BC41C(void *p);

void func_021BC30C(struct S *p, int v)
{
    if (v < 0) {
        v = 0;
    }
    if ((int)func_021BC41C(p) < v) {
        v = (int)func_021BC41C(p);
    }
    p->f38 = p->f34;
    p->f34 = v;
}
