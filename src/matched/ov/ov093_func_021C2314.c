/*
 * function: func_021C2314
 * address: 0x021C2314
 * packet: pkt_ov093_021C2314
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the return at 0x021C232A.
 * interface: func_021C5BE4 reads r0/r1/r2 and forwards r2 unchanged;
 * func_021C4F64 has two arguments in its existing DIFF note.
 * symbols:
 *   func_021C5BE4 0x021C5BE4 thumb ov093
 *   func_021C4F64 0x021C4F64 thumb ov093
 */
typedef unsigned char u8;
extern void func_021C5BE4(u8 *, u8 *, int);
extern int func_021C4F64(u8 *, u8 *);
int func_021C2314(u8 *p, u8 *a)
{
    func_021C5BE4(p, a, 0);
    return func_021C4F64(p, a);
}
