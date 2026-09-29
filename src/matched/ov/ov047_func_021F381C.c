/*
 * function: func_021F381C
 * address:  0x021F381C
 * packet:   pkt_ov047_021F381C
 * region:   ov047
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A30C8  0x021A30C8  thumb  ov021
 *   func_021AB100  0x021AB100  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB44C  0x021AB44C  thumb  ov021
 */

extern int func_021A30C8(int a);
extern int func_021AB100(void);
extern void func_021AB0F0(int a);
extern int func_021AB44C(void);

int func_021F381C(int *p)
{
    int r4 = func_021A30C8(*p);
    if (func_021AB100() == 0) {
        return 0;
    }
    func_021AB0F0(r4);
    return func_021AB44C();
}
