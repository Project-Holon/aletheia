/*
 * function: func_021AE66C
 * address:  0x021AE66C
 * packet:   pkt_ov021_021AE66C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021642B4  0x021642B4  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 */

extern void *func_021A3074(unsigned char *p);
extern int func_0216D83C(int x);
extern int func_0216D86C(int x);
extern int func_021642B4(int a, int b, int c, int d);
extern int func_0216D5F8(int x);
extern int func_0216D3CC(int x);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(int a, int b);

int func_021AE66C(int *p)
{
    void *r4 = func_021A3074(p[0x34 / 4]);
    int r6 = func_0216D83C(r4);
    int r7 = func_0216D86C(r4);
    int t = func_0216D83C(p[2]);

    r6 = func_021642B4(r6, r7, t, func_0216D86C(p[2]));
    if (r6 != func_0216D5F8(r4) && (p[9] == 0 || p[7] == 2)) {
        if (func_0216D3CC(r4) == 1) {
            func_0216D410(r4, func_02197E7C(r6, 0));
            p[0] = 0xf;
        }
    } else {
        p[0] = 0x10;
    }
    return 0;
}
