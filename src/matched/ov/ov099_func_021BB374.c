/*
 * function: func_021BB374
 * address:  0x021BB374
 * packet:   pkt_ov099_021BB374
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C37D4     0x021C37D4  data   ov099  a2
 *   func_021BB42C  0x021BB42C  thumb  ov099
 *   func_02009864  0x02009864  thumb
 *   func_02025C88  0x02025C88  thumb
 *   func_0202DA04  0x0202DA04  thumb
 *   func_0202DA48  0x0202DA48  thumb
 *   func_0202DA18  0x0202DA18  thumb
 *   func_0202DA6C  0x0202DA6C  thumb
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 */

typedef unsigned short u16;

typedef struct {
    u16 v[4];
} T4;

extern const T4 d_021C37D4;
extern void func_021BB42C(void *p);
extern int func_02009864(void *h, int id, int n);
extern int func_02025C88(void);
extern void *func_0202DA04(u16 a);
extern void *func_0202DA48(void *a, int b, int c, u16 d);
extern void *func_0202DA18(void *a, int b, int c, int d, u16 e);
extern void *func_0202DA6C(int a, int b, int c, u16 d);
extern void func_02049238(void *o);
extern void *func_0204B294(void *a, void *b, void *c, void *d, T4 *e, int f, u16 g);

void func_021BB374(char *p, int a, int b)
{
    T4 t;
    int r;
    void *o;

    t = d_021C37D4;
    if (*(void **)(p + 0x180) != 0)
        func_021BB42C(p);
    func_02009864(*(void **)(p + 4), a, 8);
    r = func_02025C88();
    o = func_0202DA04(b);
    *(void **)(p + 0x184) = func_0202DA48(o, r, 1, b);
    *(void **)(p + 0x188) = func_0202DA18(o, r, 1, 0, b);
    *(void **)(p + 0x18C) = func_0202DA6C(r, 2, 1, b);
    func_02049238(o);
    *(void **)(p + 0x180) = func_0204B294(*(void **)(p + 0x110), *(void **)(p + 0x184), *(void **)(p + 0x188), *(void **)(p + 0x18C), &t, 1, b);
}
