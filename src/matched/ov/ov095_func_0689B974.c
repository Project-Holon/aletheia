/*
 * function: func_0689B974
 * address:  0x0689B974
 * packet:   pkt_ov095_0689B974
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0689B9B4   0x0689B9B4  thumb  ov095
 *   func_0689B9C4   0x0689B9C4  thumb  ov095
 *   func_0689B9D4   0x0689B9D4  thumb  ov095
 *   func_0689B9E4   0x0689B9E4  thumb  ov095
 *   func_0689C104   0x0689C104  thumb  ov095
 */

typedef unsigned char u8;

extern int func_0689B9B4(void *);
extern void func_0689B9C4(void *, int);
typedef struct Word { int v; } Word;
extern Word func_0689B9D4(void);
extern int func_0689B9E4(void *, int);
extern void func_0689C104(void *, void *, u8);

void func_0689B974(void *a, void *b, int c)
{
    int t;
    int d;

    if (func_0689B9B4(b) == 0) {
        func_0689B9C4(b, 0x14);
        t = func_0689B9D4().v;
        d = t - func_0689B9E4(b, 0x14);
        if (d > 0)
            func_0689C104(a, b, d);
    }
}
