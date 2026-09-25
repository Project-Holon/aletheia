/*
 * function: func_021F73A4
 * address:  0x021F73A4
 * packet:   pkt_ov094_021F73A4
 * region:   ov094
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B30  0x02048B30  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_0207CBD0  0x0207CBD0  arm
 */

extern void func_02048AE8(int, int *);
extern void func_02048B30(int, int *);
extern int func_0207CFB8(int, int);
extern int func_0207CBD0(int *);

void func_021F73A4(int *p)
{
    int a[3];
    int b[3];
    func_02048AE8(p[1], a);
    func_02048B30(p[1], b);
    a[0] -= b[0];
    a[1] -= b[1];
    a[2] -= b[2];
    p[2] = func_0207CFB8(a[1], a[2]);
    p[3] = func_0207CFB8(a[2], a[0]);
    p[4] = func_0207CBD0(a);
}
