/*
 * function: func_021D7CAC
 * address:  0x021D7CAC
 * packet:   pkt_021D7CAC
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Resolved: the ov121 region hint on the data symbol was contested by the
 * other overlays in the window; un-hinted, sole-ref/data picks the unique
 * overlay start, so the ABS32 pool relocation resolves (the PC24 to
 * func_02086028 was already `label`).
 *
 * symbols:
 *   func_02086028  0x02086028  arm
 *   d_021DA174     0x021DA174  data  a4
 *
 * Addresses are Black-image addresses.
 */

extern void func_02086028(void *);
extern char d_021DA174[];

void func_021D7CAC(void)
{
    func_02086028(d_021DA174);
}
