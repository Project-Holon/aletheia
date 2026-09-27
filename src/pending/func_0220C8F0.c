/*
 * function: func_0220C8F0
 * address:  0x0220C8F0
 * packet:   pkt_0220C8F0
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Near miss, 14 of 256 bytes.  Every instruction and constant reproduces; the
 * only differences are two register-allocator artefacts: the a0->f1eac
 * temporary and the func_0201D304 result get the opposite stack slots
 * (0x0C/0x14 swapped), and the load of that result into r2 at the final
 * func_0201C724 call is scheduled one slot earlier.  Declaration order of the
 * locals does not move the slots; not enough of the source shape is
 * recoverable to pin the allocator.
 *
 * Re-verified (DIFF fixer): still 14 of 256 bytes; the 0x0C/0x14 slot swap
 * and the one-slot-early load are unchanged. Blocker stands.
 *
 * symbols:
 *   func_0201C724  0x0201C724  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045738  0x02045738  arm
 *   func_02045770  0x02045770  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045808  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_022110D4  0x022110D4  thumb  ov198
 *
 * Addresses are Black-image addresses.
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

extern int func_022110D4(Big *);
extern int func_02045EC0(int, int);
extern int func_02045770(int);
extern int func_02045738(int);
extern void func_0201C724(int, int, int, int, int, int, int);
extern void func_02045808(int);
extern int func_020457B0(int, int);
extern void func_0201EFA4(int, int, int, int, int, int);
extern void func_0201F250(int, int, int);
extern int func_0201D304(int, int, int);

void func_0220C8F0(Big *a0)
{
    char *entry = (char *)a0 + 4 + func_022110D4(a0) * 0x4c;
    int h1;
    int h2;
    int tmp;
    int p;
    int v;
    int val;
    int r4b;
    int y;

    h1 = func_02045EC0(a0->f1ea0, 0x2a);
    tmp = a0->f1eac;
    func_0201C724(tmp, func_02045770(a0->f1fe0), 0, 0, h1, a0->f0->fc, 0x3dc0);
    a0->f1fe4 = 1;
    func_02045808(h1);

    h2 = func_02045EC0(a0->f1ea0, 0x2b);
    p = func_020457B0(8, a0->f0->f10);
    func_0201EFA4(a0->f1ea4, 0, *(unsigned short *)(entry + 6), 3, 0, 1);
    func_0201F250(a0->f1ea4, p, h2);

    v = func_0201D304(p, a0->f0->fc, 0);
    v = (unsigned char)v;
    val = (unsigned char)((func_02045738(a0->f1f98) << 3) - v);

    {
        r4b = a0->f1eac;
        y = func_02045770(a0->f1f98);
        func_0201C724(r4b, y, val, 0, p, a0->f0->fc, 0x2120);
    }
    a0->f1f9c = 1;
    func_02045808(h2);
    func_02045808(p);
}
