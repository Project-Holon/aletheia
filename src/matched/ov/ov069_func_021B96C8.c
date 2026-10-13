/*
 * function: BSUBWAY_RECORD_LIST_VBlankTask
 * address:  0x021B96C8
 * packet:   pkt_ov069_021B96C8
 * region:   ov069
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two-call wrapper into ARM9 code.
 *
 * symbols:
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   func_020419E4  0x020419E4  arm
 */

void BSUBWAY_RECORD_LIST_VBlankTask(void)
{
    void CLACT_VBlankSystem(void);
    void func_020419E4(void);
    CLACT_VBlankSystem();
    func_020419E4();
}
