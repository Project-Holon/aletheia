/*
 * function: func_021B0960
 * address:  0x021B0960
 * packet:   pkt_ov021_021B0960
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B0808  0x021B0808  thumb  ov021
 *   func_021B090C  0x021B090C  thumb  ov021
 *   d_021D939C     0x021D939C  data   a4
 */

typedef unsigned char u8;
typedef struct { int x, y, z; } V;

extern V d_021D939C[][4];
extern void func_021B0808(int, V *, int, int);
extern void func_021B090C(V *, int);

void func_021B0960(int a, V *p, int q, int r3, u8 e)
{
    int i = 0;
    int j = 0;

    switch (e) {
    case 3:
        i = 1;
        break;
    case 4:
        i = 1;
        j = 1;
        break;
    case 5:
        i = 2;
        break;
    case 6:
        i = 2;
        j = 1;
        break;
    case 0:
    case 1:
    case 2:
        func_021B0808(a, p, q, r3);
        func_021B090C(p, q);
        return;
    }
    *p = d_021D939C[j][i];
    func_021B090C(p, q);
}
