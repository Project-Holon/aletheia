/*
 * function: func_021BC2D8
 * address: 0x021BC2D8
 * packet: pkt_ov217_021BC2D8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   _s32_div_f 0x0209C0A4 arm
 *   func_021BC330 0x021BC330 thumb ov217
 */
struct S { char pad[0x34]; int f34; int f38; int f3c; int f40; int f44; int f48; };

extern int _s32_div_f(int, int);
extern void func_021BC330(struct S *p, int v);

void func_021BC2D8(struct S *p)
{
    int base = p->f3c;
    int n = p->f48 + 1;
    p->f48 = n;
    func_021BC330(p, base + (p->f40 - base) * n / p->f44);
}
