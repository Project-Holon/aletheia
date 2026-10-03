/*
 * function: func_021BEBA8
 * address:  0x021BEBA8
 * packet:   pkt_ov021_021BEBA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BEF8C  0x021BEF8C  thumb  ov021
 *   func_021BEA6C  0x021BEA6C  thumb  ov021
 */

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} Work;

extern void *func_020122C0(int a, int b, void (*cb)(void), int size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void func_021BEF8C(void);
extern int func_021BEA6C(int a);

void *func_021BEBA8(int a, int b)
{
    void *t = func_020122C0(a, 0, func_021BEF8C, 0x2c);
    Work *w = func_020124E8(t);
    w->f0 = a;
    w->f4 = b;
    w->f8 = 2;
    w->fC = func_021BEA6C(2);
    return t;
}
