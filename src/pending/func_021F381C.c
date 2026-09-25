/*
 * function: func_021F381C
 * address:  0x021F381C
 * packet:   pkt_021F381C
 * region:   ov057
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  all four func_02047910 call sites are inside this range and the
 *           target has no func_ label anywhere, so it is not in
 *           layout/symbols_sdk.json and has no label/literal witness; the
 *           fifth site (func_02046BE0) resolves.  Byte-correct otherwise.
 *
 * symbols:
 *   func_02047910  0x02047910  arm
 *   func_02046BE0  0x02046BE0  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02047910(u32 a, u32 b, u32 c);
extern void func_02046BE0(u32 a, u32 b);

void func_021F381C(void *a, void *b, u8 *p)
{
    u32 m = 1 << 12;

    func_02047910(*(u32 *)(p + 0x38), 0, m);
    func_02047910(*(u32 *)(p + 0x38), 3, m);
    func_02047910(*(u32 *)(p + 0x3c), 1, m);
    func_02047910(*(u32 *)(p + 0x40), 2, m);
    func_02046BE0(1, 1);
}
