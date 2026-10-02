/*
 * function: func_02166A00
 * address:  0x02166A00
 * packet:   pkt_ov010_02166A00
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F38  0x02012F38  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02166854  0x02166854  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 */

extern int func_0215A5F4(void *b);
extern int func_0215A5DC(void *b);
extern void *func_020120F4(void *p);
extern int func_02012F38(int base);
extern int func_02159B10(void *a, void *b);
extern int func_02159AE8(void *a, void *b);
extern int func_02166854(int a, int b, int c, int d, int e);
extern void func_0215897C(int a, int b);

int func_02166A00(void *a, void *b)
{
    int r6 = func_0215A5F4(b);
    int r7 = func_0215A5DC(b);
    int v1;
    int v2;
    int v3;
    int v4;
    int t;
    func_02012F38((int)func_020120F4((void *)r7));
    v1 = func_02159B10(a, b);
    v2 = func_02159AE8(a, b);
    v3 = func_02159AE8(a, b);
    v4 = func_02159AE8(a, b);
    t = func_02166854(r7, v1, v2, v3, v4);
    if (t == 0)
        return 1;
    func_0215897C(r6, t);
    return 1;
}
