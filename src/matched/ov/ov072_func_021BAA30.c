/*
 * function: func_021BAA30
 * address:  0x021BAA30
 * packet:   pkt_ov072_021BAA30
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BA774  0x021BA774  thumb  ov072
 *   func_021BADBC  0x021BADBC  thumb  ov072
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef unsigned char u8;

typedef struct {
    int obj;
    int f4;
    int f8[10];
    u8 f30;
    u8 f31;
    u8 f32;
    int f34;
    int f38;
    int f3c;
    int f40;
} W;

extern int func_021BA774(W *p, int i);
extern void func_021BADBC(W *p, int v);
extern void func_0204B3DC(int obj, int on);

void func_021BAA30(W *p, int a)
{
    if (p->obj == 0 || p->f32 == 0xff) {
        return;
    }
    if (p->f40 != 0) {
        func_0204B3DC(p->obj, 0);
        return;
    }
    if (func_021BA774(p, 11) == 4 || func_021BA774(p, 11) == 5) {
        func_021BADBC(p, p->f30);
        func_0204B3DC(p->obj, 1);
    } else {
        func_0204B3DC(p->obj, a);
    }
}
