/*
 * function: func_021C4B8C
 * address: 0x021C4B8C
 * packet: pkt_ov093_021C4B8C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * C tail call through r3 into the ov095 walker func_06898D54 (ov095 is
 * loaded in VRAM at 0x0689xxxx), with the ov093 callback func_021C4B9C.
 * Earlier notes called this a linker thunk; it is plain mwcc C.
 * 2026-10-05 (D9r lane16): every byte right; MATCH only because the ABS32
 * to func_021C4B9C needs that file's manifest shard (filed EXACT this wave).
 * Re-run after the shard lands; expected EXACT, then move to src/matched/ov.
 *
 * symbols:
 *   func_06898D54 0x06898D54 thumb ov095
 *   func_021C4B9C 0x021C4B9C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_06898D54(void (*cb)(int, int, u8 *), u8 *arg);
extern void func_021C4B9C(int v, int k, u8 *p);

void func_021C4B8C(u8 *p)
{
    func_06898D54(func_021C4B9C, p);
}
