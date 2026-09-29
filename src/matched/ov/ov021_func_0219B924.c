/*
 * function: func_0219B924
 * address:  0x0219B924
 * packet:   pkt_ov021_0219B924
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   func_0216DA7C  0x0216DA7C  thumb  ov010
 *   func_0219B9D8  0x0219B9D8  thumb  ov021
 *   func_0219BA0C  0x0219BA0C  thumb  ov021
 *   func_0219BA6C  0x0219BA6C  thumb  ov021
 *   func_0216DA44  0x0216DA44  thumb  ov010
 */

typedef unsigned char u8;

extern void func_0216DA50(int a);
extern void func_0216DA7C(int a);
extern int func_0219B9D8(int a, u8 *b);
extern void func_0219BA0C(int a, u8 *b);
extern int func_0219BA6C(int a);
extern void func_0216DA44(int a);

int func_0219B924(int a, u8 *b)
{
    func_0216DA50(a);
    func_0216DA7C(a);
    if (func_0219B9D8(a, b) == 1) {
        func_0219BA0C(a, b);
        if (func_0219BA6C(a) == 1) {
            func_0216DA44(a);
            b[0]++;
            return 1;
        }
    }
    return 0;
}
