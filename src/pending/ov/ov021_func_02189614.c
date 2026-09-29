/*
 * function: func_02189614
 * address:  0x02189614
 * packet:   pkt_ov021_02189614
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_02012B38  0x02012B38  thumb
 *   func_02013DD0  0x02013DD0  thumb
 *   func_0201444C  0x0201444C  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_0218DC74  0x0218DC74  thumb  ov021
 *   func_0218DC70  0x0218DC70  thumb  ov021
 *   func_02012844  0x02012844  thumb
 *   func_021939C0  0x021939C0  thumb  ov021
 *   func_02193ABC  0x02193ABC  thumb  ov021
 *   func_02012964  0x02012964  thumb
 *   func_02193AFC  0x02193AFC  thumb  ov021
 *
 * blocker:  byte-correct; the THM_CALL to func_02013DD0 (arm9) has no witness:
 *           0x02013DD0 is an unlabelled arm9 leaf (Ilias's, inside
 *           func_02013D9C's listing extent). Reported EXACT by ov018_func_0217EC7C.c (match.py one
 *           --region arm9 --thumb) as:
 *             extern const int d_0209DFC0[];   (0x0209DFC0 data a4)
 *             int func_02013B10(int a0, const int *a1, int a2);
 *             int func_02013DD0(int a0)
 *             { return func_02013B10(a0, d_0209DFC0, 4); }
 */

typedef unsigned short u16;

extern void *func_02012B38(void *p);
extern int func_02013DD0(int v);
extern int func_0201444C(void *p);
extern void *func_020127C4(void *p);
extern void *func_020127D0(void *p, int z);
extern void func_0218DC74(void *a, void *b, int c);
extern void *func_0218DC70(void *a);
extern void *func_02012844(void *p);
extern void func_021939C0(void *a, void *b, int c, int d);
extern void func_02193ABC(void *a, int b, int c);
extern void *func_02012964(void *p);
extern void func_02193AFC(void *a, void *b);

void func_02189614(void *p, char *q)
{
    void *t;
    int k;
    void *m;
    void *a;

    t = func_02012B38(p);
    if (func_02013DD0(*(u16 *)(q + 0xd0)) != 0) {
        k = func_0201444C(t);
        if (k == 0)
            m = func_020127C4(*(void **)(q + 8));
        else
            m = func_020127D0(*(void **)(q + 8), 0);
        func_0218DC74(*(void **)(q + 0x48), m, k);
        a = func_0218DC70(*(void **)(q + 0x48));
        func_021939C0(a, func_02012844(p), k, *(u16 *)q);
        func_02193ABC(a, *(int *)(q + 0x10), *(u16 *)q);
        func_02193AFC(a, func_02012964(*(void **)(q + 8)));
    }
}
