/*
 * function: EXT_TestResetCounter
 * address:  0x021C93BC
 * packet:   pkt_ov114_021C93BC
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libext.TWL.HYB.a(ext_scrntest.o).  decl_line 215.  Duplicate
 * body of 0x021C8658 over a different counter datum.
 */
typedef unsigned long u32;

void EXT_TestResetCounter(void)
{
    *(u32 *)0x021D4084 = 0;
}
