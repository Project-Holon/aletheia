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
 *   BG_SYS_Update  0x020419E4  arm
 */

void BSUBWAY_RECORD_LIST_VBlankTask(void)
{
    void CLACT_VBlankSystem(void);
    void BG_SYS_Update(void);
    CLACT_VBlankSystem();
    BG_SYS_Update();
}
