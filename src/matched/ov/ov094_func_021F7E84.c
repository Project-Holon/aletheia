/*
 * function: func_021F7E84
 * address:  0x021F7E84
 * packet:   pkt_ov094_021F7E84
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub, filed as a witness for the caller ov093 BTLV_CORE_SetMonShown (wave B3 lane 17).
 *
 * symbols:
 *   func_021F7A28  0x021F7A28  thumb  ov094
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void func_021F7A28(int a, u32 b);

void func_021F7E84(u32 a)
{
    func_021F7A28(a, 0x286);
}
