/*
 * function: func_021F7EA4
 * address:  0x021F7EA4
 * packet:   pkt_ov094_021F7EA4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub, filed for the caller ov093 func_021D284C (lane S16).
 *
 * symbols:
 *   func_021F7A28  0x021F7A28  thumb  ov094
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void func_021F7A28(int a, u32 b);

void func_021F7EA4(u32 a)
{
    func_021F7A28(a, 0x26F);
}
