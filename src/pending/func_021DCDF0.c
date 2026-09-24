/*
 * function: func_021DCDF0
 * address:  0x021DCDF0
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0207D63C  0x0207D63C  thumb
 *
 * Halt handler: on mode 1 pushes the 5-argument SDK stop call with the
 * BLDCNT word 0x04000050, otherwise clears BLDCNT.
 *
 * Blocked site: +0012, the THM_CALL to the SDK func_0207D63C.  Every byte
 * matches, but that ARM9 address has no independent witness, so the field
 * stays wildcarded and the entry caps at MATCH.  Same class as
 * func_021DE898.  Re-measure when the integrator has an SDK witness.
 */

extern void func_0207D63C(int, int, int, int, int);
void func_021DCDF0(int a)
{
    if (a == 1)
        func_0207D63C(0x04000050, 0, 0x2a, 6, 0xa);
    else
        *(volatile unsigned short *)0x04000050 = 0;
}
