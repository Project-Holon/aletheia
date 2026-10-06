/*
 * function: func_021EE7C0
 * address: 0x021EE7C0
 * packet: pkt_ov028_021EE7C0
 * region: ov028
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_02014A10 0x02014A10 thumb
 *   func_021A2114 0x021A2114 thumb ov021
 */

typedef unsigned int u32;
typedef unsigned short u16;
extern int *func_021A21B8(int *);
extern void func_021A22E0(u32 *, int, int, int);
extern u16 func_02014A10(u32);
extern int func_021A2114(u32 a, int b, u32 c);
int func_021EE7C0(u32 *a, int b)
{
    int *p;
    p = func_021A21B8((int *)a);
    func_021A22E0(a, p[10], p[11], b);
    func_021A2114((u32)a, 62, func_02014A10(9));
    return 1;
}
