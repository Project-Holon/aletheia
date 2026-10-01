/*
 * function: func_021C2784
 * address:  0x021C2784
 * packet:   pkt_ov021_021C2784
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * VBlank task: arms display capture, ends itself, flags completion.
 */

typedef unsigned int u32;

extern void func_02030EAC(void *p);

void func_021C2784(void *p, u32 *done)
{
    *(volatile u32 *)0x04000064 = 0x81330010;
    func_02030EAC(p);
    if (done != 0)
        *done = 1;
}
