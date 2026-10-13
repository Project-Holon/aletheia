/*
 * function: BTL_SERVER_FLOW_ProcSideEffectsExpire
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
 * loaded in VRAM at 0x0689xxxx), with the ov093 callback BTL_SERVER_FLOW_OnSideEffectExpired.
 * Earlier notes called this a linker thunk; it is plain mwcc C.
 * 2026-10-05 (D9r lane16): every byte right; MATCH only because the ABS32
 * to BTL_SERVER_FLOW_OnSideEffectExpired needs that file's manifest shard (filed EXACT this wave).
 * Re-run after the shard lands; expected EXACT, then move to src/matched/ov.
 *
 * symbols:
 *   func_06898D54 0x06898D54 thumb ov095
 *   BTL_SERVER_FLOW_OnSideEffectExpired 0x021C4B9C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_06898D54(void (*cb)(u8, u32, u32), u32 arg);
extern void BTL_SERVER_FLOW_OnSideEffectExpired(int v, int k, u8 *p);

void BTL_SERVER_FLOW_ProcSideEffectsExpire(u8 *p)
{
    func_06898D54((void (*)(u8,  u32,  u32))BTL_SERVER_FLOW_OnSideEffectExpired, (u32)p);
}
