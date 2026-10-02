/*
 * function: func_021EE740
 * address: 0x021EE740
 * packet: pkt_ov028_021EE740
 * region: ov028
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 */

typedef unsigned int u32;
extern int *func_021A21B8(int *);
extern void func_021A22E0(u32 *, int, int, int);
int func_021EE740(u32 *a, int b)
{
    int *p;
    p = func_021A21B8((int *)a);
    func_021A22E0(a, 9, 0x7FDF, b);
    p[0] = 0;
    p[10] = 9;
    p[11] = 0x7F78;
    return 1;
}
