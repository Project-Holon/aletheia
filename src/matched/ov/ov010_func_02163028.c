/*
 * function: func_02163028
 * address:  0x02163028
 * packet:   pkt_ov010_02163028
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DA20  0x0216DA20  thumb  ov010
 *   func_021630F4  0x021630F4  thumb  ov010
 *   func_0216310C  0x0216310C  thumb  ov010
 *   func_02163130  0x02163130  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_02197EB4  0x02197EB4  thumb  ov021
 *   func_0216DB10  0x0216DB10  thumb  ov010
 *   func_02163090  0x02163090  thumb  ov010
 *   func_0219B41C  0x0219B41C  thumb  ov021
 *   func_0216D708  0x0216D708  thumb  ov010
 *   func_02163154  0x02163154  thumb  ov010
 *   func_02163188  0x02163188  thumb  ov010
 */

extern int func_0216DA20();
extern void func_021630F4();
extern void func_0216310C();
extern void func_02163130();
extern int func_0216D57C();
extern void func_02197EB4();
extern int func_0216DB10();
extern int func_02163090();
extern int func_0219B41C();
extern void func_0216D708();
extern void func_02163154();
extern void func_02163188();

void func_02163028(int a)
{
    int t = 2;

    if (func_0216DA20(a, t) == 0) {
        func_021630F4(a);
        func_0216310C(a);
        func_02163130(a);
        if (func_0216D57C(a, t << 8) != 0) {
            func_02197EB4(a);
        } else if (func_0216DB10(a) == 0) {
            if (func_02163090(a) == 1) {
                if (func_0219B41C(a) == 0) {
                    func_0216D708(a);
                }
            }
        }
        func_02163154(a);
        func_02163188(a);
    }
}
