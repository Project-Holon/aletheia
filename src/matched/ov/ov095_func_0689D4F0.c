/*
 * function: func_0689D4F0
 * address:  0x0689D4F0
 * packet:   pkt_ov095_0689D4F0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0689D544  0x0689D544  thumb
 */

typedef unsigned char u8;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
} Rec;

extern void func_0689D544(Rec *p, int i);

void func_0689D4F0(Rec *p, int i, int j)
{
    Rec t;

    t = p[i];
    p[i] = p[j];
    p[j] = t;
    func_0689D544(p, i);
    func_0689D544(p, j);
}
