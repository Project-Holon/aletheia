/*
 * function: func_02163C04
 * address:  0x02163C04
 * packet:   pkt_ov010_02163C04
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D83C  0x0216D83C  thumb
 *   func_0216D86C  0x0216D86C  thumb
 *   func_0216D804  0x0216D804  thumb
 *   func_0216D81C  0x0216D81C  thumb
 *   func_02163A08  0x02163A08  thumb
 */

typedef short s16;

extern int func_0216D83C(void);
extern int func_0216D86C(int a);
extern int func_0216D804(int a);
extern int func_0216D81C(int a);
extern void func_02163A08(int a, int b, int c, s16 *r);

int func_02163C04(int a, int x, int y, int flag)
{
    s16 r[4];
    int t;

    t = func_0216D83C();
    func_02163A08(a, t, func_0216D86C(a), r);
    if (r[0] <= x && r[2] >= x && r[1] <= y && r[3] >= y)
        return 1;
    if (flag == 1) {
        t = func_0216D804(a);
        func_02163A08(a, t, func_0216D81C(a), r);
        if (r[0] <= x && r[2] >= x && r[1] <= y && r[3] >= y)
            return 1;
    }
    return 0;
}
