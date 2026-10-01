/*
 * function: func_02204CC0
 * address:  0x02204CC0
 * packet:   pkt_ov094_02204CC0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note (2026-10-01): DIFF. Control flow, call order, argument values, hoisted
 *   offset constants and the address-taken frame block (t1 0xf8, t2 0xd8, buf 0xb4,
 *   w/h, cd/pd, c) all line up; the loop needs the (i < 4) ? 1 : 0 test to keep the
 *   branch-to-bottom entry, and the shared heap local keeps (heap & 0x7fff) | 0x8000
 *   ahead of func_020275E4. Left: register allocation. The image keeps q in r6 and
 *   recomputes p + i*4, q + i*2 and q + i after every call (only i*8 lives in r7, k
 *   and font are spilled, font at sp+0x9c just under c); 1.1p1 CSEs those sums
 *   across the calls, so q spills, k takes r7 and every slot shifts. Breaking the
 *   CSEs with (u32)i / (s32)(u32)i casts per call group plus a temporary for the
 *   func_0204B294 result (so the store address is formed after the call) gets the
 *   p/i registers and the per-call recompute, but q still lands in r7 and k in r6.
 *   Also open: func_0201DD78's colour arguments are evaluated r2, r1, r0 in the
 *   image (col kept in r0), ours evaluates r0 first and copies col to r3.
 *   Witness gaps once bytes match: func_020275F8, func_020275EC (arm, no caller
 *   outside this body) and the six d_0220Axxx tables are unresolved relocations.
 * symbols:
 *   d_0220A5B0  0x0220A5B0  data
 *   d_0220A5D0  0x0220A5D0  data
 *   d_0220A5F0  0x0220A5F0  data
 *   d_0220A392  0x0220A392  data
 *   d_0220A3C4  0x0220A3C4  data
 *   d_0220A4AC  0x0220A4AC  data
 *   func_02204C98  0x02204C98  thumb  ov094
 *   func_02205768  0x02205768  thumb  ov094
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct Point { s16 x, y; } Point;
typedef struct Pos { int x, y; } Pos;
typedef struct PosTab { Pos v[4]; } PosTab;
typedef struct { int w[9]; } Struct36;
typedef struct Slots {
    u16 id[4];
    u8 a[4];
    u8 b[4];
} Slots;

extern const PosTab d_0220A5B0;
extern const PosTab d_0220A5D0;
extern const int d_0220A5F0[];
extern const u16 d_0220A392[];
extern const Point d_0220A3C4[];
extern const Pos d_0220A4AC[];

extern void *func_020457B0(u32, u16);
extern void *func_02045EC0(void *, u32);
extern int func_0201EC64(int);
extern void func_0204B22C(void *, int);
extern int func_0201BD28(int, int);
extern void *func_0204B294(u32, u32, u32, u32, const void *, u16, u16);
extern void func_0204B404(void *, const Point *, int);
extern u32 func_020275E4(void);
extern u32 func_020275F8(u8);
extern u32 func_020275EC(u8);
extern void *func_02049E34(u32 arc, u32 file, u32 comp, void **out, u16 heap);
extern void *func_02049F34(u32 arc, u32 file, void **out, u16 heap);
extern void func_0204B6F4(void *, u32, u32);
extern void func_0204B7C8(void *, Struct36 *);
extern void func_02082A60(const void *, void *, int);
extern void func_020307B0(void *);
extern void func_0201DE00(u8 *, u8 *, u8 *);
extern void func_0201DD78(int, int, int);
extern void func_0201EF34(int, int, int);
extern void func_0201EFA4(int, int, int, int, int, int);
extern void func_0201F250(int, void *, void *);
extern void func_02204C98(void *a, void *b, int *w, int *h);
extern void func_0201C7A4(void *, s16, s16, void *, void *);
extern int func_02205768(int a, int b);
extern void func_020215BC(void *, void *, int, u16, u16);
extern void func_0201ED04(int);
extern void func_02045808(void *);

void func_02204CC0(char *p, Slots *q)
{
    PosTab t1 = d_0220A5B0;
    PosTab t2 = d_0220A5D0;
    int font;
    void *pltt;
    void *chr;
    u32 arc;
    int k;
    int file;
    void *str1;
    void *m0;
    void *str2;
    void *m2;
    void *m1;
    u16 heap;
    int i;
    Struct36 buf;
    int w;
    int h;
    void *cd;
    void *pd;
    u8 c[3];
    int col;

    str1 = func_020457B0(0x10, *(u16 *)(p + 0x240));
    m0 = func_02045EC0(*(void **)(p + 0x5c), 0);
    m1 = func_02045EC0(*(void **)(p + 0x5c), 1);
    font = func_0201EC64(*(u16 *)(p + 0x240));
    str2 = func_020457B0(0x10, *(u16 *)(p + 0x240));
    m2 = func_02045EC0(*(void **)(p + 0x5c), 2);
    func_0204B22C(*(void **)(p + 0x1f8), 0);
    for (i = 0; (i < 4) ? 1 : 0; i++) {
        if (q->id[i] != 0) {
            k = func_0201BD28(q->id[i], 0);
            file = d_0220A5F0[k];
            *(void **)(p + i * 4 + 0x1fc) = func_0204B294(*(u32 *)(p + 0x1f8), *(u32 *)(p + i * 4 + 0x1e0), *(u32 *)(p + 0x1f0), *(u32 *)(p + 0x1f4), d_0220A392, 1, *(u16 *)(p + 0x240));
            func_0204B404(*(void **)(p + i * 4 + 0x1fc), &d_0220A3C4[i], 1);
            heap = (*(u16 *)(p + 0x240) & 0x7fff) | 0x8000;
            arc = func_020275E4();
            chr = func_02049E34(arc, func_020275F8(k), 0, &cd, heap);
            func_0204B6F4(*(void **)(p + i * 4 + 0x1fc), func_020275EC(k), 1);
            func_0204B7C8(*(void **)(p + i * 4 + 0x1fc), &buf);
            func_02082A60(*(void **)((char *)cd + 0x14), (void *)(0x06600000 + buf.w[2]), 0x100);
            func_020307B0(chr);
            func_0201DE00(&c[2], &c[1], &c[0]);
            func_0201DD78(1, 2, 0);
            func_0201EF34(font, 0, q->id[i]);
            func_0201F250(font, str1, m0);
            func_02204C98(str1, *(void **)(p + 0x224), &w, &h);
            func_0201C7A4(*(void **)(p + 0x22c), d_0220A4AC[i].x - w / 2, d_0220A4AC[i].y, str1, *(void **)(p + 0x224));
            func_0201EFA4(font, 0, q->a[i], 2, 1, 1);
            func_0201EFA4(font, 1, q->b[i], 2, 1, 1);
            func_0201F250(font, str2, m2);
            col = func_02205768(q->a[i], q->b[i]);
            func_0201DD78((u8)((col >> 10) & 0x1f), (u8)((col >> 5) & 0x1f), (u8)(col & 0x1f));
            func_0201C7A4(*(void **)(p + 0x22c), t1.v[i].x, t1.v[i].y, m1, *(void **)(p + 0x224));
            func_02204C98(str2, *(void **)(p + 0x224), &w, &h);
            func_0201C7A4(*(void **)(p + 0x22c), t2.v[i].x - w / 2, t2.v[i].y, str2, *(void **)(p + 0x224));
            func_0201DD78(c[2], c[1], c[0]);
            p[0x25a + i] = q->a[i] != 0;
            p[0x262 + i] = q->id[i] != 0;
        } else {
            file = 0xc1;
        }
        heap = (*(u16 *)(p + 0x240) & 0x7fff) | 0x8000;
        pltt = func_02049F34(0xb, file, &pd, heap);
        func_020215BC(*(void **)(p + 0x64), *(void **)((char *)pd + 0xc), 1, i * 16 + 0x90, 0x20);
        func_020307B0(pltt);
    }
    p[0x25a + i] = 1;
    if (*(int *)(p + 0x50) == 2) {
        p[0x25a + i + 1] = 1;
    }
    func_0201ED04(font);
    func_02045808(str1);
    func_02045808(m1);
    func_02045808(m0);
    func_02045808(m2);
    func_02045808(str2);
}
