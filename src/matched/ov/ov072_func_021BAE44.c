/*
 * function: func_021BAE44
 * address:  0x021BAE44
 * packet:   pkt_ov072_021BAE44
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BA774  0x021BA774  thumb  ov072
 *   func_021BAA30  0x021BAA30  thumb  ov072
 *   func_021BADBC  0x021BADBC  thumb  ov072
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

extern int func_021BA774(char *p, int i);
extern void func_021BAA30(W *p, int a);
extern void func_021BADBC(char *p, int v);

void func_021BAE44(W *p)
{
    int r;

    r = 0;
    if (func_021BA774((char *)p, 11) == 4 || func_021BA774((char *)p, 11) == 5) {
        r = 1;
        if (p->f40 != 0) {
            r = 0;
        }
    }
    if (p->f38 != 0 || r != 0) {
        if (p->obj != 0) {
            func_021BAA30(p, 1);
            func_021BADBC((char *)p, p->f30);
        }
    } else {
        func_021BAA30(p, 0);
    }
}
