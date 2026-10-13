/*
 * function: FLD3D_CI_InitEventWork
 * address:  0x021C313C
 * packet:   pkt_ov021_021C313C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clears a 0x40-byte record and stores its owner (EXACT*: pad).
 */

typedef unsigned int u32;

extern void func_02082BCC(void *, unsigned, unsigned);

void FLD3D_CI_InitEventWork(u32 a, u32 *p)
{
    func_02082BCC(p, 0, 0x40);
    p[0] = a;
    p[14] = 0;
    p[15] = 0;
}
