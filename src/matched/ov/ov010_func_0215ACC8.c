/*
 * function: func_0215ACC8
 * address:  0x0215ACC8
 * packet:   pkt_ov010_0215ACC8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_020071EC  0x020071EC  thumb
 *   func_020071E4  0x020071E4  thumb
 *   func_0200723C  0x0200723C  thumb
 */

extern int func_0215A5E4(int);
extern int func_02012EBC(void);
extern unsigned short *func_02159AE8(int, int);
extern int func_020071EC(int);
extern int func_020071E4(int);
extern void func_0200723C(int, unsigned *, unsigned *);

int func_0215ACC8(int a, int b)
{
    int r4;
    unsigned short *r7;
    unsigned short *m;
    unsigned short *r5;
    unsigned s2;
    unsigned s1;

    func_0215A5E4(b);
    r4 = func_02012EBC();
    r7 = func_02159AE8(a, b);
    m = func_02159AE8(a, b);
    r5 = func_02159AE8(a, b);
    s2 = 0;
    s1 = 0;
    *r7 = func_020071EC(r4);
    *m = func_020071E4(r4);
    func_0200723C(r4, &s1, &s2);
    if (s1 * 3 < s2) {
        *r5 = 0;
    } else {
        *r5 = 1;
    }
    return 0;
}
