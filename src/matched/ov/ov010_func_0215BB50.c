/*
 * function: func_0215BB50
 * address:  0x0215BB50
 * packet:   pkt_ov010_0215BB50
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
    void *p0;
    void *p1;
    void *p2;
    int z;
    int c0;
    int c1;
    int c2;
    int c3;
} Req;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern u16 func_0215A5CC(void *);
extern void *func_02012934(void *p);
extern void func_02012944(void *);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_02159B10(void *, void *);
extern u16 func_0215C510(void *, Req *);

int func_0215BB50(void *a0, void *a1)
{
    void *h;
    u16 n;
    u16 *out;
    void *t1;
    void *t2;
    void *t3;
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
    r.h = n;
    r.p0 = t1;
    r.p1 = t2;
    r.p2 = t3;
    r.z = 0;
    r.c0 = 2;
    r.c1 = 2;
    r.c2 = 2;
    r.c3 = 4;
    *out = func_0215C510(h, &r);
    return 0;
}
