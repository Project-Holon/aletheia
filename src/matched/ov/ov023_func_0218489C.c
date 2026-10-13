/*
 * function: OEKAKI_VBlankTask
 * address:  0x0218489C
 * packet:   pkt_0218489C
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   func_020419E4  0x020419E4  arm
 */

void CLACT_VBlankSystem(void);
void func_020419E4(void);

void OEKAKI_VBlankTask(void)
{
    CLACT_VBlankSystem();
    func_020419E4();
}
