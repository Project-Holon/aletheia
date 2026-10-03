/*
 * unit:     yes
 * function: func_021E2700, func_021E275C
 * address:  0x021E2700
 * packet:   pkt_ov093_021E2700
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021E8860  0x021E8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021E03F8  0x021E03F8  thumb  ov093
 *   d_021F29C8     0x021F29C8  data   ov093  a4
 */

typedef unsigned int u32;
typedef unsigned short u16;

struct Cnt { u32 n; int max; };

extern int func_021D775C(int key);
struct QQ;
struct UtilWork;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void func_021E8860(int n);
extern u16 func_021D70A8(struct QQ *p);
extern void func_021E03F8(int a, int b);
extern int d_021F29C8[];

void func_021E2700(void *a, void *b, int c, struct Cnt *d)
{
    void *v;
    u32 i;
    int k;

    if (c == func_021D775C(3)) {
        v = func_021C7CF4(b, c);
        k = 1;
        for (i = 0; i < d->n; i++)
            k <<= 1;
        if (func_021D5BDC(v, 7))
            k <<= 1;
        func_021E8860(k);
        d->n++;
        if ((int)d->n >= d->max)
            func_021E03F8(c, func_021D70A8(a));
    }
}

int *func_021E275C(int *p)
{
    *p = 2;
    return d_021F29C8;
}
