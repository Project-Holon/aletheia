/*
 * function: func_021ABFA8
 * address:  0x021ABFA8
 * packet:   pkt_ov021_021ABFA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AC0A0  0x021AC0A0  thumb
 */

typedef unsigned short u16;

typedef struct {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[3];
    u16 h14;
    u16 pad16;
    void *f18;
    int f1c;
    int f20;
} T;

extern void func_021AC0A0(int a, int b, int c, int d, int e, int f);

void func_021ABFA8(T *t, int b, int c, int d, int e, int f)
{
    func_021AC0A0(t->f20, b, c, d, e, f);
}
