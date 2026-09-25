/*
 * function: func_021BC6FC
 * address:  0x021BC6FC
 * packet:   pkt_021BC6FC
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call getter: loads p[0x52] and tail-calls sub_020452E8.
 *
 * symbols:
 *   sub_020452E8  0x020452E8  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 sub_020452E8(u32);

u32 func_021BC6FC(u32 *p)
{
    return sub_020452E8(p[0x52]);
}
