/*
 * function: func_021F2AEC
 * address:  0x021F2AEC
 * packet:   pkt_ov029_021F2AEC
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F2B9C  0x021F2B9C  thumb  ov029
 *   func_021F2BB8  0x021F2BB8  thumb  ov029
 *   func_021F2BD4  0x021F2BD4  thumb  ov029
 *   func_021F1290  0x021F1290  thumb  ov029
 *   func_020091AC  0x020091AC  thumb
 *   func_020409B4  0x020409B4  arm
 *   func_021F20AC  0x021F20AC  thumb  ov029
 */

extern int func_021F2B9C(int p, int i, int j);
extern int func_021F2BB8(int p, int i, int j);
extern int func_021F2BD4(int p, int i, int j, int k);
extern void func_021F1290(int p, int i, int j, int k);
extern void func_020091AC(int a, int b, int c, int d, int e, int f);
extern void func_020409B4(int a);
extern void func_021F20AC(int p);

void func_021F2AEC(int p, int a1, int a2, int a3, int k)
{
    int j;
    int i;

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 9; i++) {
            if (k == func_021F2B9C(p, i, j)) {
                if (func_021F2BB8(p, i, j) != 0) {
                    func_020091AC(a1, i, j, k, 0, 1);
                    func_021F1290(p, i, j, k);
                } else if (func_021F2BD4(p, i, j, k) != 0) {
                    func_020091AC(a1, i, j, k, 0, 0);
                }
            }
        }
    }
    func_020091AC(a1, a2, a3, k, 1, 0);
    func_021F1290(p, a2, a3, k);
    func_020409B4(4);
    func_021F20AC(p);
}
