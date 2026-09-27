/*
 * function: DWCi_EncSessionGetResponse
 * address:  0x021CA228
 * packet:   pkt_ov114_021CA228
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlDWC/libdwcenc.TWL.HYB.a(dwc_encsession.o).
 *
 * symbols:
 *   d_021CF7AC   0x021CF7AC  data
 */
typedef unsigned long u32;

extern char d_021CF7AC[];

u32 DWCi_EncSessionGetResponse(u32 *out)
{
    *out = *(u32 *)(d_021CF7AC + 0x6C);
    return *(u32 *)(d_021CF7AC + 0x68);
}
