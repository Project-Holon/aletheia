/*
 * function: func_021C54BC
 * address: 0x021C54BC
 * packet: pkt_ov093_021C54BC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: Sole blocker of func_021BCCE0; ordinary default-argument tail call.
 * extent: Next function 021C54C8 is already separately matched; 12-byte leaf.
 * semantics: Forwards both pointer inputs unchanged; literal argument 0x350.
 * symbols:
 *   func_021C5D88 0x021C5D88 thumb ov093
 */
typedef unsigned char u8;
extern void func_021C5D88(u8 *, u8 *, int);
void func_021C54BC(u8 *p, u8 *a)
{
    func_021C5D88(p, a, 0x350);
}
