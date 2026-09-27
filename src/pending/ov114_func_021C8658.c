/*
 * function: EXT_TestResetCounter
 * address:  0x021C8658
 * packet:   pkt_ov114_021C8658
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlSDK/libext.TWL.HYB.a(ext_scrntest.o).  decl_line 215.
 */
typedef unsigned long u32;

void EXT_TestResetCounter(void)
{
    *(u32 *)0x021D3D2C = 0;
}
