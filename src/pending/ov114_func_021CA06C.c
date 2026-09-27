/*
 * function: DWCi_EncSetError
 * address:  0x021CA06C
 * packet:   pkt_ov114_021CA06C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlDWC/libdwcenc.TWL.HYB.a(dwc_encsession.).  decl_line 833.
 */
typedef unsigned long u32;

extern int CTRDGi_IsTaskAvailable(void);
extern void DWCi_SetError(int mode, long value);

void DWCi_EncSetError(void)
{
    if (!CTRDGi_IsTaskAvailable())
        DWCi_SetError(6, 0xFFFEA048);
    *(u32 *)0x021CF7AC = 1;
}
