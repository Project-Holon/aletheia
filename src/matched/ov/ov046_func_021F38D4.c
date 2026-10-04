/*
 * function: func_021F38D4
 * address:  0x021F38D4
 * packet:   pkt_ov046_021F38D4
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Levers: case 0 spelled k = 1 like default (cross-jumped onto the default's
 * copy, giving the table's leading b); n1/n2 named and assigned between the
 * "= 1" default and its if (before it, n + 1 is copy-propagated into every
 * call and the frame grows a slot).
 *
 * symbols:
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

extern void func_021BE700(u32 a, int b, u16 c, u16 d, int e);
extern u8 *func_021BE674(u32 a, int b, u16 c, u16 d);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE6CC(u32 a, int b, u16 c, u16 d, int e);
extern int func_021BE748(u32 a);

void func_021F38D4(u8 *base, u32 t, int idx)
{
    int *e;
    int n;
    int k;
    u8 *p;
    int m;
    int n1;
    u8 *q;
    int k3;
    int n2;
    u8 *r;

    e = (int *)(base + idx * 12);
    switch (e[0]) {
    case 0:
        k = 1;
        break;
    case 1:
        k = 5;
        break;
    case 3:
        k = 0;
        break;
    case 2:
        k = 2;
        break;
    default:
        k = 1;
        break;
    }
    n = idx * 5;
    p = func_021BE674(t, 0, n, k);
    func_021BE6B0(p, 0);
    func_021BE700(t, 0, n, k, 1);
    func_021BE6CC(t, 0, n, k, func_021BE748((u32)p));
    m = 1;
    n1 = n + 1;
    if (e[1] == 0)
        m = 0;
    q = func_021BE674(t, 0, n1, m);
    func_021BE6B0(q, 0);
    func_021BE700(t, 0, n1, m, 1);
    func_021BE6CC(t, 0, n1, m, func_021BE748((u32)q));
    k3 = 1;
    n2 = n + 2;
    if (e[2] == 0)
        k3 = 0;
    r = func_021BE674(t, 0, n2, k3);
    func_021BE6B0(r, 0);
    func_021BE700(t, 0, n2, k3, 1);
    func_021BE6CC(t, 0, n2, k3, func_021BE748((u32)r));
}
