/*
 * function: func_021EF1D4
 * address: 0x021EF1D4
 * packet: pkt_ov026_021EF1D4
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A231C 0x021A231C thumb ov021
 *   func_021A2120 0x021A2120 thumb ov021
 */

typedef unsigned int u32;
extern int *func_021A21B8(int *);
extern void func_021A231C(u32 *, int);
extern void func_021A2120(u32 *, int);
int func_021EF1D4(u32 *a, int b)
{
    func_021A21B8((int *)a);
    func_021A231C(a, b);
    func_021A2120(a, b);
    return 1;
}
