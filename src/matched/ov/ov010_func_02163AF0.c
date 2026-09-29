/*
 * function: func_02163AF0
 * address:  0x02163AF0
 * packet:   pkt_ov010_02163AF0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02163A08  0x02163A08  thumb  ov010
 *   func_02163A40  0x02163A40  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   func_0216D810  0x0216D810  thumb  ov010
 */

typedef short s16;

extern void func_02163A08();
extern int func_02163A40();
extern int func_0216D55C();
extern int func_0216D83C();
extern int func_0216D86C();
extern int func_0216D854();
extern int func_0216D804();
extern int func_0216D81C();
extern int func_0216D810();

int func_02163AF0(int a, int b, int c, int d, s16 e, int g)
{
    int v1[2];
    int v0[2];
    s16 t;

    func_02163A08(a, c, e, v1);
    if (func_0216D55C(b, 0x80) == 0) {
        func_02163A08(b, func_0216D83C(b), func_0216D86C(b), v0);
        if (func_02163A40(v1, v0) != 0) {
            t = d - func_0216D854(b);
            if (t < 0) {
                t = -t;
            }
            if (t < 1) {
                return 1;
            }
        }
        if (g == 1) {
            func_02163A08(b, func_0216D804(b), func_0216D81C(b), v0);
            if (func_02163A40(v1, v0) != 0) {
                t = d - func_0216D810(b);
                if (t < 0) {
                    t = -t;
                }
                if (t < 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
