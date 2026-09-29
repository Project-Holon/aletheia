/*
 * function: func_021BA928
 * address:  0x021BA928
 * packet:   pkt_ov099_021BA928
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020286C4  0x020286C4  thumb
 *   func_02028484  0x02028484  thumb
 *   func_0201CE48  0x0201CE48  thumb
 */

typedef unsigned char  u8;
typedef unsigned long  u32;

extern void func_020286C4(void *a, void *b, int c);
extern int  func_02028484(void *a, void *b);
extern void func_0201CE48(void *a);

typedef struct {
    char pad00[0x190];
    int f190;
    char pad194[0x28];
    void *f1bc;
    char pad1c0[0x26c - 0x1c0];
    char f26c[0x744];
    void *f9b0;
} W;

int func_021BA928(W *w)
{
    int r = 1;
    if (w->f1bc != 0) {
        if (w->f190 != 0) {
            func_020286C4(w->f9b0, w->f1bc, w->f190);
        }
        r = func_02028484(w->f26c, w->f1bc);
        if (r != 0 && w->f1bc != 0) {
            func_0201CE48(w->f1bc);
            w->f1bc = 0;
        }
    }
    return r;
}
