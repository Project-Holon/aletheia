/*
 * function: func_021BA86C
 * address:  0x021BA86C
 * packet:   pkt_ov072_021BA86C
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: f3c as `if (s5) f3c = 1; else f3c = f38 && f(...);` (a nested
 * ternary cross-jumps the two `movs r0,#1` arms). func_021BBB3C's second
 * parameter is u16 here (the caller truncates it before each bl).
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_021BBB3C  0x021BBB3C  thumb  ov072
 *   func_02166CD0  0x02166CD0  thumb  ov010
 *   func_021BA774  0x021BA774  thumb  ov072
 *   func_0204B294  0x0204B294  arm
 *   func_0204B570  0x0204B570  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B800  0x0204B800  arm
 *   func_021BAE44  0x021BAE44  thumb  ov072
 */
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 w;
} Pos;

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

extern void func_02082BCC(void *p, int v, int n);
extern u16 func_021BBB3C(int p, u16 a, int b);
extern int func_02166CD0(void *a, u32 msg);
extern int func_021BA774(W *p, int i);
extern int func_0204B294(int a, int b, int c, int d, Pos *pos, int f, u16 g);
extern void func_0204B570(int obj, int v);
extern void func_0204B84C(int obj, int v);
extern void func_0204B800(int obj, int v);
extern void func_021BAE44(W *p);

void func_021BA86C(W *p, int a, int b, int c, int s0, int s1, int s2, void *s3, u16 s4, int s5)
{
    Pos pos;
    u32 r;
    int i;

    func_02082BCC(p, 0, 0x44);
    p->f34 = 0x1000;
    p->f4 = a;
    p->f8[0] = b;
    r = func_021BBB3C(a, b, 15);
    if (r != 0xFFFF)
        p->f38 = func_02166CD0(s3, r);
    else
        p->f38 = 0;
    if (s5)
        p->f38 = 1;
    for (i = 0; i < 9; i++)
        p->f8[i + 1] = func_021BBB3C(p->f4, p->f8[0], i + 2);
    if (s5)
        p->f3c = 1;
    else
        p->f3c = p->f38 && func_021BBB3C(p->f4, p->f8[0], 12);
    r = func_021BBB3C(p->f4, p->f8[0], 16);
    if (r != 0xFFFF)
        p->f40 = func_02166CD0(s3, r) == 0;
    else
        p->f40 = 0;
    if (s5)
        p->f40 = 0;
    switch (func_021BA774(p, 11)) {
    case 0:
        p->f31 = 2;
        p->f30 = 1;
        break;
    case 2:
        p->f31 = 3;
        p->f30 = 0xff;
        break;
    case 1:
        p->f31 = 0xff;
        p->f30 = 0xff;
        break;
    case 3:
        p->f31 = 3;
        p->f30 = 0xd;
        break;
    case 4:
        p->f31 = 0xf;
        p->f30 = 0xe;
        break;
    case 5:
        p->f31 = 0x12;
        if (p->f38)
            p->f30 = 0x11;
        else
            p->f30 = 0x10;
        break;
    }
    if (func_021BA774(p, 11) != 1) {
        func_02082BCC(&pos, 0, 8);
        pos.x = func_021BA774(p, 2);
        pos.y = func_021BA774(p, 3);
        p->obj = func_0204B294(c, s0, s2, s1, &pos, 0, s4);
        func_0204B570(p->obj, 2);
        func_0204B84C(p->obj, 2);
        func_0204B800(p->obj, 4);
    }
    func_021BAE44(p);
}
