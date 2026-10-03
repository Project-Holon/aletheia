/*
 * function: func_0215BBD0
 * address:  0x0215BBD0
 * packet:   pkt_ov010_0215BBD0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of func_0215BB50 (same request record, eight reads instead of
 * three, three of them clamped to 2), and of func_0215C200: the u16 locals
 * are what make the second clamp reload its value from the spill slot.
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215C510  0x0215C510  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 h;
    int p0;
    int p1;
    int p2;
    int z;
    int c0;
    int c1;
    int c2;
    int c3;
} Req;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern u16 func_0215A5CC(void *);
struct BigObj;
extern void *func_02012934(const struct BigObj *p);
extern u8 *func_02012944(void *p);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u16 func_02159B10(void *, void *);
extern int func_0215C510(void *a, void *b);

int func_0215BBD0(void *a0, void *a1)
{
    void *h;
    u16 n;
    u16 *out;
    u16 t1;
    u16 t2;
    u16 t3;
    u16 t4;
    u16 t5;
    u16 t6;
    u16 t7;
    u16 t8;
    Req r;

    func_0215A5DC(a1);
    h = func_0215A5E4(a1);
    n = func_0215A5CC(a1);
    func_02012934(h);
    func_02012944(h);
    out = func_02159AE8(a0, a1);
    t1 = func_02159B10(a0, a1);
    t2 = func_02159B10(a0, a1);
    t3 = func_02159B10(a0, a1);
    t4 = func_02159B10(a0, a1);
    t5 = func_02159B10(a0, a1);
    t6 = func_02159B10(a0, a1);
    t7 = func_02159B10(a0, a1);
    t8 = func_02159B10(a0, a1);
    r.h = n;
    r.p0 = t1;
    r.p1 = t2;
    r.p2 = t3;
    r.z = t7;
    r.c0 = t4;
    if (r.c0 >= 3)
        r.c0 = 2;
    r.c1 = t5;
    if (r.c1 >= 3)
        r.c1 = 2;
    r.c2 = t6;
    if (r.c2 >= 3)
        r.c2 = 2;
    r.c3 = t8;
    *out = func_0215C510(h, &r);
    return 0;
}
