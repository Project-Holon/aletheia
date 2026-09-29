/*
 * function: func_021EE740
 * address:  0x021EE740
 * packet:   pkt_ov024_021EE740
 * region:   ov024
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021A23D4  0x021A23D4  thumb  ov021
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A23E8  0x021A23E8  thumb  ov021
 *   func_021A2400  0x021A2400  thumb  ov021
 *   func_021A240C  0x021A240C  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 */

int func_021A23D4(int *p);
int *func_021A21B8(int *p);
int func_021A23E8(int *p);
void func_021A2400(int *p);
int func_021A240C(int *p);
void func_021A22E0(int *p, int a, int b, int c);

int func_021EE740(int *p, int v)
{
    if (func_021A23D4(p)) {
        return 0;
    }
    *func_021A21B8(p) = 0;
    if (func_021A23E8(p)) {
        func_021A2400(p);
        func_021A22E0(p, func_021A240C(p), 0x7FFF, v);
    }
    return 1;
}
