/*
 * function: func_021C86A8
 * address:  0x021C86A8
 * packet:   pkt_ov114_021C86A8
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf in a .word run.  Extent 0x021C86A8..0x021C86B8
 * (16 bytes): ldr/ldr/bx plus one pool word naming d_021D3D2C.
 *
 * symbols:
 *   d_021D3D2C  0x021D3D2C  data  a4
 */

extern unsigned int d_021D3D2C[];

int func_021C86A8(void)
{
    return d_021D3D2C[1];
}
