/*
 * function: func_0216CDB8
 * address:  0x0216CDB8
 * packet:   pkt_ov010_0216CDB8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled thumb leaf (store, then tail call through a pool word), the
 * sole blocker of ov021 func_02189204 (lane S26).
 * symbols:
 *   func_0216D95C  0x0216D95C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0216D95C(u8 *p, u32 v);

void func_0216CDB8(u8 *p, u32 v)
{
    *(u32 *)(p + 0x40) = v;
    func_0216D95C(p, 1);
}
