/*
 * function: func_021EED58
 * address: 0x021EED58
 * packet: pkt_ov025_021EED58
 * region: ov025
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding at 0x021EED76.
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A231C 0x021A231C thumb ov021
 *   func_021A2120 0x021A2120 thumb ov021
 */
typedef unsigned int u32;
extern int *func_021A21B8(int *);
extern void func_021A231C(u32 *, int);
extern void func_021A2120(u32 *, int);
int func_021EED58(u32 *p, int x)
{
    func_021A21B8((int *)p);
    func_021A231C(p, x);
    func_021A2120(p, x);
    return 1;
}
