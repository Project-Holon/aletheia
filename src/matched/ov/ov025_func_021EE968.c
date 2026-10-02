/*
 * function: func_021EE968
 * address: 0x021EE968
 * packet: pkt_ov025_021EE968
 * region: ov025
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding at 0x021EE97E.
 * symbols:
 *   func_021A231C 0x021A231C thumb ov021
 *   func_021A2120 0x021A2120 thumb ov021
 */
typedef unsigned int u32;
extern void func_021A231C(u32 *, int);
extern void func_021A2120(u32 *, int);
int func_021EE968(u32 *p, int x)
{
    func_021A231C(p, x);
    func_021A2120(p, x);
    return 1;
}
