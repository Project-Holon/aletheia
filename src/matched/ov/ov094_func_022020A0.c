/*
 * function: func_022020A0
 * address:  0x022020A0
 * packet:   pkt_ov094_022020A0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220684C  0x0220684C  thumb  ov094
 *   func_02202248  0x02202248  thumb  ov094
 *   func_02204BAC  0x02204BAC  thumb  ov094
 *   d_0220AEB0  0x0220AEB0  data  a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Bits { unsigned lo:9; unsigned k:4; unsigned rest:19; } Bits;
typedef struct Obj {
    void *h0;
    void *h4;
    char pad08[0x4c - 8];
    int a4c;
    int a50;
    int a54;
    char pad58[0x5c - 0x58];
    int a5c;
    char pad60[0x64 - 0x60];
    int a64;
    Bits f68;
    char pad6c[0x70 - 0x6c];
    int a70;
    char pad74[0x104 - 0x74];
    int b104[5];
    char pad118[0x1b0 - 0x118];
    int b1b0[3];
    int b1bc;
    int b1c0;
    char pad1c4[0x1e0 - 0x1c4];
    int b1e0[4];
    int b1f0;
    int b1f4;
    char pad1f8[0x224 - 0x1f8];
    int a224;
    char pad228[0x23c - 0x228];
    int a23c;
    u16 heap;
    char pad242[0x274 - 0x242];
    int a274;
} Obj;
typedef struct Res { Obj *owner; int v; } Res;
extern void *func_02030734(u16, u32, int, const char *, u16);
extern int func_02030CB0(int n);
extern void *func_02030CBC(int n, void *buf);
extern int func_02045B38(int, int, int, int);
extern void *func_02030DA8(void *, void (*)(void *, Res *), void *, u32);
extern void func_0220684C(Obj *, void *, void (*)(void *));
extern void func_02202248(Obj *);
extern void func_02204BAC(void *, Res *);
extern const char d_0220AEB0[];

Obj *func_022020A0(int a, int b, int c, int d, int e, int f, int g, int h, u16 heap)
{
    Obj *p;
    Res *r;
    int i;

    p = func_02030734(heap, 0x2e0, 1, d_0220AEB0, 0x39a);
    p->heap = heap;
    p->h4 = func_02030734(p->heap, func_02030CB0(8), 1, d_0220AEB0, 0x39e);
    p->h0 = func_02030CBC(8, p->h4);
    p->a4c = a;
    p->a224 = e;
    p->a50 = b;
    p->a54 = c;
    p->a274 = f;
    p->f68.k = 15;
    p->a23c = h;
    p->a64 = d;
    p->b104[0] = -1;
    p->b104[1] = -1;
    p->b104[2] = -1;
    p->b104[3] = -1;
    p->b104[4] = -1;
    p->b1bc = -1;
    p->b1c0 = -1;
    p->b1f0 = -1;
    p->b1f4 = -1;
    for (i = 0; i < 3; i++) {
        p->b1b0[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        p->b1e0[i] = -1;
    }
    p->a5c = func_02045B38(0, 2, 12, p->heap);
    p->a70 = -1;
    func_02202248(p);
    r = func_02030734((p->heap & 0x7fff) | 0x8000, 8, 0, d_0220AEB0, 0x3cc);
    r->owner = p;
    r->v = g;
    func_0220684C(p, func_02030DA8(p->h0, func_02204BAC, r, 0), 0);
    return p;
}
