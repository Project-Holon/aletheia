/*
 * function: func_0220C8F0
 * address: 0x0220C8F0
 * packet: pkt_ov198_0220C8F0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: both 0201C724 calls are one static inline helper; the centred x is a u8 local declared after v
 * symbols:
 *   func_0201C724 0x0201C724 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045738 0x02045738 arm
 *   func_02045770 0x02045770 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_022110D4 0x022110D4 thumb ov198
 */
typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    unsigned short f10;
} Sub;

typedef struct {
    Sub *f0;
    char pad04[0x1ea0 - 4];
    int f1ea0;
    int f1ea4;
    int f1ea8;
    int f1eac;
    char pad1eb0[0x1f98 - 0x1eb0];
    int f1f98;
    unsigned char f1f9c;
    char pad1f9d[0x1fe0 - 0x1f9d];
    int f1fe0;
    unsigned char f1fe4;
} Big;

extern int func_022110D4(Big *, int);
extern int func_02045EC0(int, int);
extern int func_02045770(int);
extern int func_02045738(int);
extern void func_0201C724(int, int, int, int, int, int, int);
extern void func_02045808(int);
extern int func_020457B0(int, int);
extern void func_0201EFA4(int, int, int, int, int, int);
extern void func_0201F250(int, int, int);
extern int func_0201D304(int, int, int);

static inline void put(Big *a0, int win, int sel, int x, int h, int color)
{
    func_0201C724(win, func_02045770(sel), x, 0, h, a0->f0->fc, color);
}

void func_0220C8F0(Big *a0, int i)
{
    char *entry = (char *)a0 + 4 + func_022110D4(a0, i) * 0x4c;
    int h1;
    int h2;
    int p;
    int v;
    unsigned char x;

    h1 = func_02045EC0(a0->f1ea0, 0x2a);
    put(a0, a0->f1eac, a0->f1fe0, 0, h1, 0x3dc0);
    a0->f1fe4 = 1;
    func_02045808(h1);

    h2 = func_02045EC0(a0->f1ea0, 0x2b);
    p = func_020457B0(8, a0->f0->f10);
    func_0201EFA4(a0->f1ea4, 0, *(unsigned short *)(entry + 6), 3, 0, 1);
    func_0201F250(a0->f1ea4, p, h2);

    v = (unsigned char)func_0201D304(p, a0->f0->fc, 0);
    x = (func_02045738(a0->f1f98) << 3) - v;
    put(a0, a0->f1eac, a0->f1f98, x, p, 0x2120);
    a0->f1f9c = 1;
    func_02045808(h2);
    func_02045808(p);
}
