/*
 * file:     unit_021F2BF0.c
 * function: CTRDG_IsAgbCartridge
 * address:  0x021F2BF0
 * packet:   pkt_ov029_021F2BF0
 * region:   ov029
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * sdk:      CTRDG_IsAgbCartridge (libctrdg.TWL.HYB.thumb.a(ctrdg.o))
 *
 * note: the ctrdg.o DWARF prototype is `int CTRDG_IsAgbCartridge(void)` and its
 * body is a two-call `CTRDG_IsExisting() && CTRDGi_IsAgbCartridgeAtInit()`
 * wrapper.  The image at this address is NOT that body: sdkobj masks the two
 * 4-byte THM_CALL fields so the vendor member reports 0 concrete mismatches,
 * but the resident code actually takes a pointer in r0 and inlines the first
 * check as a byte read `p[0x45B]` before calling only
 * CTRDGi_IsAgbCartridgeAtInit.  The C here reproduces the image exactly
 * (verified EXACT); the vendor member at the catalogued row is a masked
 * mis-attribution and is never byte-reachable.
 *
 * symbols:
 *   CTRDGi_IsAgbCartridgeAtInit 0x02035c60 arm
 */

extern int CTRDGi_IsAgbCartridgeAtInit(void);

int CTRDG_IsAgbCartridge(unsigned char *p)
{
    if (p[0x45B]) {
        if (CTRDGi_IsAgbCartridgeAtInit())
            return 1;
    }
    return 0;
}
