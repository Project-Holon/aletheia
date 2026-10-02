/*
 * function: func_021C88EC
 * address:  0x021C88EC
 * packet:   pkt_ov021_021C88EC
 * region:   ov021
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
 *   func_02012ED0  0x02012ED0  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_021C87D4  0x021C87D4  thumb  ov021
 */

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void func_020120F4();
extern int *func_02012ED0();
extern int func_02159B10(int a, int b);
extern int func_02011330(int a);
extern void func_021C87D4(int p, int i, int v);

int func_021C88EC(int a, int b)
{
    int *r7;
    int sp;
    int r5;
    int v;

    func_0215A5F4((void *)b);
    func_0215A5DC((void *)b);
    func_020120F4();
    r7 = func_02012ED0();
    sp = func_02159B10(a, b);
    r5 = func_02011330(a);
    func_02011330(a);
    v = func_02159B10(a, b);
    switch (r5) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    case 8:
        func_021C87D4(*r7, sp, v == 1);
        break;
    }
    return 0;
}
