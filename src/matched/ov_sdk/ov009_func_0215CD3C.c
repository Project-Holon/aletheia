/*
 * function: func_0215CD3C
 * address:  0x0215CD3C
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021A1CD8   0x021A1CD8  data
 *   g_021AA484   0x021AA484  data
 *   g_021AA480   0x021AA480  data
 *   func_02085D94  0x02085D94  arm
 *   func_0215CE7C  0x0215CE7C  arm  ov009
 *
 * Allocate one block for `n` records: the first region is the word-aligned
 * n*4 pointer array and the second the word-aligned 0x2c-byte records, both
 * sized through the allocator hook at +0x18 of the object the global points
 * at.  Each record is initialised (func_0215CE7C) into the second region and
 * the block is published at 0x021AA480.  Returns -1 when allocation fails.
 */

typedef void *(*Alloc1)(int);

extern char g_021A1CD8[];
extern char g_021AA484[];
extern char g_021AA480[];
extern void func_02085D94(char *msg, char *p, int n);
extern void func_0215CE7C(void *ptr);

int func_0215CD3C(int n)
{
    char *base;
    char *p;
    int off;
    int size;
    int i;

    size = (n * 0x2c + 3) & ~3;
    off = (n * 4 + 3) & ~3;

    base = (char *)(*(Alloc1 *)(*(char **)g_021A1CD8 + 0x18))(size + off);
    if (base == 0)
        return -1;

    func_02085D94(g_021AA484, base, n);

    p = base + off;
    for (i = n; i > 0; i--) {
        func_0215CE7C(p);
        p += 0x2c;
    }

    *(char **)g_021AA480 = base;
    return 0;
}
