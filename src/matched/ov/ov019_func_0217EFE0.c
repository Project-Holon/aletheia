/*
 * function: func_0217EFE0
 * address:  0x0217EFE0
 * packet:   pkt_ov019_0217EFE0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02024988  0x02024988  thumb
 *   func_020249A0  0x020249A0  thumb
 *   d_0218044C     0x0218044C  data
 */

extern int func_02012EBC(int a);
extern int func_02024988(int a);
extern void func_020249A0(int a, int b);
extern int d_0218044C[];

void func_0217EFE0(int a, unsigned int n)
{
    int r;
    unsigned short i;
    r = func_02024988(func_02012EBC(a));
    i = n - 1;
    if (n >= 1 && n <= 8) {
        if (i < 8) {
            func_020249A0(r, d_0218044C[i]);
            return;
        }
        func_020249A0(r, 7);
        return;
    }
    func_020249A0(r, 7);
}
