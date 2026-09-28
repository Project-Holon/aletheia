/*
 * function: DWCi_EncSetError
 * address:  0x021CA06C
 * packet:   pkt_ov114_021CA06C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlDWC/libdwcenc.TWL.HYB.a(dwc_encsession.).  decl_line 833.
 *
 * Closed 2026-09-28: the name CTRDGi_IsTaskAvailable is ambiguous in
 * symbols_sdk.json (11 addresses); the bare name resolved to 0x02010054 (a
 * thumb entry), so the call compiled to `blx` at the wrong address.  Pinning
 * it in the symbols block as `CTRDGi_IsTaskAvailable 0x02059F38 arm` gives the
 * `bl` the image has.  The catalogued name belongs to a different SDK build
 * instance; see
 * docs/idioms/an-overlay-thunk-sdk-callee-is-the-overlays-own-build.md.
 *
 * symbols:
 *   CTRDGi_IsTaskAvailable  0x02059F38  arm
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
