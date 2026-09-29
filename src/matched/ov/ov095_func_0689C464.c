/*
 * function: func_0689C464
 * address:  0x0689C464
 * packet:   pkt_ov095_0689C464
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0689C424   0x0689C424  thumb  ov095
 *   func_0689C4E0   0x0689C4E0  thumb  ov095
 *   func_0689C4F0   0x0689C4F0  thumb  ov095
 *   func_0689C500   0x0689C500  thumb  ov095
 *   func_0689C510   0x0689C510  thumb  ov095
 *   func_0689C520   0x0689C520  thumb  ov095
 *   func_0689C530   0x0689C530  thumb  ov095
 */

typedef unsigned short u16;
typedef struct Word { int v; } Word;

extern int func_0689C424(int, int);
extern void func_0689C4E0(void *, int, u16);
extern int func_0689C4F0(void *);
extern void func_0689C500(void *, int);
extern void func_0689C510(void *, int);
extern int func_0689C520(Word);
extern void func_0689C530(void *, int);

int func_0689C464(int a, Word b, void *c, unsigned char d, void *e)
{
    int f;
    int k;

    f = 1;
    if (d == 0)
        f = 0;
    k = func_0689C424(a, f);
    if (k >= 0) {
        func_0689C4E0(e, 2, k);
        func_0689C500(e, func_0689C4F0(c));
        if (f != 0)
            func_0689C510(e, d);
        switch (a) {
        case 8:
            func_0689C530(e, func_0689C520(b));
            break;
        case 0x12:
            func_0689C530(e, 0x49);
            break;
        }
        return 1;
    }
    return 0;
}
