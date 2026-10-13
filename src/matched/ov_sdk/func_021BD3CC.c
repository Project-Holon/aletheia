/*
 * function: DWCi_CMNlFontFlag
 * address:  0x021BD3CC
 * packet:   pkt_021BD3CC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_CMNlFontFlag 0x021BD3CC arm
 *   gDwcLanguageTable 0x021DA04C data
 *
 * Table lookup through the function-pointer table at 0x021DA04C.
 * Addresses are Black-image addresses.
 */

extern unsigned char func_021C0EC8(void);
extern int gDwcLanguageTable[];

int DWCi_CMNlFontFlag(void)
{
    return gDwcLanguageTable[func_021C0EC8()];
}
