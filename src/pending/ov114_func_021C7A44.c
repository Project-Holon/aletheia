/*
 * function: DWCi_Ndi_memcpy
 * address:  0x021C7A44
 * packet:   pkt_ov114_021C7A44
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlDWC/libdwcnd.TWL.HYB.a(dwci_nd.o).  decl_line 1812.  Duplicate of
 * 0x021BA100.
 */
typedef unsigned long u32;

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

void DWCi_Ndi_memcpy(void *dst, void *src, u32 size)
{
    MI_CpuCopy8(src, dst, size);
}
