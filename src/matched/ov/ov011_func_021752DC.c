/*
 * function: func_021752DC
 * address:  0x021752DC
 * packet:   pkt_ov011_021752DC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_0216786C  0x0216786C  thumb ov010
 *   func_02012FB0  0x02012FB0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Hd {
    u8 pad[0x14];
    u16 f14;
    u16 lo : 3;
    u16 x : 6;
    u16 mid : 6;
    u16 top : 1;
} Hd;

int func_02026478(int a);
void func_020127A4(void);
int func_02012AC8(void);
int func_0216786C(int a, Hd *b);
u8 func_02012FB0(int a);

int func_021752DC(u8 *p)
{
    int ctx;
    int v;
    int r;
    int k;
    Hd *h;

    ctx = func_02026478(*(int *)(p + 4));
    func_020127A4();
    v = func_02012AC8();
    h = (Hd *)(p + 0x70);
    r = func_0216786C(*(int *)(p + 8), h);
    if (h->f14 != v) {
        h->f14 = v;
        r = 1;
    }
    if (h->x != func_02012FB0(ctx)) {
        h->x = func_02012FB0(ctx);
        r = 1;
    }
    k = (*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15;
    if (h->top != k) {
        h->top = k;
        r = 1;
    }
    return r;
}
