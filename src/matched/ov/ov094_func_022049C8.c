/*
 * function: func_022049C8
 * address:  0x022049C8
 * packet:   pkt_ov094_022049C8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02040618  0x02040618  arm
 *   func_02040588  0x02040588  arm
 *   func_0220687C  0x0220687C  thumb  ov094
 */
typedef unsigned char u8;

typedef struct Ctx {
    void *main;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
} Ctx;

extern void func_02040618(u8 a, int b, int c);
extern void func_02040588(int a, u8 b);
extern void func_0220687C(char *p, void *q);

void func_022049C8(int a0, Ctx *c)
{
    if (c->f4 != -1) {
        func_02040618(c->f4, 0, c->f8);
        func_02040618(c->f4, 3, c->fc);
    }
    if (c->f10 != 2) {
        func_02040588(4, c->f10);
    }
    if (c->f14 != 2) {
        func_02040588(5, c->f14);
    }
    if (c->f18 != 2) {
        func_02040588(6, c->f18);
    }
    if (c->f1c != 2) {
        func_02040588(7, c->f1c);
    }
    func_0220687C(c->main, (void *)a0);
}
