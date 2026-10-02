/*
 * function: func_021BC380
 * address: 0x021BC380
 * packet: pkt_ov217_021BC380
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   func_021BC40C 0x021BC40C thumb ov217
 *   func_021BC3B8 0x021BC3B8 thumb ov217
 */
struct S { char pad[0x34]; int f34; };

extern int func_021BC40C(struct S *p);
extern void func_021BC3B8(int v);

void func_021BC380(struct S *p)
{
    int v = p->f34 - 24;
    if (v < -24) {
        v = -24;
    }
    if (func_021BC40C(p) < v) {
        v = func_021BC40C(p);
    }
    func_021BC3B8(v);
}
