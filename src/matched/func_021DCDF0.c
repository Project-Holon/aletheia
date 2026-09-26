/*
 * function: func_021DCDF0
 * address:  0x021DCDF0
 * packet:   pkt_021DCDF0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D63C  0x0207D63C  arm
 *
 * Halt handler: on mode 1 pushes the 5-argument SDK stop call with the
 * BLDCNT word 0x04000050, otherwise clears BLDCNT.
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x0207D63C is the ARM
 * SDK symbol G2x_SetBlendAlpha_; declaring it `arm` (not `thumb`) lets the
 * `sdk` class attest the +0012 THM_CALL.  Verified EXACT, 36 bytes.
 */

extern void func_0207D63C(int, int, int, int, int);
void func_021DCDF0(int a)
{
    if (a == 1)
        func_0207D63C(0x04000050, 0, 0x2a, 6, 0xa);
    else
        *(volatile unsigned short *)0x04000050 = 0;
}
