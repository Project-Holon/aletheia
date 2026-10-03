/*
 * function: func_02022230
 * address:  0x02022230
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The companion forwarder to func_02022224: it passes the caller's engine
 * selector straight through to func_020222CC and supplies the unused second
 * argument as zero.  Same pool-word-and-`bx` tail call shape.
 *
 * symbols:
 *   func_020222CC  0x020222CC  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022230.c \
 *       --func func_02022230 --addr 0x02022230 --cc 1.1p1 --thumb
 */
typedef unsigned int u32;

extern void func_020222CC(u32 which, int brightness);

void func_02022230(u32 which)
{
    func_020222CC(which, 0);
}
