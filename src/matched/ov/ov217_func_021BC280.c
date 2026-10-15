/*
 * function: RESEARCH_LIST_DampMomentum
 * address: 0x021BC280
 * packet: pkt_ov217_021BC280
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   _dflt 0x0209B750 arm
 *   _dmul 0x0209B2E8 arm
 *   _dfix 0x0209C508 arm
 */
struct S { char pad[0x4c]; int f4c; };

void RESEARCH_LIST_DampMomentum(struct S *p)
{
    double d = p->f4c;
    int v;
    d *= 1.5;
    v = d;
    p->f4c = v;
    if (v > 9) {
        p->f4c = 9;
    } else if (v < -9) {
        p->f4c = -9;
    }
}
