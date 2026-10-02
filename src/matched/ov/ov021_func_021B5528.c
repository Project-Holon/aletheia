/*
 * function: func_021B5528
 * address:  0x021B5528
 * packet:   pkt_ov021_021B5528
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_021D2D50  0x021D2D50  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 h0;
    u16 h2;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 ha;
    u16 hc;
    u8 be;
    u8 bf;
    u32 w10;
    u32 w14;
} Rec;

extern int func_02159B10();
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_021D2D50(void *a, Rec *src);
extern void func_0215897C();

int func_021B5528(int a0, int a1)
{
    int v0 = func_02159B10(a0, a1);
    int v1 = func_02159B10(a0, a1);
    int v2 = func_02159B10(a0, a1);
    int v3 = func_02159B10(a0, a1);
    int v4 = func_02159B10(a0, a1);
    int v5 = func_02159B10(a0, a1);
    int v6 = func_02159B10(a0, a1);
    int v7 = func_02159B10(a0, a1);
    void *r;
    void *o;
    Rec s;

    r = func_0215A5F4((void *)a1);
    o = func_0215A5DC((void *)a1);
    s.h0 = v0;
    s.h2 = v1;
    s.w10 = v2;
    s.bf = v3;
    s.be = v3;
    s.w14 = 0;
    s.h4 = v4;
    s.h6 = v5;
    s.h8 = v6;
    s.ha = 0;
    s.hc = v7;
    func_0215897C(r, func_021D2D50((void *)o, &s));
    return 1;
}
