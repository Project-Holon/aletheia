/*
 * function: func_021EF514
 * address: 0x021EF514
 * packet: pkt_ov025_021EF514
 * region: ov025
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A2228 0x021A2228 thumb ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int *func_021A21B8(int *);
extern void func_021A2228(u8 *, int, int, int, int);

int func_021EF514(u8 *a)
{
    int *p;
    p = func_021A21B8((int *)a);
    func_021A2228(a, 0, 16, 2, -2);
    *p = 100;
    return 1;
}
