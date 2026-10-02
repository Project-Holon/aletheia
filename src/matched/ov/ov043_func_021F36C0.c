/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov043_021F36C0
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The two 0x021C0628 argument tables must be const: non-const, every
 * stack-argument store lands ahead of the register loads.  The second
 * loop's flag is an if/else (beq; movs #1; b; movs #0), the third loop's a
 * ternary (movs #1; bne; movs #0).  0x0218CEE0 and 0x021C0628 are
 * unlabelled ov021 leaves filed alongside.
 *
 * symbols:
 *   d_021F4510     0x021F4510  data  a4
 *   d_021F4480     0x021F4480  data  a4
 *   d_021F4318     0x021F4318  data  a4
 *   d_021F4358     0x021F4358  data  a4
 *   d_021F434C     0x021F434C  data  a4
 *   d_021F4340     0x021F4340  data  a4
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C64  0x02188C64  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_0218CEE0  0x0218CEE0  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021C0628  0x021C0628  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021F3F38  0x021F3F38  thumb  ov043
 *   func_021F4174  0x021F4174  thumb  ov043
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A01BC  0x021A01BC  thumb  ov021
 *   func_021A01B4  0x021A01B4  thumb  ov021
 *   sub_02030344   0x02030344  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
} EA;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10[2];
} EB;

extern const EA d_021F4510[];
extern const EB d_021F4480[];
extern int d_021F4318;
extern const V d_021F4358[];
extern const V d_021F434C;
extern const V d_021F4340;

extern void *func_02188D2C(void *p);
extern u32   func_02188C64(void *p);
extern u32   func_02188C80(void *p);
extern int   func_02188C84(void *p);
extern void *func_02188C98(void *p);
extern void *func_02188CB4(void *p);
extern void *func_0218CEE0(void *p);
extern void  func_02189764(void *p, int a, int b, int c);
extern u32   func_020120F4(u32 a);
extern u32   func_02012EC4(u32 a);
extern int  *func_0200B3A4(u32 a, u32 b);
extern void  func_021C0628(u8 i, int a, int b, int c, int d, int e, int f, void *t);
extern void  func_021BE760(void *p, void *a, int b);
extern V    *func_021BE480(void *p, int i, u16 j);
extern void  func_021BE4A4(void *p, int i, u16 j, int v);
extern void *func_021BE674(void *p, int i, u16 j, u16 k);
extern void  func_021BE6B8(void *p, int v);
extern void  func_021BE6B0(void *p, int v);
extern void  func_021BE700(void *p, int i, u16 j, u16 k, int flag);
extern int   func_021BE748(void *p);
extern void  func_021BE6CC(void *p, int i, u16 j, u16 k, int flag);
extern void  func_021F3F38(int *a, void *b, int c);
extern void  func_021F4174(void *p);
extern void  func_021A3038(void *id, int *out);
extern int   func_021A01BC(u32 a, u32 b);
extern int   func_021A01B4(u32 a, u32 b);
extern void *sub_02030344(u32 heapId);

void func_021F36C0(void *a0)
{
    void *s;
    int *q;
    u32 g;
    void *w;
    V *e;
    void *b;
    int i;
    int k;
    u8 flag;
    u8 x;
    int pos[3];

    s = func_02188D2C(a0);
    g = func_02188C64(a0);
    q = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(a0))), 7);
    func_02189764(a0, 1, func_02188C84(a0), 0x58);
    w = func_0218CEE0(func_02188C98(a0));
    for (i = 0; i < 8; i++) {
        func_021C0628(i, d_021F4510[i].f0, d_021F4510[i].f4, d_021F4510[i].f8,
                      d_021F4510[i].fc, d_021F4510[i].f10, 0x800000, w);
    }
    for (i = 0; i < 6; i++) {
        x = i + 8;
        if (q[i] != 0) {
            flag = 1;
        } else {
            flag = 0;
        }
        func_021C0628(x, d_021F4480[i].f0, d_021F4480[i].f4, d_021F4480[i].f8,
                      d_021F4480[i].fc, d_021F4480[i].f10[flag], 0x800000, w);
    }
    func_021BE760(s, &d_021F4318, 0);
    for (i = 0; i < 6; i++) {
        e = func_021BE480(s, 0, i);
        *e = d_021F4358[i];
        flag = q[i] ? 1 : 0;
        e->b = d_021F4480[i].f10[flag];
        func_021BE4A4(s, 0, i, 1);
        for (k = 0; k < 2; k++) {
            b = func_021BE674(s, 0, i, k);
            func_021BE6B8(b, 0);
            func_021BE6B0(b, 1);
        }
        func_021F3F38(q, s, i);
    }
    e = func_021BE480(s, 0, 7);
    *e = d_021F434C;
    func_021BE4A4(s, 0, 7, 1);
    for (k = 0; k < 2; k++) {
        b = func_021BE674(s, 0, 7, k);
        func_021BE6B8(b, 0);
        func_021BE6B0(b, 1);
    }
    func_021F4174(s);
    e = func_021BE480(s, 0, 6);
    *e = d_021F4340;
    func_021BE4A4(s, 0, 6, 1);
    func_021BE700(s, 0, 6, 0, 1);
    b = func_021BE674(s, 0, 6, 0);
    func_021BE6B8(b, 0);
    func_021BE6B0(b, 1);
    if (q[6]) {
        func_021BE6CC(s, 0, 6, 0, func_021BE748(b));
    }
    func_021A3038(func_02188CB4(a0), pos);
    if (pos[1] <= -0x280000) {
        func_021A01BC(g, 0x7FDF);
        func_021A01B4(g, 9);
    }
    sub_02030344(0x15);
}
