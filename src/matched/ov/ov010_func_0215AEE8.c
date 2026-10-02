/*
 * function: func_0215AEE8
 * address:  0x0215AEE8
 * packet:   pkt_ov010_0215AEE8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern void *func_0215A5E4(void *a0);
extern int func_0215A5CC();
extern int func_02159B10();
extern void *func_0200CA1C(void *a);
extern void *func_020173F0(u32 species, u32 level, u64 id, u32 heap);
extern int func_0200CFA0();
extern int func_020307B0();

int func_0215AEE8(int a0, int a1)
{
    void *v0;
    int k;
    int m, o;
    void *n;
    v0 = func_0200CA1C((void *)func_0215A5E4((void *)a1));
    k = func_0215A5CC(a1);
    m = func_02159B10(a0, a1);
    o = func_02159B10(a0, a1);
    n = func_020173F0(o, 1, 0xFFFFFFFF00000000ULL, k);
    switch (m) {
    case 0:
        func_0200CFA0(v0, n);
        break;
    case 1:
        break;
    }
    func_020307B0(n);
    return 0;
}
