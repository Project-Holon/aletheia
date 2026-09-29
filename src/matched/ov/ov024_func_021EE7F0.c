/*
 * function: func_021EE7F0
 * address:  0x021EE7F0
 * packet:   pkt_ov024_021EE7F0
 * region:   ov024
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021EE7F0  0x021EE7F0  thumb  ov024
 *   func_021A23E8  0x021A23E8  thumb  ov021
 *   func_021A2400  0x021A2400  thumb  ov021
 *   func_021A240C  0x021A240C  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   func_021A23F4  0x021A23F4  thumb  ov021
 *   func_021A2418  0x021A2418  thumb  ov021
 *   func_021A2114  0x021A2114  thumb  ov021
 */

int func_021A23E8(int p);
int func_021A2400(int p);
int func_021A240C(int p);
void func_021A22E0(int p, int a, int b, int c);
int func_021A23F4(int p);
int func_021A2418(int p);
void func_021A2114(int p, int a, int b);

int func_021EE7F0(int p, int v)
{
    int t;

    if (func_021A23E8(p)) {
        t = func_021A2400(p);
        func_021A22E0(p, func_021A240C(p), t, v);
    }
    if (func_021A23F4(p)) {
        func_021A2114(p, 0x52, func_021A2418(p));
    }
    return 1;
}
