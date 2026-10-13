/*
 * function: DWC_GdbGetAsyncResult
 * address:  0x021E1454
 * packet:   pkt_ov175_021E1454
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: DWC_GdbGetAsyncResult (TwlDWC/libdwcgdb.TWL.HYB.a,
 * dwc_gdb.o), ov175.  Read the +0x10 async-result word.
 *
 * symbols:
 *   gDwcGdbEntity  0x021E5334  data
 */

typedef unsigned int u32;

extern u32 gDwcGdbEntity[];

u32 DWC_GdbGetAsyncResult(void)
{
    return gDwcGdbEntity[4];
}
